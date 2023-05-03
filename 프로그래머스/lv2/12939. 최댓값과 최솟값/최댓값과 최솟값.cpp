#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    stringstream num(s);
    string tmp;
    int min, max;
    int min_flag =0;
    int max_flag =0;
    
    while(num >> tmp) {
        if (min_flag !=0) {
            if (stoi(tmp) < min) {
                min = stoi(tmp);
            }
        }
        else {
            min = stoi(tmp);
            min_flag = 1;
        }
        
        if (max_flag!=0) {
            if (stoi(tmp) > max) {
                max = stoi(tmp);
            }
        }
        else {
            max = stoi(tmp);
            max_flag = 1;
        }
    }
    
    answer = to_string(min) + " " + to_string(max);
    
    return answer;
}