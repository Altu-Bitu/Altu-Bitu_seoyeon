#include <iostream>
#include <vector>
#include <tuple>
#include <queue>


/*
MST 구하기 - VER.kruskal
가장 작은 가중치를 가진 간선부터 더해나가는 그리디식 알고리즘.
해당 간선을 추가했을때 사이클이 발생하지 않는 다면 트리에 포함.
사이클 발생여부는 유니온 파인드 알고리즘을 활용.
*/

//틀렸습니다 받음. 왜지.

using namespace std;
typedef tuple<int, int, int> tp; //u->v를 연결하는 가중치 w의 간선을 (w,u,v)로 저장

vector<int> parent;

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) //값이 음수면 루트 정점
        return node; // 입력한 node가 속한 집합의 representative node가 자기자신이므로 그대로 반환.
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산 -> 사이클 발생 여부 판단.
bool unionInput(int x, int y) {
    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
        return false;
    if (parent[xp] < parent[yp]) { // xp 집합의 크기가 yp집합보다 크다면 
        parent[xp] += parent[yp]; //새로운 루트 xp
        parent[yp] = xp; // 집합yp에 속했던 정점들이 모두 집합 xp에 속하도록 갱신됨.
    }
    else { // xp 집합의 크기가 yp집합보다 작다면
        parent[yp] += parent[xp]; //새로운 루트 yp
        parent[xp] = yp; // 집합xp에 속했던 정점들이 모두 집합 yp에 속하도록 갱신됨.
    }
    return true;
}

//kruskal
long long kruskal(int v, priority_queue<tp, vector<tp>, greater<>>& pq) { // v : 정점 개수.
    int cnt = 0;
    long long sum = 0;
   
    while (cnt < v - 1) { 

        if (pq.empty()) // 더이상 간선이 존재하지 않으면
            return 0; // MST못만듬.

        int  weight = get<0>(pq.top());
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());
        pq.pop();

        if (unionInput(x, y)) { //유니온이 가능하다면 (= 사이클이 발생하지 않는다면)
            cnt++; //사용한 간선 하나 추가
            sum += weight; // 전체의 가중치 합 더함.
        }
    }
    return sum;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int v, e, a, b, c;
    long long sum =0 ;
    priority_queue<tp, vector<tp>, greater<>> pq; 

    //입력
    cin >> v >> e;
    parent.assign(v + 1, -1); //parent[i]는 i의 부모정점 저장.
    while (e--) {
        cin >> a >> b >> c;
        sum += c; //총비용축적
        pq.push({ c, a, b });
    }

    long long mst_cost = kruskal(v, pq);
   
    if (mst_cost)
        cout << sum- mst_cost;
    else
        cout << -1;

  
}