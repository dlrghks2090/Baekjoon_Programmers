#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    int day;
    int count = 0;
    
    for(int i=0; i<progresses.size(); i++) {
        count =0;
        while((progresses[i] + speeds[i]*count) < 100) {
            ++count;
        }
        days.push_back(count);
    }
    
    day = days[0];
    count = 1;
    for(int i = 1; i<days.size(); i++) {
        if(day >= days[i]) {
            count++;
        }
        else {
            answer.push_back(count);
            day = days[i];
            count = 1;
        }
    }
    answer.push_back(count);
    
    return answer;
}