#include<iostream>

using namespace std;

int main() {

	int n;
	int arr[1001] = { 0, };		// 상자의 크기를 적은 배열
	int dp[1001] = { 0, };		// 현재 상자까지 넣을 수 있는 최대 상자의 수를 저장시킬 배열
	int sol = 0;				// 한줄에 넣을 수 있는 최대의 상자 개수를 넣는 변수


	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	fill_n(dp, 1001, 1);	// 넣을 수 있는 상자의 수는 항상 자기자신을 포함시키기때문에 1개이상이므로 1로 초기화시킨다.


	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i]) {
				if (dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
				}
			}
		}
		if (dp[i] > sol) {
			sol = dp[i];
		}
	}

	cout << sol;



	return 0;
}