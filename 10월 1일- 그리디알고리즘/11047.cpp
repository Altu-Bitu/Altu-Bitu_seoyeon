#include <iostream>
#include <vector>

using namespace std;

//필요한 동전 개수의 최솟값 구하는 함수
int coinCnt(int n, int k, vector<int>& coin) {

    //가치가 큰 동전부터 순서대로 최대로 사용하자! (동전개수 최소)

    int cnt = 0; //필요한 동전 개수 카운트

    for (int i = n - 1; i >= 0; i--) { //i:동전 인덱스

        if (k == 0) //목표금액을 다 충족한 경우.
            break;

        if (coin[i] <= k) { //동전 사용이 가능하면

            cnt += (k / coin[i]); // 사용할 수 있는 만큼 최대로 cnt에 더해줌 
            k = k % coin[i]; //남은 금액
        }
    }

    return cnt;
}

int main() {

    int n, k; //동전개수, 목표금액

    //입력
    cin >> n >> k;

    vector<int> coin(n, 0);
    for (int i = 0; i < n; i++)
        cin >> coin[i];

    //연산 & 출력
    cout << coinCnt(n, k, coin);

    return 0;
}