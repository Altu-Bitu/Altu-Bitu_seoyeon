#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int SIZE = 1e5; //(0 ≤ N ≤ 100,000)

//역추적
vector<int> back( int n,vector<int>& path) { //x: k(도착지점)부터
    vector<int> result(0); //정답 경로
    int x = 1;
    while (x != -1) { // x==-1 -> 더이상 역추적할 경로가 존재하지 않는다. 
        result.push_back(x);
        x = path[x]; //다음 정점
    }
    return result;
}

int bfs(int n, vector<int>& path) {
    vector<int> check(SIZE + 1, 0);
    queue<int> q; //큐에 좌푯값 저장
    int ans = 0; //최단 시간

    check[n] = 1; //시작 노드 방문 체크
    q.push(n); //시작 노드 초기화
    while (!q.empty()) {
        int x = q.front(); //현재 탐색하려는 위치
        q.pop();

        if (x == 1) { //1이면 탐색 종료.
            ans = check[x] - 1; //시작 노드 초기화를 1로 했기 때문에 1을 빼줌
            break;
        }
        vector<int> child ; //자식노드 

        if (x % 3 == 0) {
            child.push_back(x / 3);
        }
        if (x % 2 == 0) {
            child.push_back(x / 2);
        }
        child.push_back(x-1);

       
        for (int i = 0; i < child.size(); i++) {
            if (child[i] >= 1 && child[i] <= SIZE && !check[child[i]]) { //범위 내에 있고, 첫 방문이라면
                check[child[i]] = check[x] + 1;
                path[child[i]] = x; //경로 저장
                q.push(child[i]);
            }
        }
    }
    return ans;
}

/**
 * 최단거리(BFS) 역추적
 * - 기본 문제: 숨바꼭질
 */

int main() {

    vector<int> path(SIZE + 1, -1); //경로 저장 벡터.  index에 존재하지 않는 값인 -1 로 초기화.
    int n;

    //입력
    cin >> n;

    //연산
    int ans = bfs(n, path);
    vector<int> result = back(n,path);

    //출력
    cout << ans << '\n';
    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i] << ' ';
    return 0;
}