#include <string>
#include <vector>

using namespace std;

int arr[21] = {0,};
int target_ = 0;
int answer = 0;


void dfs(vector<int> numbers, int idx, int sum_of_num) {
    if (idx == numbers.size()){
        if (sum_of_num == target_) {
            answer++;
        }
        return;
    }
    
    dfs(numbers, idx+1, sum_of_num + numbers[idx]);
    dfs(numbers, idx+1, sum_of_num - numbers[idx]);
}

int solution(vector<int> numbers, int target) {
    target_ = target;
    
    dfs(numbers, 0, 0);
    
    return answer;
}