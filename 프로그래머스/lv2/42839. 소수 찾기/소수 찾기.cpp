#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int answer = 0;
int visit[10000000];
map<int,int> m;


void dfs(string numbers, string num) {
    
    int count = 0;
    
    for(int i=0; i<numbers.size(); i++) {
        if (visit[i] == 0) {
            int n = stoi(num+numbers[i]);
            cout << num+numbers[i] << '\n';
            for(int i=2; i<=n/2; i++) {
                if (n%i == 0) {
                    count++;
                    break;
                }
            }
            if (count == 0 && n > 1){
                m.insert({n, 1});
                cout << "소수 : " << n << '\n';
            }
            visit[i] = 1;
            dfs(numbers,num+numbers[i]);
            visit[i] = 0;
        }
        count = 0;
    }
}

int solution(string numbers) {
    
    dfs(numbers, "");
    
    answer = m.size();
    
    return answer;
}