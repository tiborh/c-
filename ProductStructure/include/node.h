#ifndef NODE_H
#define NODE_H

#include <deque>
#include <map>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>
#include "line.h"

const int no_tier = -1;
const int nosup_nid = -100;
const int nu_of_node_dat = 4;

class node
{
public:
    //constructor/destructor
    node(std::string prodnam,
         std::string prodnum,
         std::string prodrev,
         std::string proddes):
        nid(next_id++),
        tier(no_tier),
        nam(prodnam),
        num(prodnum),
        rev(prodrev),
        des(proddes),
        sup(nullptr),
        subs(0)
    {
    }
    node(line*);
    node(const node &other);
    std::map<std::string,std::string> get_node_info();
    //tier
    int set_tier(int plevel)
    {
        tier = plevel;
        return tier;
    }
    int get_tier() { return tier; }
    //node id
    int get_nid() { return nid; }
    std::string get_nam() { return nam; }
    std::string get_num() { return num; }

    //subs
    bool push_sub(node* a_sub);
    node* pop_sub();
    int clr_subs();
    unsigned int num_subs() const;
    std::string list_subs() const;
    std::vector<std::map<std::string,std::string>> get_subs_data();
    std::deque<node*> get_subs();

    //sup
    bool lnk_sup(node* a_sup);
    node* rem_sup();
    bool has_sup();
    node* get_sup() { return sup; }

    //operators
    node& operator=(const node &other) //copies the node
    {
        nid = next_id++;
        tier = other.tier;
        nam = other.nam;
        num = other.num;
        rev = other.rev;
        des = other.des;
        sup = nullptr;
        subs = {};

        return *this;
    }
    /*
    node& operator++()
    {
        ++tier;
        return *this;
    }
    node& operator--()
    {
        if (tier > 0)
            --tier;
        return *this;
    }
    */
    friend std::ostream& operator<<(std::ostream& os,const node &other);

protected:
    int nid;
    int tier; //-1 means: not in tree
    std::string nam;
    std::string num;
    std::string rev;
    std::string des;
    node* sup;
    std::deque<node*> subs;
private:
    static unsigned int next_id;
};


#endif // NODE_H
