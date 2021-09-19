#include <iostream>
#include <queue>


using namespace std;


long long card_sum(priority_queue <long long, vector<long long>, greater<long long>>& q) {

	long long sum = 0;
	while (!q.empty())
	{
		sum += q.top();
		q.pop();

	}

	return sum;
}

// 카드가 지닐수 있는 최댓값 ? a_max(1,000,000) 가 1000장, 카드합체 15000번 일때 . 
// 카드합체 500번마다 a에 담긴 값이 전부 두배 증가하므로 15000번 카드놀이후에는 30번의 두배증가를 겪고 각카드에 최대 1,000,000 * (2^30) 이 담김
//  따라서 long long 이용해야함


// Q. 2 30 1,000,000 1,000,000 은 제대로 된 값이 출력되지 않는데 맞았다고 뜸.

int main() {


	priority_queue <long long, vector<long long>, greater<long long>> q; //최소힙 

	//주어진 숫자를 우선순위 큐에 넣고 제일작은 값 두개를 꺼내어 더한다음 그 값으로 두번 push해줌.

	int n, m; //카드수 ,카드합체수

	cin >> n >> m;

	//카드 초기 상태 우선순위 큐에 저장.
	while (n--) {

		int c;
		cin >> c;

		q.push(c);

	}

	//m번의 카드합체 
	while (m--) {

		long long a = q.top();
		q.pop();

		long long b = q.top();
		q.pop();

		long long sum = a + b;
		q.push(sum); q.push(sum); // 카드 두 장 모두에 덮어쓴다.


	}


	cout << card_sum(q);
}