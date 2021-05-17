#include "ListS.h"

using namespace std;

int main(){

    ListS<int> list1;

    list1.insert_head(10);
    list1.insert_tail(22);
    list1.insert(30);
    list1.insert(8);
    list1.insert(15);

    cout << list1;

}