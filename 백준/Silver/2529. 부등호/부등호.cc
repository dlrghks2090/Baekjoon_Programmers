#include<iostream>
#include<string>

using namespace std;

int k;
char map[11] = { 0, };
int arr[12] = { 0, };
long long sol_max = 0;
long long sol_min = 10000000000;
int judge_start = 1;

int success = 0;

void calcul(int count) {
	long long total = 0;

	for (int i = 1; i <= count; i++) {
		total = 10 * total + arr[i];
	}

	if (total > sol_max) {
		sol_max = total;
	}

	if (total < sol_min) {
		sol_min = total;
	}
}

void dfs(int count) {

	if (count == k + 1) {

		/*for (int aa = 1; aa <= count; aa++) {
			cout << arr[aa] << " ";
		}*/
		//cout << endl;
		calcul(count);
		return;
	}

	

	for (int i = 0; i <= 9; i++) {

		int flag = 0;

		for (int j = 1; j <= count; j++) {
			if (arr[j] == i) {
				flag = 1;
				break;
			}
		}

		if (flag == 1) {
			continue;
		}

		if (count != 0) {

			//cout << "count = " << count << endl;
			//cout << "해당 map = " << map[count] << endl;
			//cout << "arr[count] = " << arr[count] << " i = " << i << endl;

			if (map[count] == '>') {
				if (arr[count] < i) {
					continue;
				}
			}

			if (map[count] == '<') {
				if (arr[count] > i) {
					continue;
				}
			}
		}

		arr[count + 1] = i;

		dfs(count + 1);
	}

}

void start_set() {
	for (int i = 0; i < k; i++) {
		judge_start *= 10;
	}
}

int main() {

	cin >> k;

	for (int i = 1; i <= k; i++) {
		cin >> map[i];
	}

	start_set();

	dfs(0);

	if (sol_max / judge_start == 0) {
		cout << "0" << sol_max << endl;
	}
	else {
		cout << sol_max << endl;
	}

	if (sol_min / judge_start == 0) {
		cout << "0" << sol_min << endl;
	}
	else {
		cout << sol_min << endl;
	}


	return 0;
}