#include<iostream>
#include<cstdlib>

using namespace std;

int N;
int sol = 10000000;
int map[22][22] = { 0, };
int arr[22] = { 0, };

void calcul(int count);

void dfs(int n, int count) {

	if (count == N) {
		return;
	}

	if (count != 0) {

		/*cout << "멤버 : ";
		for (int i = 1; i <= count; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;

		cout << "====== 총 count 수 : " << count << endl;*/
		calcul(count);
	}

	for (int i = n; i <= N; i++) {

		arr[count + 1] = i;
		dfs(i + 1, count + 1);
	}

}

void calcul(int count) {
	int arr2[22] = { 0, };
	int num = 1;
	int flag = 0;

	int arr_sum = 0;
	int arr2_sum = 0;

	int result = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= count; j++) {
			if (arr[j] == i) {
				flag = 1;
			}
		}
		if (flag == 0) {
			arr2[num] = i;
			num++;
		}
		flag = 0;
	}

	for (int i = 1; i <= count; i++) {
		for (int j = 1; j <= count; j++) {
			if (i == j) {
				
			}
			else {
				arr_sum += map[arr[i]][arr[j]];
			}
		}
	}

	for (int i = 1; i <= N - count; i++) {
		for (int j = 1; j <= N - count; j++) {
			if (i == j) {
				
			}
			else {
				arr2_sum += map[arr2[i]][arr2[j]];
			}
		}
	}

	result = abs(arr_sum - arr2_sum);

	//cout << "++++++ result 답 : " << result << endl;

	if (sol > result) {
		sol = result;
	}

	//cout << "!!!!! 갱신된 최종 답 : " << sol << endl;

}

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	dfs(1, 0);

	cout << sol;


	return 0;
}