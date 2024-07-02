// provides main(); this line is required in only one .cpp file
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include <stack>
#include <complex>

#include <iostream>
#include <string>
#include "node.hpp"
#include "tree.hpp"
#include <string>



TEST_CASE("test binary tree  preorder iterator") {
    cout << "test binary tree  preorder iterator" << endl;
    Tree<double, 2> tree; // Binary tree that contains doubles.
    Node<double>* root_node = new Node<double>(1.1);
    tree.add_root(root_node);
    Node<double>* n1 = new Node<double>(1.2);
    Node<double>* n2 = new Node<double>(1.3);
    Node<double>* n3 = new Node<double>(1.4);
    Node<double>* n4 = new Node<double>(1.5);
    Node<double>* n5 = new Node<double>(1.6);


    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    vector<double> expected = { 1.1, 1.2, 1.4, 1.5, 1.3, 1.6 };
    vector<double> actual;

    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it)
    {
         actual.push_back(it->get_value());
    }

    CHECK(expected == actual); 
   
}

TEST_CASE("test binary tree  postorder iterator") {
    cout << "test binary tree  postorder iterator" << endl;
    Tree<double, 2> tree; // Binary tree that contains doubles.
    Node<double>* root_node = new Node<double>(1.1);
    tree.add_root(root_node);
    Node<double>* n1 = new Node<double>(1.2);
    Node<double>* n2 = new Node<double>(1.3);
    Node<double>* n3 = new Node<double>(1.4);
    Node<double>* n4 = new Node<double>(1.5);
    Node<double>* n5 = new Node<double>(1.6);


    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    vector<double> expected = { 1.4, 1.5, 1.2, 1.6, 1.3, 1.1 };
    vector<double> actual;

    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it)
    {
        actual.push_back(it->get_value());
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1

    CHECK(expected == actual);

}

TEST_CASE("test binary tree  inorder iterator") {
    cout << "test binary tree  inorder iterator" << endl;
    Tree<double, 2> tree; // Binary tree that contains doubles.
    Node<double>* root_node = new Node<double>(1.1);
    tree.add_root(root_node);
    Node<double>* n1 = new Node<double>(1.2);
    Node<double>* n2 = new Node<double>(1.3);
    Node<double>* n3 = new Node<double>(1.4);
    Node<double>* n4 = new Node<double>(1.5);
    Node<double>* n5 = new Node<double>(1.6);


    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    vector<double> expected = { 1.4, 1.2, 1.5, 1.1, 1.6, 1.3 };
    vector<double> actual;

    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it)
    {
        actual.push_back(it->get_value());
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3

    CHECK(expected == actual); 

}

TEST_CASE("test binary tree  bfs iterator") {
    cout << "test binary tree  bfs iterator" << endl;
    Tree<double, 2> tree; // Binary tree that contains doubles.
    Node<double>* root_node = new Node<double>(1.1);
    tree.add_root(root_node);
    Node<double>* n1 = new Node<double>(1.2);
    Node<double>* n2 = new Node<double>(1.3);
    Node<double>* n3 = new Node<double>(1.4);
    Node<double>* n4 = new Node<double>(1.5);
    Node<double>* n5 = new Node<double>(1.6);


    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    vector<double> expected = { 1.1, 1.2, 1.3, 1.4, 1.5, 1.6 };
    vector<double> actual;

    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it)
    {
        actual.push_back(it->get_value());
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    CHECK(expected == actual);

}

TEST_CASE("test binary tree auto loop bfs iterator") {
    cout << "test binary tree auto loop bfs iterator" << endl;
    Tree<double, 2> tree; // Binary tree that contains doubles.
    Node<double>* root_node = new Node<double>(1.1);
    tree.add_root(root_node);
    Node<double>* n1 = new Node<double>(1.2);
    Node<double>* n2 = new Node<double>(1.3);
    Node<double>* n3 = new Node<double>(1.4);
    Node<double>* n4 = new Node<double>(1.5);
    Node<double>* n5 = new Node<double>(1.6);


    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    vector<double> expected = { 1.1, 1.2, 1.3, 1.4, 1.5, 1.6 };
    vector<double> actual;

    for (auto node : tree)
    {
         actual.push_back(node.get_value());
      
    } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    CHECK(expected == actual);

}


TEST_CASE("test minimum binary heap  iterator") {
    cout << "test minimum binary heap  iterator" << endl;
    Tree<double, 2> tree; // Binary tree that contains doubles.
    Node<double>* root_node = new Node<double>(1.1);
    tree.add_root(root_node);
    Node<double>* n1 = new Node<double>(1.2);
    Node<double>* n2 = new Node<double>(1.3);
    Node<double>* n3 = new Node<double>(1.4);
    Node<double>* n4 = new Node<double>(1.5);
    Node<double>* n5 = new Node<double>(1.6);


    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    vector<double> expected = { 1.1, 1.2, 1.4,1.5, 1.3, 1.6 };
    vector<double> actual;

    tree.myHeap();


    for (auto it = tree.begin_heap(); it != tree.end_heap(); ++it)
    {
        actual.push_back(*it);
    } // prints: 1.1, 1.2, 1.4,1.5, 1.3, 1.6

    CHECK(expected == actual);

    

}

