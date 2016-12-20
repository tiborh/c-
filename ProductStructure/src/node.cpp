#include "node.h"

using namespace std;

unsigned int node::next_id = 1;

node::node(const node &other)
{
    nid = next_id++;
    tier = other.tier;
    nam = other.nam;
    num = other.num;
    rev = other.rev;
    des = other.des;
    sup = nullptr;
    subs = {};
}

node::node(line* aLine)
{
    nid = next_id++;
    tier = aLine->get_tier();
    nam = aLine->get_nam();
    num = aLine->get_num();
    rev = aLine->get_rev();
    des = aLine->get_des();
    sup = nullptr;
    subs = {};
}

map<string,string> node::get_node_info()
{
    map<string,string> nodeData;
    nodeData["FuncDes"] = nam;
    nodeData["ProdNum"] = num;
    nodeData["RState"] = rev;
    nodeData["VersDes"] = des;

    return nodeData;
}

bool node::push_sub(node* a_sub)
{
    unsigned int siz = subs.size();
    subs.push_back(a_sub);
    return (subs.size() > siz) ? true : false;
}

node* node::pop_sub()
{
    if (subs.size() == 0)
        return NULL;
    node* front_node = subs.front();
    subs.pop_front();
    return front_node;
}

unsigned int node::num_subs() const
{
    return subs.size();
}

std::string node::list_subs() const
{
    if (subs.size() == 0)
        return std::string("");
    std::stringstream collector;
    std::deque<node*>::const_iterator subsi;
    for (subsi = subs.begin(); subsi != subs.end(); ++subsi)
        collector << ((*subsi)->get_nid() << ((subsi == subs.end()-1) ? '\0' : ' '));
    return collector.str();
}

bool node::lnk_sup(node* a_sup)
{
    if (a_sup == sup)
        return false;
    node* testlink = sup;
    sup = a_sup;
    return (testlink == sup) ? false : true;
}

node* node::rem_sup()
{
    node* the_sup = sup;
    sup = NULL;
    return the_sup;
}

bool node::has_sup()
{
    return (sup == NULL) ? false : true;
}

vector<map<string,string>> node::get_subs_data()
{
    vector<map<string,string>> subs_dat_out;
    for (node* ni: subs)
        subs_dat_out.push_back(ni->get_node_info());

    return subs_dat_out;
}

std::deque<node*> node::get_subs()
{
    std::deque<node*> copy_of_subs = subs;
    return copy_of_subs;
}

std::ostream& operator<<(std::ostream& os, const node &other)
{
    return os << "Tier: " << other.tier << ",\n"
           << "\tNID:\t" << other.nid << ",\n"
           << "\tName:\t" << other.nam << ",\n"
           << "\tNumber:\t" << other.num << ",\n"
           << "\tRState:\t" << other.rev << ",\n"
           //need to handle top nodes, where no supnode!
           << "\tVDes:\t" << other.des << ",\n"
           << "\tsup:\t" << ((other.sup == nullptr) ? nosup_nid : (*other.sup).get_nid()) << ",\n"
           << "\tsubs:\t" << other.list_subs() << " (" << other.num_subs() << ")\n";
}
