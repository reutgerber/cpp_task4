#pragma once

#include "node.hpp"
#include <stack>
#include "queue"
#include "dfsiterator.hpp"

template<typename T, int k = 2>
class BfsOrderIterator : public DfsOrderIterator<T> {
public:
    using value_type = Node<T>;
    using pointer = Node<T>*;
    using reference = Node<T>&;

    BfsOrderIterator<T, k>(Node<T>* root) :DfsOrderIterator<T>(root) {
        if (k > 2)
            return;
        this->currentNode = nullptr;
            if (root) queue.push(root);
            advance();
        
    }






    BfsOrderIterator operator++() {
        advance();
        return *this;
    }

    BfsOrderIterator operator++(int) {
        BfsOrderIterator tmp = *this;
        advance();
        return tmp;
    }

    reference operator*() {
        return *DfsOrderIterator<T>::currentNode;
    }

    pointer operator->() {
        return DfsOrderIterator<T>::currentNode;
    }

    bool operator==(const BfsOrderIterator& other) {
        if (k > 2)
            return  DfsOrderIterator<T>::operator==(other);
        return (other.currentNode == this->currentNode && this->queue == other.queue);
    }

    bool operator!=(const BfsOrderIterator<T, k>& other) {
        return !(*this == other);
    }

private:
    std::queue<Node<T>*> queue;

  


    void advance() {
        if (k > 2)
        {
            DfsOrderIterator<T>::advance();
            return;
        }
        if (!queue.empty()) {
            this->currentNode = queue.front();
            queue.pop();
            for (auto child : this->currentNode->children) {
                queue.push(child);
            }
        }
        else {
            this->currentNode = nullptr;
        }
    }





};



