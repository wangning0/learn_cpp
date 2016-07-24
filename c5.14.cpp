#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main(){
//    char ch;
//    char str = ' ';
//    char maxStr = ' ';
//    int maxCount = 0;
//    int count = 0;
//    while (cin >> ch) {
//        if( str == ch ) {
//            count++;
//        } else {
//            count = 1;
//        }
//        if( count > maxCount ) {
//            maxCount = count;
//            maxStr = ch;
//        }
//        str = ch;
//    }
//    cout << maxStr << ' ' << maxCount;
    pair<string, int> max_duplicated;
    int count = 0;
    for (string str, preStr; cin >> str ; preStr = str) {
        if( str == preStr ) {
            count++;
        } else {
            count = 0;
        }
        if( max_duplicated.second < count ) {
            max_duplicated = { preStr, count };
        }
        if (max_duplicated.first.empty()) cout << "There's no duplicated string." << endl;
        else cout << "the word " << max_duplicated.first << " occurred " << max_duplicated.second + 1 << " times. " << endl;
    }
    return 0;
}