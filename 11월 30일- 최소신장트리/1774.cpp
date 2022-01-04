#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<double, double> ci;
typedef tuple<double, int, int> tp;

/*
이미 연결된 통로간은 거리를0으로 초기화하여 mst에 우선적으로 간택되도록하자.
*/
vector<int> parent;


//Find 연산
int findParent(int node) {
    if (parent[node] < 0) //값이 음수면 루트 정점
        return node;
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
bool unionInput(int x, int y) {

    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp) //같은 집합에 있다면 
        return false; //유니온 할 수 없음 (사이클 발생)

    if (parent[xp] < parent[yp]) { //xp에 속한 정점의 수가 더 많다면 -> 새로운 루트 xp
        parent[xp] += parent[yp];
        parent[yp] = xp;
    }
    else {//yp에 속한 정점의 수가 더 많다면 -> 새로운 루트 yp
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
    return true;
}

//kruskal
double kruskal(int v, priority_queue<tp, vector<tp>, greater<>>& pq) {
    int cnt = 0;
    double sum = 0;

    while (cnt < v - 1) { //사용한 간선의 수가 v-1보다 적을 동안
        double weight = get<0>(pq.top());
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());
        pq.pop();

        if (unionInput(x, y)) { //유니온 했다면
            cnt++;
            sum += weight;
        }
    }
    return sum; // 가중치 합 리턴
}

int main() {
    int n,m; //우주신들의 개수, 이미 연결된 신들과의통로
    priority_queue<tp, vector<tp>, greater<>> pq; //간선을 최소 가중치 순으로 저장할 우선순위큐

    //입력
    cin >> n >> m;
    parent.assign(n, -1);
    vector<ci> gods(n);
    for (int i = 0; i < n; i++)
        cin >> gods[i].first >> gods[i].second; // 신 좌표 입력.

    //연산
    //임의의 두 신에 대한 거리(간선) 모두 구하기 -> n(n-1)/2 개의 간선정보 추가
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {

            // 두 정점사이의 거리 공식 :  루트 {(x1-x2)^2 +(v1-y2)^2 } 
            double xd = gods[i].first - gods[j].first; //x좌표차
            double yd = gods[i].second - gods[j].second; // y좌표 차
            pq.push({ sqrt(xd * xd + yd * yd), i, j });
        }
    }
    // 이미 연결된 통로간은 거리를0으로 초기화 -> 사이클 발생해도 크루스칼이 알아서 걸러줌
    int u, v;
    while (m--) {
        cin >> u >> v;
        pq.push({ 0, u-1, v-1 });
    }

    //연산 & 출력
    cout << fixed;
    cout.precision(2);
    cout << kruskal(n, pq);
}