#include <iostream>
using namespace std;

bool fibon_elem( int, int & );
bool print_sequence( int );

int main(){
    int pos;
    cout << "Please enter a position:";
    cin >> pos;
    
    int elem;
    if( fibon_elem(pos, elem) ){
        cout << "element # " << pos << "is" << elem << endl;
        print_sequence(pos);
    } else {
        cout << "sorry could not calcuate element # " << pos << endl;
    }
    return 0;
}

bool fibon_elem( int pos, int &elem ){
    if( pos <=0 || pos > 1024 ){
        elem = 0;
        return false;
    }
    elem = 1;
    int n_2 = 1, n_1 = 1;
    for( int ix = 3; ix <= pos; ++ix ){
        elem = n_2 + n_1;
        n_2 = n_1;
        n_1 = elem;
    }
    return true;
}

bool print_sequence( int pos ){
    if( pos <= 0 || pos > 1024 ){
        cout << "invalid postion " << "pos";
        return false;
    }
    cout << "The Fibonacci Swquence for " << pos << "positions:\n\t";
    switch (pos) {
        default:
        case 2:
            cout << "1 ";
        case 1:
            cout << "1 ";
            break;
    }
    int elem;
    int n_2 = 1;
    int n_1 = 1;
    for ( int ix = 3; ix <= pos; ++ix ) {
        elem = n_1 + n_2;
        n_2 = n_1;
        n_1 = elem;
        cout << elem << " ";
    }
    cout << "\n";
    return true;
}
