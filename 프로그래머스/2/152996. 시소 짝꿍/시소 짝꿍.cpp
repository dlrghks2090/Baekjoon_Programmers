#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long answer = 0;
int arr[3] = {2,3,4};

void check(int n1, int n2) {
    
    if (n1 == n2) {
        answer++;
        return;
    }
    
    for(int i=0; i<2; i++) {
        for (int j=i+1; j<3; j++) {
            if(n2*arr[i] == n1*arr[j]) {
                answer++;
                return;
            }
        }
    }
    
}


long long solution(vector<int> weights) {
    
    sort(weights.begin(), weights.end());
    
    for(int i=0; i < weights.size()-1; i++) {
        for(int j=i+1; j<weights.size(); j++) {
            check(weights[i], weights[j]);
        }
    }
    return answer;
}