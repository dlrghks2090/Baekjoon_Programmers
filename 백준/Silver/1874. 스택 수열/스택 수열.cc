#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {

	stack<int> s;
	int n;
	vector<char> c;
	int num = 1;

	cin >> n;
	vector<int> v(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> v[i];

	}
	s.push(num);
	c.push_back('+');

	for (int i = 0; i < n; i++) {
		//cout << i << " 번째 수를 위한 연산" << '\n';
		while (1) {
			if (s.empty()) {
				num = num + 1;
				//cout << num << " push" << '\n';
				s.push(num);
				c.push_back('+');
			}
			else if (s.top() < v[i]) {
				num = num + 1;
				if (num > n) {
					cout << "NO";
					return 0;
				}
				
				//cout << num << " push" << '\n';
				s.push(num);
				c.push_back('+');
			}
			else if (s.top() == v[i]) {
				//cout << s.top() << " pop" << '\n';
				s.pop();
				c.push_back('-');
				break;
			}
			else {
				cout << "NO";
				return 0;
			}
		}
	}

	for (int i = 0; i < c.size(); i++) {
		cout << c[i] << '\n';
	}
	


	return 0; 
}