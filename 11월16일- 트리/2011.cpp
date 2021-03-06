#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1e6;

int cntPassword(int n, string s) {
    vector<int> dp(n + 1, 0); //암호 해석할 수 있는 경우의 수를 저장할 1차원 dp배열

    if (s[0] == '0') // 처음 시작이 0인경우 
        return 0; // 암호해독불가능

    dp[0] = dp[1] = 1; //s[0]의 암호 해석 경우의 수 1로 초기화

    for (int i = 2; i <= n; i++) { // 두번째자리 ~ 마지막자리까지

        // 현재 수가 0인데 앞의 수가 1이나 2가 아닌경우 ex) 30,40
        if (s[i - 1] == '0' && (s[i - 2] < '1' || s[i - 2] > '2'))
            return 0; // 매치되는 알파벳 존재 X

        if (s[i - 1] != '0') // 현재수가 0이 아니라면  (한자릿수)
            dp[i] += dp[i - 1]; // 한자릿수로 해석하는 경우의 수 추가

        //  이전 스트링이 26이하의 수일경우 (두자릿수)
        if (s[i - 2] == '1' || (s[i - 1] <= '6' && s[i - 2] == '2'))
            dp[i] += dp[i - 2]; // 두자릿수로 해석하는 경우의 수 추가

        dp[i] %= MOD; // 정답이 매우 크다면, 1000000으로 나눈 나머지를 출력
    }
    return dp[n]; //dp[n]에는 최종으로 해석될수있는 경우의수가 저장됨.
}

/**
 * dp[i] = i인덱스까지 암호 해석할 수 있는 경우의 수 저장
 * => dp[i] = dp[i-1] + dp[i-2] (단, dp[i-1]과 dp[i-2]에서 이어서 암호 만들 수 있는 경우만)
 *
 * 1. '0' 혼자는 암호 해석 불가
 * 2. 처음 시작이 '0'인 경우 주의
 * 3. 현재 수가 '0'인데 앞의 수가 '1'이나 '2'가 아닌 경우 -> 암호 해석할 수 없음
 * 4. 두 개의 수를 하나의 알파벳으로 고려할 때, 26이하의 수인지 잘 확인해야 함
 *
 * 본 풀이는 dp 배열 인덱스를 편하게 관리하기 위해 1번 인덱스부터 시작
 */

int main() {

    string s; //암호

    //입력
    cin >> s;

    //연산 & 출력
    cout << cntPassword(s.length(), s) << '\n';
    return 0;
}