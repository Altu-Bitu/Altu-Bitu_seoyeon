#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci; // 연결된 정점, 가중치를 저장할 pair 자료형을 ci로 저장.

ci dfs(int node, int parent, vector<vector<ci>>& graph) {

    int pos = node, len = 0; //지름을 구성하는 노드 중 하나, 그 노드까지의 거리
    for (int i = 0; i < graph[node].size(); i++) { // node와 연결된 정점들 모두 순회
        int next_node = graph[node][i].first; // 다음에 탐색할 노드.

       
.       //무방향 그래프이기 때문에 바로 직전에 탐색한 정점(부모정점) 을 기억해두고 탐색 방지. 
        if (next_node == parent) 
            continue;

        ci dfs_search = dfs(next_node, node, graph); //자식 노드에 대해 dfs 탐색
        if (graph[node][i].second + dfs_search.first > len) { //기존 거리보다 길다면 갱신
            len = graph[node][i].second + dfs_search.first; // 현재노드에서 연결된 정점까지의 가중치(node->i) + 현재까지의 가중치
            pos = dfs_search.second; // 위치 갱신
        }
    }
    return { len, pos }; //최대길이, 위치
}

/**
 * 1. 지름을 이루는 두 점은 모두 리프 노드
 * 2. 임의의 한 노드에서 가장 멀리 있는 노드(리프 노드)는 지름을 이루는 노드 중 하나
 * 3. 지름을 이루는 노드에서 가장 멀리 있는 노드는 지름을 이루는 다른 노드
 *
 * 부모->자식의 방향만 저장하면 리프 노드에서 다른 리프 노드로 탐색할 수 없으므로 무방향 그래프로 저장
 */
int main() {
    int n, p, c, w; //노드의 개수,부모노드,자식노드, 가중치

    //입력
    cin >> n;

    vector<vector<ci>> graph(n + 1, vector<ci>(0)); // 트리 정보를 저장할 2차원 배열. 
    for (int i = 1; i < n; i++) { //무방향 그래프로 만들기
        cin >> p >> c >> w; // p->c 로가는 가중치 w의 간선
        graph[p].emplace_back(c, w); // p ->c 연결
        graph[c].emplace_back(p, w); //c->p 연결
    }

    //연산
    ci first_node = dfs(1, -1, graph); //지름을 구성하는 노드 하나 찾기
    ci second_node = dfs(first_node.second, -1, graph); //지름을 구성하는 다른 노드 찾기

    //출력
    cout << second_node.first;
}