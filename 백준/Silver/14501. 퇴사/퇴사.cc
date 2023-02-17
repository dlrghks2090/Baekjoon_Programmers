#include<iostream>

using namespace std;

int N;
int sol = 0;
int T[16] = { 0, };
int P[16] = { 0, };

void dfs(int n, int total) {

	if (n > N) {
		if (sol < total) {
			sol = total;
			//cout << "n = " << n << " 일때 끝날때 들어온 total 값 : " << total << endl;
			return;
		}
	}
	
	for (int i = n; i <= N; i++) {
		if ((i - 1) + T[i] <= N) {
			dfs(i + T[i], total + P[i]);
		}
		else {
			if (sol < total) {
				sol = total;

				//cout << "n = " << n << " 일때 else에 들어온 total 값 : " << total << endl;
			}
		}
	}

}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> T[i + 1] >> P[i + 1];
	}

	dfs(1, 0);

	cout << sol;

	return 0;
}