#include <string>
#include <vector>

using namespace std;

vector<int> answer;

void dfs(const vector<vector<int>>& arr, int num, int idx1, int idx2) {
     
    int ele = arr[idx1][idx2];
    int flag = 0;
    
    for(int i=idx1; i<idx1+num; i++) {
        for(int j=idx2; j<idx2+num; j++) {
            if (ele != arr[i][j]) {
                flag = 1;
                break;
            }
        }
    }
    
    if (flag == 0) {
        if(ele == 0) {
            answer[0]++;
        }
        else {
            answer[1]++;
        }
        return;
    }
    else {
        for(int i=idx1; i<idx1+num; i = i+num/2) {
            for (int j=idx2; j<idx2+num; j = j+num/2) {
                dfs(arr, num/2, i, j);
            }
        }
    }
}

vector<int> solution(vector<vector<int>> arr) {
    
    answer.push_back(0);
    answer.push_back(0);
    
    dfs(arr, arr.size(),0,0);
    
    return answer;
}