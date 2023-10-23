#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> answer;
bool visit[10001];
bool check = false;

void dfs(string airport, vector<vector<string>>& tickets ,int count){
    // 모든 공항을 방문했다면 탐색 종료
    if (count == tickets.size()) {
        check = true;
        cout << "=================" << '\n';
        return;
    }
    // 티켓 수만큼 체크
    for (int i=0; i<tickets.size(); i++) {
        // 이전 공항이 현재 출발하는 공항과 같고, 방문하지 않은 곳일때
        if (tickets[i][0] == airport && visit[i] == false) {
            visit[i] = true;
            answer.push_back(tickets[i][1]);
            dfs(tickets[i][1], tickets, count+1);
            cout << "이전 공항= " << tickets[i][0] << "  방문한 공항= " << tickets[i][1] << '\n';
            if (check != true) {
                visit[i] = false;
                answer.pop_back();
            }
            
        }
        
        
    }
    
}

vector<string> solution(vector<vector<string>> tickets) {
    
    
    // 알파벳 순 경로를 바로 찾기 위해 티켓을 사전순으로 정렬
    sort(tickets.begin(), tickets.end());
    
    cout << "==정렬된 티켓 출력==" << '\n';
    for (int i=0; i<tickets.size(); i++) {
        cout << tickets[i][0] << " " << tickets[i][1] << "\n\n";
    }
    
    // 첫 시작 항공인 "ICN" 공항 추가
    answer.push_back("ICN");
    // 깊이 우선 탐색 실행
    dfs("ICN", tickets, 0);
    
    cout << "==정렬된 티켓 출력==" << '\n';
    for (int i=0; i<tickets.size(); i++) {
        cout << tickets[i][0] << " " << tickets[i][1] << '\n';
    }
    
    for (int i=0; i<answer.size(); i++) {
        cout << answer[i] << " "  << '\n';
    }
    
    return answer;
}