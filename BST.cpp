#include "BST.h"
#include <vector>
#include <iostream>

/**
 * Implement the BST constructor
 */
BST::BST() {
    /* YOUR CODE HERE */
    root = NULL;
    numElements = 0;
}

/**
 * Implement the BST destructor
 */
BST::~BST() {
    /* YOUR CODE HERE */
    clear();
}

/**
 * Implement size() correctly
 */
unsigned int BST::size() const {
    /* YOUR CODE HERE */
    return numElements;
}

/**
 * Implement clear() correctly without memory leaks
 */
void BST::clear() {
    /* YOUR CODE HERE */
    myDelete(root);
    numElements=0;
}

/**
 * Implement insert() correctly
 */
bool BST::insert(int element) {
    /* YOUR CODE HERE */
    cout << "----------" << element << "count =" << numElements;
    Node* curr = root;
    if(curr == NULL) {
        root = new Node(element);
        numElements++;
        return true;
    }
    while(curr && curr->data != element) {
        if(curr->data > element) {
            if(curr->leftChild)
                curr = curr->leftChild;
            else {
                Node* newNode = new Node(element);
                curr->leftChild = newNode;
                newNode->parent = curr;
                numElements++;
                return true;
            }
                
            continue;
        }
        if(curr->data < element)     {
            if(curr->rightChild)
                curr = curr->rightChild;
            else {
                Node* newNode = new Node(element);
                curr->rightChild = newNode;
                newNode->parent = curr;
                numElements++;
                return true;
            }
            continue;
        }
    }

    return false;
}

/**
 * Implement find() correctly
 */
bool BST::find(const int & query) const {
    /* YOUR CODE HERE */
    Node* curr = root;
    while(curr && curr->data != query) {
        if(curr->data > query) {
            if(curr->leftChild)
                curr = curr->leftChild;
            else
                return false;
            continue;
        }
        if(curr->data < query)     {
            if(curr->rightChild)
                curr = curr->rightChild;
            else
                return false;
            continue;
        }
    }

    return true;
}

/**
 * Implement the getLeftMostNode() function correctly
 */
BST::Node* BST::getLeftMostNode() {
    /* YOUR CODE HERE */
    Node* curr = root;
    while(curr->leftChild)
        curr = curr->leftChild;

    return curr;
}

/**
 * Implement the BST::Node successor function correctly
 */
BST::Node* BST::Node::successor() {
    /* YOUR CODE HERE */
    if(this->rightChild) {
        Node* curr = this->rightChild;
        while(curr->leftChild) {
            curr = curr->leftChild;
        }
        return curr;
    }
    else {
        Node* curr = this;
        while(curr->parent != NULL) {
            if(curr == curr->parent->leftChild)
                return curr->parent;
            else
                curr = curr->parent;
            
        }
    }
    return NULL;
}

void BST::myDelete(Node* curr) {
    if (curr == NULL)
        return;
    if (curr->leftChild) {
        myDelete(curr->leftChild);
    }
    if(curr->rightChild) {
        myDelete(curr->rightChild);
    }
    /*if(curr->leftChild == NULL && curr->rightChild == NULL) {
        Node* parent = curr->parent;
        if(parent != NULL) {
            if(parent->leftChild == curr) {
                parent->leftChild = NULL;
            } else {
                parent->rightChild = NULL;
            }
            delete curr;
            curr = parent;
            return;
        } else {
            delete curr;
            curr = NULL;
            return;
        }
    }

    if(curr) {
        Node* parent = curr->parent;
        delete curr;
        curr = parent;
        return;
    }*/
    /*if (curr->parent) {
        Node* parent = curr->parent;
        if(parent->leftChild == curr) {
            parent->leftChild = NULL;
        } else if(parent->rightChild == curr) {
            parent->rightChild = NULL;
        }
    }*/
    delete curr;
}
