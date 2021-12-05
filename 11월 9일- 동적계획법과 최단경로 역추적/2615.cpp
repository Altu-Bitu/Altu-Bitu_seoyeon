#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 19;


// 검정: 1
// 흰색: 2
// 알X : 0

//검은색이 이기면 1, 흰색이 이기면 2, 승부결정전은 0 

// 2차원 DP배열을 만들고 몇번째 칸에서 왔는지 정보를 저장하자. 
// 우선, 알이 있는 곳은 1로 초기화.
// 근방에 동일한 숫자가 있으면 cnt+1. 

//범위와 돌의 종류가 유효한지 확인
bool promising(int r, int c, int stone, vector<vector<int>>& board) {
    return r >= 0 && r < SIZE&& c >= 0 && c < SIZE&& board[r][c] == stone; // 0<=r<SIZE  , 0<=c<SIZE , board[r][c]가 주어진 돌의 종류(검,흰)와 일치한다면true
}

//(r, c)를 가장 왼쪽으로 하는 이어지는 바둑알의 개수를 구하자.
bool validDir(int r, int c, int d, int stone, vector<vector<int>>& board) { // 행 ,열 ,방향, 시작점(백vs흰), 판

    //가로, 세로, 우하향 대각선, 우상향 대각선
    int dr[4] = { 0, 1, 1, -1 }; // 행 증가값
    int dc[4] = { 1, 0, 1, 1 }; // 열 증가값

    //(r, c) 이전에 위치한 이어지는 돌이 있는지 확인.
    bool is_six = promising(r - dr[d], c - dc[d], stone, board);

    int cnt = 0; // 연속된 돌의 개수를 저장.
    while (cnt < 6 && promising(r, c, stone, board)) { //육목까지 도달전 &&  이동한 위치에 같은 색상의 돌이 놓여있다면
        cnt++; //
        r += dr[d]; // d방향으로 행 이동
        c += dc[d]; // d방향으로 열 이동
    }
    return cnt == 5 && !is_six; //육목을 이룰경우 false리턴.
}

bool isEnd(int r, int c, vector<vector<int>>& board) {
    for (int i = 0; i < 4; i++) { //가로, 세로, 우하향 대각선, 우상향 대각선
        if (validDir(r, c, i, board[r][c], board)) //(r,c)에서 i방향으로 오목을 만들 수 있는지 확인.
            return true; //오목을 만들수 있다면 바로 승부가 결정남.
    }
    return false; //if문에 걸리지 않으면 오목을 만들수 없으므로 게임이 끝나지 않음.
}

/**
 * 1. 특정 좌표(r, c)를 가장 왼쪽으로 하는 가능한 모든 오목 배치에 대해 오목 여부 확인
 *    가능한 모든 배치 :  오른쪽, 아래, 우하향, 우상향
 * 2. 육목이상이 되는 경우 : (r, c) 왼쪽에 같은 돌이 있는 경우
 */
int main() {
    vector<vector<int>> board(SIZE, vector<int>(SIZE, 0));

    //입력
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            cin >> board[i][j];
    }

    //연산 & 출력
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!board[i][j]) //돌이 없다면
                continue; //오목을 이룰수 없음.
            if (isEnd(i, j, board)) { //누군가 오목을 이루어 게임이 끝난다면
                cout << board[i][j] << '\n' << i + 1 << ' ' << j + 1; //승자 및 가장 왼쪽 점 출력.
                return 0;
            }
        }
    }
    cout << 0; // 아무도 오목을 만들지 못할경우 0 출력
}

