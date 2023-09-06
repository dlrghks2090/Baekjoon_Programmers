#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int map[101][101];
int count =1;
int visit[101];

void dfs(int idx, int n){
    
    for(int i=1; i<=n; i++) {
        if (map[idx][i] == 1 && visit[i] == 0) {
            count++;
            visit[i] = 1;
            dfs(i, n);
            visit[i] = 0;
        }
    }
    
}

void init_visit(int n) {
    for(int i = 1; i<=n; i++) {
        visit[i] = 0;
    }
}

// wires_rows는 2차원 배열 wires의 행 길이, wires_cols는 2차원 배열 wires의 열 길이입니다.
// row = 간선의 수 , col = 2
int solution(int n, int** wires, size_t wires_rows, size_t wires_cols) {
    int answer = 10000;
    int diffsol;
    
    // 간선정보로 송전탑간의 연결 표시
    for(int i=0; i<wires_rows; i++) {
        map[wires[i][0]][wires[i][1]] = map[wires[i][1]][wires[i][0]] = 1;
    }
    
    for(int i=0; i<wires_rows; i++) {
        map[wires[i][0]][wires[i][1]] = map[wires[i][1]][wires[i][0]] = 0;
        visit[wires[i][0]] = 1;
        dfs(wires[i][0], n);
        map[wires[i][0]][wires[i][1]] = map[wires[i][1]][wires[i][0]] = 1;
        
        diffsol = abs((n-count)-count);
        if (answer > diffsol ) {
            answer = diffsol;
        }
        count = 1;
        init_visit(n);
    }
    
    return answer;
}