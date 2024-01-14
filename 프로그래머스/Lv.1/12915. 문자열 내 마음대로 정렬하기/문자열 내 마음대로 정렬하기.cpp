#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int idx;

bool comp(string str1, string str2) {
    if (str1[idx] < str2[idx]) {
        return true;
    }
    else if(str1[idx] > str2[idx]) {
        return false;
    }
    else {
        return str1 < str2;
    }
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    idx = n;
    
    sort(strings.begin(), strings.end(), comp);
    
    for(int i=0; i<strings.size(); i++) {
        answer.push_back(strings[i]);
    }
    return answer;
}