#include <iostream>
#include <vector>
//
using namespace std;
const int INF = 1e9;

// 가장 빨리 만들 수 있는 높이의 후보들을 먼저 찾아봅시다. 입력이 크지 않으니 가능한 모든 높이에 대해 계산해봐도 좋아요. 
//블럭을 쌓던 와중에 블럭이 다 떨어지면 어떻게 될까요? 
//그 높이를 만들 수 없다고 판단해야 할까요?
//-> 당장 쌓을 블록이 없더라도 언젠가 다른 곳의 블록을 제거해서 쌓을 수 있음

int mineLand(int n, int m, int b, int height, vector<vector<int>> &land) {
    // height : 타깃 높이값 
    int tot_time = 0; //총 소요되는 시간

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (land[i][j] > height) { // 타겟높이보다 높다면
                b += (land[i][j] - height); // 좌표 (i, j)의 가장 위에 있는 블록을 제거하여 인벤토리에 넣는다.
                tot_time += 2 * (land[i][j] - height); // 1번작업은 2초소요
            } else if (land[i][j] < height) { //타겟높이보다 낮다면
                b -= (height - land[i][j]); //인벤토리에서 블록 하나를 꺼내어 좌표 (i, j)의 가장 위에 있는 블록 위에 놓는다.
                tot_time += (height - land[i][j]); //2번작업은 1초소요
            }
        }
    }
    if (b < 0) //최종적으로 블럭이 음수면 불가능한 높이
        return INF + 1; 
    return tot_time;
}

/**
 * 1. 가장 낮은 땅의 높이를 h라고 할 때, h-1의 높이를 만드는건 h보다 2*(N*M)의 시간이 더 소요됨
 * 2. 가장 높은 땅의 높이를 h라고 할 때, h+1의 높이를 만드는건 h보다 (N*M)의 시간이 더 소요됨
 * -> 따라서 땅의 높이가 될 수 있는 후보는 (가장 낮은 땅) ~ (가장 높은 땅)
 * -> 가능한 모든 높이에 대해 브루트포스 연산해도 시간 초과 X
 *
 */
int main() {
    int n, m, b, min_height = 256, max_height = 0;
    //N개의 줄에 각각 M개의 정수로 땅의 높이가 주어짐. (i + 2)번째 줄의 (j + 1)번째 수는 좌표 (i, j)에서의 땅의 높이를 나타냄.

    //입력
    cin >> n >> m >> b;
    vector<vector<int>> land(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> land[i][j];
            min_height = min(min_height, land[i][j]); //제일 낮은 땅 높이
            max_height = max(max_height, land[i][j]); //제일 높은 땅 높이
        }
    }

    //연산
    int min_time = INF, height = 0; ////땅을 고르는 데 걸리는 시간, 땅의 높이
    for (int i = min_height; i <= max_height; i++) {
        int t = mineLand(n, m, b, i, land);
        if (t <= min_time) { //가장 빨리 작업이 끝나는 높이
            min_time = t; //최소시간 갱신
            height = i; //그때의 땅의 높이 저장.
        }
    }

    //출력
    cout << min_time << ' ' << height; //땅을 고르는 데 걸리는 시간과 땅의 높이를 출력
}