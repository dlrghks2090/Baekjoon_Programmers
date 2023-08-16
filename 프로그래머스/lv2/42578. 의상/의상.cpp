#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    unordered_map<string, int> hash_map;
    int size = hash_map.size();
    int sol = 1;
    
    for(int i=0; i<clothes.size(); i++) {
        if (hash_map.find(clothes[i][1]) == hash_map.end())
            hash_map.insert(make_pair(clothes[i][1], 1));
        else {
            hash_map[clothes[i][1]] +=1;
        }
    }
    
    for (auto iter : hash_map) {
        cout << "수 :" << iter.second+1 << '\n';
        sol = sol * (iter.second + 1);
    }
    
    answer = sol -1;
    
    return answer;
}