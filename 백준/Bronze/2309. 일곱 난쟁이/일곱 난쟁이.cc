#include<iostream>
#include<algorithm>

using namespace std;

int sol[7] = { 0, };
int sum_all = 0;
int final_sol[7] = { 0, };

void back(int* arr, int arr_idx, int sol_idx) {
	sum_all = 0;


	for (int i = 0; i < 7; i++) {
		sum_all += sol[i];
	}
	if (sum_all == 100) {

		if (sol_idx == 7) {
			sort(sol, sol + 7);
			copy(sol, sol + 7, final_sol);
			return;
		}
	}

	for (int j = arr_idx; j < 9; j++) {
		sol[sol_idx] = arr[j];
		back(arr, j + 1, sol_idx + 1);
	}
}


int main() {
	
	int arr[9] = { 0, };

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}
	back(arr, 0, 0);
	sort(sol, sol + 7);

	for (int i = 0; i < 7; i++) {
		cout << final_sol[i] << '\n';
	}
	return 0;
}