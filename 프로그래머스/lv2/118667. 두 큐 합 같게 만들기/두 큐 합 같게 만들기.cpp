#include <string>
#include <vector>

using namespace std;


int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    vector<int> v;
    
    int s1 = 0;
    int e1 = queue1.size()-1;
    int s2 = queue1.size();
    int e2 = queue1.size()*2-1;
    
    int size = queue1.size()*2;
    long long sum1 = 0, sum2 = 0;
    
    for(int i=0; i<queue1.size(); i++) {
        v.push_back(queue1[i]);
        sum1 += queue1[i];
    }
    
    for(int i=0; i<queue2.size(); i++) {
        v.push_back(queue2[i]);
        sum2 += queue2[i];
    }
    
    while(answer <= size*2) {
        if (sum1 < sum2) {
            sum1 += v[(++e1)%size];
            sum2 -= v[(s2++)%size];
        }
        else if(sum1 > sum2) {
            sum1 -= v[(s1++)%size];
            sum2 += v[(++e2%size)];
        }
        else {
            return answer;
        }
        answer++;
    }
    
    return -1;
}