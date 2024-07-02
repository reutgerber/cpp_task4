#reutgerber@gmail.com
#pragma once
#pragma once
#include "node.hpp"
#include <stack>
#include "dfsiterator.hpp"

template<typename T, int k = 2>
class InOrderIterator : public DfsOrderIterator<T> {
public:
    using value_type = Node<T>;
    using pointer = Node<T>*;
    using reference = Node<T>&;

    InOrderIterator<T,k>(Node<T>* root) :DfsOrderIterator<T>(root) {
        if (k > 2)
            return;
        this->currentNode = root;
        while (this->currentNode) {
            visitStack.push(this->currentNode);
            this->currentNode = this->currentNode->children.empty() ? nullptr : this->currentNode->children[0];
        }
        if (!visitStack.empty()) {
            this->currentNode = visitStack.top();
            visitStack.pop();
        }
    }



 


    InOrderIterator operator++() {
        advance();
        return *this;
    }

    InOrderIterator operator++(int) {
        InOrderIterator tmp = *this;
        advance();
        return tmp;
    }

    reference operator*() {
        return *DfsOrderIterator<T>::currentNode;
    }

    pointer operator->() {
        return DfsOrderIterator<T>::currentNode;
    }

    bool operator==(const InOrderIterator& other) {
        if (k > 2)
            return  DfsOrderIterator<T>::operator==(other);
        return (other.currentNode == this->currentNode && this->visitStack == other.visitStack);
    }

    bool operator!=(const InOrderIterator<T, k>& other) {
        return !(*this == other);
    }

private:
    stack<Node<T>*>  visitStack;
 

    void advance() {
        if (k > 2)
        {
            DfsOrderIterator<T>::advance();
            return;
        }
        if (!DfsOrderIterator<T>::currentNode) return;

        if (!DfsOrderIterator<T>::currentNode->children.empty() && DfsOrderIterator<T>::currentNode->children.size() > 1) {
            Node<T>* temp = DfsOrderIterator<T>::currentNode->children[1];
            while (temp) {
                visitStack.push(temp);
                temp = temp->children.empty() ? nullptr : temp->children[0];
            }
        }

        if (!visitStack.empty()) {
            DfsOrderIterator<T>::currentNode = visitStack.top();
            visitStack.pop();
        }
        else {
            DfsOrderIterator<T>::currentNode = nullptr;
        }
    }


   


};


