#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    int per_size = id_list.size();
    int re_size = report.size();
    int arr[1001][1001] = { 0, };
    int* stop;
    int* sol;

    stop = new int[1001];
    sol = new int[1001];

    for (int i = 0; i < 1001; i++) {
        stop[i] = 0;
        sol[i] = 0;
    }

    for (int i = 0; i < re_size; i++) {
        int idx1, idx2;
        string a = "";
        string b = "";
        int k = 0;
        for (; k < report[i].size(); k++) {
            if (report[i][k] != ' ')
                a.push_back(report[i][k]);
            else
                break;
        }
        ++k;
        for (; k < report[i].size(); k++) {
            b.push_back(report[i][k]);
        }

        //cout << a << "와"<< b << "입니다." << endl;

        idx1 = idx2 = 0;
        for (int j = 0; j < per_size; j++) {
            if (id_list[j].compare(a) == 0) {
                //cout << id_list[j] << "는 " << a << "와 같습니다."<<endl;
                idx1 = j;
            }
            if (id_list[j].compare(b) == 0) {
                //cout << id_list[j] << "는 " << b << "와 같습니다." << endl;
                idx2 = j;
            }
        }

        if (arr[idx1][idx2] != 1) {
            arr[idx1][idx2] = 1;
            ++stop[idx2];
        }
    }

    for (int i = 0; i < per_size; i++) {
        if (stop[i] >= k) {
            for (int j = 0; j < per_size; j++) {
                if (arr[j][i] == 1) {
                    ++sol[j];
                }
            }
        }
    }

    for (int i = 0; i < per_size; i++) {
        answer.push_back(sol[i]);
        //cout << sol[i] << endl;
    }

    delete[] stop;
    delete[] sol;

    return answer;
}