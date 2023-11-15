#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> tmp;
    
    for(int i=0; i<operations.size(); i++) {
        string str;
        istringstream ss(operations[i]);
        
        getline(ss, str, ' ');
        if(str == "D") {
            getline(ss, str, ' ');
            if (stoi(str) == 1 && !tmp.empty()) {
                tmp.pop_back();
            }
            else if (stoi(str) == -1 && !tmp.empty()) {
                tmp.pop_front();
            }
        }
        else if (str == "I") {
            getline(ss, str, ' ');
            tmp.push_back(stoi(str));
            sort(tmp.begin(),tmp.end());
        }
    }
    
    if (tmp.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(tmp.back());
        answer.push_back(tmp.front());
    }
    
    return answer;
}