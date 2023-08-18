#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int num = arr[0];
    
    answer.push_back(num);
    
    for (int i=1; i<arr.size(); i++) {
        if(arr[i] != num) {
            num = arr[i];
            answer.push_back(num);
        }
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}