#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    map<string,int> words;
    words["w"] = 10;
    words["n"] = 20;
    
    map<string,int>::iterator it = words.begin();
    for ( ; it != words.end(); ++it) {
        cout << "key :" << it->first;
        cout << "\n";
        cout << "value :" << it->second;
        cout << "\n";
    }
    return 0;
}