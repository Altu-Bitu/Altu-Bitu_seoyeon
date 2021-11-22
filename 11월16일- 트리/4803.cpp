#include <iostream>
#include <vector>

using namespace std;

bool is_tree;
vector<bool> visited;
vector<vector<int>> tree;

//무방향 그래프이기 때문에 바로 직전에 탐색한 정점(부모정점) 을 기억해두고
// 직전 정점을다시 탐색해 사이클로 오해하는 일이 없도록하자! 
// BFS는 직전에 탐색한 정점이 부모 정점이라는 보장이 없으므로 불가능하다.

void dfs(int node, int parent) {
    if (visited[node]) { //이미 방문한 정점이라면 사이클이 발생한 것
        is_tree = false;
        return;
    }

    visited[node] = true; //방문체크

    for (int i = 0; i < tree[node].size(); i++) {
       

        if (tree[node][i] != parent) { //부모 정점이 아니라면.
            dfs(tree[node][i], node);
           }
        
    }
}

void printResult(int num, int cnt) {
    cout << "Case " << num;
    if (cnt == 0)
        cout << ": No trees.\n";
    else if (cnt == 1)
        cout << ": There is one tree.\n";
    else
        cout << ": A forest of " << cnt << " trees.\n";
}

int main() {
    int n, m, a, b, test_case = 0;

    while (true) {
        test_case++;

        //입력
        cin >> n >> m;
        if ((n == 0) && (m == 0)) //종료 조건
            break;
        visited.assign(n + 1, false);
        tree.assign(n + 1, vector<int>(0)); // 정점간의 연결관계 저장

        while (m--) { //무방향 그래프
            cin >> a >> b;
            tree[a].push_back(b); // a->b 연결
            tree[b].push_back(a); // b->a 연결 
        }

        //연산
        int tree_cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (visited[i]) //이미 방문한 정점
                continue;
            is_tree = true;
            dfs(i, -1);
            if (is_tree) //트리가 맞다면
                tree_cnt++;
        }

        //출력
        printResult(test_case, tree_cnt);
    }
}