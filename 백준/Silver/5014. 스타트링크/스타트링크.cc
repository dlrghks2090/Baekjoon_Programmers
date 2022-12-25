#include<iostream>
#include<queue>

using namespace std;

// F: 최고층,  S: 현재 층,  G: 스타트링크가 있는 층,  U: 위로 U만큼 이동하는 버튼,  D: 아래로 D만큼 이동하는 버튼
int F, S, G, U, D;
int sol = -1;
int visit[10000002] = { 0, };

void bfs(int num) {

	pair<int, int> p;
	queue<pair<int, int>> que;

	p.first = num;
	p.second = 0;
	que.push(p);
	visit[num] = 1;

	while (1) {
		pair<int, int> p2;

		if (que.empty() == true) {
			//cout << "큐가 비었다." << endl;
			break;
		}
		if (que.front().first == G) {
			sol = que.front().second;
			break;
		}
		
		

		p.first = que.front().first;
		p.second = que.front().second;

		/*cout << "현재 층 : " << p.first << endl;
		cout << "이동 횟수 : " << p.second << endl;*/
		que.pop();

		if (p.first + U <= F && visit[p.first + U] == 0) {
			p2.first = p.first + U;
			p2.second = p.second + 1;
			que.push(p2);
			visit[p2.first] = 1;
		}
		if (p.first - D >= 1 && visit[p.first - D] == 0) {
			p2.first = p.first - D;
			p2.second = p.second + 1;
			que.push(p2);
			visit[p2.first] = 1;
		}
	}

}

int main() {

	cin >> F >> S >> G >> U >> D;

	bfs(S);

	if (sol == -1) {
		cout << "use the stairs";
	}
	else {
		cout << sol;
	}

	return 0;
}