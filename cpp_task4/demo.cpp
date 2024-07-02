#include "node.hpp"
#include <stack>
#include <complex>

#include <iostream>
#include <string>
#include "node.hpp"
#include "tree.hpp"

using namespace std;

int main()
{

    Node<double> *root_node = new Node<double>(1.1);
    Tree<double, 2> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<double> *n1 = new Node<double>(1.2);
    Node<double> *n2 = new Node<double>(1.3);
    Node<double> *n3 = new Node<double>(1.4);
    Node<double> *n4 = new Node<double>(1.5);
    Node<double> *n5 = new Node<double>(1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
    tree.drawTree(root_node);
    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */

    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it)
    {
        cout << *it << endl;
        cout << endl;
    }
    // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1

    cout << endl;
    cout << "in order iterator" << endl;
    cout << endl;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3

    cout << endl;
    cout << "BFS iterator" << endl;
    cout << endl;

    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    cout << endl;
    cout << "use auto loop for BFS iterator" << endl;
    cout << endl;

    for (auto node : tree)
    {
        cout << node.get_value() << endl;
    } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    tree.myHeap();

    cout << endl;
    cout << "print heap iterator" << endl;
    cout << endl;

    for (auto it = tree.begin_heap(); it != tree.end_heap(); ++it)
    {
        cout << *it << endl;
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    // cout << tree; // Should print the graph using GUI.

    tree.DeleteAll();

    root_node = new Node<double>(1.1);
    n1 = new Node<double>(1.2);
    n2 = new Node<double>(1.3);
    n3 = new Node<double>(1.4);
    n4 = new Node<double>(1.5);
    n5 = new Node<double>(1.6);

    Tree<double, 3> three_ary_tree; // 3-ary tree.
    three_ary_tree.add_root(root_node);
    three_ary_tree.add_sub_node(root_node, n1);
    three_ary_tree.add_sub_node(root_node, n2);
    three_ary_tree.add_sub_node(root_node, n3);
    three_ary_tree.add_sub_node(n1, n4);
    three_ary_tree.add_sub_node(n2, n5);

    // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */

    cout << endl;
    cout << "three_ary_tree PreOrderIterator" << endl;
    cout << endl;

    for (auto it = three_ary_tree.begin_pre_order(); it != three_ary_tree.end_pre_order(); ++it)
    {
        cout << *it << endl;
        cout << endl;
    }

    complex<double> croot(1.1, 1.1);
    complex<double> c1(1.2, 1.2);
    complex<double> c2(1.3, 1.3);
    complex<double> c3(1.4, 1.4);
    complex<double> c4(1.5, 1.5);
    complex<double> c5(1.6, 1.6);

    Node<complex<double>> *c_root_node = new Node<complex<double>>(croot);
    Node<complex<double>> *c1_node = new Node<complex<double>>(c1);
    Node<complex<double>> *c2_node = new Node<complex<double>>(c2);
    Node<complex<double>> *c3_node = new Node<complex<double>>(c3);
    Node<complex<double>> *c4_node = new Node<complex<double>>(c4);
    Node<complex<double>> *c5_node = new Node<complex<double>>(c5);

    cout << endl;
    cout << "complex_tree PreOrderIterator" << endl;
    cout << endl;

    Tree<complex<double>, 2> complex_tree;
    complex_tree.add_root(c_root_node);
    complex_tree.add_sub_node(c_root_node, c1_node);
    complex_tree.add_sub_node(c_root_node, c2_node);
    complex_tree.add_sub_node(c1_node, c3_node);
    complex_tree.add_sub_node(c1_node, c4_node);
    complex_tree.add_sub_node(c2_node, c5_node);

    for (auto it = complex_tree.begin_pre_order(); it != complex_tree.end_pre_order(); ++it)
    {
        cout << *it << endl;
        cout << endl;
    }
    return 0;
}