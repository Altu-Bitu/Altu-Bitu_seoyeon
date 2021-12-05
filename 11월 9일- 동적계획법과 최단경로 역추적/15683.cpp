#include <iostream>
#include <vector>

using namespace std;

int n, m, ans = 65; // 사무실 최대 크기(8*8) +1
vector<vector<int>> board; // cctv + 감시정보를 저장할 2차배열

// 찾은 cctv의 범위를 체크
void ray(int row, int col, int dir) {
    int dr[4] = { -1, 0, 1, 0 };
    int dc[4] = { 0, 1, 0, -1 };

    while (row >= 0 && row < n && col >= 0 && col < m && board[row][col] != 6) { //dir 방향으로 뻗어나가며 cctv 표시
        if (board[row][col] == 0) //다른 cctv를 지우지 않기 위해 빈 공간일 때만 표시
            board[row][col] = 7; // cctv가 감시하는 범위에 포함 (#표시)
        row += dr[dir]; // dir방향으로 행이동
        col += dc[dir]; // dir방향으로 열이동
    }
}

//cctv 방향 지정
void install(int cctv, int row, int col, int dir) {
    if (cctv >= 1) //1, 2, 3, 4, 5번 cctv
        ray(row, col, dir);
    if (cctv >= 2 && cctv != 3) //2, 4, 5번 cctv
        ray(row, col, (dir + 2) % 4);
    if (cctv >= 3) //3, 4, 5번 cctv
        ray(row, col, (dir + 1) % 4);
    if (cctv == 5) //5번 cctv
        ray(row, col, (dir + 3) % 4);
}

//사각지대 계산
int blindSpot() {
    int cnt = 0; // 사각지대 갯수
    for (int i = 0; i < n; i++) { // 0 ~ n-1
        for (int j = 0; j < m; j++) { //0 ~ m-1
            if (!board[i][j]) // board[i][j]가 0이라면(=감시되지 않는 곳이라면) 
                cnt++; // 사각지대 증가
        }
    }
    return cnt; // 반환
}

void backtracking(int idx) {
    if (idx == n * m) { //기저 조건 : 사무실의 모든 위치 확인
        ans = min(ans, blindSpot()); //사각지대 계산 후 최솟값 갱신
        return;
    }

    int row = idx / m;
    int col = idx % m;
    int cur = board[row][col];
    if (cur == 0 || cur == 6 || cur == 7) //cctv가 없는 곳
        return backtracking(idx + 1);

    vector<vector<int>> save = board; //unvisited 처리용 board 상태 저장
    for (int i = 0; i < 4; i++) { //4개의 방향에 대해 cctv 설치
        install(cur, row, col, i); //cctv 설치
        backtracking(idx + 1); // 재귀 호출. 
        board = save; //다음탐색을 위해 복원.

        //2번 cctv는 범위의 특성상 서로 다른 설치 방법이 2가지 뿐이고, 5번 cctv는 같은 이유로 설치 방법이 1가지다.
        if ((cur == 2 && i == 1) || (cur == 5 && i == 0))
            break; // 그래서 cur_cctv를 확인하며 불필요한 탐색을 하지 않도록 조건을 걸어 break한다.
    }
}

/**
 * cctv가 설치될 수 있는 모든 경우를 고려하는 완전탐색 문제
 *
 * 1. 각 cctv에 대해 가능한 모든 방향을 고려하여 설치
 *    1, 3, 4번 cctv : 4방향
 *    2번 cctv : 2방향
 *    5번 cctv : 1방향
 * 2. install 함수에서 각 cctv의 빛이 뻗어나갈 방향을 잡음
 * 3. ray 함수에서 cctv의 감시 가능 범위 표시
 * 4. 모든 위치를 확인했으면 blindSpot 함수를 통해 사각지대 계산
 *
 * 풀이 : https://myunji.tistory.com/411
 * 해당 코드는 위 링크의 코드를 리팩토링한 코드입니다.
 * 말로는 풀이를 설명하기 어려우니 링크를 꼭 확인해주세요!
 */
int main() {
    //입력
    cin >> n >> m;
    board.assign(n, vector<int>(m)); //[n][m] 이차배열 할당.

    for (int i = 0; i < n; i++) { // 0 ~ n-1
        for (int j = 0; j < m; j++) // 0 ~ m-1
            cin >> board[i][j]; //입력
    }

    //연산
    backtracking(0);

    //출력
    cout << ans;
}