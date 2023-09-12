#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int answer = 0;
int col_check[9];
int last_col;
int max_size;
int visit[9];
int row_size;
int col_size;
vector<string> key;

void init_visit() {
    for(int i=0; i<=col_size; i++) {
        visit[i] = 0;
    }
}

void set_check(vector<vector<string>> relation) {
    cout << "set_check 입장!" << '\n';
    set<string> s;
    
    for(int i = 0; i<row_size; i++) {
        string str = "";
        for(int j = 0; j<col_size; j++) {
            if (visit[j] == 1) {
                //cout << "방문! : " << relation[i][j] << " ";
                str = str + " " + relation[i][j];
            }
        }
        cout << '\n' << str << '\n';
        s.insert(str);
    }
    if (s.size() == row_size) {
        string str2 = "";
        answer++;
        
        for(int i=0; i<col_size; i++) {
            if (visit[i] == 1) {
                cout << "col : " << i << '\n';
                //last_col--;
                //col_check[i] = 1;
                str2 += to_string(i);
            }
        }
        key.push_back(str2);
    }
}

void dfs(vector<vector<string>> relation, int count, int idx) {
    
    if (max_size == count) {
        string str = "";
        for(int i=0; i<col_size; i++) {
            if (visit[i] == 1) {
                str += to_string(i);
            }
        }
        for (int i=0; i<key.size(); i++) {
            int count = 0;
            for(int j=0; j<key[i].size(); j++) {
                if (str.find(key[i][j]) == string::npos) {

                }
                else {
                    count++;
                }
            }
            if (count == key[i].size()) {
                return;
            }
        }
        set_check(relation);
        return;
    }
    
    for(int i=idx; i<col_size; i++) {
        if (col_check[i] == 0 && visit[i] == 0) {
            visit[i] = 1;
            dfs(relation, count+1, i+1);
            visit[i] = 0;
        }
    }
    
}

int solution(vector<vector<string>> relation) {

    col_size = relation[0].size();
    row_size = relation.size();
    last_col = col_size;
    
    for(int i=0; i<col_size;i++) {
        set<string> s;
        for(int j=0; j<row_size; j++) {
            s.insert(relation[j][i]);
        }
        
        if (s.size() == row_size) {
            col_check[i] = 1;
            answer++;
            last_col--;
            key.push_back(to_string(i));
        }
        cout << s.size() << '\n';
    }
    cout << "last_col = " << last_col << '\n';
    for (int i=2; i<=last_col; i++) {
        max_size = i;
        dfs(relation, 0, 0);
        init_visit();
    }
    
    return answer;
}