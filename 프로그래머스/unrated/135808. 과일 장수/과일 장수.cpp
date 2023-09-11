#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int v_size;
    int count;
    
    // 오름차순으로 정렬
    sort(score.begin(), score.end());
    // 내림차순으로 만들기 위해 뒤집기함수 사용
    reverse(score.begin(), score.end());
    
    v_size = score.size();
    
    count = v_size/m;
    
    for (int i=1; i<=count; i++) {
        answer += m*score[m*i-1];
    }
    
    return answer;
}