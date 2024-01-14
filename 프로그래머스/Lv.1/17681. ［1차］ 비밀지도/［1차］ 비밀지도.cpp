#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    // arr1 체크
    for(int i=0; i<n; i++) {
        string str = "";
        for (int j=0; j<n; j++) {
            if (arr1[i]/2 != 0) {
                if (arr1[i]%2 == 1) {
                    str = "#" + str;
                }
                else {
                    str = " " + str;
                }
                arr1[i] = arr1[i]/2;
            }
            else {
                if (arr1[i]%2 == 1) {
                    str = "#" + str;
                    arr1[i] = 0;
                }
                else {
                    str = " " + str;
                }
            }
        }
        answer.push_back(str);
    }
    
    // arr2 체크
    for(int i=0; i<n; i++) {
        string str = "";
        for (int j=0; j<n; j++) {
            if (arr2[i]/2 != 0) {
                if (arr2[i]%2 == 1) {
                    str = "#" + str;
                }
                else {
                    str = " " + str;
                }
                arr2[i] = arr2[i]/2;
            }
            else {
                if (arr2[i]%2 == 1) {
                    str = "#" + str;
                    arr2[i] = 0;
                }
                else {
                    str = " " + str;
                }
            }
        }
        for(int k=0; k<n; k++) {
            if(answer[i][k] == ' ' && str[k] == '#'){
                answer[i][k] = '#';
            }
        }
    }
    
    return answer;
}