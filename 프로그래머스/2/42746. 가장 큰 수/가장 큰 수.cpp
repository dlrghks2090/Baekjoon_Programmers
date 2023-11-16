#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    string s1="";
    string s2="";
    
    s1 = to_string(a);
    s2 = to_string(b);
    
    if (s1+s2 > s2+s1) {
        return true;
    }
    else {
        return false;
    }
}

string solution(vector<int> numbers) {
    string answer = "";
    int flag = 0;
    
    sort(numbers.begin(),numbers.end(),cmp);
    
    for(int i=0; i<numbers.size(); i++) {
        if (numbers[i] == 0) {
            if (flag == 1) {
                answer += to_string(numbers[i]);
            }
        }
        else {
            flag = 1;
            answer += to_string(numbers[i]);
        }
        //cout << numbers[i] << " ";
    }
    
    if (answer == "") {
        answer += "0";
    }
    
    
    return answer;
}