#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> arr(26,-1);
    
    for(int i=0; i<s.size(); i++) {
        if (arr[s[i] - 'a'] == -1) {
            answer.push_back(-1);
            arr[s[i] - 'a'] = i;
        }
        else {
            answer.push_back(i-arr[s[i] - 'a']);
            arr[s[i] - 'a'] = i;
        }
    }
    return answer;
}