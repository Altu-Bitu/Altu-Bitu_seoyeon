#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

#define INF 987654321

using namespace std;

//플로이드-워셜 역추적


vector<int> back(int start,int end, vector<vector<int>>& path) { 
    vector<int> result(0); //정답 경로
    if (start == end) {

    }

    result.push_back(end);
    end= path[start][end];
   
    while (end!= -1) { // x==-1 -> 더이상 역추적할 경로가 존재하지 않는다. 
      
        int k = path[start][end]; // 경유지
        result.push_back(k);
        end = path[start][k]; //다음 정점
    }
    result.push_back(start);
    return result;
}
void printPath(int n,vector<vector<int>>& path) {

    cout << "path"<<'\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << setw(3)<<path[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}
//플로이드-워셜 
void floydWarshall(int n, vector<vector<int>>& graph, vector<vector<int>>& path) {
    
    for (int k = 1; k <= n; k++) { // k : 거치는 정점
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                int dist = graph[i][k] + graph[k][j]; //중간에 k를 거쳐서 i에서 j로 감
                if (dist >= INF) continue;
                if (graph[i][j] > dist) //i->j와 i->k->j 중 더 짧은 경로 저장
                {
                    graph[i][j] = dist;
                    path[i][j] = k;

                }
            }
        }
    }
}


int main() {

    int n, m, u, v, w;

    //입력
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF)); 
    vector<vector<int>> path(n + 1, vector<int>(n + 1, -1)); // 경로 저장

    for (int i = 1; i <= n; i++) //자기 자신과의 거리
        graph[i][i] = 0;

    while (m--) {
        cin >> u >> v >> w; // u -> v로 가는 가중치 w의 간선
        graph[u][v] = min(graph[u][v], w); //중복 간선이 들어올 수 있으므로 최솟값 사용

    }
   
    //연산
    floydWarshall(n, graph, path);

    printPath(n, path);

    //출력 1
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ((graph[i][j] == INF) ? 0 : graph[i][j]) << ' '; // 경로가 없으면 0을 출력
        }
        cout << '\n';
    }
    cout << '\n';
    //출력 2
    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            vector<int> result = back(i,j, path);
            cout << result.size() << '\n';
            for (int i = result.size() - 1; i >= 0; i--)
                cout << result[i] << ' ';
        }
    }*/
}




  

   
   
   
