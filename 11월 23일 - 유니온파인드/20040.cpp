#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//C에 속한 임의의 선분의 한 끝점에서 출발하여 모든 선분을 한 번씩만 지나서 출발점으로 되돌아올 수 있다.

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) //루트 정점이라면
        return node; // 루트 바로 리턴
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
//게임의 진행 상황이 주어지면 몇 번째 차례에서 사이클이 완성되었는지, 혹은 아직 게임이 진행 중인지를 판단하는 함수
bool unionInput(int x, int y) {

    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
        return false;
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp];
        parent[yp] = xp; //yp의 부모 -> xp로 
    } else { //새로운 루트 yp
        parent[yp] += parent[xp];
        parent[xp] = yp; //xp의 부모 -> yp로 
    }
    return true;
}

/**
 * 사이클이 발생한 순간 = 같은 집합에 있는 원소 두 개를 유니온하려 할 때
 * unionInput 함수의 반환형을 bool로 선언하여 cycle이 생성되는 순간 발견하기
 */
int main() {
    int n, m, x, y;

    //입력
    cin >> n >> m; // n개의 점,m개의 입력 
    parent.assign(n, -1);
    for (int i = 0; i < m; i++) {
        cin >> x >> y; //i번째 차례에 해당 플레이어가 선택한 두 점의 번호 

        //연산 & 출력
        if (!unionInput(x, y)) { //유니온 할 수 없음 = 사이클이 생성됨
            cout << i + 1; // 몇 번째 차례에서 처음으로 사이클이 완성된 것인지를 출력
            return 0;
        }
    }
    cout << 0;
}