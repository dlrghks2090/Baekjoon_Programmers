#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    int id_size = new_id.size();
    int an_size;

    for (int i = 0; i < id_size; i++) {
        if (new_id[i] >= 65 && new_id[i] <= 90) {
            answer.push_back(new_id[i] + 32);
        }
        else if (new_id[i] >= 97 && new_id[i] <= 122) {
            answer.push_back(new_id[i]);
        }
        else if (new_id[i] >= '0' && new_id[i] <= '9') {
            answer.push_back(new_id[i]);
        }
        else if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') {
            answer.push_back(new_id[i]);
        }
    }


    for (int i = 0; i < answer.size() - 1; i++) {
        if (answer[i] == '.' && answer[i + 1] == '.') {
            answer.erase(i, 1);
            --i;
        }
    }

    if (answer[0] == '.')
        answer.erase(0, 1);
    if (answer[answer.size() - 1] == '.')
        answer.pop_back();
    
    if (answer.empty())
        answer.push_back('a');

    if (answer.size() >= 16) {
        answer.erase(15, answer.size());
        while (answer[answer.size() - 1] == '.') {
            answer.pop_back();
        }
    }

    if (answer.size() <= 2) {
        while (answer.size() < 3) {
            answer.push_back(answer[answer.size() - 1]);
        }
    }
    

    return answer;
}