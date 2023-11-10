/*
    풀이>
        

*/

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 50*50 을 500*500 으로 키워서 계산한다.
int map[101][101];
int goal_x,goal_y;
int visit[101][101];
int answer = 100000;
int idx1[4] = {1,0,-1,0};
int idx2[4] = {0,1,0,-1};


void bfs(int x, int y) {
    
    // y,x,이동 count
    queue<pair<pair<int,int>,int>> que;
    
    que.push(make_pair(make_pair(y,x),0));
    visit[y][x] = 1;
    
    while(!que.empty()) {
        
        int arr1 = que.front().first.first;
        int arr2 = que.front().first.second;
        int count = que.front().second;
        
        que.pop();
        
        if (arr2==goal_x*2 && arr1==goal_y*2) {
            cout << count/2 <<'\n';
            //visit[y][x] = 0;
            if (answer > count) {
                answer = count;
                break;
            }
        }

        //cout << "y= " << y << " x= " << x <<'\n';

        for(int i=0; i<4; i++) {
            if (map[arr1+idx2[i]][arr2+idx1[i]] == 1 && visit[arr1+idx2[i]][arr2+idx1[i]] == 0) {
                visit[arr1+idx2[i]][arr2+idx1[i]] = 1;
                que.push(make_pair(make_pair(arr1+idx2[i],arr2+idx1[i]),count+1));
            }
        }
        
        
    }
}

void check_map(int left_x, int left_y, int right_x, int right_y){
    for(int i=left_x*2; i<= right_x*2; i++) {
        map[left_y*2][i] = map[right_y*2][i] = 1;
    }
    for(int i=left_y*2; i<= right_y*2; i++) {
        map[i][left_x*2] = map[i][right_x*2] = 1;
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    
    goal_x = itemX;
    goal_y = itemY;
    
    // 모든 사각형을 2배로 확장하여 맵에 그린다.
    for(int i=0; i<rectangle.size(); i++) {
        check_map(rectangle[i][0],rectangle[i][1],rectangle[i][2],rectangle[i][3]);
    }
    
    // 모든 사각형의 내부를 비워낸다.
    for(int k=0; k<rectangle.size(); k++) {
        // 사각형의 내부를 비우기 위한 이중 for문의 조건 설정
        for(int i=rectangle[k][1]*2+1; i<rectangle[k][3]*2; i++){
            for(int j=rectangle[k][0]*2+1; j<rectangle[k][2]*2; j++) {
                if (map[i][j] == 1) {
                    map[i][j] =0;
                }
            }
        }
    }
    
    
    // 좌표에 정상 그림 출력
    for(int i=0; i<101; i++) {
        for(int j=0; j<101; j++) {
            if (j%2 == 0 && i%2 ==0)
                cout << map[i][j];
        }
        if (i%2 == 0)
            cout << '\n';
    }
    
    cout << '\n';
    // 좌표에 두배 확대된 그림 출력
    for(int i=0; i<101; i++) {
        for(int j=0; j<101; j++) {
            cout << map[i][j];
                
        }
        cout << '\n';
    }
    
    //visit[characterX*2][characterY*2] = 1;
    bfs(characterX*2,characterY*2);
    
    answer = answer/2;
    
    return answer;
}