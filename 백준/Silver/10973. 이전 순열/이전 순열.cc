#include<iostream>
#include<algorithm>

using namespace std;


bool desc(int a, int b) {
	return a > b;
}

int main() {

	int N;
	int* arr;
	int point = 0;
	int flag = 0;
	int camp = 10001 ;
	int point_2 = 0;
	int tmp2 = 0;
	int tmp;

	cin >> N;
	arr = new int[N];
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i < N; i++) {
		if (arr[N - i] < arr[N - i - 1]) {
			point = N - i - 1;
			flag = 1;
			break;
		}
	}

	if (flag == 0) {
		cout << -1 << endl;
		return 0;
	}
	
	point_2 = point;
	for (int i = point + 1; i < N; i++) {
		if (arr[point] > arr[i]) {
			if (arr[i] > tmp2) {
				point_2 = i;
				tmp2 = arr[i];
			}
		}
	}

	//cout << "기준점: " << arr[point] << endl;
	//cout << "바꿀 값" << arr[point_2] << endl;

	tmp = arr[point];
	arr[point] = arr[point_2];
	arr[point_2] = tmp;

	/*for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;*/

	sort(arr + point + 1, arr + N, desc);

	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
		
	delete[] arr;

	return 0;
}


//  1234  1243  1324  1342 