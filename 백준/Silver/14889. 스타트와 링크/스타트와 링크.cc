#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

int N;
int sol = 10000000;
int map[22][22] = { 0, };
int arr[22] = { 0, };

void calcul();

void dfs(int n, int count) {

	if (count > N / 2) {
		calcul();
		return;
	}
	
	for (int i = n; i <= N; i++) {
		arr[count] = i;
		dfs(i + 1, count + 1);
	}

}

void calcul() {
	int arr2[22] = { 0, };
	int num = 1;
	int arr_num = 1;

	int arr_sum = 0;
	int arr2_sum = 0;

	int result = 0;

	for (int i = 1; i <= N; i++) {
		if (arr[arr_num] == i) {
			arr_num++;
		}
		else {
			arr2[num] = i;
			num++;
		}
	}

	for (int i = 1; i <= N / 2; i++) {
		for (int j = 1; j <= N / 2; j++) {
			if (i == j) {
				continue;
			}

			arr_sum += map[arr[i]][arr[j]];
			arr2_sum += map[arr2[i]][arr2[j]];
		}
	}

	result = abs(arr_sum - arr2_sum);

	if (sol > result) {
		sol = result;
	}

}

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	dfs(1, 1);
	
	cout << sol;


	return 0;
}