#reutgerber@gmail.com
#pragma once
#include "node.hpp"
#include <stack>
template<typename T>
class DfsOrderIterator {
public:
	using value_type = Node<T>;
	using pointer = Node<T>*;
	using reference = Node<T>&;

	DfsOrderIterator(Node<T>* root)
	{
		if (root)
		{
			traversal.push(root);
		}
		advance();
	}

	DfsOrderIterator operator++()
	{
		advance();
		return *this;

	}
	DfsOrderIterator operator++(int)
	{
		DfsOrderIterator tmp = *this;
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
	bool operator== (const DfsOrderIterator& other)
	{
		return (other.currentNode == this->currentNode && this->traversal == other.traversal);
	}
	bool operator != (const DfsOrderIterator& other)
	{
		return !(*this == other);

	}
protected:
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
