#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <tuple>
#include <algorithm>

using namespace std;
typedef vector<vector<int>> matrix;
typedef tuple<int, int, int> tp;

/*
봄: 하나의 칸마다 나이가 어린 나무부터 자신의 나이만큼 양분을 먹고, 나이가 1 증가함
 *    각 칸에 양분이 부족해 자신의 나이만큼 양분을 못 먹는 나무는 즉시 죽음
*/
queue<tp> spring(matrix &land, deque<tp> &tree, queue<pair<int, int>> &breeding_tree) {

    queue<tp> dead_tree; //죽은 트리 목록
    int size = tree.size(); // while문에 사용할 트리의 개수 keep 

    while (size--) { //모든 나무 검사
        int age = get<0>(tree.front()); //나이
        int row = get<1>(tree.front()); //행
        int col = get<2>(tree.front()); //열
        tree.pop_front();

        if (land[row][col] < age) { //자신의 나이만큼 양분을 먹을 수 없다면
            dead_tree.push({age, row, col}); // 죽은 나무에 추가
            continue; //다음 나무 검사
        }

        //자신의 나이만큼 양분을 먹을 수 있다면 

        land[row][col] -= age; //자신의 나이만큼 땅에서 양분을 착마.
        tree.emplace_back(age + 1, row, col); // 나이 1 증가
        if ((age + 1) % 5 == 0) //나이가 5의 배수라면
            breeding_tree.push({row, col}); // 가을에 번식할 트리목록에 추가.
    }
    return dead_tree; //죽은 트리 목록 반환
}

/*
여름: 봄에 죽은 나무가 양분으로 변함. 죽은 나무마다 나이를 2로 나눈 값이 양분으로 추가 (소수점 버림)
*/
void summer(queue<tp> &dead_tree, matrix &land) {

    while (!dead_tree.empty()) { // 죽은 나무를 하나씩 순회하면서
        int age = get<0>(dead_tree.front()); //죽은 나무의 나이
        int row = get<1>(dead_tree.front()); //죽은 나무의 행 위치
        int col = get<2>(dead_tree.front()); //죽은 나무의 열 위치
        dead_tree.pop(); // 다음 트리 탐색을 위해 pop. 
        land[row][col] += (age / 2); // 죽은 나무의 나이를 2로 나눈값만큼 양분으로 추가
    }
}

/*
가을: 나이가 5의 배수인 나무가 번식. 인접한 8개 칸에 나이가 1인 나무가 생김
*/
void fall(int n, deque<tp> &tree, queue<pair<int, int>> &breeding_tree) {

    // 하 상 좌 우 ,좌하향,우하향,좌상향,우상향
    int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1}; // 행 증가량
    int dc[8] = {0, 0, -1, 1, -1, 1, -1, 1}; // 열 증가량

    while (!breeding_tree.empty()) { // 번식할 나무목록을 순회하면서
        int row = breeding_tree.front().first; //번식할 나무의 행
        int col = breeding_tree.front().second; //번식할 나무의 열
        breeding_tree.pop(); //다음 트리탐색을 위해 pop

        for (int j = 0; j < 8; j++) {
            int nr = row + dr[j]; // 다음 행 위치
            int nc = col + dc[j]; // 다음 열 위치
            if (nr < 0 || nr >= n || nc < 0 || nc >= n) //범위를 벗어난다면
                continue; // 패스 
            tree.push_front({1, nr, nc}); //새로 생긴 나무 푸시.
        }
    }
}
/*
 겨울: 로봇(S2D2)이 땅을 돌아다니면서 A[r][c]만큼 각 칸에 양분 추가
 */
void winter(int n, matrix &a, matrix &land) {

    for (int i = 0; i < n; i++) // 행순회
        for (int j = 0; j < n; j++) // 열 순회
            land[i][j] += a[i][j]; // A[r][c]만큼 각 칸에 양분 추가
}

/**
 * K년이 지난 후 상도의 땅에 살아있는 나무의 개수
 *
 * [문제 풀이]
 * a: 로봇(S2D2)가 겨울에 주는 양분의 양
 * land: 땅의 양분
 * breeding_tree: 나이가 5의 배수인 트리 (번식할 트리)
 * tree: 땅에 심은 나무 나이, 행, 열 정보
 * -> deque 컨테이너를 활용해 번식한 나무를 앞에 넣어주면 입력 후에만 정렬해서 사용 가능
 *
 * 문제의 설명대로 계절별 연산을 진행
 */

int main() {
    int n, m, k, x, y, z; // 땅크기. 나무의개수, 년, 나무좌표 (x,y), 나무의 나이

    //입력
    cin >> n >> m >> k;

    matrix a(n, vector<int>(n, 0)); // 나무 정보를 저장할 n x n 크기의 행렬.
    matrix land(n, vector<int>(n, 5)); //처음 양분 모든 칸에 5
    queue<pair<int, int>> breeding_tree; //번식할 트리
    deque<tp> tree; // 현재 상도의 땅에 살아있는 나무들

    for (int i = 0; i < n; i++) // i = 0 ~ n-1
        for (int j = 0; j < n; j++) // j = 0 ~ n-1
            cin >> a[i][j]; //초기 배열 값 입력받기 

    while (m--) { //심은 나무의 개수 입력받기
        cin >> x >> y >> z; // 나무 좌표 (x,y) , 양분 z
        tree.emplace_back(z, x - 1, y - 1); //(0, 0)부터 시작하도록 구현하기위해 1을 빼준 인덱스에 접근
    }

    //연산
    sort(tree.begin(), tree.end()); //어린 나이 순으로 정렬

    while (k--) { // 매년이 지날때마다
        queue<tp> dead_tree = spring(land, tree, breeding_tree); //봄이 지나고 죽은 나무
        summer(dead_tree, land); //여름이 지나고 죽은 나무가 양분으로추가
        fall(n, tree, breeding_tree); // 가을이 지나고 나무가 번식
        winter(n, a, land); // 겨울이 지나고 로봇이 각 칸마다 양분 추가
    }

    //출력
    cout << tree.size(); // 모든 년이 지나고 살아있는 나무 수 출력.
}