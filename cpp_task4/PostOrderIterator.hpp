#pragma once
#include "node.hpp"
#include <stack>
#include "dfsiterator.hpp"

template<typename T,int k=2>
class PostOrderIterator : public DfsOrderIterator<T>{
public:
    using value_type = Node<T>;
    using pointer = Node<T>*;
    using reference = Node<T>&;

   
    PostOrderIterator<T,k>(Node<T>* root) :DfsOrderIterator<T>(root) {
        if (k > 2)
            return;
        this->currentNode = nullptr;
        if (root) {
            fillStack(root);
            advance();
        }
    }


    PostOrderIterator operator++() {
        advance();
        return *this;
    }

    PostOrderIterator operator++(int) {
        PostOrderIterator tmp = *this;
        advance();
        return tmp;
    }

    reference operator*() {
        return *DfsOrderIterator<T>::currentNode;
    }

    pointer operator->() {
        return DfsOrderIterator<T>::currentNode;
    }

    bool operator==(const PostOrderIterator& other) {
        if (k > 2)
            return  DfsOrderIterator<T>::operator==(other);
        return (other.currentNode == this->currentNode && this->visitStack == other.visitStack);
    }

    bool operator!=(const PostOrderIterator<T,k>& other) {
        return !(*this == other);
    }

private:
    stack<Node<T>*>  visitStack;
   // Node<T>* currentNode;


    void advance() {
        if (k > 2)
        {
            DfsOrderIterator<T>::advance();
            return;
        }
        if (!visitStack.empty()) {
            DfsOrderIterator<T>::currentNode = visitStack.top();
            visitStack.pop();
        }
        else {
            DfsOrderIterator<T>::currentNode = nullptr;
        }
    }

    void fillStack(Node<T>* node) {
        if (!node) return;
        std::stack<Node<T>*> tempStack;
        tempStack.push(node);
        while (!tempStack.empty()) {
            Node<T>* n = tempStack.top();
            tempStack.pop();
            visitStack.push(n);
            for (auto it = n->children.begin(); it != n->children.end(); ++it) {
                tempStack.push(*it);
            }
        }
    }


};

