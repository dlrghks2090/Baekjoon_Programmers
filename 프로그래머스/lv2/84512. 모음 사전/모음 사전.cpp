// 프로그래머스_LV2_완전탐색(DFS)_모음사전

/*
    풀이>
    1. DFS를 사용해 a,e,i,o,u 로 만든 단어들의 사전을 만들었다.
    2. algorithm 라이브러리에서 제공하는 find함수르 입력으로 들어오는 word 문자열의 위치를 찾아 메모리 주소를 반환한다.


*/


#include <string>
#include <vector>
#include <algorithm>
//#include <iostream>

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
    
    // idx는 v.begin()을 기준으로 몇 번째 위치에 있는지가 저장된다.
    auto idx = find(v.begin(), v.end(), word);    
    
    // 따라서 answer 에는 idx - v.begin() 처럼 시작점을 빼주어야 해당 위치의 값을 구할 수 있다.
    answer = idx - v.begin() + 1;
    
    return answer;
}