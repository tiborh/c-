#include <iostream>
#include "tests.h"
#include <cassert>

using namespace std;

void node_test()
{
    cout << "Node tests:\n";
    cout << "\tNode creation test: \t";
    node *test_node = new node("EA","AVA 901 36/1","R1A","15.0");
    //cout << *test_node << '\n';
    assert(test_node->get_tier()==no_tier);
    assert(test_node->get_nid() == 1);
    map<string,string> tnd1 = test_node->get_node_info();
    assert(tnd1["FuncDes"]=="EA");
    assert(tnd1["ProdNum"]=="AVA 901 36/1");
    assert(tnd1["RState"]=="R1A");
    assert(tnd1["VersDes"]=="15.0");
    assert(test_node->has_sup()==false);
    assert(test_node->num_subs()==0);
    cout << "Passed\n";

    cout << "\tNode creation from line test: \t";
    line *tl1 = new line("abc12345\tr1a\t一\t百千万");
    node *tn1 = new node(tl1);
    //cout << *test_node << '\n';
    assert(tn1->get_tier()==0);
    assert(tn1->get_nid() == 2);
    map<string,string> tnd2 = tn1->get_node_info();
    assert(tnd2["FuncDes"]=="一");
    assert(tnd2["ProdNum"]=="abc12345");
    assert(tnd2["RState"]=="r1a");
    assert(tnd2["VersDes"]=="百千万");
    assert(tn1->has_sup()==false);
    assert(tn1->num_subs()==0);
    cout << "Passed\n";

    cout << "\tTier set test: \t";
    //++(*test_node);
    //cout << *test_node << '\n';
    assert(test_node->get_tier()==0);
    cout << "Passed\n";

    cout << "\tNode linking test: \t";
    node *test_node2 = new node("EEA","AVA 901 36/2","R2A","15.1");
    //cout << *test_node2 << '\n';
    test_node2->lnk_sup(test_node);
    test_node->push_sub(test_node2);
    //test_node2->set_tier(test_node->get_tier()+1);
    assert(test_node->get_tier()== 0);
    assert(test_node2->get_tier() == 1);
    assert(test_node2->has_sup() == true);
    assert(test_node->num_subs() == 1);
    assert(test_node->has_sup() == false);
    assert(test_node2->num_subs() == 0);
    assert(test_node2->get_nid() == 3);
    cout << "Passed\n";

    cout << "\tNode increment/decrement test: \t";
    //++(*test_node2);
    assert(test_node2->get_tier() == 2);
    //cout << *test_node2 << '\n';
    //--(*test_node2);
    assert(test_node2->get_tier() == 1);
    //cout << *test_node2 << '\n';
    cout << "Passed\n";

    cout << "\tNode copy test: \t";
    node *test_node3 = new node(*test_node2);
    //cout << *test_node3 << '\n';
    assert(test_node3->get_tier()==no_tier);
    assert(test_node3->get_nid() == 4);
    map<string,string> tnd3 = test_node3->get_node_info();
    assert(tnd3["FuncDes"]=="EEA");
    assert(tnd3["ProdNum"]=="AVA 901 36/2");
    assert(tnd3["RState"]=="R2A");
    assert(tnd3["VersDes"]=="15.1");
    assert(test_node3->has_sup()==false);
    assert(test_node3->num_subs()==0);
    cout << "Passed\n";

    cout << "\tSecond connection test: \t";
    test_node3->lnk_sup(test_node);
    test_node->push_sub(test_node3);
    //test_node3->set_tier(test_node->get_tier()+1);
    //cout << *test_node << '\n';
    //cout << *test_node3 << '\n';
    assert(test_node->get_tier()== 0);
    assert(test_node3->get_tier() == 1);
    assert(test_node3->has_sup() == true);
    assert(test_node->num_subs() == 2);
    assert(test_node->has_sup() == false);
    assert(test_node3->num_subs() == 0);
    cout << "Passed\n";
}
