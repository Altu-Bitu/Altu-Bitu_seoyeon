#include <iostream>
#include <vector>


using namespace std;


//플로이드-워셜 -> 가능한 모든 정점 두개의 조합에 대한 경우의 수
void floydWarshall(int v, vector<vector<int>>& graph) {


    for (int k = 1; k <= v; k++) { // k : 거치는 정점
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {

               
                if (graph[i][j]) // 관계를 이미 알고 있다면
                    continue; 

                if(graph[i][k]==1 && graph[k][j]==1)// i <- k <-j 인경우
                    graph[i][j] = 1;

                else if (graph[i][k] == -1 && graph[k][j] == -1)// i->j->k 인경우
                    graph[i][j] = -1;
            
     
            }
        }
    }
}

// graph[i][j]는 사건 i->j의 관계를 저장
// 0 : 관계모름
// -1 : 선 관계 (i가 j보다 먼저 일어난경우)
// 1 :  후 관계 (i가 j보다 나중에 일어난경우)


int main() {

    int v, n, q; //사건개수, 관계개수, 알고싶은 사건개수

    cin >> v >> n;


    vector<vector<int>> graph(v + 1, vector<int>(v + 1, 0)); // 사건 선후관계 저장
    

    for (int t = 0; t < n; t++) {

        int i, j;

        cin >> i >> j; 

        graph[i][j] = -1;
        graph[j][i] = 1; // i 가 j보다 우선하면 당연히 j는 i보다 뒤처진다.
    }
   

    floydWarshall(v, graph);

    cin >> q;
    while (q--) {
        int i, j;

        cin >> i >> j;
        cout << graph[i][j]<<'\n';


    }

}