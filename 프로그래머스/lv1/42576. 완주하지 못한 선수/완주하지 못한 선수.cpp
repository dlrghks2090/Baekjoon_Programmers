#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> hash_map;
    
    for(int i = 0; i<completion.size(); i++) {
        if (hash_map.find(completion[i]) == hash_map.end()) {
            hash_map.insert(make_pair(completion[i], 1));
        }
        else{
            hash_map[completion[i]]++;
        }
    }
    
    for(int i = 0; i<participant.size(); i++) {
        if (hash_map.find(participant[i]) == hash_map.end()) {
            return participant[i];
        }
        else {
            if (hash_map[participant[i]] == 0) {
                return participant[i];
            }
            else {
                hash_map[participant[i]]--;
            }
        }
    }
    
    return answer;
}