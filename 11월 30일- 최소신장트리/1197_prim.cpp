#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 1e6;
typedef pair<int, int> ci; // 가중치 w와 연결된 정점v 를 (w,v)로저장



/*
MST 구하기 - VER.prim
"nonMST와 MST 사이를 잇는 간선 중 가중치가 최소인 간선을 찾아서 MST에 포함시킨다."

1. 각 정점에서 인접한 노드들중 아직 방문하지 않은 노드들을 모두 우선순위큐에 넣는다. (이때, dist배열을 활용하면 
2. 우선순위큐에서 가장 작은 가중치를 지닌 정점을 꺼낸다 (=MST에 포함)
3. pq가 빌때까지 위 과정을 반복한다.
.                                                                                                                                                                    

*/

int prim(int v, int start, vector<vector<ci>>& graph) { // v: 정점 수. start : 시작정점 

    int sum = 0; // 비용(가중치)총 합

    // 가중치 총 합만 리턴하면 되므로 dist배열은 필요하지 x
   vector<int> dist(v + 1, INF); //각 정점까지의 비용 (없어도 상관없으나, 사용하면 메모리를 좀 더 아낄 수 있음)
    vector<bool> visited(v + 1, false); //정점 방문 여부 (다익스트라와 달리 프림에선 필요!)
      
    priority_queue<ci, vector<ci>, greater<>> pq;

    //초기화
    dist[start] = 0;
    pq.push({ 0, start }); // 가중치, 정점

    while (!pq.empty()) {


        //가중치가 가장 적은 정점을 빼옴.
        int weight = pq.top().first; //간선 가중치
        int node = pq.top().second; //현재 정점
        pq.pop();

        if (visited[node]) //이미 확인했던 정점
            continue;
        sum += weight; //MST 간선 가중치 총 합에 더해줌
        visited[node] = true; //방문 처리

        for (int i = 0; i < graph[node].size(); i++) { //연결된 모든 node확인.
            int next_node = graph[node][i].first;
            int next_weight = graph[node][i].second;


            // dist배열을 쓰지 않으면 우선순위큐에 들어가는 간선과 정점이 많아져서 while문의 총 연산횟수 증가.
            if (!visited[next_node] && next_weight< dist[next_node] ) { //미방문 정점(이면서 더 짧은 간선을 통해 갈 수 있다면)
                dist[next_node] = next_weight;
                pq.push({ next_weight, next_node }); // 가중치 갱신
            }
        }
    }
    return sum;
}

int main() {
    int v, e, a, b, c;

    //입력
    cin >> v >> e;
    vector<vector<ci>> graph(v + 1, vector<ci>(0));
    while (e--) { //무방향 그래프이므로 쌍방으로 저장.
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c); //a ->b . 를 잇는 가중치 c의 간선
        graph[b].emplace_back(a, c); //b ->a . 를 잇는 가중치 c의 간선
    }

    //연산 & 출력
    cout << prim(v, 1, graph);
}