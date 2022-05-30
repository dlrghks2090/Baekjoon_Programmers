#include<iostream>

using namespace std;

void search(int* arr, int* flag, int total) {
	for (int i = 1; i < 9; i++) {
		for (int j = i + 1; j <= 9; j++) {
			if (total - (arr[i] + arr[j]) == 100) {
				flag[i] = flag[j] = 1;
				return;
			}
		}
	}

}

int main() {

	int arr[10] = { 0, };
	int flag[10] = { 0, };
	int total = 0;

	for (int i = 1; i <= 9; i++) {
		cin >> arr[i];
		total += arr[i];
	}

	search(arr, flag, total);

	for (int i = 1; i <= 9; i++) {
		if (flag[i] == 0) {
			cout << arr[i] << endl;
		}
	}



	return 0;
}