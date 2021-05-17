#ifndef LIST_S_H
#define LIST_S_H
#include <iostream>
#include "NodeS.h"

using namespace std;

template<class T>
class ListS{

    NodeDL<T> *head, *tail, *nil;
    int length;
    bool ascend;

    public:

    ListS(bool ascend) : head(NULL), tail(NULL), ascend(ascend), length(0){
        nil = new NodeDL<T>;
    }
    ListS() : head(NULL), tail(NULL), ascend(true), length(0){
        nil = new NodeDL<T>;
    }

    bool is_empty(){
        return (head == NULL) &&  (tail == NULL);
    }

    NodeDL<T> * get_head() const {return head;}
    NodeDL<T> * get_tail() const {return tail;}
    NodeDL<T> * get_nil() const {return nil;}
    int get_lenth() const {return length;}
    bool is_ascending const {return ascend;}

    void insert_head(T value){
        NodeDL<T> * n = new NodeDL<T>(value);

        if(this->is_empty()){
            head = n;
            tail = n;
            n->set_next(nil);
            n->set_prev(nil);
            nil->set_next(head);
            nil->set_prev(tail);
        }
        else{
            n->set_next(head);
            head->set_prev(n);
            n->set_prev(nil);
            head = n;
            nil->set_next(head);
        }
        length++;
    }
}

#endif