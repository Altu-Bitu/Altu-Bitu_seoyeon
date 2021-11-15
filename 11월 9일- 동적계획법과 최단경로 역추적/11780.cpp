#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

#define INF 10e8

/* 백준 질문 참조 :https://www.acmicpc.net/board/view/20793 */
using namespace std;

//플로이드-워셜 역추적

//path[i][j] 에 저장된 값
//INF -> 경로가 없다. , -1 -> 직행이 최단거리이다. k :i->j 까지의 최단경로에 반드시 k가 포함된다.
//start -> end 까지 가는 최단경로를 result배열에 순서대로 push 해주는 함수.
void back(int start,int end, vector<vector<int>>& path, vector<int>& result) {
    
    if (start == end)
        return;

    int k = path[start][end]; //경유지

    if (k == INF) // start -> end경로가 존재하지 않는다면
        return;

    if (k == -1) //start -> end로 직행하는 것이 최단경로라면
    {
        result.push_back(start);
        result.push_back(end);
        return;
    }

 
    // i -> k 와 k->j 로 재귀적으로 함수를 호출하자

    back(start, k,path,result); //start -> k (경유지)
    result.pop_back(); //k 가 두번 push되므로 한번 삭제.
    back(k, end,path,result); // k(경유지) -> end 


}

/*
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
*/

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
                    path[i][j] = k; // 경로 저장

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
    vector<vector<int>> path(n + 1, vector<int>(n + 1, INF)); // 경로 저장

    for (int i = 1; i <= n; i++) //자기 자신과의 거리
        graph[i][i] = 0;

    while (m--) {
        cin >> u >> v >> w; // u -> v로 가는 가중치 w의 간선
        graph[u][v] = min(graph[u][v], w); //중복 간선이 들어올 수 있으므로 최솟값 사용
        path[u][v] = -1;

    }
 
   
    //연산
    floydWarshall(n, graph, path);

    
    //printPath(n, path); 

    //출력 1
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ((graph[i][j] == INF) ? 0 : graph[i][j]) << ' '; // 경로가 없으면 0을 출력
        }
        cout << '\n';
    }


    vector<int> result;

    //출력 2
    for (int i = 1; i <= n; i++) {
       
        for (int j = 1; j <= n; j++) {
            result.clear();
            back(i, j, path,result);
            cout << result.size() <<' ';
            for (int i = 0; i < result.size();i++)
                cout << result[i] << ' ';
            cout << '\n';
        }
       
    }
}




  

   
   
   
