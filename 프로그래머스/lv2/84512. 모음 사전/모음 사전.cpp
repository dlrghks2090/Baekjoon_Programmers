#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> v;

void dfs(char* arr, string str, int count) {
    
    if (count > 4) {
        return;
    }
    
    for (int i=0;i<5; i++) {
        v.push_back(str+arr[i]);
        dfs(arr,str+arr[i], count+1);
    }
}

int solution(string word) {
    int answer = 0;
    char arr[] = {'A', 'E', 'I', 'O', 'U'};
    
    dfs(arr, "", 0);
    
    auto idx = find(v.begin(), v.end(), word);
    
    answer = idx - v.begin() + 1;
    
    return answer;
}