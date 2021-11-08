#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e7; //최대비용 = 이동비용(100,000) * 도시의개수(100)

//플로이드-워셜
void floydWarshall(int n, vector<vector<int>>& graph) {

    // 정점 i -> j 로의 거리를 찾음.

    for (int k = 1; k <= n; k++) { // k : 거치는 정점
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                // Q. 모든 노드를 확인하나..? i=j 인경우나 i=k or j=k인 경우는 이미 k를 포함하므로 필요없지 않은가?

                // 둘중 하나가 INF라면 dist는 INF보다 커진다! -> 그러나 이미 INF로 초기화시켜두었기때문에 고려되지 x
                int dist = graph[i][k] + graph[k][j]; //중간에 k를 거쳐서 i에서 j로 감
                graph[i][j] = min(graph[i][j], dist); //i->j와 i->k->j 중 더 짧은 경로
            }
        }
    }
}

int main() {
    int n, m, a, b, c;

    //입력
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF)); // [i][j] 크기의 가중치 배열
    for (int i = 1; i <= n; i++) //자기 자신과의 거리
        graph[i][i] = 0;

    while (m--) {
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c); //중복 간선이 들어올 수 있으므로 최솟값 사용
       // ex) 1->2를 잇는 가중치 3의 간선 , 1->2를 잇는 가중치 5의 간선 => 최솟값 사용!
    }

    //연산
    floydWarshall(n, graph);

    //출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << ((graph[i][j] == INF) ? 0 : graph[i][j]) << ' '; // 경로가 없으면 0을 출력
        cout << '\n';
    }
}