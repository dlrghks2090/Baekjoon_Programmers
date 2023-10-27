#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

struct cmp{
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;   
    int count = 0;  // 우선순위 큐에 들어간 작업의 수
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    
    sort(jobs.begin(), jobs.end());
    
    while(count < jobs.size() || !pq.empty()) {
        if (count < jobs.size() && jobs[count][0] <= time) {
            pq.push(jobs[count]);
            count++;
            continue;
        }
        
        if (!pq.empty()) {
            time += pq.top()[1];
            answer += time - pq.top()[0];
            pq.pop();
        }
        else {
            time = jobs[count][0];
        }
    }
    
    answer /= jobs.size();
    
    return answer;
}
