#include <string>
#include <vector>

using namespace std;

int visit[1000001];

int solution(int n) {
    int answer = 0;
    int count = 0;
    
    for(int i=2; i<=n; i++) {
        if (visit[i] == 0) {
            answer++;
            for(int j=2; i*j <= n; j++) {
                visit[i*j] = 1;
            }
        }
    }
    return answer;
}