# include <iostream>
# include <vector>
using namespace std;

int main() {

template <typename elemType> void display_message (const string &msg, constvector<elemType> &vec) {
    cout << msg;
    for( int ix = 0; ix < vec.size(); ++ix ) {
      elemType t = vec[ix];
      cout << t << " ";
    }

}
  return 0;
}
