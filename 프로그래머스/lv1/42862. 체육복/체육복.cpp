#include <string>
#include <vector>
#include <iostream>

using namespace std;

void init_arr(int n, int* arr){
    
    for (int i=1; i<=n; i++) {
        arr[i] =1;
    }
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    int* arr = new int[n+2] {0,};
    
    init_arr(n, arr);
    
    //cout << arr[0] <<  " " << arr[3];
    
    for(int i=0; i<lost.size(); i++) {
        arr[lost[i]] -= 1;
    }
    
    for(int i=0; i<reserve.size(); i++) {
        arr[reserve[i]] += 1;
    }
    
    for(int i=1; i<=n; i++) {
        cout << i+1 <<" 번째 수 = " << arr[i+1] << '\n';
        if(arr[i] == 0) {
            if (arr[i-1] == 1) {
                answer++;
                arr[i-1]--;
            }
            else if(arr[i+1] == 2){
                answer++;
                arr[i+1]--;
            }
            else {
                continue;
            }
        }
        else {
            answer++;
            arr[i]--;
        }
    }
    
    delete[] arr;
    return answer;
}