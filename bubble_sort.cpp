//passing by reference  传址
//passing by value      传值
//reference 扮演着外界与对象之间一个间接手柄的角色
#include <iostream>
#include <vector>
#include <cstddef>
using namespace std;

void display( const vector<int> &vec ){
    for( int ix = 0; ix < vec.size(); ix++ ){
        cout << vec[ix] << ' ';
    }
    cout << endl;
}

/*void display( const vector<int> *vec ){
    if( ! vec ) {
        cout << "display(): the vector pointers is 0\n";
        return;
    }
    //vec->size() pointer与reference的区别
    for( int ix = 0; ix < vec->size(); ix++ ){
        cout << (*vec)[ix] << ' ';
    }
    cout << endl;
    //传入的参数也应该是一个地址
}*/

void swap( int &val1, int &val2 ){
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

void bubble_sort( vector<int> &vec ){
    for ( int ix = 0; ix < vec.size(); ix++ ) {
        for( int jx = ix + 1; jx < vec.size(); jx++ ){
            if( vec[ix] > vec[jx] ){
                swap( vec[ix], vec[jx] );
            }
        }
    }
}

int main(){
    int ia[8] = {8,32,43,23,43,32,4,1};
    vector<int> vec( ia, ia+8 );
    cout << "vector before sort: ";
    display(vec);
    bubble_sort(vec);
    cout << "after sort: ";
    display(vec);
    return 0;
}