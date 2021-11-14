#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci; // 노드번호로의 가중치
const int INF = 1e5 * 2; //최대 V-1개의 간선(2000) * 가중치 (10)

//다익스트라
vector<int> dijkstra(int vertex, int start, vector<vector<ci>>& graph) { // 정점의 개수, 시작점, 연결리스트
    vector<int> dist(vertex + 1, INF); // 특정 정점까지의 최단경로 저장.
    priority_queue<ci, vector<ci>, greater<>> pq; //first : 시작점으로부터의 거리, second : 정점. minheap

    //시작 위치 초기화
    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {

        int weight = pq.top().first; // 시작점 ~ 우선순위큐 탑에있는 노드 까지의 거리
        int node = pq.top().second;
        pq.pop();

        // 이미 확인했던 정점 ex) 노드 4까지의 최단거리가 7->4로 갱신되면 우선순위 큐에 두번 push가 일어남.(중복)
        // (7,4) -> (5,4)  dist[4] = 5 로 갱신된채로 존재
        // 따라서 (7,4) 를 만났을때  7 > 5 로 가중치가 더 크므로 무시하고 나중에 (5,4)를 기준으로 정보를 활용해야함.

        if (weight > dist[node])  // 이부분을 빼먹으면 시간초과
            continue;
        for (int i = 0; i < graph[node].size(); i++) { //node로부터 연결된 정점 확인

            int next_node = graph[node][i].first; //연결된 정점
            int next_weight = weight + graph[node][i].second; //시작점으로부터 연결된 정점까지의 거리
            if (dist[next_node] > next_weight) { //더 짧은 경로로 갈 수 있다면
                dist[next_node] = next_weight;
                pq.push({ next_weight, next_node });
            }
        }
    }
    return dist;
}

int main() {
    int vertex, edge, k, u, v, w;

    //입력
    cin >> vertex >> edge >> k;
    vector<vector<ci>> graph(vertex + 1, vector<ci>(0)); //인접 리스트
    while (edge--) {
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w); //방향 그래프: u -> v로 가는 가중치 w의 간선이 존재.
    }

    //연산
    vector<int> ans = dijkstra(vertex, k, graph);

    //출력
    for (int i = 1; i <= vertex; i++) {
        if (ans[i] == INF)
            cout << "INF";
        else
            cout << ans[i];
        cout << '\n';
    }
}