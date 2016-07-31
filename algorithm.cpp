#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using namespace placeholders;
bool predicate(const std::string &s)
{
    return s.size() >= 5;
}

void elimDups(vector<string> &words) {
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique,words.end());
}
void biggies ( vector<string> &words,vector<string>::size_type sz ) {
    elimDups(words);
    stable_sort(words.begin(), words.end(), [](const string &a,const string &b){
        return a.size() < b.size();
    });
    auto wc = find_if(words.begin(), words.end(), [sz](const string &a){
        return a.size() >= sz;
    });
    for_each(wc, words.end(), [](const string &s){
        cout << s << ' ';
    });
}
bool choose_length_words (const string &s,int leg) {
    return s.size() <= leg;
}
bool check_size(const string &s,string::size_type sz) {
    return s.size() >= sz;
}
int main()
{
    vector<string> vec = {"hello","aaaaaaaa","aaaaaaaaaa","aaa","aaaaaaaa","aaaaaaaa","aaa"};
    vector<int> vec1{ 0, 1, 2, 3, 4, 5, 6, 7 };
    string str("123456");
    auto result = find_if(vec1.begin(), vec1.end(), bind(check_size, str, _1));
    if (result != vec1.cend())
        cout << *result << endl;
    else
        cout << "Not found" << endl;

    //int leg = 6;
    int time = 6;
    auto cnt = count_if(vec.begin(), vec.end(), bind(choose_length_words,_1,6));
    cout << cnt << endl;
    auto check_and_decrement = [&time]()-> bool {
        if(time){
            time--;
            return true;
        } else {
            return false;
        }
    };
    while (time) {
        check_and_decrement();
        cout << time << ' ';
    }
    return 0;
}

//transform(v1.begin(), v1.end(), v1.begin(), [](int i) -> int {
//    if( i < 0 ) {
//        return -i;
//    } else {
//        return i;
//    }
//});
