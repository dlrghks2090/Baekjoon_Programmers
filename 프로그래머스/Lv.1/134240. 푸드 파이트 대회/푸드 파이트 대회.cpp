#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    stack<char> stk;
    
    for(int i=1; i<food.size(); i++) {
        for(int j=1; j<= food[i]/2; j++) {
            answer.push_back(i+'0');
            stk.push(i+'0');
        }
    }
    answer.push_back('0');
    while(!stk.empty()) {
        answer.push_back(stk.top());
        stk.pop();
    }
    
    return answer;
}