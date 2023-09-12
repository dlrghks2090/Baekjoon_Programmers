#include <string>
#include <iostream>

using namespace std;

int solution(string dirs) {
    
    int arr[11][11][4] = {0,};
    int answer = 0;
    int x = 5;
    int y = 5;
    
    for(int i=0; i<dirs.size(); i++) {
        //cout << dirs[i] << '\n';
        if(dirs[i] == 'U' && y+1 < 11) {
            y +=1;
            if (arr[x][y][1] == 0) {
                arr[x][y][1] = 1;
                arr[x][y-1][0] = 1;
                answer++;
            }
        }
        else if (dirs[i] == 'D' && y-1 > -1) {
            y -=1;
            if (arr[x][y][0] == 0) {
                arr[x][y][0] = 1;
                arr[x][y+1][1] = 1;
                answer++;
            }
        }
        else if (dirs[i] == 'R' && x+1 < 11) {
            x += 1;
            if (arr[x][y][3] == 0) {
                arr[x][y][3] = 1;
                arr[x - 1][y][2] = 1;
                answer++;
            }
        }
        else if (dirs[i] == 'L' && x-1 > -1) {
            x -= 1;
            //cout << arr[x][y][2] << '\n';
            if (arr[x][y][2] == 0) {
                //cout << arr[x][y][2] << '\n';
                arr[x][y][2] = 1;
                arr[x + 1][y][3] = 1;
                answer++;
            }
        }
        //cout << "x: " << x << " y: " << y << '\n';
        //cout << "sol= " << answer <<'\n';
    }
    
    return answer;
}