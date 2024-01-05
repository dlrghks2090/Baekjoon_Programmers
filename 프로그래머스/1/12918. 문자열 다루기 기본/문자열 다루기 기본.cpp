#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int count=0;
    
    for(int i=0; i<s.size(); i++) {
        if (s[i] < '0' || '9' < s[i]) {
            return false;
        }
        count++;
    }
    if(count == 4 || count == 6) {
        return answer;
    }
    else
        return false;
}