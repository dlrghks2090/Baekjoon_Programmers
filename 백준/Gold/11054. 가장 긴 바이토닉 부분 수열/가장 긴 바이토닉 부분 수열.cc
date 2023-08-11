#include<iostream>

using namespace std;

int main() {

	int N;
	int arr[1001] = { 0, };
	int dp1[1001] = { 0, };
	int dp2[1001] = { 0, };
	int sol = 0;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	dp1[1] = 1;

	for (int i = 2; i <= N; i++) {
		dp1[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp1[i] < dp1[j] + 1) {
					dp1[i] = dp1[j] + 1;
				}
			}
		}
	}

	dp2[N] = 1;

	for (int i = N-1; i >= 1; i--) {
		dp2[i] = 1;
		for (int j = N; j > i; j--) {
			if (arr[j] < arr[i]) {
				if (dp2[j] + 1 > dp2[i]) {
					dp2[i] = dp2[j] + 1;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (sol < dp1[i] + dp2[i]) {
			sol = dp1[i] + dp2[i];
		}
	}

	cout << sol - 1;

	return 0;
}