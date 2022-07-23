#include<iostream>
#include<string>

using namespace std;

int main() {

	int x, y;
	string str[7] = { "SUN","MON", "TUE", "WED", "THU", "FRI", "SAT" };
	int count = 0;
	cin >> x >> y;

	for (int i = 1; i <= 12; i++) {
		if (x == 1) {
			cout << str[y % 7];
			break;
		}
		else {
			count += 31;
		}
		if (x == 2) {
			count = count + y;

			cout << str[count % 7];
			break;
		}
		else {
			count += 28;
		}
		if(x == 3) {
			count = count + y;
			cout << str[count % 7];
			break;
		}
		else {
		count += 31;
		}
		if (x == 4) {
			count = count + y;
			cout << str[count % 7];
			break;
		}
		else {
			count += 30;
		}
		if (x == 5) {
			count = count + y;
			cout << str[count % 7];
			break;
		}
		else {
			count += 31;
		}
		if (x == 6) {
			count = count + y;
			cout << str[count % 7];
			break;
		}
		else {
			count += 30;
		}
		if (x == 7) {
			count = count + y;
			cout << str[count % 7];
			break;
		}
		else {
			count += 31;
		}
		if (x == 8) {
			count = count + y;
			cout << str[count % 7];
			break;
		}
		else {
			count += 31;
		}
		if (x == 9) {
			count = count + y;
			cout << str[count % 7];
			break;
		}
		else {
			count += 30;
		}
		if (x == 10) {
			count = count + y;
			cout << str[count % 7];
			break;
		}
		else {
			count += 31;
		}
		if (x == 11) {
			count = count + y;
			cout << str[count % 7];
			break;
		}
		else {
			count += 30;
		}
		if (x == 12) {
			count = count + y;
			cout << str[count % 7];
			break;
		}
		else {
			count += 31;
		}

	}
	return 0;
}