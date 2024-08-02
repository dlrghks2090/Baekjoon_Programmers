/*  
    1. 배열형 벡터를 사용해 시간복잡도를 준수하여 간선 그래프 작성
    2. 노드 1부터 시작하여 DFS or BFS로 sol배열에 부모노드 체크
*/
#include<iostream>
#include<vector>
#define MAX 100001

using namespace std;

vector<int> v[MAX]; // 간선 그래프
int sol[MAX];   // 부모 노드 체크 배열

void dfs(int node) {

    //cout << node << '\n';
    for (int i=0; i<v[node].size(); i++) {
        if (sol[v[node][i]] == 0) {
            sol[v[node][i]] = node;
            dfs(v[node][i]);
        }
    }
}

int main() {

    int N;
    int x,y;

    cin >> N;

    for(int i=1; i<N; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    sol[1] = -1;

    dfs(1);

    for(int i=2; i<=N; i++) {
        cout << sol[i] << '\n';
    }

    return 0;
}