#include <iostream>
#include <vector>
#include <stack>

using namespace std;
vector<int> check; //방문체크와 동시에 이전 경로 저장.

vector<int> graph;
void dfs(int x) {
	if (check[x] == true)
		return;

	check[x] = tr;


}
//DFS : 깊이 우선 탐색
vector<int> dfs(int n, int v) { // 정점의 개수,시작노드
    stack<int> st;
    vector<bool> visited(n + 1, false); //방문 노드 체크
    vector<int> result; //탐색순으로 노드 저장


    st.push(v); //처음 탐색 노드 삽입
    visited[v] = true; //방문 체크
    result.push_back(v);

    //탐색 시작
    while (!st.empty()) {
        //더이상 자식노드가 존재하지 않을때 stack이 pop되어야함
        int node = st.top(); //현재 탐색하려는 노드
        bool check = false; //연결 노드 존재 여부
    
        //인접리스트로 검사
        for (int i = 0; i < graph[node].size(); i++) { //연결된 노드만
            if (!visited[graph[node][i]]) { //이미 연결된 노드 정보만 있으므로, 방문 체크만!
                check = true;
                visited[adj_list[node][i]] = true;
                st.push(adj_list[node][i]);
                result.push_back(adj_list[node][i]); //탐색 노드 바로 삽입
                break;
            }
        }
        
        if (!check) 
            st.pop();
    }

    return result;
}
int main() {

	int n,u,v;
	cin >> n;
    graph.assign(n, 0);
	check.assign(n+1, -1);

    for (int )

}