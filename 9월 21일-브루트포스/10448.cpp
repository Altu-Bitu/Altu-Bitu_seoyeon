#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 45; //1000을 넘어가는 삼각수는 필요없으므로 index는 45까지.

vector<int> tri_num(SIZE); //삼각수를 저장할 배열



//유레카인지 검사하는 반복문 함수
bool eureka(int num) {
    for (int i = 1; i <= 45; i++) {
        for (int j = 1; j <= 45; j++) {
            for (int k = 1; k <= 45; k++) {
                if (tri_num[i] + tri_num[j] + tri_num[k] == num) // num이 삼각수의 조합으로 만들어질수 있다면 
                    return true;//유레카이다.
            }
        }
    }

    return false; //if문에 걸리지 않으면 유레카가 아니다.
}

/**
 * [유레카 이론]
 * 삼각수 T(n) = n * (n + 1) / 2
 * 어떤 자연수가 정확히 3개의 삼각수의 합으로 표현 가능한지 검사해라
 *
 * [풀이]
 * 어떤 자연수(k)가 주어졌을 때, n=1부터 모든 삼각수 합을 3개씩 조합해보자
 * 이때, n = 45일 때, T(45) = 45 * 46 / 2 = 1,035 이고, k의 최댓값은 1,000이므로 45의 삼각수까지만 계산하면 됨!
 * 모두 해봤자, 45 * 45 * 45 < 1억 이므로, 브루트 포스 접근 완전 가능!
 */

int main() {
    int t, k;

    //입력
    cin >> t;

    //삼각수 SIZE까지 미리 구하기 -> while문을 돌때마다 구하면 너무 비효율적.
    for (int i = 1; i <= 45; i++)
        tri_num[i] = i * (i + 1) / 2; //n번째 삼각수 공식 s[n]=n(n+1)/2 .
    //tri_num[i]에는 i번째 삼각수값이 담긴다.

    //입력 + 연산 + 출력
    while (t--) {
        cin >> k;

        //반복문 풀이
        cout << eureka(k) << '\n'; // k가 유레카인지 확인한다.

 
    }

    return 0;
}





