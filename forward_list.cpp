#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <list>
#include <deque>
#include <forward_list>

using std::vector; using std::string; using std::ifstream; using std::cout; using std::endl;

using namespace std;

//void ReadFileToVec(const string& fileName, vector<string>& vec)
//{
//    ifstream ifs(fileName);
//    if (ifs)
//    {
//        string buf;
//        while (std::getline(ifs, buf))
//            vec.push_back(buf);
//    }
//}
//bool find_item ( vector<int>::const_iterator first,vector<int>::const_iterator last, int i ) {
//    bool finded = false;
//    for (; first != last; first++) {
//        if ( *first == i ) {
//            finded = true;
//        }
//    }
//    return finded;
//}
void fls_find_add( forward_list<string> &fls, string s1, string s2 ) {
    auto prev = fls.before_begin();
    auto curr = fls.begin();
    while (curr != fls.end()) {
        if( *curr == s1 ) {
            fls.insert_after(prev, s2)++;
            return;
        } else {
            prev = curr;
            ++curr;
        }
    }
}
int main()
{
    forward_list<string> fls = {"hello","world","lala"};
    const string str1 = "world";
    const string str2 = "!";
    fls_find_add(fls, str1, str2);
    for(auto f : fls ) {
        cout << f << endl;
    }
    return 0;
}