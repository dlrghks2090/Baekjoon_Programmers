#include <string>
#include <vector>

using namespace std;

int answer = -1;
int visit[10];

void dfs(int k, vector<vector<int>> dungeons, int count){
    
    if (answer < count) {
        answer = count;
    }
    
    for(int i=0; i<dungeons.size(); i++) {
        if (visit[i] == 0 && k >= dungeons[i][0]) {
            visit[i] = 1;
            dfs(k-dungeons[i][1], dungeons, count+1);
            visit[i] = 0;
        }
    }
    
}

int solution(int k, vector<vector<int>> dungeons) {
    
    
    dfs(k, dungeons, 0);
    
    return answer;
}