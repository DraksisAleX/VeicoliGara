#ifndef LISTDL_H
#define LISTDL_H
#include <iostream>
#include <sstream>
#include "NodeDL.h"
using namespace std;

template<class T>
class ListDL{

    NodeDL<T> *head, *tail;
    int length;
    bool ascend;

    void insert_ascending(T value){
        NodeDL<T> * temp = new NodeDL<T>(value);
        if(head == NULL && tail == NULL){
            this->insert_head(value);
            return;
        }
        if(head->get_value() > value){
            this->insert_head(value);
            return;
        }
        if(tail->get_value() <= value){
            this->insert_tail(value);
            return;
        }
        NodeDL<T> * curr = head;
        while (curr->get_value() < value)
        {
            curr = curr->get_next();
        }
        temp->set_prev(curr->get_prev());
        temp->set_next(curr);
        curr->get_prev()->set_next(temp);
        curr->set_prev(temp);
        length++;
    }

    public:

    ListDL() : head(NULL), tail(NULL), length(0), ascend(true) {}
    ListDL(bool ascend) : head(NULL), tail(NULL), length(0), ascend(ascend) {}

    void set_ascending_order() {ascend = true;}
    void set_descending_order() {ascend = false;}

    NodeDL<T> * get_head() const {return this->head;}
    NodeDL<T> * get_tail() const {return this->tail;}
    bool is_ascending() const {return this->ascend;}
    int get_length() const {return this->length;}

    void insert_head(T value){
        NodeDL<T> * temp = new NodeDL<T>(value);
        if (head == NULL && tail == NULL)
        {
            head = temp;
            tail = temp;
        }
        else{
            temp->set_next(head);
            head->set_prev(temp);
            head = temp;
        }
        length++;
    }

    void insert_tail(T value){
        NodeDL<T> * temp = new NodeDL<T>(value);
        if (tail == NULL && head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else{
            temp->set_prev(tail);
            tail->set_next(temp);
            tail = temp;
        }
        length++;
    }

    friend ostream& operator<<(ostream& out, const ListDL<T> list){
        out << "Lista di lunghezza " << list.length << ", HEAD = " << list.head << ", TAIL = " << list.tail << endl << endl;
        NodeDL<T> * curr = list.head;
        while (curr != NULL)
        {
            out << "\t" << *curr << endl;
            curr = curr->get_next();
        }
        return out;
    }

    void insert(T value){
        if(this->is_ascending()) this->insert_ascending(value);
        else cout << "Da implementare";
    }

    void delete_value(T value){
        NodeDL<T> * curr = head;
        while (curr != NULL && curr->get_value() != value)
        {
            curr = curr->get_next();
        }
        if (curr == NULL)
        {
            cout << "\n\nError: value " << value << " not found.\n\n";
            return;
        }
        if(curr != head) curr->get_prev()->set_next(curr->get_next());
        if(curr != tail) curr->get_next()->set_prev(curr->get_prev());    
        if(curr == head) head = head->get_next();
        if(curr == tail) tail = tail->get_prev();
        delete curr;
        length--;
    }

};
#endif