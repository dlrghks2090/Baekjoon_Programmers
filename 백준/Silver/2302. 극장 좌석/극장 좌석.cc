#include<iostream>

using namespace std;

int main() {

	int N;
	int M;
	int arr[41] = { 0, };
	int dp[41] = { 0, };

	cin >> N;
	cin >> M;

	for (int i = 1; i <= M; i++) {
		cin >> arr[i];
	} 

	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		int flag = 0;

		for (int j = 1; j <= M; j++) {
			if (arr[j] == i) {
				flag = 1;
				dp[i] = dp[i - 1];
				break;
			}
			else if (arr[j] == i - 1) {
				flag = 1;
				dp[i] = dp[i - 1];
				break;
			}
		}

		if (flag == 0) {
			dp[i] = dp[i-1] + dp[i-2];
		}

		//cout << i<< "번째 dp :" << dp[i] << endl;
	}


	cout << dp[N];

	return 0;
}