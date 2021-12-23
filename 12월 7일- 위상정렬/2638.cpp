#include<iostream>
#include<vector>

using namespace std;
/*
치즈가 없는 공간이라고 해도 외부 공기와 접촉한 곳과 아닌 곳의 차이가 있어요. 
외부 공간과 내부 공간을 어떻게 구분해야 할까요? 치즈가 녹다보면 새로운 외부 공간이 생기기도 할거예요. 
각각의 시간마다 녹을 수 있는 치즈들은 모두 동시에 녹아야 한다는 것 잊지 마세요.

매 시간 경과마다 bfs 돌려서 외부 공간 표시하기

내부공간 : 1 
외부공간 :-1

*/

//상하 좌우

int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,-1,1 };
int n, m;
vector <vector<int>> map;

// 외부공간을 -1로 표시.
void dfs(int r,int c) {

	if (r >= n || c >= m || map[r][c] == -1) //범위를 벗어나거나 이미 확인한 곳이라면
		return; 

	map[r][c] == -1; //방문체크

	//상하좌우 탐색.
	for (int i = 0; i < 4; i++) {
		dfs(r+dr[i],c+dc[i]);

	}
}
//(r,c) 가 외부와 접촉해있는면이 2면 이상인지 판단.
bool contact(int r,int c) {
	int cnt = 0; //접촉해있는 면 개수

	// 상하좌우
	for (int i = 0; i < 4; i++) {

		if ((r + dr[i] >= m) || (c + dc[i] >= n)) //범위를 벗어난다면
			continue;

		if (map[r + dr[i]][r + dc[i]] == -1) //외부와 접촉
			cnt++;
	}

	if (cnt >= 2)
		return true;
	else
		return false;
}

//모든 치즈가 녹아서 없어졌는지 판단. 
bool isAllMelt() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (map[i][j] != 0)
				return false;
		}
	}

	return true;
		

}

int melt(int n,int m) {

	int t = 0; //경과시간
	while (true) {

		

		dfs(0, 0); // 외부공간 -1로 표시 


		// 다음 턴에 녹는 치즈위치를 2로 표시해두기
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				if (map[i][j] == 1) {

					if (contact(i,j))
						map[i][j] = 2;


				}
			}
		}

	
		
		// 2로 표시된 치즈 한번에 녹이기
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				if (map[i][j] == 2) {
					map[i][j] = 0;

				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				cout << map[i][j];
			}

			cout << "\n";
		}
		t++;
		if (isAllMelt())
			break;

	}


	return t;

}


int main() {

	cin >> n >> m;
	map.assign(n, vector<int>(m, 0));


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	cout << melt(n, m);

	
}