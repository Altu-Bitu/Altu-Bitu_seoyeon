#include <iostream>
#include <vector>
#include <queue>

using namespace std;


//모든 곳을 탐색해야하므로 DFS,BFS 둘다 가능


typedef pair<int, int> ci; //row, col 저장하기 위한 pair

 //bfs 탐색한번당 섬 하나.
void bfs(int i, int j, int h, int w, vector<vector<int>>& map) { //(i,j) ->탐색 시작점

    queue<ci> q;
    //상, 하, 좌, 우, 북서,북동, 남서,남동
    int dr[8] = { -1, 1, 0, 0 , 1,1,-1,-1 };
    int dc[8] = { 0, 0, -1, 1 , -1,1,-1,1 };

    q.push(ci(i, j));


    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) { //상, 하, 좌, 우 ,북서,북동, 남서,남동 방향 탐색(인접한 노드 탐색)
            int nr = cr + dr[i]; //방문하려는 노드
            int nc = cc + dc[i]; //방문하려는 노드

            //범위체크( 1<=nr<=h, 1<=nc<=w) + 땅체크와 동시에 방문체크
            if (nr > 0 && nr <= h && nc > 0 && nc <= w && map[nr][nc] == 1) {

                map[nr][nc] = 2; // 방문체크 
                q.push(ci(nr, nc));
            }
        }
    }

}

int solution(int w, int h, vector<vector<int>> map) {

    int cnt = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {

            if (map[i][j] == 1) //(i,j)를 아직 방문하지 않았고, 땅이라면
            {
                map[i][j] = 2;
                bfs(i, j, h, w, map); //(i,j)를 포함하는 섬 탐색.

                /* 디버깅용 출력
                for (int i = 1; i <= h; i++) {
                    for (int j = 1; j <= w; j++) {
                        cout << map[i][j] << ' ';
                    }
                    cout << '\n';
                }
                cout << "\n";
                */
               
                cnt++;

            }
        }
    }
    return cnt;

}

/**
탐색을 완료한 섬은 1->2 로 바뀐다

ex) 5 4

1 0 1 0 0
1 0 0 0 0
1 0 1 0 1
1 0 0 1 0

2 0 1 0 0
2 0 0 0 0
2 0 1 0 1
2 0 0 1 0

2 0 2 0 0
2 0 0 0 0
2 0 1 0 1
2 0 0 1 0

2 0 2 0 0
2 0 0 0 0
2 0 2 0 2
2 0 0 2 0

cnt = 3
*/
int main() {


    int w, h;

    while (true) {


        cin >> w >> h; // 열, 행

        if (w == 0 && h == 0)
            break;

        vector<vector<int>>map(h + 1, vector<int>(w + 1, 0));

        //맵 정보 입력/  0 :바다  1: 땅
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> map[i][j];
            }
        }

        cout << solution(w, h, map)<<'\n';



    }


}