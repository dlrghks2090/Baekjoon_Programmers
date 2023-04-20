#include <string>
#include <vector>
#include <queue>

using namespace std;

int visit[201] = {0,};

void bfs(vector<vector<int>> computers, int n, int idx) {
    queue<int> que;
    
    que.push(idx);
    visit[idx] = 1;
    
    while(!que.empty()) {
        
        int tmp = que.front();
        
        que.pop();
        
        for (int i = 0; i < n; i++) {
            if (computers[tmp][i] == 1 && visit[i] == 0) {
                visit[i] = 1;
                que.push(i);
            }
        }
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i<n; i++) {
        if (visit[i] == 0) {
            bfs(computers, n , i);
            answer++;
        }
    }
    
    return answer;
}