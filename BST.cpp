#include "BST.h"
#include <vector>

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
    recursiveDelete(root);
    numElements=0;
}

/**
 * Implement insert() correctly
 */
bool BST::insert(int element) {
    /* YOUR CODE HERE */
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

void BST::recursiveDelete(Node* curr) {
    /* YOUR CODE HERE*/
    if(curr == NULL)
        return;
    if(curr->leftChild == NULL && curr->rightChild == NULL) {
        //Node* parent = curr->parent;
        delete curr;
        return;
    }
    if(curr && curr->leftChild) {
        recursiveDelete(curr->leftChild);
    }
    if(curr && curr->rightChild) {
        recursiveDelete(curr->rightChild);
    }

    if(curr) {
        delete curr;
        curr = NULL;
    }
}
