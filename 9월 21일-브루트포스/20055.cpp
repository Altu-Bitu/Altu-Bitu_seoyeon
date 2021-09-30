#include <iostream>
#include <vector>

using namespace std;

struct info { //내구도와 로봇 존재 여부
    int power; // 내구도
    bool is_on; // 로봇이 올려져 있는지 여부
};

vector<info> belt;  //컨테이너 벨트 정보(내구도, 로봇 여부)
int zero_power;     //내구도가 0인 벨트 칸의 개수


//1단계 -> 벨트를 회전시키기위해서 벡터값을 일일히 shift해줄필요 없다. 
 //컨베이어 벨트는 고정하고, 올리는위치(start)와 내리는 위치(end)만 바꿔주면 된다. 

//컨베이어 한줄의 길이가 n일때 pos에서 한칸뒤로간 position을 구해주는 함수.
int minusPosition(int n, int pos) { //인덱스 감소

    if (--pos >= 0) //감소시킨 위치가 0보다 클때에만 pos값 반환 -> 0보다 작아지면 한바퀴를 초과했다는 뜻이므로.
        return pos;

    return n * 2 - 1; // 한바퀴를 초과해서 돌면 다시 끝점으로 초기화.
}


//두번째 단계 ->가장 먼저 벨트에 올라간 로봇부터, 벨트 회전 방향으로 한 칸 이동할 수 있다면 이동
void second(int n, int start, int end) {

    int cur = end; //end쪽에 있는 로봇이 가장 먼저 벨트에 올라간 로봇이므로 cur을 end로 초기화.
    while (cur != start) { //end - 1 부터 start 까지 검사 

        cur = minusPosition(n, cur); //end -> end-1로 만들기 위함.
        int next = (cur + 1) % (n * 2); //다음칸의 위치. 2n으로 모듈러 연산을 해주어야 항상 0 ~ 2n-1의 인덱스를 가짐.

        if (belt[cur].is_on && !belt[next].is_on && belt[next].power) { //현재 위치에 로봇이 있고, 다음 위치에 로봇이 없으며 내구성 1이상인 경우 -> 로봇 옮김
            belt[cur].is_on = false; //현재 위치에서 로봇을 내린다.
            belt[next].power--; //다음칸 내구도 감소

            if (next != end) //내리는 위치 아닐 경우만
                belt[next].is_on = true; //로봇 옮기기

            if (belt[next].power == 0)// 다음칸의 내구도가 0이라면
                zero_power++; //내구도가 0인 칸의 개수 +1
        }
    }
}

//세번째 단계 -> 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇 올림
void third(int start) {
    if (belt[start].power) { //올리는 위치의 내구도가 0이 아니라면 
        belt[start].is_on = true; //로봇 올림
        belt[start].power--; // 올렸으니 내구도 감소시킴.
        if (belt[start].power == 0) //만일 로봇을 올림으로서 내구도가 0이 되었다면
            zero_power++;//내구도가 0인 칸의 개수 +1
    }
}
// 로봇이 올라가 있는 상태로 시작하는것이 아님. 

// 내리는 위치에 도달하면 무조건 내림.

/**
 * [컨베이어 벨트 위의 로봇 문제]
 * 1. 벨트가 각 칸 위의 로봇과 함께 한 칸 회전
 * 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트 회전 방향으로 한 칸 이동할 수 있다면 이동 (이동가능: 이동하려는 칸에 로봇이 없고, 그 칸의 내구도가 1 이상이어야 함)
 * 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇 올림
 * 4. 내구도가 0인 칸의 개수가 k개 이상이라면 과정 종료. 그렇지 않다면 1로 돌아감
 * -> 1 ~ 3까지가 1단계
 *
 * [문제 풀이]
 * 벨트의 로봇을 옮기는 게 아니라, 올리는 위치와 내리는 위치의 인덱스 값을 바꿔서 접근
 * 필요한 컨테이너: 내구도와 로봇의 존재여부를 체크할 배열
 * 1번: 벨트의 방향이 오른쪽이므로, 벨트 한 칸 회전 시 올리는 위치와 내리는 위치의 인덱스 값은 하나 감소
 * 2번: 가장 먼저 올라간 로봇부터 고려해야 하므로 (내리는 위치 - 1)부터 (올리는 위치)까지 검사 -> 로봇 옮기는 거 가능하면 존재여부 체크하고 내구도 감소
 * 3번: 올리는 위치 칸 내구도 0이 아니라면 해당 칸 로봇 존재 여부 체크 + 내구도 감소
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; // n: 위쪽 컨베이어벨트의 길이, k:내구도가 0인 칸의개수 (종료조건)

    //입력
    cin >> n >> k;
    belt.assign(n * 2, { 0, false }); // 모든 칸의내구도 0, 로봇 올려져있지 않은 상태로 초기화하기.

    for (int i = 0; i < n * 2; i++) // 총 칸의 개수 2n만큼 
        cin >> belt[i].power;//내구도 입력받기.

    //연산
    int start = 0;    //올리는 위치
    int end = n - 1;  //내리는 위치
    int step = 0;     //단계 수

    while (true) {

        
        //1번 -> 컨베이어벨트 회전(로봇과 함께)
        start = minusPosition(n, start);
        end = minusPosition(n, end);

        if (belt[end].is_on) //벨트 회전 후, 로봇이 내리는 위치에 있다면 내리기
            belt[end].is_on = false;

        //2번 -> 벨트 회전방향으로 로봇들이 한칸씩 이동.
        second(n, start, end);


        //3번 -> 올리는위치에 로봇올림
        third(start);

        step++; // 1~3번을 마치면 1단계를 마친것.

        if (zero_power >= k) //내구도가 0인 칸의개수가 k개 이상이라면
            break; //반복문을 종료한다.
    }

    //출력
    cout << step << '\n';

    return 0;
}