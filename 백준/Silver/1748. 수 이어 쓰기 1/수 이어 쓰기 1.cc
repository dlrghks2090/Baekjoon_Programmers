#include<iostream>

using namespace std;

int main() {

	long long N;
	long long pre_num = 0;
	long long num = 9;
	long long sol = 0;
	long long count = 1;

	cin >> N;

	while(1) {
		if (N <= num) {
			sol = sol + (N - pre_num) * count;
			break;
		}
		else {
			sol = sol + (num - pre_num) * count;
		}
		count++;
		pre_num = num;
		num = num * 10 + 9;
	}

	cout << sol;


	return 0;
}