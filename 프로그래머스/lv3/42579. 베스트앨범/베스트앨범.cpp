#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b) {
    if (a.first > b.first) {
        return true;
    }
    else if (a.first == b.first) {
        return a.second < b.second;
    }
    else {
        return false;
    }
}

bool compare_map(pair<string,int> a, pair<string,int> b) {
    if (a.second > b.second) {
        return true;
    }
    else {
        return false;
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<vector<int>> vec;
    unordered_map<string,int> map;
    
    for(int i=0; i<genres.size(); i++) {
        if(map.find(genres[i]) == map.end()) {
            map.insert(make_pair(genres[i], plays[i]));
        }
        else {
            map[genres[i]] += plays[i];
        }
    }
    vector<pair<string,int>> hash_map (map.begin(), map.end());
    // 값을 기준으로 내림차순 정렬
    sort(hash_map.begin(), hash_map.end(), compare_map);
    
    for(auto iter = hash_map.begin(); iter != hash_map.end(); iter++) {
        vector<pair<int, int>> v;
        vector<int> v2;
        int count = 0;
        for(int j = 0; j<genres.size(); j++) {
            if (iter->first == genres[j]) {
                v.push_back(make_pair(plays[j], j));
            }
        }
        sort(v.begin(),v.end(), compare);
        for (int j=0; j<v.size(); j++) {
            
            if (count == 2)
                break;
            answer.push_back(v[j].second);
            ++count;
        }
        vec.push_back(v2);
    }
    
   
    return answer;
}