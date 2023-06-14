#include<iostream>

using namespace std;

int N;
int arr[9] = { 0, };
int visit[9] = { 0, };
int sol[9] = { 0, };
int s = 0;

void dfs(int count) {
	if (count == N) {
		int tmp = 0;

		for (int i = 1; i < N; i++) {
			tmp += abs(sol[i] - sol[i + 1]);
		}

		if (s < tmp) {
			s = tmp;
		}
	}

	for (int i = 1; i <= N; i++) {

		if (visit[i] != 1) {
			sol[count+1] = arr[i];
			visit[i] = 1;
			dfs(count + 1);
			visit[i] = 0;
		}
	}

}

int main() {


	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	dfs(0);

	cout << s;

	return 0;
}