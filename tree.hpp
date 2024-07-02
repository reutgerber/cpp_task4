#reutgerber@gmail.com
#include "PreOrderiterator.hpp"
#include "PostOrderIterator.hpp"
#include "in_order_iterator.hpp"
#include "bfs_iterator.hpp"
#include "node.hpp"
#include "heap_iterator.hpp"
#include "dfsiterator.hpp"


template<typename T,int k=2>
class Tree {
	Node<T>* root;
	
public:
	void add_root(Node<T>* root)
	{
		this->root = root;
	}
	Tree()
	{
		root = nullptr;
	
	}

	~Tree()
	{
		if (!deleted)
			DeleteAll();
	}

	void DeleteAll()
	{
		
		deleteTree(root);
		deleted = true;
	}

	void myHeap()
	{
		for (auto node : *this)
		{
			add_to_heap(node.get_value(), min_heap);
		}

	}

	DfsOrderIterator<T> begin_dfs_order()
	{
		return DfsOrderIterator<T>(root);
	}
	DfsOrderIterator<T> end_dfs_order()
	{
		return DfsOrderIterator<T>(nullptr);
	}

	PreOrderIterator<T> begin_pre_order()
	{
		return PreOrderIterator<T>(root);
	}
	PreOrderIterator<T> end_pre_order()
	{
		return PreOrderIterator<T>(nullptr);
	}
	PostOrderIterator<T, k> begin_post_order()
	{
		
		return PostOrderIterator<T, k>(root);
	}
	PostOrderIterator<T, k> end_post_order()
	{
		return PostOrderIterator<T, k>(nullptr);
	}
	InOrderIterator<T, k> begin_in_order()
	{

		return InOrderIterator<T, k>(root);
	}
	InOrderIterator<T, k> end_in_order()
	{
		return InOrderIterator<T, k>(nullptr);
	}

	BfsOrderIterator<T, k> begin_bfs_scan()
	{

		return BfsOrderIterator<T, k>(root);
	}
	BfsOrderIterator<T, k> end_bfs_scan()
	{
		return BfsOrderIterator<T, k>(nullptr);
	}


	BfsOrderIterator<T, k> begin()
	{

		return BfsOrderIterator<T, k>(root);
	}
	BfsOrderIterator<T, k> end()
	{
		return BfsOrderIterator<T, k>(nullptr);
	}

	HeapIterator<T> begin_heap()
	{
		return HeapIterator<T>(0,min_heap);
	}

	HeapIterator<T> end_heap()
	{
		
		return HeapIterator<T>(min_heap.size(), min_heap);
	}


	


	void add_sub_node(Node<T>* parent, Node<T>* child)
	{
		parent->add_child(child, k);

	}

private:
	bool deleted = false;
	vector<T> min_heap;

	bool check(int parentIndex, int newIndex, vector<T>& v)
	{
		if (parentIndex < 0)
			return false;
		if (v[parentIndex] > v[newIndex])
		{
			swap(v[parentIndex], v[newIndex]);
			check(parentIndex - 1, parentIndex, v);
			return true;
		}
		return false;

	}


	void add_to_heap(T val, vector<T>& v)
	{
		v.push_back(val);
		bool ret = check(v.size() - 2, v.size() - 1, v);

	}
	void deleteTree(Node<T>* node) {
		if (node) {
			for (auto child : node->children) {
				deleteTree(child);
			}
			delete node;
		}
	}



};
