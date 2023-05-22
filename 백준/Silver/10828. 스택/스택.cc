#include<iostream>
#include<vector>

using namespace std;

class Stack {

	int* buffer;
	const int size;
	int top;
	int count;
public:
	Stack(int size) :size(size) {
		buffer = new int[size];
		top = -1;
		count = 0;
	}
	~Stack() {
		delete[] buffer;
	}

	bool Push(int data) {

		if (IsFull()) {
			return false;
		}
		++count;
		++top;
		buffer[top] = data;

		return true;
	}

	int Pop() {
		if (IsEmpty()) {
			return -1;
		}
		--count;
		int re = buffer[top];
		--top;

		return re;

	}

	int Top() {

		if (IsEmpty())
			return -1;
		else
			return buffer[top];
	}
	int Count() {
		return count;
	}


	int IsEmpty() {

		return top == -1;
	}

	int IsFull() {
		return (top + 1) == size;
	}



};

int main() {

	int N;
	string* str;
	int put_num;
	vector <int> num;
	int num_idx = 0;
	cin >> N;
	str = new string[N];
	
	Stack st(N);

	for (int i = 0; i < N; i++) {
		cin >> str[i];
		if (str[i] == "push") {
			cin >> put_num;
			num.push_back(put_num);
			
		}
		
	}
	/*
	cout << "--------여기서 부터 확인 입니다.------" << '\n';
	for (int i = 0; i < N; i++) {
		cout << str[i] << '\n';
	}


	cout << "--------여기서 부터 출력 입니다.------" << '\n';
	*/
	num_idx = 0;
	for (int i = 0; i < N; i++) {
		if (str[i] == "push") {
			st.Push(num[num_idx]);
			num_idx += 1;
		}
		else if (str[i] == "top") {
			cout << st.Top() << '\n';
		}
		else if (str[i] == "pop") {
			cout << st.Pop() << '\n';
		}
		else if (str[i] == "size") {
			cout << st.Count() << '\n';
		}
		else if (str[i] == "empty") {
			cout << st.IsEmpty() << '\n';
		}

	}


	return 0;
}