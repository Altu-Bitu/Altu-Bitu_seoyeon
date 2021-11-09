#include <iostream>
#include <vector>
#include <map>
#include<queue>

using namespace std;

//1. 파티장가는길
// v-1번 다익스트라.
//2. 돌아가는길
// X를 시작점으로 다익스트라 한번.

// 총 v번 다익스트라 쓰면 시간초과 아닌가..? 플로이드도 O(N3) 이라 n<=500 정도일때 유효한데..

// 해결 : 2번의 다익스트라로 풀수 있는 방법이 있다!!!
/* 참조 질문 : https://www.acmicpc.net/board/view/4263*/

// 1. x번 마을에서 다익스트라 한번 ( x번 -> 다른마을로 돌아가는 최단경로)
// 2. 그래프의 방향을 모두 바꿔서 x번 마을에서 다익스트라 한번 ( 다른마을 -> x번 마을로 가는 최단경로)

typedef pair<int, int> ci; // 노드번호로의 가중치
const int INF = 1e4 * 100; //최대 V-1개의 간선(10000) * 가중치 (100)

//다익스트라
vector<int> dijkstra(int vertex, int start, vector<vector<ci>>& graph) { // 정점의 개수, 시작점, 연결리스트
    vector<int> dist(vertex + 1, INF); // 특정 정점까지의 최단경로 저장.
    priority_queue<ci, vector<ci>, greater<>> pq; //first : 시작점으로부터의 거리, second : 정점. minheap

    //시작 위치 초기화
    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {

        int weight = pq.top().first; 
        int node = pq.top().second;
        pq.pop();

        
        if (weight > dist[node])  // 중복 노드 체크
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

	int n, m, x, u, v, w;

    //입력
	cin >> n >> m >> x;

  
    vector<vector<ci>> graph(n + 1, vector<ci>(0)); //인접 리스트(정방향)
    vector<vector<ci>> rgraph(n + 1, vector<ci>(0)); //인접 리스트(역방향)

    while (m--) {
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w); //정방향 그래프: u -> v로 가는 가중치 w의 간선이 존재.
        rgraph[v].emplace_back(u, w); //역방향 그래프: v -> u로 가는 가중치 w의 간선이 존재.
    }


    vector<int> come_back = dijkstra(n, x, graph); // x번 -> 다른 마을로 돌아올때
    vector<int> go = dijkstra(n, x, rgraph); // 다른마을 -> x번 갈때

    int max_time = 0;
    for (int i = 1; i <=n; i++) {

        if (max_time < come_back[i] + go[i])
            max_time = come_back[i] + go[i];

    }
       
    cout << max_time;
}