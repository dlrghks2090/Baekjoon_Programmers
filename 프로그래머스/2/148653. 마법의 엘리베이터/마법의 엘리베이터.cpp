#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int answer = 100000000;

void bfs(int num) {
    queue<pair<int, int>> que;
    
    que.push(make_pair(num,0));
    
    while(!que.empty()) {
        int n = que.front().first;
        int count = que.front().second;
        que.pop();
        
        cout << "n= " << n << " count= " << count << '\n';
        
        if (n == 0) {
            if (answer > count)
                answer = count;
            continue;
        }
        
        if (n>= 10) {
            que.push(make_pair(n/10, count+n%10));
            if (n%10 == 0) {
                que.push(make_pair(n/10, count));
            }
            else
                que.push(make_pair(n/10 +1, count+(10-n%10)%10));
        }
        else if (n >0) {
            if (n <=5) {
                que.push(make_pair(0, count+n));
            }
            else {
                que.push(make_pair(0, count+(10-n)+1));
            }
        }
    }
}

int solution(int storey) {
    
    int tmp = storey;
    
    bfs(storey);
    
    return answer;
}