#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    long long a,b;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i=0; i<scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    
    while (pq.size() > 1 && pq.top() < K) {
        a = pq.top();
        pq.pop();
        b = pq.top()*2;
        pq.pop();
        
        pq.push(a+b);
        answer++;
    }
    if (pq.top() < K)
        return -1;
    else
        return answer;
}