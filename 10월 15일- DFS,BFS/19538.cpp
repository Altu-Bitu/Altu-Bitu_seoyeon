#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> adj_list; //인접리스트



//BFS : 너비 우선 탐색
vector<int> bfs(int n, vector<int> distributors) {
	queue<int> q;
	vector<int> dp(n + 1, -1); // dp배열에 처음 루머를 믿게 된 시간 저장.
	vector<int> believer(n + 1, 0); // 주변인들이 몇 명 믿는지

	for (int i = 0; i<distributors.size(); i++) {

		q.push(distributors[i]);
		dp[distributors[i]] = 0; //소문 최초 유포자는 처음(t=0)부터 루머를 믿기 시작함.
	}


	//탐색 시작
	while (!q.empty()) {

		
		
		int current = q.front(); //현재 탐색하려는 노드
		int time = dp[current]; // 현재 사람이 루머 믿은 시각.
		q.pop();
		
		/*for (int i = 1; i <= n; i++) {
			cout << dp[i] << ' ';
		}
		cout << current<<'\n';*/

		//인접리스트로 검사
		for (int i = 0; i < adj_list[current].size(); i++) { // current의 주변인만 탐색.

			int rumoree = adj_list[current][i]; // 소문을 퍼뜨릴 대상자 
			believer[rumoree]++; //rumoree의 주변에서 루머를 믿는 사람 증가


			if (dp[rumoree] == -1)  //소문을 믿지 않는 사람이라면
			{
				if (believer[rumoree] * 2 >= adj_list[rumoree].size()) // 주변인 중 절반 이상의 사람들이 믿을때
				{
					dp[rumoree] = time + 1; // 소문을 믿게 된다. 
					q.push(rumoree);

				}
			}

		}
	}
	return dp;
}

	

/**
1. 1 -> 2 연결이면 2->1 도 무조건 연결되어있음에 유의하기! 
2.  dp배열에 처음 루머를 믿게 된 시간 저장하기
3. 방문 체크를 탐색할 때 바로 하는 게 아니라, 루머를 믿게 될 경우 하는 게 중요!!

-1 : 루머를 믿지 않는 상태 / n : 루머를 믿기 시작한 시간

ex) 예제 입력 1
[dp배열]

-1 -1 -1 -1 -1 -1 -1
 0 -1 -1 -1 -1  0 -1
 0  1 -1 -1 -1  0 -1
 0  1  2 -1 -1  0 -1
 0  1  2  3  -1 0 -1
 0  1  2  3  4  0 -1



*/


int main() {

	int n;
	cin >> n;

	
	adj_list.assign(n + 1, vector<int>()); 
	

		int t;
	for (int i = 1; i <= n; i++) {
		
		cin >> t;
		while (t) // 입력값이 0이 아닐동안만 입력받기.
		{
			adj_list[i].push_back(t);
			cin >> t;
		} 

	}
		
	int m; //최초 유포자의 수
	cin >> m;
	vector<int> distributors(m,0);
	
	
	for(int i=0;i<m;i++){

		cin>>distributors[i];
	}



	vector<int> solution = bfs(n, distributors);

	for (int i = 1; i <= n; i++) {
		cout << solution[i]<<' ';
	}




}