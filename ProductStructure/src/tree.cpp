#include "tree.h"
#include <iostream>
#include <gvc.h>

using namespace std;

string tree::colour_seq[] = {"darkorange","springgreen","yellowgreen","yellow","gold","aquamarine"};

tree::tree(std::string bnam,
           std::string bnum,
           std::string brev,
           std::string bdes)
{
    top_node = new node(bnam,bnum,brev,bdes);
    //++(*top_node);
    pcur = top_node;
    tsize = 1;
    tiers = 1;
}

tree::tree(node* aNode)
{
    top_node = aNode;
    //++(*top_node);
    pcur = top_node;
    tsize = 1;
    tiers = 1;
}

tree::~tree()
{
    if (tsize > 0)
    {
        if (top_node->num_subs() > 0)
        {

        }
        else
            delete top_node;
    }
}

bool tree::init(std::string bnam,
                std::string bnum,
                std::string brev,
                std::string bdes)
{
    if (tsize == 0)
    {
        top_node = new node(bnam,bnum,brev,bdes);
        //++(*top_node);
        pcur = top_node;
        tsize = 1;
        tiers = 1;
        return true;
    }
    else
        return false;
}

bool tree::add_node(node *aNode)
{
    if (pcur->get_tier() == aNode->get_tier())
        add_sibling(aNode);
    else if (pcur->get_tier() == aNode->get_tier() - 1)
        add_child(aNode);
    else if (pcur->get_tier() > aNode->get_tier())
    {
        pcur = pcur->get_sup();
        add_node(aNode);
    }
    else if (pcur->get_tier() < aNode->get_tier())
    {
        cout << "new node is more than one level deeper than the current tier\n";
        return false;
    }
    return true;
}

bool tree::add_child(node* aNode)
{
    node *new_node = new node(*aNode);
    if (new_node == 0)
        return false;
    pcur->push_sub(new_node);
    new_node->lnk_sup(pcur);
    if (new_node->get_tier() == no_tier)
        new_node->set_tier(pcur->get_tier()+1);
    pcur = new_node;
    if (tiers < new_node->get_tier()+1)
        ++tiers;
    ++tsize;
    return true;
}

bool tree::add_nuncle(int levelup, node* aNode)
{
    node* tmptr = pcur;
    for (int i = 0; i < levelup; ++i)
    {
        if (!point_up())
        {
            cerr << "No more parents!\n";
            cerr << "Cannot add:\n" << *aNode << '\n';
            pcur = tmptr;
            return false;
        }
    }
    if (!add_child(aNode))
        return false;

    return true;
}

bool tree::add_uncle(node* aNode)
{
    if (!add_nuncle(2,aNode))
        return false;
    return true;
}

bool tree::add_sibling(node* aNode)
{
    if (!add_nuncle(1,aNode))
        return false;
    return true;
}

bool tree::add_top_child(node* aNode)
{
    pcur = top_node;
    if (!add_child(aNode))
        return false;
    return true;
}

bool tree::point_up()
{
    if (pcur->get_sup() == nullptr)
        return false;
    else
    {
        pcur = pcur->get_sup();
        return true;
    }
}

const char* tree::get_topnode_label() {
        stringstream ss;
        ss << top_node->get_nam();
        ss << "\\n";
        ss << top_node->get_num();
    return ss.str().c_str();
}

void tree::draw_graph(const char *graphtype, const char *connector)
{
    if (tsize > 1)
    {
        cout << "strict " << graphtype << " \"" << top_node->get_nam() << "\" {\n";
        cout << "\toverlap=\"false\";\n";
        draw_inner(top_node,connector);
        cout << "}\n";
    }
    else
        cerr << "Nothing to print: product is too small.\n";

}

void tree::draw_inner(node* topn, const char *connector)
{
        deque<node*> the_subs = topn->get_subs();
        for (node* tn : the_subs)
        {
            //string configed_node =
            cout << "\t\"" << topn->get_nam() << "\\n" << topn->get_num() << '"';
            cout << connector << '"' << tn->get_nam() << "\\n" << tn->get_num() << "\"\n";
            if (tn->num_subs()>0)
                draw_inner(tn,connector);
        }
}

void tree::draw_graphviz()
{
    Agraph_t *g;
    g = agopen(const_cast<char*>(get_top_nam().c_str()), Agundirected, NULL);
    agattr(g,AGRAPH,const_cast<char*>("overlap"),const_cast<char*>("false"));
    agattr(g,AGRAPH,const_cast<char*>("size"),const_cast<char*>("11,7.5"));
    agattr(g,AGNODE,const_cast<char*>("shape"),const_cast<char*>("box"));
    Agnode_t* gtopnode = agnode(g,const_cast<char*>(get_topnode_label()),TRUE);
    draw_graphviz(top_node,g,gtopnode);
    agwrite(g,stdout);
}

template <typename T1, typename T2>
void tree::draw_graphviz(node *topn, T1 *g, T2 *gtopnode)
{
        deque<node*> the_subs = topn->get_subs();
        for (node* tn : the_subs)
        {
            string node_label = tn->get_nam() + "\\n" + tn->get_num();
            stringstream ss;
            ss << "e" << topn->get_nid() << "to" << tn->get_nid();
            string edge_label = ss.str();
            Agnode_t* gsubnode = agnode(g,const_cast<char*>(node_label.c_str()),TRUE);
            if (NULL == agedge(g,gtopnode,gsubnode,NULL,FALSE))
                agedge(g,gtopnode,gsubnode,const_cast<char*>(edge_label.c_str()),TRUE);
            if (tn->num_subs()>0)
                draw_graphviz<Agraph_t,Agnode_t>(tn,g,gsubnode);
        }
}


ostream& operator<<(ostream& os,const tree &other)
{
    //os << "tree size: " << other.tsize << '\n'
    //   << "nu of tiers: " << other.tiers << '\n';

    if (other.tsize > 0)
    {
        os << *other.top_node;
    }

    return os;
}

void tree::os_subs()
{
    cout << *top_node;
    os_subs(top_node);
}

void tree::os_subs(node* topn)
{
    deque<node*> the_subs = topn->get_subs();
    for (node* tn : the_subs)
    {
        cout << *tn << '\n';
        if (tn->num_subs() > 0)
            os_subs(tn);
    }
}

