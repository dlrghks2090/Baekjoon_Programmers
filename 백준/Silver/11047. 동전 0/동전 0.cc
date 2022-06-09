#include<iostream>

using namespace std;

int main() {

	int N, K;
	int* arr;
	int tmp = 0;
	int sol = 0;

	cin >> N >> K;
	arr = new int[N+1];
	tmp = K;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = N - 1; i >= 0; i--) {
		if (tmp / arr[i] != 0) {
			sol += tmp / arr[i];
			tmp = tmp % arr[i];
		}
	}

	cout << sol;

	delete[] arr;
	return 0;
}