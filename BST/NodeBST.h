#ifndef NODE_BST_H
#define NODE_BST_H

#include <iostream>
using namespace std;

template<class T>
class NodeBST{
    T key;
    NodeBST<T> *left, *right, *parent;

    public:

    NodeBST(T key) : key(key), left(NULL), right(NULL), parent(NULL) {}
    NodeBST() : key(0), left(NULL), right(NULL), parent(NULL) {}

    NodeBST<T>* get_left() const {return left;}
    NodeBST<T>* get_right() const {return right;}
    NodeBST<T>* get_parent() const {return parent;}

    void set_left(NodeBST<T>* left) {this->left = left;}
    void set_right(NodeBST<T>* right) {this->right = right;}
    void set_parent(NodeBST<T>* parent) {this->parent = parent;} 

    friend ostream& operator<<(ostream &out, const NodeBST<T>& n){
        out << "BST Node: " << &n;
        out << "\n\tkey = " << n.key << ", left = " << n.left << ", right = " << n.right << ", parent = " << n.parent << endl;
        return out;
    }
};

#endif