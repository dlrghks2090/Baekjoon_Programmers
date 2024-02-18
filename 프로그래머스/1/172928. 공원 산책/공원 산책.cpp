#include <string>
#include <vector>
#include <iostream>

using namespace std;


vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer {0,0};
    
    
    // 시작점 세팅
    for (int i=0; i<park.size(); i++) {
        for (int j=0; j<park[0].size(); j++) {
            if (park[i][j] == 'S') {
                answer[0] = i;
                answer[1] = j;
                break;
            }
        }
    }
    
    cout << "시작점 = " << answer[0] << " " << answer[1] << '\n';
    
    // 최종 도착지점 찾기
    for(int i=0; i<routes.size(); i++) {
        int num = routes[i][2] -'0';
        int tmp=0;
        
        
        if(routes[i][0] == 'E') {
            tmp = answer[1];
            for (int j = 0; j < num; j++) {
                if (answer[1]+1 < park[0].size() && park[answer[0]][answer[1]+1] != 'X') {
                    cout << "오른쪽으로 1만큼 이동 ";
                    ++answer[1];
                }
                else{
                    cout << "지금까지 이동 취소";
                    answer[1] = tmp;
                    break;
                }
            }
        }
        else if(routes[i][0] == 'W') {
            tmp = answer[1];
            for (int j = 0; j < num; j++) {
                if (answer[1]-1 >= 0 && park[answer[0]][answer[1]-1] != 'X') {
                    cout << "오른쪽으로 -1만큼 이동 ";
                    --answer[1];
                }
                else{
                    cout << "지금까지 이동 취소";
                    answer[1] = tmp;
                    break;
                }
            }
        }
        else if(routes[i][0] == 'S') {
            tmp = answer[0];
            for (int j = 0; j < num; j++) {
                if (answer[0]+1 < park.size() && park[answer[0]+1][answer[1]] == 'O') {
                    cout << "왼쪽으로 1만큼 이동 ";
                    ++answer[0];
                }
                else{
                    cout << "지금까지 이동 취소";
                    answer[0] = tmp;
                    break;
                }
            }
        }
        else if(routes[i][0] == 'N') {
            tmp = answer[0];
            for (int j = 0; j < num; j++) {
                if (answer[0]-1 >= 0 && park[answer[0]-1][answer[1]] != 'X') {
                    cout << "왼쪽으로 -1만큼 이동 ";
                    --answer[0];
                }
                else{
                    cout << "지금까지 이동 취소";
                    answer[0] = tmp;
                    break;
                }
            }
        }
        // 이동위치 확인
        cout << answer[0] << " " << answer[1] << '\n';
    }
    
    return answer;
}