#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;
	string sol = "";

	for (int i = 0; i < s.size(); i++) {
		
		if ('0' <= s[i] && s[i] <= '9') {
			sol.push_back(s[i]);
		}
		else {
			if (s.find("zero") == i) {
				sol.push_back('0');
				s[i] = '0';
				i = i + 3;
				s[i] = '0';
			}
			else if (s.find("one") == i) {
				sol.push_back('1');
				s[i] = '0';
				i = i + 2;
				s[i] = '0';
			}
			else if (s.find("two") == i) {
				sol.push_back('2');
				s[i] = '0';
				i = i + 2;
				s[i] = '0';
			}
			else if (s.find("three") == i) {
				sol.push_back('3');
				s[i] = '0';
				i = i + 4;
				s[i] = '0';
			}
			else if (s.find("four") == i) {
				sol.push_back('4');
				s[i] = '0';
				i = i + 3;
				s[i] = '0';
			}
			else if (s.find("five") == i) {
				sol.push_back('5');
				s[i] = '0';
				i = i + 3;
				s[i] = '0';

			}
			else if (s.find("six") == i) {
				sol.push_back('6');
				s[i] = '0';
				i = i + 2;
				s[i] = '0';
			}
			else if (s.find("seven") == i) {
				sol.push_back('7');
				s[i] = '0';
				i = i + 4;
				s[i] = '0';
			}
			else if (s.find("eight") == i) {
				sol.push_back('8');
				s[i] = '0';
				i = i + 4;
				s[i] = '0';
			}
			else if (s.find("nine") == i) {
				sol.push_back('9');
				s[i] = '0';
				i = i + 3;
				s[i] = '0';
			}
		}
	}
	answer = stoi(sol);
	return answer;
}