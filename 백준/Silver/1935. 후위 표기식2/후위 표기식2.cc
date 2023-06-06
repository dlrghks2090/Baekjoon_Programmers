#include<iostream>
#include<string>
#include<stack>

using namespace std;

int arr[26] = { 0, };

int main() {

	int N;
	string str;
	stack<double> st;

	cin >> N;
	cin >> str;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < str.size(); i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			st.push((double)(arr[(str[i]-'0') - ('A'-'0')]));
		}
		else {
			double a, b;

			b = st.top();
			st.pop();

			a = st.top();
			st.pop();

			if (str[i] == '+') {
				st.push(a + (double)b);
			}
			else if (str[i] == '-') {
				st.push(a - (double)b);
			}
			else if (str[i] == '*') {
				st.push(a * (double)b);
			}
			else if (str[i] == '/') {
				st.push(a / (double)b);
			}
		}
	}

	cout.setf(ios::fixed);
	cout.precision(2);
	cout << st.top();

	return 0;
}