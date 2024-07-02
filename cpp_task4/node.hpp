#pragma once
#include <iostream>
#include <vector>

using namespace std;
template<typename T>

class Node {
public:
	T data;
	vector<Node<T>*> children;





	Node(T data) {
		this->data = data;
	}

	T get_value()
	{
		return data;
	}

	void add_child(Node<T>* child, int max_children)
	{
		if (children.size() <= max_children)
			children.push_back(child);
		else
			cout<<"exceeded max_cildren"<<endl;


	}

	friend ostream& operator<<(ostream& out, const Node& node) {
		out << node.data << " num of children=" << node.children.size() << " ";
		for (auto it = node.children.begin(); it != node.children.end(); it++)
			out << (*it)->data << " ";
		return out;
	}
};
