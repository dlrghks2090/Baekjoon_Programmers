#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int answer = -1;
set<int> s;

void bfs(int x, int y, int n) {
    
    queue<pair<int,int>> que;
    
    que.push({x,0});
    
    while(!que.empty()) {
        int total = que.front().first;
        int count = que.front().second;
        que.pop();
        
        if (total == y) {
            answer = count;
            return;
        }
        else if (total < y) {
            if (s.insert(total*3).second) {
                que.push({total*3, count+1});
            }
            if (s.insert(total*2).second){
                que.push({total*2, count+1});
            }
            if (s.insert(total+n).second) {
                que.push({total+n, count+1});
            }
        }
    }
    
}

int solution(int x, int y, int n) {

    bfs(x,y,n);

    return answer;
}