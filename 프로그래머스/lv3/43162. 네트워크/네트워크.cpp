#include <string>
#include <vector>
#include <queue>

using namespace std;

int visit[201] = {0,};

void bfs(vector<vector<int>> computers, int n, int idx) {   //한번 실행되면 네트워크 1개 추가
    queue<int> que;
    
    que.push(idx);
    visit[idx] = 1;
    
    while(!que.empty()) {
        
        int tmp = que.front();
        
        que.pop();
        
        for (int i = 0; i < n; i++) {       // tmp번호의 컴퓨터와 연결된 컴퓨터 전부 확인
            if (computers[tmp][i] == 1 && visit[i] == 0) {  // 연결된 컴퓨터 중에 방문하지 않았던 컴퓨터가 존재한다면 push
                visit[i] = 1;
                que.push(i);
            }
        }
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i<n; i++) {
        if (visit[i] == 0) {    // 방문되지 않는 컴퓨터일때 탐색 시작
            bfs(computers, n , i);
            answer++;
        }
    }
    
    return answer;
}