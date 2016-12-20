#include <iostream>
#include "tests.h"
#include <cassert>
#include "util.h"

using namespace std;

void tree_test()
{
    cout << "Tree tests:\n";

    cout << "\tEmpty tree test: \t";
    tree *first_tree = new tree();
    //cout << *first_tree;
    assert(first_tree->size() == 0);
    assert(first_tree->nu_of_tiers() == 0);
    cout << "Passed.\n";

    cout << "\tTop node constructor test:\t";
    tree *prod_tree = new tree("EA 15","AVA 901 36/1","R1A","15.0");
    assert(prod_tree!=0);
    //cout << *prod_tree;
    assert(prod_tree->size() == 1);
    assert(prod_tree->nu_of_tiers() == 1);
    assert(prod_tree->get_ctier() == 0);
    cout << "Passed.\n";

    cout << "\tTop node from node*:\t";
    node *tn = new node("EA","AVA 901 36/1","R1A","15.0");
    tree *tt = new tree(tn);
    assert(tt!=0);
    //cout << *prod_tree;
    assert(tt->size() == 1);
    assert(tt->nu_of_tiers() == 1);
    assert(tt->get_ctier() == 0);
    cout << "Passed.\n";

    cout << "\tInitialisation test for empty tree: \t";
    assert(first_tree->init("Function Designation","Number","Rstate","Version Designation")==true);
    assert(first_tree->size() == 1);
    assert(first_tree->nu_of_tiers() == 1);
    assert(prod_tree->get_ctier() == 0);
    //print_map<string,string>(first_tree->get_top_info());
    map<string,string> tni = first_tree->get_top_info();
    assert(tni["FuncDes"]=="Function Designation");
    assert(tni["ProdNum"]=="Number");
    assert(tni["RState"]=="Rstate");
    assert(tni["VersDes"]=="Version Designation");
    cout << "Passed.\n";

    cout << "Adding nodes:\n";
    cout << "\tadd_node() test: \t";
    node *test_node2 = new node("EA GUI","CRA 119 1787/3","R1A","");
    assert(prod_tree->add_child(test_node2)==true);
    //cout << first_tree->size() << '\n';
    //cout << first_tree->nu_of_tiers() << '\n';
    assert(prod_tree->size() == 2);
    assert(prod_tree->nu_of_tiers() == 2);
    assert(prod_tree->get_ctier() == 1);
    //cout << *first_tree;
    cout << "Passed.\n";

    cout << "\tadd_uncle test (1): \t";
    node *test_node3 = new node("EA Core and Probe","CRA 119 1788/3","R1A","");
    assert(test_node3!=0);
    assert(prod_tree->add_nuncle(1,test_node3)==true);
    assert(prod_tree->size() == 3);
    assert(prod_tree->nu_of_tiers() == 2);
    cout << "Passed.\n";

    cout << "\tadd_sibling test: \t";
    node *test_node4 = new node("Platform","CRA 119 1896/3","R1A","");
    assert(test_node4!=0);
    assert(prod_tree->add_sibling(test_node4)==true);
    assert(prod_tree->size() == 4);
    assert(prod_tree->nu_of_tiers() == 2);
    assert(prod_tree->get_ctier() == 1);
    cout << "Passed.\n";

    cout << "\tadd_uncle test (negative)\t";
    node *test_node5 = new node("Offline Data Analytics","CRA 119 1947/3","R1A","");
    assert(test_node5!=0);
    //assert(prod_tree->add_uncle(test_node5)==false);
    assert(prod_tree->get_ctier() == 1);
    //cout << "Passed.\n";

    cout << "\tAdding some more nodes for the tree to grow...\n";
    node *test_node6 = new node("Platform","CNA 403 2797/3","R1A","");
    assert(test_node6!=0);
    assert(prod_tree->add_child(test_node6)==true);
    assert(prod_tree->size() == 5);
    assert(prod_tree->nu_of_tiers() == 3);
    assert(prod_tree->get_ctier() == 2);

    node *test_node7 = new node("OS","CAA 901 3153/3","R1A","");
    assert(prod_tree->add_child(test_node7)==true);
    node *test_node8 = new node("Linux Extensions","CAA 901 3154/3","R1A","");
    assert(prod_tree->add_sibling(test_node8)==true);
    node *test_node9 = new node("OAM Software","CAA 901 3155/3","R1A","");
    assert(prod_tree->add_sibling(test_node9)==true);
    node *test_node10 = new node("Application Server","CAA 901 3157/3","R1A","");
    assert(prod_tree->add_sibling(test_node10)==true);
    assert(prod_tree->size() == 9);
    assert(prod_tree->nu_of_tiers() == 4);
    assert(prod_tree->get_ctier() == 3);

    assert(prod_tree->add_top_child(test_node5)==true);
    assert(prod_tree->size() == 10);
    assert(prod_tree->nu_of_tiers() == 4);
    assert(prod_tree->get_ctier() == 1);

    node *test_node11 = new node("Scheduler","CNA 403 2908/3","R1A","");
    assert(prod_tree->add_child(test_node11)==true);
    node *test_node12 = new node("Scheduler","CAA 901 3185/3","R1A","");
    assert(prod_tree->add_child(test_node12)==true);

    node *test_node13 = new node("Preprocessors","CNA 403 2909/3","R1A","");
    assert(prod_tree->add_uncle(test_node13)==true);
    node *test_node14 = new node("Preprocessors","CAA 901 3186/3","R1A","");
    assert(prod_tree->add_child(test_node14)==true);
    assert(prod_tree->size() == 14);
    assert(prod_tree->nu_of_tiers() == 4);
    assert(prod_tree->get_ctier() == 3);

    prod_tree->draw_graph();

}
