#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int answer = -1;
int visit[101][101];

pair<int,int> find_R(vector<string> board) {
    pair<int,int> p;
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[i].size(); j++) {
            if(board[i][j] == 'R') {
                p = make_pair(i,j);
            }
        }
    }
    return p;
}

void bfs(vector<string> board, pair<int,int> start){
    
    queue<pair<pair<int,int>,int>> que;
    
    que.push(make_pair(start,0));
    visit[start.first][start.second] = 1;
    
    while(!que.empty()) {
        int idx1 = que.front().first.first;
        int idx2 = que.front().first.second;
        int count = que.front().second;
        que.pop();
        
        cout << "idx1= " << idx1 << " idx2= " << idx2 << " count= " << count << '\n';
        if (board[idx1][idx2] == 'G') {
            answer = count;
            return;
        }
        
        // 오른쪽
        for(int i=idx2+1; i<board[0].size(); i++) {
            if(board[idx1][i] == 'D')
                break;
            if (i+1 < board[0].size()) {
                if (board[idx1][i+1] == 'D') {
                    if (visit[idx1][i] == 0) {
                        visit[idx1][i] = 1;
                        que.push(make_pair(make_pair(idx1,i),count+1));
                    }
                    break;
                }
            }
            else {
                if (visit[idx1][i] == 0) {
                    visit[idx1][i] = 1;
                    que.push(make_pair(make_pair(idx1,i),count+1));
                }
            }             
        }
        
        // 왼쪽
        for(int i=idx2-1; i>=0; i--) {
            if(board[idx1][i] == 'D')
                break;
            if (i-1 >= 0) {
                if (board[idx1][i-1] == 'D') {
                    if (visit[idx1][i] == 0) {
                        visit[idx1][i] = 1;
                        que.push(make_pair(make_pair(idx1,i),count+1));
                    }
                    break;
                }
            }
            else {
                if (visit[idx1][i] == 0) {
                    visit[idx1][i] = 1;
                    que.push(make_pair(make_pair(idx1,i),count+1));
                }
            }
        }
        
        // 아래
        for(int i=idx1+1; i<board.size(); i++) {
            if(board[i][idx2] == 'D')
                break;
            if(i+1 < board.size()) {
                if(board[i+1][idx2] == 'D') {
                    if(visit[i][idx2] == 0) {
                        visit[i][idx2] = 1;
                        que.push(make_pair(make_pair(i,idx2),count+1));
                    }
                    break;
                }
            }
            else {
                if(visit[i][idx2] == 0) {
                    visit[i][idx2] = 1;
                    que.push(make_pair(make_pair(i,idx2),count+1));
                }
            }
        }
        
        // 위
        for(int i=idx1-1; 0<=i; i--) {
            if(board[i][idx2] == 'D')
                break;
            if(i-1 >= 0) {
                if(board[i-1][idx2] == 'D') {
                    if(visit[i][idx2] == 0) {
                        visit[i][idx2] = 1;
                        que.push(make_pair(make_pair(i,idx2),count+1));
                    }
                    break;
                }
            }
            else {
                if(visit[i][idx2] == 0) {
                    visit[i][idx2] = 1;
                    que.push(make_pair(make_pair(i,idx2),count+1));
                }
            }
        }
    }
}

int solution(vector<string> board) {
    
    pair<int,int> start = find_R(board);
    
    bfs(board, start);
    
    return answer;
}