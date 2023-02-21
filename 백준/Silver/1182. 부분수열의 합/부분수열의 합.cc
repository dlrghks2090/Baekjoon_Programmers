#include<iostream>

using namespace std;

int N, S;
int map[22] = { 0, };
int arr[22] = { 0, };
int sol = 0;

void dfs(int num, int count) {

	if (count != 0) {
		int total = 0;

		for (int k = 1; k <= count; k++) {
			total += arr[k];
		}

		//cout << "count : " << count << "  total : " << total << '\n';

		if (total == S) {
			sol++;
		}
	}

	for (int i = num; i <= N; i++) {
		arr[count + 1] = map[i];
		dfs(i + 1, count + 1);
	}

}

int main() {

	cin >> N >> S;

	for (int i = 1; i <= N; i++) {
		cin >> map[i];
	}

	dfs(1, 0);

	cout << sol;


	return 0;
}