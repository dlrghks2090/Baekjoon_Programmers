#include<iostream>

using namespace std;

int N;
int T[16] = { 0, };
int P[16] = { 0, };

int sol = 0;

void dfs(int idx, int total, int pre_val) {

	if (idx > N) {
		if (idx == N + 1) {
			total += pre_val;
		}
		if (sol < total) {
			sol = total;
		}
		return;
	}

	for (int i = idx; i <= N; i++) {
		//cout << total + pre_val << '\n';
		dfs(i+ T[i], total+pre_val, P[i]);
	}

}




int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}

	dfs(1, 0, 0);

	cout << sol;

	return 0;
}