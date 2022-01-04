#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//위상정렬
vector<int> topologicalSort(int n, vector<int>& indegree, vector<vector<int>>& graph) {
    vector<int> result;
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) //진입차수가 0이라면
            q.push(i); // 큐에 푸시
    }

    // 큐에 존재하는 정점들을 하나씩 꺼내어 연결을 끊으면서 진입차수가 0인 된 점들을 큐에 푸시함

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        result.push_back(node); //현재 정점 순서에 삽입
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i]; // node와 연결된 정점들 
            indegree[next_node]--; //연결된 정점의 진입차수를 1씩 감소
            if (!indegree[next_node]) //연결된 정점의 진입차수가 0이 되었다면
                q.push(next_node);
        }
    }
    return result;
}

int main() {
    int n, m, a, b; // n명의 학생, 비교횟수 

    //입력
    cin >> n >> m;
    vector<int> indegree(n + 1, 0); //각 정점의 진입차수
    vector<vector<int>> graph(n + 1, vector<int>(0)); //인접 리스트 그래프

    while (m--) {
        cin >> a >> b; //a < b
        indegree[b]++; // 진입차수 추가. 
        graph[a].push_back(b);
    }

    //연산
    vector<int> result = topologicalSort(n, indegree, graph);

    //출력 -> 키가 작은 순서대로
    for (int i = 0; i < n; i++)
        cout << result[i] << ' ';

    return 0;
}