
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci; // 노드번호로의 가중치
const int INF = 1e5 * 2; // 최대 V-1개의 간선(2000) * 가중치 (10)


 //상, 하, 좌, 우,
int dr[8] = { 1, -1, 0, 0  };
int dc[8] = { 0, 0, -1, 1 };

/* 디버깅용
void print_dist(vector< vector<int> > dist, int n) {

    //출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j];
        }
        cout << '\n';
    }
    cout << '\n';


}
*/

// 다익스트라: 하나의 시작점 -> 모든 정점 까지의 최단경로
vector< vector<int> > dijkstra(int n, vector <vector<int>> map) { // 동굴크기 , 연결리스트

    vector< vector<int> > dist(n + 1, vector<int>(n+1,INF)); // 특정 정점까지의 최소금액 저장.

    priority_queue<pair <int ,ci>, vector<pair <int, ci>>, greater<>> pq; //first : 해당 정점까지의 최소금액, second : 정점. 
 
    dist[0][0] = map[0][0]; //시작 금액 초기화



    pq.push({ map[0][0],ci(0,0)});

   
    while (!pq.empty()) {

       // print_dist(dist, n);

        int weight = pq.top().first; // 시작점 ~ 우선순위큐 탑에있는 노드 까지의 거리
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();


        if (weight > dist[r][c])  // 같은 정점을 방문하는 것 막기
            continue;

       
        for (int i = 0; i < 4; i++) { // 상 하 좌 우 길 탐색 (현재 정점으로부터 연결된 정점 확인)
           
            int nr = r + dr[i]; 
            int nc = c + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
               
                int next_weight = weight + map[nr][nc]; //시작점으로부터 연결된 정점까지의 거리

               
                if (dist[nr][nc] > next_weight) { //더 최소금액을 잃고 갈 수 있다면
                   
                    dist[nr][nc] = next_weight;
                    pq.push({ next_weight, ci(nr,nc) });
                }

            }

        }
       
    }
    return dist;
}
 
int main() {

	int n;

    int i = 1;
    while (true) {


   
	cin >> n;

    if (!n)
        break;

	vector <vector<int>> map(n, vector<int>(n,0));


	//입력
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

    vector< vector<int> > ans = dijkstra(n, map);
    cout << "Problem " << i++ << ": " << ans[n - 1][n - 1]<<'\n';  

    }
}