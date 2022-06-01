#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int arr1[10] = { 0, };
	int arr2[10] = { 0, };

	int sol1 = 0;
	int sol2 = 0;

	for (int i = 0; i < 10; i++) {
		cin >> arr1[i];
	}

	for (int i = 0; i < 10; i++) {
		cin >> arr2[i];
	}

	sort(arr1, arr1 + 10);
	sort(arr2, arr2 + 10);

	sol1 = arr1[7] + arr1[8] + arr1[9];
	sol2 = arr2[7] + arr2[8] + arr2[9];

	cout << sol1 << " " << sol2;


	return 0;
}