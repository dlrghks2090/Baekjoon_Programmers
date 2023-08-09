#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main() {

	int N;
	int arr[1001] = { 0, };
	int dp[1001][2] = { 0, };
	stack<int> st;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	dp[1][1] = 1;
	dp[1][0] = 1;

	if (N == 1) {
		cout << 1 << '\n';
		cout << arr[1];
		return 0;
	}

	for (int i = 2; i <= N; i++) {
		dp[i][0] = i;
		dp[i][1] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i]) {
				if (dp[i][1] < dp[j][1] + 1) {
					dp[i][1] = dp[j][1] + 1;
					dp[i][0] = j;
				}
			}
		}

		if (dp[0][1] < dp[i][1]) {
			dp[0][1] = dp[i][1];
			dp[0][0] = i;
		}
	}

	int idx = dp[0][0];

	while (1) {
		st.push(arr[idx]);

		if (dp[idx][0] == idx) {
			break;
		}
		idx = dp[idx][0];
	}

	cout << dp[0][1] << '\n';
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}


	return 0;
}