#include <iostream>
#include <queue>

using namespace std;



struct cmp {
	bool operator()(int a, int b) {

		if (abs(a) == abs(b)) //절댓값이 같다면
			return a > b; //크기가 작은순서대로 (sort함수와 반대)

		return abs(a) > abs(b);//절댓값이 작은 순서대로

	}
	
};




int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int n; //연산수

	priority_queue <int, vector<int>, cmp> pq;

	cin >> n; 

	while (n--) {


		int x; //2^31은 딱 INT_MAX범위
		cin >> x;

		if (x == 0) { //0일경우 

			if (pq.empty()) //우선순위큐가 비었다면 0출력 
				cout << 0 << '\n';

			else { //우선순위큐가 비지 않았다면
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else //0이 아닌값이 들어올경우
			pq.push(x);
		
	}

}