#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> innings; // 각 선수가 각 이닝에서 얻는 결과
vector<int> order(10, 0); //타순
vector<bool> check(10, false); //n번 선수의 순서가 결정되었는지를 저장할 check배열
int n, ans; //이닝 수,정답

//현재 배치의 점수
int calcScore() {
    int score = 0; //총 점수
    int idx = 1; //타순 저장된 order 인덱스 번호
    for (int i = 0; i < n; i++) { //i: 이닝
        vector<bool> baseman(4, 0); //각 루수마다 선수가 있는지
        int out = 0; //아웃 선수 카운트
        while (out < 3) { //out이 3회미만일 경우에만 현재 이닝 지속.
            int state = innings[i][order[idx++]]; //현재 선수의 공격 상태
            if (idx == 10) // 9번타자까지 공을쳤다면
                idx = 1; // 1번타자가 다시 타석에 섬.
            switch (state) {
                case 0: //아웃
                    out++; //아웃횟수 1증가
                    break; 
                case 1: //안타, 1루씩 진루
                    score += baseman[3]; //3루에 있는 선수있다면 홈 도착
                    //이부분 조건반복문이 0이 아니라 1이어도 됨! 
                    for (int i = 3; i > 1; i--) //현재 루에 서있는 선수들을
                        baseman[i] = baseman[i - 1]; //다음 루로 한칸씩 옮겨줌
                        // 1->2,2->3.
                    baseman[1] = 1; //새로운 선수 1루에 도착
                    break;
                case 2: //2루타, 2루씩 진루
                    score += baseman[3] + baseman[2]; //3루, 2루에 선수 있다면 홈 도착
                    baseman[3] = baseman[1]; //1루 -> 3루 이동
                    baseman[2] = 1; //새로운 선수 2루에 도착
                    baseman[1] = 0; //초기화
                    break;
                case 3: //3루타, 3루씩 진루
                    for (int i = 3; i > 0; i--) { //3루, 2루, 1루에 선수 있다면 홈 도착
                        score += baseman[i]; // 득점
                        baseman[i] = 0; // 모든 루를 0으로 초기화
                    }
                    baseman[3] = 1; //새로운 선수 3루에 도착
                    break;
                case 4: //홈런
                    for (int i = 3; i > 0; i--) { //3루, 2루, 1루에 선수 있다면 
                        score += baseman[i]; //득점
                        baseman[i] = 0; //모든 루를 0으로 초기화
                    }
                    score++; //새로운 선수도 홈 바로 도착
                    break;
            }
        }
    }

    return score;
}

//가능한 배치 모두 구하기
void array(int cnt) { //cnt: 타자순서
    if (cnt == 4) { //4번 타자는 정해져 있으므로
        array(cnt + 1); //다음 타자의 순서를 모색한다.
        return; //리턴
    }
    if (cnt == 10) { //9번 타자까지 정해짐 (기저조건)
        int score = calcScore(); //점수 계산
        ans = max(ans, score); // ans < score 이면 score값을 갱신
        return; //리턴
    }
    for (int i = 2; i <= 9; i++) { // 1번타자의 선수는 정해져있으므로 2~9까지!
        if (!check[i]) {
            order[cnt] = i; //cnt번 타자: i번 선수
            check[i] = true; //i번 선수 순서 정해짐
            array(cnt + 1); //다음 타자
            check[i] = false; //다음 탐색을 위해 원래대로 돌려놓기
        }
    }
}

/**
 * 구현 + 브루트 포스, 백트래킹
 * 1. 우선 가능한 타순을 모두 구한다. (이때, 4번 타자는 항상 1번 선수여야 함) (브루트 포스, 백트래킹)
 * 2. 구한 타순에 대한 각각의 점수를 구하며 최대 점수를 갱신한다. (구현)
 */

int main() {
    
    cin >> n;//입력
    innings.assign(n, vector<int>(10, 0)); //할당 및 0으로 초기화

    for (int i = 0; i < n; i++) { // 0~n-1
        for (int j = 1; j < 10; j++) { // 1~9
            cin >> innings[i][j]; //i번째 이닝에서 n번 선수 득점값 (1~9) 입력
        }
    }

    //연산
    order[4] = 1; //4번 타자는 1번 선수
    check[1] = true; //1번 선수는 순서 정해짐
    array(1); //1번째 타자 순서부터 모색시작.

    //출력
    cout << ans << '\n';

    return 0;
}