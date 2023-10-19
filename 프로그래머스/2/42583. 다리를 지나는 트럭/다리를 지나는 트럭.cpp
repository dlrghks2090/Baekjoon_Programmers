#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include<iostream>

using namespace std;

int answer = 0;

void bfs(int& bridge_length, int& weight, vector<int>& truck_weights) {
    deque<pair<pair<int,int>,int>> que;
    int total = 0;
    
    for(int i=0; i<bridge_length; i++) {
        que.push_back(make_pair(make_pair(-1,0),0));
    }
    
    while(!que.empty()) {
        int idx = que[bridge_length-1].first.first;
        int count = que[bridge_length-1].first.second;
        int value = que.front().second;
        
        int last_idx = que[bridge_length-1].first.first;
        total = total + que[bridge_length-1].second;
    
        //cout << "last_idx: " << que[bridge_length-1].first.first << " count: " << count << " total: " << total << " idx: " << idx << '\n';
        
        if (que.front().first.first == truck_weights.size()-1) {
            answer = count+1;
            return;
        }
        
        que.pop_front();
        total = total - value;
        
        
        if (total + truck_weights[idx+1] <= weight) {
            que.push_back(make_pair(make_pair(idx+1, count+1),truck_weights[idx+1]));
        }
        else {
            que.push_back(make_pair(make_pair(idx, count+1),0));
        }
        
        
    }
    
    
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    
    
    bfs(bridge_length, weight, truck_weights);
    return answer;
}