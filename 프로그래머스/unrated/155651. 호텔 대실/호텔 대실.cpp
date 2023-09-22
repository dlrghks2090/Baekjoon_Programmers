#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp1(vector<string> a, vector<string> b) {
    
    return a[0] < b[0];
}
bool cmp2(vector<string> a, vector<string> b) {
    return a[1] < b[1];
}

int minus_time(string a, string b) {
    int hour = stoi(a.substr(0,2)) - stoi(b.substr(0,2));
    int min = hour*60 + stoi(a.substr(3,2)) - stoi(b.substr(3,2));
    
    return min;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<vector<string>> v;
    int flag = 0;
    
    
    sort(book_time.begin(), book_time.end(), cmp1);
    
    v.push_back(book_time[0]);
    
    for(int i=1; i<book_time.size(); i++) {
        int book_start;
        string b_str;
        int v_end;
        string v_str;
        
        b_str = book_time[i][0].substr(0,2) + book_time[i][0].substr(3,2);
        book_start = stoi(b_str);
        for(int j=0; j<v.size(); j++) {
            
            v_str = v[j][1].substr(0,2) + v[j][1].substr(3,2);
            v_end = stoi(v_str);
            if (minus_time(book_time[i][0], v[j][1]) >= 10) {
                v[j][1] = book_time[i][1];
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            v.push_back(book_time[i]);
        }
        flag = 0;
        sort(v.begin(), v.end(), cmp2);
    }
    
    answer = v.size();
    
    return answer;
}