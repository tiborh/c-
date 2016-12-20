#ifndef TREE_H
#define TREE_H

#include "node.h"
#include "line.h"

class tree
{
    public:
        tree():top_node(nullptr),pcur(nullptr),tsize(0),tiers(0){}
        tree(std::string,std::string,std::string,std::string);
        tree(node*);
        ~tree();
        bool init(std::string,std::string,std::string,std::string);
        std::map<std::string,std::string> get_top_info()
        {
            return (*top_node).get_node_info();
        }
        std::map<std::string,std::string> get_cur_info()
        {
            return (*pcur).get_node_info();
        }
        int get_ctier() { return pcur->get_tier(); }
        bool add_node(node*);   // if new nodes are well-tiered, use this
        bool add_child(node*); // base case, adds where pcur points at, all others call this one
        //bool add_child(node* aNode,node* parent); // if supnode and subnodes are not empty, do nothing and return false
        bool add_sibling(node*); // leads back to add_child
        bool add_nuncle(int, node*); // ditto, levelup == 1 is same as add_sibling
        bool add_uncle(node*); //add a node to two levels up
        bool add_top_child(node*); // adds a new child to topnode
        unsigned int size() const { return tsize; }
        int nu_of_tiers() const { return tiers; }
        bool point_up();
        //void draw_neato(const char *graphtype = "graph G ",const char *connector = " -- ");
        void draw_graph(const char *graphtype = "digraph ",const char *connector = " -> ");
        friend std::ostream& operator<<(std::ostream&,const tree&);
        void os_subs();
        void os_subs(node*);
        std::string get_top_nam() { return top_node->get_nam(); }
        std::string get_top_num() { return top_node->get_num(); }
        std::string get_cur_nam() { return pcur->get_nam(); }
        std::string get_cur_num() { return pcur->get_num(); }
        const char* get_topnode_label();
        const char* get_curnode_label();
        void draw_graphviz();
        template <typename T1, typename T2>
        void draw_graphviz(node*,T1*,T2*);
    protected:
        node *top_node;
        node *pcur;
        void draw_inner(node*,const char *);
    private:
        unsigned int tsize;
        int tiers;
        static std::string colour_seq[];
};

#endif // TREE_H
