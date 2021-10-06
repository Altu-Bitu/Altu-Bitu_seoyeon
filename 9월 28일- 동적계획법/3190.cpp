#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci; //pair자료형을  ci로 정의하여 가독성 높임.

ci dir[4] = {{0,  1},  //우
             {-1, 0},  //상
             {0,  -1}, //좌
             {1,  0}}; //하

//게임을 진행하는 함수
int playGame(int n, vector<vector<int>> &board, map<int, char> &cmd) {
    //뱀 초기화

	//뱀이 이동하는 모든 칸에 관한 정보를 덱에 집어넣는 알고리즘!

	//뱀머리 --> front , 뱀꼬리 --> back
    deque<ci> snake; // <int,int> 를 담는 덱
    snake.push_front(ci(0, 0)); // 뱀의 머리(=꼬리) 위치 푸시 
    board[0][0] = 1; // 처음 뱀은 (0,0)에 위치해있다.

    int t = 0, head = 0; //시간, 뱀의 머리 방향 -> 처음엔 우측을 향하고 있으므로 head를 0으로.
    while (true) {
        t++; // 반복문을 하나 돌때마다 시간을 1초씩 증가시킴.

        //뱀의 머리가 위치하게될 칸
        int nr = snake.front().first + dir[head].first; //뱀의머리의 행좌표 + 뱀의 머리가향하는 방향의 행좌표
        int nc = snake.front().second + dir[head].second; //뱀의머리의 열좌표 + 뱀의 머리가향하는 방향의 열좌표

        //게임 종료 조건 : 벽에 부딪히거나, 자기자신의 몸과 부딪힘
        if (nr < 0 || nr >= n || nc < 0 || nc >= n || board[nr][nc] == 1)
		//시간을 미리 증가시키고 시작하기때문에 처음시작때 마지막 조건문에 걸리는 일 X
            break;

        if (board[nr][nc] != 2) { //이동한 칸에 사과가 없다면 
            board[snake.back().first][snake.back().second] = 0; //몸길이를 줄여서 꼬리가 위치한 칸을 비워준다
            snake.pop_back(); //꼬리를 바꿈.
        }
	

        //뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다
        snake.push_front(ci(nr, nc));
        board[nr][nc] = 1; // 뱀이 위치하고 있음을 표시

        //이번에 방향을 변환하는지 확인
        if (cmd[t] == 'L') //왼쪽 회전
            head = (head + 1) % 4; //우측 -> 위 -> 좌측 -> 아래 (+1씩 증가), 아래->우측으로 이어져야하기때문에 %연산.
			// ex. head가 2라면 현재 좌측을 향하고 있다는 소리이고 좌측에서 한번더 왼쪽 회전을 하게 되면 아래를 향하게 된다.
        if (cmd[t] == 'D') //오른쪽 회전
            head = (head + 3) % 4;// 우측 -> 아래 -> 좌측 ->위 (+3씩 증가), 위->우측 이어져야하므로 %연산.
			//ex. head가 1이라면 현재 위를 향하고 있다는 소리이고 위에서 오른쪽 회전을 하면 우측을 향하게 된다. 

			
    }
    return t; //게임이 종료되었을시에 시간 반환
}

/**
 * 0 0 1
 * 0 2 1
 * 0 0 1
 *
 * 편의를 위해 문제와 달리 (0, 0)부터 시작
 *
 * 보드의 상태가 위와 같을 때
 * 뱀의 몸은 (0, 2)~(2, 2)에 걸쳐 있고, 사과는 (1, 1)에 위치하고 있음
 * -> 뱀의 꼬리와 머리 위치를 알기 위해 덱 사용
 * -> 덱의 front : 머리, 덱의 back : 꼬리
 *
 * 원활한 방향 변환을 위해 dir 배열 사용
 */
int main() {
    int n, k, row, col, l, x; //보드의 크기,사과의 개수,행,열,방향전환횟수,시간
    char c; 

    //입력
    cin >> n >> k; //보드크기,사과의 개수 입력받기

    vector<vector<int>> board(n, vector<int>(n)); // 사과 & 뱀을 위치시킬 2차원 배열

    for (int i = 0; i < k; i++) { //k번 반복
        cin >> row >> col; // 사과가 존재하는 행,열 입력받기
        board[row - 1][col - 1] = 2; //사과 표시
    }
    cin >> l; // 방향전환횟수

    map<int, char> cmd; //int : 언제 char : 어디로  방향을 전환할지 저장

    for (int i = 0; i < l; i++) { //회전 정보
        cin >> x >> c; //시간,방향
        cmd[x] = c; //map에 저장
    }

    //연산 & 출력
    cout << playGame(n, board, cmd);
}