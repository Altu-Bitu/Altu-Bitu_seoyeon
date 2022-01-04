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
    int n, m, k; //가수의수,보조 pd의 수 ,보조 pd가 담당한가수의수

    //입력
    cin >> n >> m;
    vector<int> indegree(n + 1, 0); //각 정점의 진입차수
    vector<vector<int>> graph(n + 1, vector<int>(0)); //인접 리스트 그래프
    vector<int> sequence;

    while (m--) {
     
        cin >> k;
        sequence.assign(k, 0);

        //순서 입력받기
        for (int i=0;i<k;i++)
            cin >> sequence[i];

        
        for (int i = 0; i < k - 1; i++)
        {
            indegree[sequence[i+1]]++; // 진입차수 추가. 
            graph[sequence[i]].push_back(sequence[i+1]);
        }
        
    }

    //연산
    vector<int> result = topologicalSort(n, indegree, graph);

   
    if (result.size() < n) { //모든 노드를 방문하지 못했을 경우

        cout << 0;
    }
    else {
        for (int i = 0; i < n; i++)
            cout << result[i] << ' ';
    }
   
}