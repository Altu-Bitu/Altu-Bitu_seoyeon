#include <iostream>
#include <vector>

using namespace std;

int cntCleanRobot(int r, int c, int d, vector<vector<int>>& board) {

    //상, 우, 하, 좌
    int dr[4] = { -1, 0, 1, 0 }; //행증가량
    int dc[4] = { 0, 1, 0, -1 }; //열증가량

    int step = 0, ans = 0;
    while (true) { 
        if (board[r][c] == 0) { // 청소가 되어있지않다면
            board[r][c] = 2; // 청소완료 표시
            ans++; //청소된 공간 추가
        }

        if (step == 4) { // 한바퀴를 돌아 다시 제자리로 왔을때 

            if (board[r - dr[d]][c - dc[d]] == 1) // 뒤쪽방향이 벽이라 후진도 할 수 없을때.
                return ans; // 작동멈추고 현재 답 리턴.

            //후진할수 있으면 바라보는 방향을 유지한 채로 한 칸 후진
            r -= dr[d]; // 행 후진
            c -= dc[d]; // 열 후진
            step = 0; // 회전 카운트 초기화
        }
        else { // step =1,2,3 인 경우

            d = (d + 3) % 4; // 바라보고 있는 방향 구하기.

            if (board[r + dr[d]][c + dc[d]]) { //바라보고있는 쪽에 벽이있다면
                step++; //한칸 회전 
                continue; // 다음 면 탐색 지속
            }
            //벽이 없다면 이동
            r += dr[d]; //행이동
            c += dc[d]; //열이동
            step = 0; //회전 카운트 초기화
        }
    }
}

/**
 * board 정보 -> 0: 빈 칸, 1: 벽, 2: 청소한 공간
 * step: 회전 카운트. 4가 되면 한 바퀴 돌아 다시 제자리로 돌아왔음을 의미
 *
 * 항상 첫 행, 마지막 행, 첫 열, 마지막 열은 벽이라고 문제에서 주어졌으므로 범위 검사를 할 필요가 없음
 */

int main() {

    int n, m, r, c, d; // 세로,가로,x좌표,y좌표,바라보고있는 방향.

    //입력
    cin >> n >> m >> r >> c >> d;

    vector<vector<int>> board(n, vector<int>(m, 0)); // 청소정보 저장할 nXm 크기의 2차원배열.

    //지도 정보입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    //연산 & 출력
    cout << cntCleanRobot(r, c, d, board);
    return 0;
}
