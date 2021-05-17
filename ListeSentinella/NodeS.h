#ifndef NODEDL_H
#define NODEDL_H
#include <iostream>
#include <sstream>
using namespace std;

template<class T>
class NodeDL{
    T value;
    NodeDL<T> * prev;
    NodeDL<T> * next;
    int compareTo(const NodeDL<T>& node)const{
        if(this->value > node.value) return 1;
        else if(this->value < node.value) return -1;
        else if(this->value == node.value) return 0;
        return 0;
    }

    public:

    NodeDL(T value, NodeDL<T> *prev, NodeDL<T> *next) : value(value), prev(prev), next(next) {}
    NodeDL(T value) : value(value) {this->prev=NULL; this->next=NULL;}
    NodeDL() : prev(NULL), next(NULL), value(NULL){}

    void set_value(T value){this->value = value;}
    void set_prev(NodeDL<T> *prev){this->prev = prev;}
    void set_next(NodeDL<T> *next){this->next = next;}

    T get_value() const {return value;}
    NodeDL<T> * get_prev() const {return prev;}
    NodeDL<T> * get_next() const {return next;}

    string toString() const {
		stringstream stream;
		stream << "NodeDL value = " << value << ", prev = " << prev << ", next = " << next;
		return stream.str();
	}

	friend ostream& operator<<(ostream& out, const NodeDL<T>& n) {
		out << n.toString();
		return out;
	}

    bool operator<(NodeDL<T>& n){
        return this->compareTo(n) < 0;
    }
    bool operator>(NodeDL<T>& n){
        return this->compareTo(n) > 0;
    }
    bool operator==(NodeDL<T>& n){
        return this->compareTo(n) == 0;
    }
    bool operator<=(NodeDL<T>& n){
        return this->compareTo(n) <= 0;
    }
    bool operator>=(NodeDL<T>& n){
        return this->compareTo(n) >= 0;
    }
};
#endif