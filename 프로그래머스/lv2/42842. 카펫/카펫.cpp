#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int x,y;
    int total;
    
    for(int i=1; i<= yellow/i; i++) {
        if (yellow%i == 0) {
            x = yellow/i;
            y = i;
            total = x*2 + y*2 + 4;
            if (brown == total) {
                cout << "x= " << x << "  y= " << y << '\n';
                answer.push_back(x+2);
                answer.push_back(y+2);
                break;
            }
        }
    }
    return answer;
}