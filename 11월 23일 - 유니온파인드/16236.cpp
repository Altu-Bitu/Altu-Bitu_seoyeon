#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 401;
typedef pair<int, int> ci;

pair<int, ci> nextPos(int n, int shark_size, ci &shark, vector<vector<int>> &board) {

    // 상하좌우
    int dr[4] = {-1, 1, 0, 0}; //행 증가값
    int dc[4] = {0, 0, -1, 1}; //열 증가값  

    int min_dist = INF; // 최소거리를 INF로 초기화 
    queue<ci> q; //상어가 갈 수 있는 곳을 담은 큐 
    vector<vector<int>> visited(n, vector<int>(n, 0)); //상어의 방문 여부
    vector<ci> list; //상어가 먹을 수 있는 물고기들의 위치


    visited[shark.first][shark.second] = 1;
    q.push(shark);
    while (!q.empty()) { //계속해서 상어를 이동시키며 이동할 때마다 bfs를 실행

        int row = q.front().first; //현재 행값
        int col = q.front().second; //현재 열값

        int dist = visited[row][col]; // 최소거리를 
        q.pop(); // row,col 값을 빼왔으니 다음 loop를 위해 pop

        if (dist >= min_dist) //최단거리 이상은 탐색할 필요 없음
            continue;

        for (int i = 0; i < 4; i++) { //상하좌우 탐색
            int nr = row + dr[i]; //다음에 위치할 행
            int nc = col + dc[i]; //다음에 위치할 열

//bfs 함수는 먹을 수 있는 물고기의 좌표를 저장하는 부분과 물고기를 실제로 먹는 부분으로 나뉜다.

            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] || board[nr][nc] > shark_size)
            //주어진 범위를 벗어나거나 이미 방문한적이있거나 이동하려는 곳에 자기보다 크기가 큰 물고기가 있다면
                continue; //패스

            visited[nr][nc] = visited[row][col] + 1; // 방문체크와 동시에 거리갱신
            if (board[nr][nc] && board[nr][nc] < shark_size) { //먹을 수 있는 물고기 발견
                list.emplace_back(nr, nc); // 최단거리에 있는 물고기들의 좌표를 저장
                min_dist = visited[nr][nc]; // 최단거리 갱신
                continue;
            }
            q.push({nr, nc}); //상어가 갈수있는 위치 추가.
        }
    }

    if (list.empty()) //상어가 갈 수 있는 곳이 없음
        return {min_dist, {-1, -1}};//  상어가 더이상 이동할 수 없을 때 (-1, -1)을 반환
        //그러니 while문의 종료 조건도 (-1, -1)로 하면 된다.

    sort(list.begin(), list.end(), [](const ci &p1, const ci &p2) { //정렬 ->조건에 맞는 물고기의 좌표가 맨 앞으로 오게하기 위함
        if (p1.first != p2.first) //행좌표가 다르다면
            return p1.first < p2.first; //오름차순으로

        return p1.second < p2.second; //행좌표가 같을경우 열좌표를 오름차순으로
    });
    return {min_dist - 1, list[0]};
}

int simulation(int n, pair<int, int> &shark, vector<vector<int>> &board) {
    int ans = 0, size = 2, cnt = 0;
    while (true) {
        pair<int, ci> result = nextPos(n, size, shark, board);
        if (result.first == INF) //더 이상 먹을 수 있는 물고기가 공간에 없음
            break;
        ans += result.first;
        cnt++;
        if (cnt == size) { //먹은 물고기의 수가 상어의 크기와 같다면
            cnt = 0; //cnt는 다시 0으로 초기화
            size++;//상어 크기 증가
        }

        //상어 이동
        ci pos = result.second; //상어이동시킬좌표
        board[shark.first][shark.second] = 0; //이동하기전에 있던곳은 0으로.
        shark = pos; //이동
    }
    return ans; //아기 상어가 몇 초 동안  물고기를 잡아먹을 수 있는지 리턴
}

/**
 * 1. 상어로부터 가장 가까운 거리에 있는 모든 물고기 탐색 (BFS)
 * 2. 우선순위 조건에 맞추어 먹으러 갈 물고기 확정
 *    탐색하는 방향에 우선순위를 두는 걸로 해결되지 않음! (예제 입력 4) 정렬 필요
 * 3. 상어가 이동할 수 있는 곳이 없을 때까지 BFS 탐색 반복
 *
 * 입력 범위가 작기 때문에 매번 BFS 탐색을 반복해도 시간 초과 X
 * 가능한 물고기의 최대 마리 수 : 399마리
 * 최대 BFS 탐색 횟수 : 399회, 1회 탐색마다 while 문은 최대 400회 미만으로 순회
 * 총 연산 횟수 약 160000번으로 충분히 가능
 *
 * 해설 : https://myunji.tistory.com/378
 * *글 자체는 별로 도움이 안되고...그냥 리팩토링하면 코드가 이렇게 되는구나 정도만 봐주세요
 */
int main() {
    int n; //공간의 크기 
    pair<int, int> shark_pos; //상어위치

    //입력
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n)); // 맵에 관한 정보를 저장할 2차원 벡터배열

    for (int i = 0; i < n; i++) { //i =0~n-1
        for (int j = 0; j < n; j++) { // j= 0~n-1
            cin >> board[i][j]; //한칸 정보 입력받기 
            if (board[i][j] == 9) //상어의 초기 위치
                shark_pos = make_pair(i, j); // 상어의 위치정보를 담는 pair자료형 생성.
        }
    }

    //연산 & 출력
    cout << simulation(n, shark_pos, board);
}