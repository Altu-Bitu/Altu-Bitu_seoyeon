#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main() {


	
	queue <int> q;
	int n;

	//입력
	cin >> n;
	for (int i = 1; i <= n; i++)
		q.push(i);

	while (q.size() >1) {

		q.pop(); //카드를 한장 버린다.
		q.push(q.front()); //맨 위의 카드를 제일 아래에 있는 카드 밑으로 옮긴다.

		q.pop();//맨 위의 카드를 없앤다.


	}

	cout << q.front();

}