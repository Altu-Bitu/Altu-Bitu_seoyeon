#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> adj_list; //인접리스트



//BFS : 너비 우선 탐색
vector<int> bfs(int n, vector<int> distributors) {
    queue<int> q;
    vector<int> dp(n + 1, -1); //dp배열에 처음 루머를 믿게 된 시간 저장.
	

	for (int i = 0; distributors.size(); i++) {

		q.push(distributors[i]);
		dp[distributors[i]] = 0; //소문 최초 유포자는 처음부터 루머를 믿기 시작함.
	}
   
    

    //탐색 시작
    while (!q.empty()) {
        int current = q.front(); //현재 탐색하려는 노드
        q.pop();      
      
        //인접리스트로 검사

        for (int i = 0; i < adj_list[current].size(); i++) { // current의 주변인만 탐색.
			
			
            if (dp[adj_list[current][i]]==-1) { //소문을 아직 믿지 않는 사람이라면 

				int total = adj_list[i].size();
				// 주변인의 절반이상이 루머를 믿고 있다면
                dp[adj_list[current][i]] = dp[current]+1;
                q.push(adj_list[current][i]);
            }
        }
        
    }

	return dp;

}
/*

-1 : 루머를 믿지 않는 상태 / n : 루머를 믿기 시작한 시간

-1 0 0 0 0 -1 0
-1 -1 0 0 0 0 0



*/


int main() {

	int n;
	cin >> n;

	
	adj_list.assign(n + 1, vector<int>()); 
	

		int t;
	for (int i = 0; i < n; i++) {
		
		cin >> t;
		while (t); // 0이 아닐동안만 입력받기.
		{
			adj_list[i].push_back(t);
			cin >> t;
		} 

	}
		
	int m; //최초 유포자의 수

	vector<int> distributors(m);
	
	
	for(int i=0;i<m;i++){

		cin>>distributors[i];
	}



	vector<int> solution = bfs(n, distributors);

	for (int i = 0; i < solution.size(); i++) {
		cout << solution[i];
	}




}