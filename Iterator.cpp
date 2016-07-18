#include <iostream>
#include <vector>
#include <list>
using namespace std;

template < typename IteratorType, typename elemType >
IteratorType find_( IteratorType first, IteratorType last, const elemType &value ){
    for( ; first != last; ++first ){
        if( *first == value ){
            return first;
        }
    }
    return last;
}

int main(){
    const int asize = 8;
    int ia[asize] = { 1, 2, 3, 4, 22, 32, 31, 1024 };
    vector<int> ivec( ia, ia + asize );
    list<int> ilist( ia, ia + asize );
    
    int *pia = find_( ia, ia+asize, 1024 );
    if ( pia != ia+asize ){
        cout << "array 找到了";
    } else {
        cout << "array没找到了";
    }
    cout << "\n";
    
    vector<int>::iterator it;
    it = find_( ivec.begin(), ivec.end(), 1024);
    if ( it != ivec.end() ){
        cout << "vector 找到了";
    } else {
        cout << "vector没找到了";
    }
    cout << "\n";
    
    list<int>::iterator iter;
    iter = find( ilist.begin(), ilist.end(), 1024 );
    if ( iter != ilist.end() ){
        cout << "list 找到了";
    } else {
        cout << "list没找到了";
    }
    cout << "\n";
    
    return 0;
}
