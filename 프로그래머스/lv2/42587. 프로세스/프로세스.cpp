#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<pair<int,int>> pr;
    
    for (int i = 0; i<priorities.size(); i++) {
        if (i == location ) {
            pr.push_back(make_pair(priorities[i], 1));
        }
        else {
            pr.push_back(make_pair(priorities[i], 0));
        }
    }
    
    while(1) {
        int count = 0;
        for(int i = 1; i<pr.size(); i++) {
            if (pr[0].first < pr[i].first){
                ++count;
                break;
            }
        }
        if (count == 0) {
            ++answer;
            if (pr[0].second == 1) {
                return answer;
            }
            
            pr.pop_front();
        }
        else {
            pr.push_back(pr.front());
            pr.pop_front();
        }
    }
    return answer;
}