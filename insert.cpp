#include <iostream>
#include <list>
using namespace std;

int main() {
    int ival = 10;
    //iterator.insert(iterator position,elemType value)
    list<int> ilist(10,1);
    list<int>::iterator it = ilist.begin();
    while ( it != ilist.end() ) {
        if( *it >= ival ) {
            ilist.insert(it, ival);
            break;
        }
        ++it;
    }
    if( it == ilist.end() ){
        ilist.push_back(ival);
    }
    cout << ilist.back();
    return 0;
}