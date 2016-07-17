# include <iostream>
# include <vector>
using namespace std;

int main() {
  return 0;
}

const vector<int> *fibon_seq( int size ){
    const int max_size = 1024l
    static vector<int> elems;
    if( size <=0 || size > max_size ){
      cerr << "error";
      return 0;
    }
    for( int ix = elems.size(); ix < size; ix++ ){
      //...
      elems.push_back( elems[ix-1] + elems[ix-2] );
    }
    return &elems;
}