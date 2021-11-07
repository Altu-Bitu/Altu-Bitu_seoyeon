#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 200001

int dp[MAX] = { 0, }; // 방문체크 + 이동횟수 저장

// n <= 2k 일 경우에는 거리를 가깝게 하기 위해 우선 2*n 이동.
// 아니라면 x-1,x+1,2x 를 모두 큐에 넣음. 

//BFS : 너비 우선 탐색 
int bfs(int n, int k) {

	

	queue <int> q; // 수빈이의 위치 경우의수 저장 큐 


	q.push(n);
	dp[n] = true;

	//전처리
	
	//1. n <<< k 인경우
	while(2 * q.front() <=  k)
	{
		
		int temp = q.front();
		q.pop();
		q.push(2 * temp);
		dp[2 * temp] = dp[temp]+1;
	}

	//2.  n>k인경우
	if (n > k)
		return n - k;// -쪽으로 n-k번 움직이면 됨.

	// 큐에 하나의 원소만 남은채로 시작.

		while (!q.empty()) {

			
			if (dp[k])
				return dp[k]-1;

			int current = q.front();
				q.pop();

				int temp;

				temp = current - 1;

				if (dp[temp] == 0 && temp >=0)
				{	
					
					q.push(temp); cout << temp <<' ';
					dp[temp] = dp[current] + 1;

				}
				temp = current + 1;
				if (dp[temp] == 0 && temp <= MAX-1)
				{
					q.push(temp); cout << temp << ' ';
					dp[temp] = dp[current] + 1;

				}
				temp = 2 * current ;
				if (dp[2 * current] == 0 && temp <= MAX - 1)
				{
					q.push(temp); cout << temp << ' ';
					dp[temp] = dp[current] + 1;

				}
	
		}

	}



		


int main() {

	 
	int n, k; 


	cin >> n >> k;

	cout << bfs(n, k);
	
	

}