#include<iostream>
#include<algorithm>

using namespace std;

int N, M;
int arr[7] = { 0, };
int sol[7] = { 0, };

void dfs(int count) {

	if (count == M) {
		for (int i = 0; i < M; i++) {
			cout << sol[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		sol[count] = arr[i];
		dfs(count + 1);
	}


}

int main() {


	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	dfs(0);


	return 0;
}