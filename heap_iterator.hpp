#reutgerber@gmail.com
#pragma once
#include "node.hpp"
#include <vector>
#include <stack>
template<typename T>
class HeapIterator{
public:
	using pointer = T*;
	using reference = T&;

	HeapIterator(int index,vector<T>& min_heap)
	{
		this->min_heap = min_heap;
		
			if (index< min_heap.size())
			{
				auto root = make_pair(min_heap[index], index);
				traversal.push(root);
			}
		advance();
	}

	HeapIterator operator++()
	{
	
		advance();

		return *this;

	}
	HeapIterator operator++(int)
	{
		HeapIterator tmp = *this;
		advance();
		return tmp;
	}
	reference operator*()
	{
		return currentNode.first;

	}
	pointer operator->()
	{
		return &currentNode.first;
	}
	bool operator== (const HeapIterator& other)
	{
		return (other.currentNode == this->currentNode && this->traversal == other.traversal);
	}
	bool operator != (const HeapIterator& other)
	{
		return !(*this == other);

	}
protected:
	vector<T> min_heap;
	//int currentIndex;
	stack<pair<T,int>> traversal;
	pair<T, int> currentNode;


	void advance()
	{
		if (traversal.empty())
		{
			currentNode = make_pair(0,-1);
		}
		else
		{
			currentNode = traversal.top();
			traversal.pop();

			int rightIndex = 2 * currentNode.second + 2;
			int leftIndex = 2 * currentNode.second + 1;
			if (rightIndex< min_heap.size())
				traversal.push(make_pair(min_heap[rightIndex], rightIndex));
			if (leftIndex< min_heap.size())
				traversal.push(make_pair(min_heap[leftIndex], leftIndex));


		}
	}


	



};

