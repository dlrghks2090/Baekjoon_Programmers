#include <string>
#include <vector>
#include <iostream>

using namespace std;

int visit[26];

void init_visit(int n) {
    for(int i=1; i<=n; i++) {
        visit[i] = 0;
    }
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int idx;
    int flag=0;
    int count;
    visit[0] = 1;
    
    
    for (int i=0; i<skill_trees.size(); i++) {
        idx=-1;
        flag=0;
        count = 0;
        init_visit(skill.size());
        
        for(int j=0; j<skill_trees[i].size(); j++) {
            for(int k=1; k<=skill.size(); k++) {
                if (skill_trees[i][j] == skill[k-1]) {
                    if (idx < k && visit[k-1] == 1) {
                        idx = k;
                        visit[k] = 1;
                        cout << "k= " << k << " skill= " << skill[k-1] << '\n';
                        break;
                    } 
                    flag=1;
                    cout << "k= " << k << " skill= " << skill[k-1] << '\n';
                    break;
                    
                }
            }
            if (flag == 1) {
                break;
            }
            count++;
        }
        if (count == skill_trees[i].size()) {
            answer++;
            cout << "성공: " << skill_trees[i] << '\n';
        }
        else {
            cout << "실패: " << skill_trees[i] << '\n';
        }
        
        
    }
    return answer;
}