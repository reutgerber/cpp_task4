#reutgerber@gmail.com
#pragma once
#include "node.hpp"
#include <stack>

using namespace std;

template<typename T>
class PreOrderIterator {
public:
	using value_type = Node<T>;
	using pointer = Node<T>*;
	using reference = Node<T>&;

	PreOrderIterator(Node<T>* root)
	{
		if (root)
		{
			traversal.push(root);
		}
		advance();
	}

	PreOrderIterator operator++()
	{
		advance();
		return *this;

	}
	PreOrderIterator operator++(int)
	{
		PreOrderIterator tmp = *this;
		advance();
		return tmp;
	}
	reference operator*()
	{
		return *currentNode;

	}
	pointer operator->()
	{
		return currentNode;
	}
	bool operator== (const PreOrderIterator& other)
	{
		return (other.currentNode == this->currentNode && this->traversal == other.traversal);
	}
	bool operator != (const PreOrderIterator& other)
	{
		return !(*this == other);

	}
private:
	stack< Node<T>*>  traversal;
	Node<T>* currentNode;
	void advance()
	{
		if (traversal.empty())
		{
			currentNode = nullptr;
		}
		else
		{
			currentNode = traversal.top();
			traversal.pop();


			auto start = currentNode->children.rbegin();
			auto end = currentNode->children.rend();
			for (auto it = start; it != end; it++)
				traversal.push(*it);

		}
	}



};
