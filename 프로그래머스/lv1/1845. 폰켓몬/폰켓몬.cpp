#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int visit[200001] = {0,};
    
    for(int i = 0; i<nums.size(); i++) {
        if (visit[nums[i]] == 0 && answer < nums.size()/2) {
            visit[nums[i]] = 1;
            answer++;
        }
    }
    
    return answer;
}