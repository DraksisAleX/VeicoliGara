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
    bool is_ascending() const {return ascend;}

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
            nil->set_next(n);
            head = n;
        }
        length++;
    }

    void insert_tail(T value){
        if(this->is_empty()){
            this->insert_head(value);
            return;
        }
        NodeDL<T> * n =  new NodeDL<T>(value);
        n->set_prev(tail);
        n->set_next(nil);
        tail->set_next(n);
        tail = n;
        nil->set_prev(tail);

        length++;
    }

    void insert(T value){
        if((this->is_ascending() && (value < head->get_value())) || (!this->is_ascending() &&  (value >= head->get_value()))){
            this->insert_head(value);
            return;
        }
        if((this->is_ascending() && (value >= tail->get_value())) || (!this->is_ascending() &&  (value < tail->get_value()))){
            this->insert_tail(value);
        }

        NodeDL<T> * cur = head;
        NodeDL<T> * n = new NodeDL<T>(value);
        if(this->is_ascending()){
            while(cur->get_value() < n->get_value() && cur != nil){
                cur = cur->get_next();
            }
            n->set_prev(cur->get_prev());
            n->set_next(cur);
            cur->get_prev()->set_next(n);
            cur->set_prev(n);
            length++;
        }
        else{
            while(cur >= n && cur != nil){
                cur = cur->get_next();
            }
            n->set_prev(cur->get_prev());
            n->set_next(cur);
            cur->get_prev()->set_next(n);
            cur->set_prev(n);
            length++;
        }
    }

    friend ostream& operator<<(ostream& out, const ListS<T> list){
        out << "Lista di lunghezza " << list.length << ", HEAD = " << list.head << ", TAIL = " << list.tail << endl << endl;
        NodeDL<T> * curr = list.head;
        while (curr != list.nil)
        {
            out << "\t" << *curr << endl;
            curr = curr->get_next();
        }
        return out;
    }
};

#endif