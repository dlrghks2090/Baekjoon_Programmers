#include <string>
#include <vector>
#include <iostream>

using namespace std;

int idx1_size,idx2_size;


int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer=0;   // 답을 반환할 변수
    
    idx1_size = board.size();   // 보드의 행의 크기
    idx2_size = board[0].size();    // 보드의 열의 크기
    
    vector<vector<int>> tmp(idx1_size+1, vector<int>(idx2_size+1,0));
    
    // 누적합을 적용할 맵을 그리는 로직
    for(int i=0; i<skill.size(); i++) {
        // 건물의 내구도를 낮출때
        if (skill[i][0] == 1) {
            tmp[skill[i][1]][skill[i][2]] = tmp[skill[i][1]][skill[i][2]] - skill[i][5];
            tmp[skill[i][3]+1][skill[i][4]+1] = tmp[skill[i][3]+1][skill[i][4]+1] - skill[i][5];
            tmp[skill[i][1]][skill[i][4]+1] = tmp[skill[i][1]][skill[i][4]+1] + skill[i][5];
            tmp[skill[i][3]+1][skill[i][2]] = tmp[skill[i][3]+1][skill[i][2]] + skill[i][5];
        }
        // 건물의 내구도를 높일때
        else {
            tmp[skill[i][1]][skill[i][2]] += skill[i][5];
            tmp[skill[i][3]+1][skill[i][4]+1] += skill[i][5];
            tmp[skill[i][1]][skill[i][4]+1] = tmp[skill[i][1]][skill[i][4]+1] - skill[i][5];
            tmp[skill[i][3]+1][skill[i][2]] = tmp[skill[i][3]+1][skill[i][2]] - skill[i][5];
        }
    }
    
    
    for(int i=0; i<=idx2_size; i++) {
        for(int j=0; j<idx1_size;j++) {
            tmp[j+1][i] += tmp[j][i];
        }
    }
    
    for(int i=0; i<=idx1_size; i++) {
        for(int j=0; j<idx2_size;j++) {
            tmp[i][j+1] += tmp[i][j];
        }
    }
    
    for(int i=0; i<idx1_size; i++) {
        for(int j=0; j<idx2_size;j++) {
            //cout << board[i][j] + tmp[i][j] << " ";
            if (0 < board[i][j] + tmp[i][j]) {
                answer++;
            }
        }
        //cout << '\n';
    }
    
    
    return answer;
}
