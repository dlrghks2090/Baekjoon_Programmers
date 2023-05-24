#include<iostream>
#include<vector>

using namespace std;

int main() {

	int N;
	vector<int> que;
	vector<int> sol;
	string str;
	int num;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "push") {
			cin >> num;
			que.push_back(num);
		}
		else if (str == "pop") {
			if (que.size() == 0) {
				sol.push_back(-1);
			}
			else {
				sol.push_back(que[0]);
				que.erase(que.begin());
			}
		}
		else if (str == "size") {
			sol.push_back(que.size());
		}
		else if (str == "empty") {
			if (que.size() == 0) {
				sol.push_back(1);
			}
			else {
				sol.push_back(0);
			}
		}
		else if (str == "front") {
			if (que.size() == 0) {
				sol.push_back(-1);
			}
			else {
				sol.push_back(que[0]);
			}
		}
		else if (str == "back") {
			if (que.size() == 0) {
				sol.push_back(-1);
			}
			else {
				sol.push_back(que[que.size() - 1]);
			}
		}
	}

	for (int i = 0; i < sol.size(); i++) {
		cout << sol[i] << '\n';
	}

	return 0;
}