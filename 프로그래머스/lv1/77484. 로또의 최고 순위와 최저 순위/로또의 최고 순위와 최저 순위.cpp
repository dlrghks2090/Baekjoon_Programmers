#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int count = 0;
    int zero = 0;
    
    for (int i = 0; i<lottos.size(); i++) {
        for (int j = 0; j<win_nums.size(); j++) {
            if (win_nums[j] == lottos[i]) {
                count++;
                break;
            }
            else if (lottos[i] == 0) {
                zero++;
                break;
            }
        }
    }
    
    // 최대 등수
    if (count + zero == 6) {
        answer.push_back(1);
    }
    else if (count + zero == 5) {
        answer.push_back(2);
    }
    else if (count + zero == 4) {
        answer.push_back(3);
    }
    else if (count + zero == 3) {
        answer.push_back(4);
    }
    else if (count + zero == 2) {
        answer.push_back(5);
    }
    else {
        answer.push_back(6);
    }
    
    // 최소 등수
    if (count == 6) {
        answer.push_back(1);
    }
    else if (count == 5) {
        answer.push_back(2);
    }
    else if (count == 4) {
        answer.push_back(3);
    }
    else if (count == 3) {
        answer.push_back(4);
    }
    else if (count == 2) {
        answer.push_back(5);
    }
    else {
        answer.push_back(6);
    }
    
    return answer;
}