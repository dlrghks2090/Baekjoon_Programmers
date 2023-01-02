#include <string>
#include <vector>
#include <queue>
#include <iostream>>

using namespace std;

string start_str = "";
string target_str = "";
int visit[51] = {0,};
int sol = 0;
int answer = 51;

void bfs(vector<string> words) {
    queue<pair<int,int>> que;
    pair<int,int> p;
    int idx = 0;
    int count = 0;
    int n;
    
    
    for(int i = 0; i<words.size(); i++) {
        n = 0;
        for(int j=0; j<start_str.size(); j++) {
            if (start_str[j] != words[i][j])
                n++;
        }
        if (n == 1 && visit[i] == 0){
            p.first = i;
            p.second = count + 1;
            que.push(p);
            visit[i] = 1;
            //cout << "현재 단어: " << start_str << "   다음 단어: " << words[i] << "    건너온 개수 : " << count << '\n';
        }
    }
    
    while(1) {
        if (que.empty() == true) {
            break;
        }
        idx = que.front().first;
        count = que.front().second;
        que.pop();
        
        if (words[idx] == target_str) {
            if (answer > count)
                answer = count;
            break;
        }
        
        for(int i = 0; i<words.size(); i++) {
            n = 0;
            start_str = "";
            start_str += words[idx];
            for(int j=0; j<start_str.size(); j++) {
                if (start_str[j] != words[i][j])
                    n++;
            }
            if (n == 1 && visit[i] == 0){
                p.first = i;
                p.second = count + 1;
                que.push(p);
                visit[i] = 1;
                cout << "현재 단어: " << start_str << "   다음 단어: " << words[i] << "    건너온 개수 : " << count << '\n';
            }
        }
    }

}

int solution(string begin, string target, vector<string> words) {
    
    int n = 0;
    start_str += begin;
    target_str += target;
    
    for(int i=0; i<words.size(); i++) {
        if(words[i] == target) {
            n++;
        }
    }
    if (n == 0) {
        return 0;
    }
    //cout << start_str.size() << '\n';
    bfs(words);
    
    if (answer == 51) {
        return 0;
    }
    
    return answer;
}