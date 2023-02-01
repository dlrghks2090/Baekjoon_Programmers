#include<iostream>

using namespace std;

int N;
int K;
int arr[11] = { 0, };
int sol = 0;

int main() {

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = N - 1; i >= 0; i--) {
		if (K / arr[i] != 0) {
			sol += K / arr[i];
			K = K % arr[i];
		}

		if (K == 0) {
			break;
		}
	}

	cout << sol;


	return 0;
}