TEST_CASE("test three_ary_tree preorder  iterator") {
    cout << "test three_ary_tree preorder iterator" << endl;
    Node<double>* root_node = new Node<double>(1.1);
    Node<double>* n1 = new Node<double>(1.2);
    Node<double>* n2 = new Node<double>(1.3);
    Node<double>* n3 = new Node<double>(1.4);
    Node<double>* n4 = new Node<double>(1.5);
    Node<double>* n5 = new Node<double>(1.6);

    Tree<double, 3> three_ary_tree; // 3-ary tree.
    three_ary_tree.add_root(root_node);
    three_ary_tree.add_sub_node(root_node, n1);
    three_ary_tree.add_sub_node(root_node, n2);
    three_ary_tree.add_sub_node(root_node, n3);
    three_ary_tree.add_sub_node(n1, n4);
    three_ary_tree.add_sub_node(n2, n5);

    vector<double> expected = { 1.1, 1.2, 1.5,1.3, 1.6, 1.4 };
    vector<double> actual;

    for (auto it = three_ary_tree.begin_pre_order(); it != three_ary_tree.end_pre_order(); ++it)
    {
        actual.push_back(it->get_value());
    }
    CHECK(expected == actual);
}

TEST_CASE("test three_ary_tree dfsiterator  iterator") {
    cout << "test three_ary_tree dfsiterator iterator" << endl;
    Node<double>* root_node = new Node<double>(1.1);
    Node<double>* n1 = new Node<double>(1.2);
    Node<double>* n2 = new Node<double>(1.3);
    Node<double>* n3 = new Node<double>(1.4);
    Node<double>* n4 = new Node<double>(1.5);
    Node<double>* n5 = new Node<double>(1.6);

    Tree<double, 3> three_ary_tree; // 3-ary tree.
    three_ary_tree.add_root(root_node);
    three_ary_tree.add_sub_node(root_node, n1);
    three_ary_tree.add_sub_node(root_node, n2);
    three_ary_tree.add_sub_node(root_node, n3);
    three_ary_tree.add_sub_node(n1, n4);
    three_ary_tree.add_sub_node(n2, n5);

    vector<double> expected = { 1.1, 1.2, 1.5,1.3, 1.6, 1.4 };
    vector<double> actual;

    for (auto it = three_ary_tree.begin_dfs_order(); it != three_ary_tree.end_dfs_order(); ++it)
    {
        actual.push_back(it->get_value());
    }
    CHECK(expected == actual);
}



TEST_CASE("test complex preorder  iterator") {
    cout << "test complex preorder iterator" << endl;
    complex<double> croot(1.1, 1.1);
    complex<double> c1(1.2, 1.2);
    complex<double> c2(1.3, 1.3);
    complex<double> c3(1.4, 1.4);
    complex<double> c4(1.5, 1.5);
    complex<double> c5(1.6, 1.6);


    Node<complex<double>>* c_root_node = new Node<complex<double>>(croot);
    Node<complex<double>>* c1_node = new Node<complex<double>>(c1);
    Node<complex<double>>* c2_node = new Node<complex<double>>(c2);
    Node<complex<double>>* c3_node = new Node<complex<double>>(c3);
    Node<complex<double>>* c4_node = new Node<complex<double>>(c4);
    Node<complex<double>>* c5_node = new Node<complex<double>>(c5);



    Tree<complex<double>, 2> complex_tree;
    complex_tree.add_root(c_root_node);
    complex_tree.add_sub_node(c_root_node, c1_node);
    complex_tree.add_sub_node(c_root_node, c2_node);
    complex_tree.add_sub_node(c1_node, c3_node);
    complex_tree.add_sub_node(c1_node, c4_node);
    complex_tree.add_sub_node(c2_node, c5_node);

    vector<complex<double>> expected = { croot, c1, c3,c4, c2, c5 };
    vector<complex<double>> actual;

    for (auto it = complex_tree.begin_pre_order(); it != complex_tree.end_pre_order(); ++it)
    {
        actual.push_back(it->get_value());
    }
    CHECK(expected == actual);


}


TEST_CASE("test string binary tree  preorder iterator") {
    cout << "test string binary tree  preorder iterator" << endl;
    Tree<string, 2> tree; // Binary tree that contains doubles.
    Node<string>* root_node = new Node<string>("all");
    tree.add_root(root_node);
    Node<string>* n1 = new Node<string>("you");
    Node<string>* n2 = new Node<string>("need");
    Node<string>* n3 = new Node<string>("is");
    Node<string>* n4 = new Node<string>("love");
    Node<string>* n5 = new Node<string>("hello");


    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    vector<string> expected = { "all", "you", "is", "love", "need","hello" };
    vector<string> actual;

    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it)
    {
        actual.push_back(it->get_value());
    }

    CHECK(expected == actual);

}
