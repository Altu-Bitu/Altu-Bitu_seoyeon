#include <iostream>
#include <vector> 

using namespace std;


char map[400][400]; //397이 최대. 


// 바깥쪽 네모부터 안쪽 네모까지 재귀적으로 그려나간다. 



// n= 3 일때에는 (0,0)에서 가로,세로 모두 길이 9 (4*3-3)의 테두리를 가짐.
// n=2 일때에는 (2,2)에서 가로,세로 모두 길이 5 (4*2-3)의 테두리를 가짐.
// n=1 일때에는 (4,4)에서 별 하나 그리고 return.

// 즉, 테두리를 그리기 시작하는 좌측상단 지점의 위치가 (x,y) -> (x+2,y+2) 로 늘어나는 규칙.


//x,y는 좌측상단지점으로 네모를 그리는 기준점
void drawSqure(int n, int x, int y) {

    int length = 4 * n - 3;  // 가로 세로 테두리의 길이

    if (n == 1) {
        map[x][y] = '*';
        return;
    }
 
    for (int i = x; i < x + length; i++) {
        map[i][y] = '*';//왼쪽 테두리, 열 고정
        map[i][y + length - 1] = '*';//오른쪽 테두리, 열 고정
    }


    for (int j = y; j < y + length; j++) {
        map[x][j] = '*'; //위 테두리, 행 고정
        map[x + length - 1][j] = '*';//아래 테두리, 행고정
    }

  
    

    // n을 줄여가면서 다음번 네모를 그린다. n=1 이 되면 호출이 종료 된다.
    drawSqure(n - 1, x + 2, y + 2);
    return;

}

int main() {

	int n;

	cin >> n;

	for (int i = 0; i < 4 * n - 3; i++) {

		for (int j = 0; j < 4 * n - 3; j++) {
			map[i][j] = ' ';//map을 초기화

		}

	}

    drawSqure(n, 0, 0);

    // 출력
    for (int i = 0; i < 4 * n - 3; i++) {
        for (int j = 0; j < 4 * n - 3; j++) {
            cout << map[i][j];
        }
        cout << '\n';
    }
}


