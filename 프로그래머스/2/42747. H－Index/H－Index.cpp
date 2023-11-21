#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int v_size = citations.size();
    int count = 0;
    
    sort(citations.begin(), citations.end());
    reverse(citations.begin(), citations.end());
    
    while(1) {
        count = 0;
        for(int i=0; i<v_size; i++) {
            if (answer > citations[i]) {
                break;
            }
            
            count++;
        }
        if (count < answer) {
            return answer-1;
        }
        answer++;
    }
    
    return answer;
}