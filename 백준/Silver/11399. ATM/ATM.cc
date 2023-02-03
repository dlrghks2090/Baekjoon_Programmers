#include<iostream>
#include<algorithm>

using namespace std;

int N;
int sol = 0;
int arr[1001] = { 0, };


int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	sort(arr + 1, arr + 1 + N);

	for (int i = 1; i <= N; i++) {
		sol += arr[i] * (N + 1 - i);
	}

	cout << sol;

	return 0;
}