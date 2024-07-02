#ifndef TREE_HPP
#define TREE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include "node.hpp"
#include "PreOrderiterator.hpp"
#include "PostOrderIterator.hpp"
#include "in_order_iterator.hpp"
#include "bfs_iterator.hpp"
#include "heap_iterator.hpp"
#include "dfsiterator.hpp"

template <typename T, int k = 2>
class Tree
{
	Node<T> *root;

public:
	// Assuming Node and other necessary declarations are already in tree.hpp

	// Function to draw a single node
	// Function to draw a single node, modified to draw nodes vertically
	// Function to draw a single node, modified to draw nodes in a tree structure both vertically and horizontally
	void drawNode(sf::RenderWindow &window, Node<T> *node, float x, float y, float parentX, float parentY, int level, float horizontalSpacing, float verticalSpacing)
	{
		if (!node)
			return;

		// Draw the node (circle)
		sf::CircleShape shape(20); // Radius of 20 units
		shape.setFillColor(sf::Color::Green);
		shape.setPosition(x - shape.getRadius(), y - shape.getRadius());
		window.draw(shape);

		// Draw the line from parent to this node
		if (level != 0)
		{
			sf::Vertex line[] = {
				sf::Vertex(sf::Vector2f(parentX, parentY + 20)),
				sf::Vertex(sf::Vector2f(x, y))};
			window.draw(line, 2, sf::Lines);
		}

		// Convert node value to string and create text object
		sf::Text text;
		sf::Font font;
		font.loadFromFile("arial.ttf");				// Load the font
		text.setFont(font);							// Set the font
		text.setString(std::to_string(node->data)); // Assuming the value can be converted to string
		text.setCharacterSize(15);					// Set the character size
		text.setFillColor(sf::Color::White);		// Set the text color
		text.setPosition(x - 10, y - 10);			// Position the text near the node

		window.draw(text); // Draw the text

		// Calculate positions and draw children
		float childX = x - (node->children.size() - 1) * horizontalSpacing / 2.0f;
		for (auto child : node->children)
		{
			drawNode(window, child, childX, y + verticalSpacing, x, y, level + 1, horizontalSpacing / 2, verticalSpacing);
			childX += horizontalSpacing;
		}
	}
	// Function to setup the SFML window and draw the tree, modified to match the new drawNode signature
	void drawTree(Node<T> *root)
	{
		sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization");

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			float startY = 50; // Start drawing from the top of the window
			drawNode(window, root, 400, startY, 0, 0, 0, 200, 100);
			window.display();
		}
	}

	void add_root(Node<T> *root)
	{
		this->root = root;
	}

	Tree() : root(nullptr), deleted(false) {}

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
		return HeapIterator<T>(0, min_heap);
	}

	HeapIterator<T> end_heap()
	{
		return HeapIterator<T>(min_heap.size(), min_heap);
	}

	void add_sub_node(Node<T> *parent, Node<T> *child)
	{
		parent->add_child(child, k);
	}

private:
	bool deleted;
	std::vector<T> min_heap;

	bool check(int parentIndex, int newIndex, std::vector<T> &v)
	{
		if (parentIndex < 0)
			return false;
		if (v[parentIndex] > v[newIndex])
		{
			std::swap(v[parentIndex], v[newIndex]);
			check(parentIndex - 1, parentIndex, v);
			return true;
		}
		return false;
	}

	void add_to_heap(T val, std::vector<T> &v)
	{
		v.push_back(val);
		bool ret = check(v.size() - 2, v.size() - 1, v);
	}

	void deleteTree(Node<T> *node)
	{
		if (node)
		{
			for (auto child : node->children)
			{
				deleteTree(child);
			}
			delete node;
		}
	}
};

#endif // TREE_HPP
