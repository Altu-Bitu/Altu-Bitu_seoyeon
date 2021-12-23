#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

//위상정렬 + DP
vector<vector<int>> topologicalSort(int n, vector<int>& indegree, vector<vector<ci>>& graph) {
    queue<int> q; // 위상정렬
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); //각 부품이 몇 개 필요한지 저장할 2차원 dp배열

    for (int i = 1; i <= n; i++) { //초기화 
        if (!indegree[i]) { //진입차수가 0이라면 -> 기본 부품
            q.push(i); // 큐에 푸시 
            dp[i][i] = 1; //기본 부품 초기화
        }
    }
    while (!q.empty()) { //큐가 비어있지 않을 동안

        int node = q.front(); //현재 방문한 노드
        q.pop(); // 다음 노드 탐색을 위해 pop 

        for (int i = 0; i < graph[node].size(); i++) { //node와 연결되어있는 정점 수 만큼

            int next_node = graph[node][i].first; //node와 연결되어있는 정점
            int cnt = graph[node][i].second; //필요한 부품 수
            indegree[next_node]--; //연결된 정점의 진입차수를 1씩 감소
            if (!indegree[next_node]) //연결된 정점의 진입차수가 0이 되었다면
                q.push(next_node); // 큐에 푸시 
    

             //(현재 정점을 이루는 부품 개수 * 필요한 현재 정점의 개수)를 더함
            for (int j = 1; j <= n; j++)
                dp[next_node][j] += dp[node][j] * cnt; 
           
        }
    }
    return dp; //각 부품이 몇 개 필요한지 저장한 2차원 dp배열리턴
}

/**
 * 각 부품마다 종류별 필요한 부품 개수를 저장하기 위해 2차원 배열 사용 (행: 부품, 열: 행을 이루는데 각 부품별 필요한 개수)
 * 위상 정렬 순서에 따라, 이어진 다음 정점의 부품별 개수를 (현재 정점을 이루는 부품별 개수 * 필요한 현재 정점 수)를 더해주며 구함
 */

int main() {
    int n, m, x, y, k;

    //입력
    cin >> n >> m;
    vector<vector<ci>> graph(n + 1, vector<ci>(0));
    vector<int> indegree(n + 1, 0);
    while (m--) {
        cin >> x >> y >> k; //y -> x
        indegree[x]++;
        graph[y].push_back({ x, k }); // y->x k개 필요
    }

    //연산
    vector<vector<int>> result = topologicalSort(n, indegree, graph);

    //출력
    for (int i = 1; i <= n; i++) {

        if (result[i][i]) //기본 부품이라면
            cout << i << ' ' << result[n][i] << '\n';
    }
    return 0;
}