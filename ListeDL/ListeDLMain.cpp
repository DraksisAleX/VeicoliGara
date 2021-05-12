#include <iostream>
#include "NodeDL.h"
#include "ListDL.h"
using namespace std;

int main(){

    NodeDL<int> n(10);
    NodeDL<int> p(15);

    cout << (n > p) << endl;
    cout << (n < p) << endl;
    cout << (n == p) << endl;

    ListDL<int> list;

    list.insert_head(10);
    list.insert_head(5);
    list.insert_tail(15);

    cout << list;

    list.insert(7);
    list.insert(12);
    list.insert(9);
    list.insert(3);
    list.insert(42);

    cout << list;

    list.delete_value(9);
    cout << list;
    list.delete_value(3);
    cout << list;
    list.delete_value(42);

    cout << list;

    return 0;

}