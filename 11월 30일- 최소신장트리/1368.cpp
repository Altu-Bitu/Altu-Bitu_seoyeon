#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 1e6;
typedef pair<int, int> ci; // 가중치 w와 연결된 정점v 를 (w,v)로저장

/** hint
 각 논들 사이의 간선을 고려하면서 우물을 파는 경우도 고려하기엔 너무 복잡해요. 
우물을 파는 경우도 간선처럼 처리할 수 있는 방법은 없을까요? 모든 물은 바다에서 시작되지 않을까요?

-> 바다라는 새로운 정점을 하나 추가하고,
각정점에서 논에 직접 우물을 파는 비용을 바다와 연결하는 비용으로서 간주하자.
*/


int prim(int v, int start, vector<vector<int>>& graph) { // v: 정점 수. start : 시작정점 

    int sum = 0; // 비용(가중치)총 합

    vector<int> dist(v + 1, INF); //각 정점까지의 비용 
    vector<bool> visited(v + 1, false); //정점 방문 여부

    priority_queue<ci, vector<ci>, greater<>> pq;

    //초기화
    dist[start] = 0;
    pq.push({ 0, start }); // 가중치, 정점

    while (!pq.empty()) {

        int weight = pq.top().first; //간선 가중치
        int node = pq.top().second; //현재 정점
        pq.pop();

        if (visited[node]) //이미 확인했던 정점
            continue;
        sum += weight; //MST 간선 가중치 총 합에 더해줌
        visited[node] = true; //방문 처리

       
        for (int i = 1; i <= v; i++) { //연결된 모든 node확인.
            if (graph[node][i] != 0) { //자기자신이면 패스 
                if (!visited[i] && graph[node][i] < dist[i]) { //MST에 포함되지 않았고 더 짧은 간선을 통해 갈 수 있다면)
                    dist[i] = graph[node][i]; // 비용 갱신
                    pq.push({ dist[i], i });
                }
            }
        }
    }
    return sum;
}

int main() {
    int v, e, a, b, c,tmp;

    //입력
    cin >> v;
    vector<vector<int>> graph(v + 2, vector<int>(v + 2,0)); // 바다까지 포함해서 v+1개의 정점정보저장.

    //바다(v+1번째 정점)와 다른 논과  의 연결관계입력.
    for (int i = 1; i <= v; i++) {
        cin >> tmp;
        graph[v + 1][i]= tmp;
        graph[i][v+1] = tmp;
    }

    // 바다를 제외한 나머지 논들간의 연결관계 입력
    for (int i = 1; i <= v ; i++) {
        for (int j = 1; j <= v ;j++) {
            cin >> graph[i][j]; //i->j로 가는 비용 저장.
        }

    }
  
    //연산 & 출력
    cout << prim(v+1, 1, graph); //v가 아니라 v+1을 넘겨줌.
}