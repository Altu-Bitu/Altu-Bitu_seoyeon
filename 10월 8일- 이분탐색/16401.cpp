#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//과자 길이가 mid일 때 몇 명에게 나눠주는지
int childNum(vector<int> &snacks, int len) {
    int cnt = 0; //몇 명에게 나누어주는지
    for (int i = snacks.size() - 1; i >= 0; i--) { //가장 긴 과자부터 검사
        if (snacks[i] < len) //나누어주려는 길이보다 작아지면 더 이상 못 나눠줌
            break; // 따라서 반복문 종료
        cnt += (snacks[i] / len); // 각 스낵의 길이/len만큼 나누어줄 수 있는 사람수가 추가.
    }

    return cnt; //리턴
}

int upperSearch(vector<int> &snacks, int left, int right, int target) {
    int ans = 0; //
    while (left <= right) { //left,right 교차시 탐색종료
        int mid = (left + right) / 2; //과자의 길이
        int cnt = childNum(snacks, mid); //과자의 길이가 mid일때 나누어줄 수 있는 아이들의 수

        if (cnt >= target) { //target보다 더 많은 아이들에게 나눠준다면 -> 과자 길이를 더 늘릴 수 있음
            left = mid + 1; // 오른쪽탐색
            ans = mid; // 종료조건에 걸리면 리턴할 답 세팅.
        } else {
            right = mid - 1; //왼쪽탐색
        }
    }

    return ans; //리턴
}

/**
 * n개의 과자가 있을 때 m명의 조카에게 각각 같은 길이로 줄 수 있는 과자의 최대 길이를 구하는 문제
 * -> 특정 과자 길이에 대하여 m명의 조카에게 나누어 줄 수 있는가?
 *
 * left: 과자 길이의 최솟값 -> 1
 * right: 과자 길이의 최댓값
 *
 * 과자를 몇 명에게 나누어줄 수 있는지 차례로 검사하다 나누어줄 수 없으면 빠져나오기 위해 정렬을 먼저 해주면 좋음
 */

int main() {
    int m, n, left = 1, right = 0; //조카의 수, 과자의수, 이분탐색을 위한 포인터

    //입력
    cin >> m >> n;
    vector<int> snacks(n, 0); //과자의 길이를 담을 컨테이너
    for (int i = 0; i < n; i++) //과자의 수 만큼
        cin >> snacks[i]; //입력

    //연산
    sort(snacks.begin(), snacks.end()); //오름차순 정렬
    right = snacks[n - 1]; // snacks[n]은 존재 X

    //연산 & 출력
    cout << upperSearch(snacks, left, right, m);

    return 0;
}