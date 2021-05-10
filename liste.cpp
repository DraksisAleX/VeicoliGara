
#include <iostream>
#include <sstream>
#include "student.h"

using namespace std;

template<class T>
class Node{
    private:
    T value;
    Node<T> * next;

    public:
    Node(T value, Node<T> * next) : value(value), next(next) {}
    Node(T value) : value(value), next(NULL) {}
    Node() : value(0), next(NULL) {}

    Node<T> * get_next() {return this->next;}
    T get_value() {return this->value;}
    void setNext(Node<T> * pt) { this->next = pt;}
    void setValue(T val) {this->value = val;}

    string toString(){
        stringstream stream;
        stream << "Node value = " << value << ", next = " << next << "\n";
        return stream.str();
    }
};

template<class T>
class List{
    private:
    Node<T> * head;
    int lenght;

    public:
    List(Node<T> head) : head(head), lenght(0){}
    List() : head(NULL) {lenght = 0;}

    void insert(Node<T> * n) {
		if(head == NULL) {
			head = n;
			lenght++;
			return;
		}
		
		Node<T> * current = head;
		while(current->get_next() != NULL) {
			current = current->get_next();
		}
		current->setNext(n);
		lenght++;
	}

    void insert(T value) {
		Node<T> * temp = new Node<T>(value);
		this->insert(temp);
	}

    void insert_in_order(T value){
        Node<T> * temp = new Node<T>(value);

        if(head == NULL){
            this->insert(temp);
            return;
        }

        if(head->get_value() >= value ){
            temp->setNext(head);
            head = temp;
            lenght++;
            return;
        }

        Node<T> *prev = head;
        Node<T> *current = head->get_next();

        while (current != NULL)
        {
            if(prev->get_value() < value && current->get_value() >= value){
                prev->setNext(temp);
                temp->setNext(current);
                lenght++;
                return;
            }
            else{
                prev = current;
                current = current->get_next();
            }
        }

        prev->setNext(temp);
        lenght++;
        return;    
    }

    bool search(T value){
        if(head == NULL) return false;
        Node<T> * temp = head;
        while (temp!=NULL)
        {
            if(temp->get_value() == value) return true;
            temp = temp->get_next();
        }
        return false;
    }

    Node<T> * deleteNode(T value){
        if(this->search(value)){
            if(head->get_value() == value){
                Node<T> * temp = head;
                head = head->get_next();
                lenght--;
                return temp;
            }
            Node<T> * prev = head;
            Node<T> * curr = head->get_next();
            while (curr != NULL)
            {
                if(curr->get_value() == value){
                    prev->setNext(curr->get_next());
                    lenght--;
                    return curr;
                }
                else{
                    prev = curr;
                    curr = curr->get_next();
                }
            }
        }
        return NULL;
    }

    friend ostream& operator<<(ostream& out, const List<T>& l) {
		out << "Lista di lunghezza: " << l.lenght << " head = " << l.head << endl;
		Node<T> * current = l.head;
		while(current != NULL) {
			out << "\t" << current->toString() << endl;
			current = current->get_next();
		}
		return out;
	}
};

int main(){
    Node<int> n0(10);
    Node<int> n1(20);
    Node<int> n2;

    cout << n0.toString();
    cout << n1.toString();
    cout << n2.toString();

    List<int> list;
    list.insert(&n0);
    list.insert(&n1);
    list.insert(30);
    list.insert_in_order(15);
    list.insert_in_order(25);
    list.insert_in_order(18);

    cout << list << endl;

    list.deleteNode(18);
    list.deleteNode(10);
    list.deleteNode(30);

    cout << list << endl;

    Studente s1("a","a","a",20);
    Studente s2("b","a","a",20);
    Studente s3("a","b","a",20);
    Studente s4("a","a","a",21);

    cout << (s1 < s2) << endl;
    cout << (s1 > s2) << endl;
    cout << (s1 > s3) << endl;
    cout << (s3 > s2) << endl;
    cout << (s1 > s4) << endl;
    cout << (s1 == s1) << endl;

    List<Studente> list2;
    list2.insert_in_order(s1);
    list2.insert_in_order(s2);
    list2.insert_in_order(s3);
    list2.insert_in_order(s4);

    cout << list2 << endl;
}