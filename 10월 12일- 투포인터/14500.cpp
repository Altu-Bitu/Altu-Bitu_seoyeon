#include <iostream>
#include <vector>

using namespace std;

int ans, n, m;
vector<vector<int>> board;

//좌,우,하,상
int dr[4] = { -1, 1, 0, 0 }; 
int dc[4] = { 0, 0, -1, 1 };

//board[row][col]을 가운데로 하는 +모양을 만들고 나서, 제일 값이 작은 가장자리 블럭 하나를 빼준다
int horn(int row, int col) {
    int cnt = 0, min_block = 1001, sum = board[row][col];

    for (int i = 0; i < 4; i++) { // 현재로부터 상,하,좌,우 지점을 탐색

        int nr = row + dr[i]; //행 좌표 -> -1 1 0 0 순으로 증가 
        int nc = col + dc[i]; //열 좌표 -> 0 0 -1 1 순으로 증가

        if (nr < 0 || nr >= n || nc < 0 || nc >= m) //범위를 벗어나면 무시
            continue;
        min_block = min(min_block, board[nr][nc]); //min_block 갱신
        sum += board[nr][nc]; // 탐색한 board 값 더하기
        cnt++;
    }

    if (cnt < 3) //가능한 가장자리가 최소 3개 이상이어야함.
        return 0;

    if (cnt == 3) //ㅗㅏㅜㅓ (십자 모양은 벽에 부딪혀 만들수없는경우)
        return sum;

    //+
    return sum - min_block; // 십자모양을 만든경우. -> 제일 값이 작은 가장자리 블럭 하나를 빼준다
}

//한붓 그리기가 가능한 블럭들 백트래킹 탐색
void backtracking(int row, int col, int cnt, int sum) {

    if (cnt == 4) { //기저조건 : 4개의 블럭을 탐색함
        ans = max(ans, sum);// ans 갱신
        return;
    }

    for (int i = 0; i < 4; i++) { // 현재로부터 상,하,좌,우 지점을 탐색
        int nr = row + dr[i];  //행 좌표 -> -1 1 0 0 순으로 증가 
        int nc = col + dc[i]; //열 좌표 -> 0 0 -1 1 순으로 증가

        if (nr < 0 || nr >= n || nc < 0 || nc >= m || !board[nr][nc]) //범위를 벗어나거나, 이미 방문했다면
            continue;

        int save = board[nr][nc]; // 현재 블럭을 킵해둠. -> 다음 탐색을 위해 복원해야하므로

        board[nr][nc] = 0; // 방문 표시
        backtracking(nr, nc, cnt + 1, sum + save); // 카운트를 하나 증가시키고 save를 sum에 더한채로 함수 호출
        board[nr][nc] = save; // 다음 탐색을 위해 복원
    }
}

/**
 * 1. 각 블럭을 백트래킹이 가능한 블럭과 불가능한 블럭으로 나누기
 *    -> 블럭을 한붓 그리기로 그릴 수 있으면 백트래킹이 가능 아니라면 불가능
 *    -> 보라색 블럭을 제외하면 모두 백트래킹 가능
 * 2. 보라색 블럭은 + 모양에서 가장자리를 하나 제거한 것과 같음
 *    -> 가운데 블럭을 중심으로 가장자리 블럭을 붙여보고 가능한 최댓값 구하기
 * 3. 각 블럭에 대해 깊이가 4인 백트래킹 함수를 수행하며 최댓값 갱신
 *
 * 해설 : https://myunji.tistory.com/297
 * *코드가 살짝 달라요(블로그 코드는 최적화 하기 전)
 */

int main() {

    //입력
    cin >> n >> m;
    board.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    //연산 -> 한붓그리기 or horn 함수를 시작할 기준점 설정
    for (int i = 0; i < n; i++) { // 행
        for (int j = 0; j < m; j++) { //열 

            ans = max(ans, horn(i, j)); //보라색 블럭 처리
            int save = board[i][j]; // 현재 블럭 keep해두기

            board[i][j] = 0; // 방문표시
            backtracking(i, j, 1, save); //나머지 모양 처리
            board[i][j] = save; // 다음 탐색을 위해 복원
        }
    }

    //출력
    cout << ans;
}