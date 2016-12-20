#include <iostream>
#include "tree.h"
#include "node.h"
#include "tests.h"
#include "util.h"
#include "line.h"
#include "line_collector.h"
#include <cassert>
#include <deque>

using namespace std;

int main(int argc, char **argv)
{
#ifndef NDEBUG
    //node_test();
    //tree_test();
    //line_test();
#endif

    deque<line*> lc = linecollector();
    line *topnodeline = lc.front();
    lc.pop_front();
    node *topnode = new node(topnodeline);
    tree *tt = new tree(topnode);
    //int my_tier = 0;

    /*
    for (deque<line*>::iterator ilc = lc.begin(); ilc != lc.end(); ++ilc)
    {
        line* aLine = *ilc;
        node* aNode = new node(aLine);
        if (aLine->get_tier() == tt->get_ctier())
        {
            tt->add_sibling(aNode);
        } else if (aLine->get_tier() == tt->get_ctier() + 1)
        {
            tt->add_child(aNode);
            //++my_tier;
        } else if (aLine->get_tier() < tt->get_ctier())
        {
            tt->add_nuncle(tt->get_ctier() - aLine->get_tier() - 2,aNode);
            //my_tier = aLine->get_tier();
        } else if (aLine->get_tier() == 1)
        {
            tt->add_top_child(aNode);
            //my_tier = 1;
        } else
        {
            //cerr << "Do not know what to do with this node (my_tier:" << my_tier << "):\n" << *aNode << '\n';
            cerr << "Do not know what to do with this node:\n" << *aNode << '\n';
            break;
        }
        if (tt->get_ctier() != aLine->get_tier())
        {
            cerr << "Tier discrepancy!\n";
            cerr << "Line: (" << aLine->get_tier() << ")\n";
            cerr << *aLine << "\n\n";
            cerr << "in tree: (" << tt->get_ctier() << ")\n";
            cerr << *tt << '\n';
        }
    }
    */

    for (deque<line*>::iterator ilc = lc.begin(); ilc != lc.end(); ++ilc)
    {
        line* aLine = *ilc;
        node* aNode = new node(aLine);
        tt->add_node(aNode);
    }
    //tt->draw_neato();
    //tt->draw_graph("graph"," -- ");
    //tt->os_subs();
    tt->draw_graphviz();
    //draw_graphviz(tt);

    return 0;
}
