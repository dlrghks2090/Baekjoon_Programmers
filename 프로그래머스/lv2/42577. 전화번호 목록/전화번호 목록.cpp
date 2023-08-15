#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> hash_map;
    int size = phone_book.size();
    
    for(int i=0; i<size; i++) {
        hash_map.insert(make_pair(phone_book[i],1));
    }
    
    for (int i = 0; i<size; i++) {
        string str = "";
        for (int j=0; j<phone_book[i].size()-1; j++) {
            str += phone_book[i][j];
            //cout << "str = " << str << '\n';
            if(hash_map[str]) {
                //cout << "str = " << str << '\n';
                return false;
            }
        }
        
    }
    return answer;
}