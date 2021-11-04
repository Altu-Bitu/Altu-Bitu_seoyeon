#include <iostream>
#include <vector>

using namespace std;

//블루레이 크기가 mid일 때, 몇 개의 블루레이를 쓰는지 리턴
int bluRayNum(vector<int> &lesson, int size) {
    int len = 0; //한 블루레이에 들어가는 강의 길이
    int cnt = 0; //블루레이 개수

    for (int i = 0; i < lesson.size(); i++) { // 강의의 개수만큼
        if (len + lesson[i] > size) { //한 블루레이에 들어갈 수 있는 길이를 초과한다면
            len = 0; // 강의길이를 0으로 초기화
            cnt++; // 블루레이 개수 늘림
        }
        len += lesson[i]; // 현재 강의의 길이만큼 len을 늘림 -> size를 초과하는지 아닌지 판단 위함.
    }

    return cnt + 1; //마지막 구간의 블루레이 더해서 리턴
}

int lowerSearch(vector<int> &lesson, int left, int right, int target) {
    int ans = 0; //m개의 블루레이를 만족할 때 최소 크기
    while (left <= right) { // left와 right가 교차되면 반복문 종료.
        int mid = (left + right) / 2; // 이분탐색을 위한 기준점
        int cnt = bluRayNum(lesson, mid); //mid일때 사용하는 사용하는 블루레이 개수

        if (cnt <= target) {  // cnt가 주어진 블루레이 갯수보다 작다면
            right = mid - 1; // 왼쪽 탐색
            ans = mid; //cnt == target일 때
        } else {
            left = mid + 1; //오른쪽탐색
        }
    }

    return ans; //리턴
}

/**
 * m개의 블루레이에 모든 기타 강의 동영상을 녹화할 때 블루레이 크기의 최소를 구하는 문제
 * -> 특정 블루레이 크기로 기타 강의 동영상을 차례로 녹화할 때, 총 블루레이 개수가 m개가 되는가?
 *
 * left: 가능한 블루레이의 최소 크기 (블루레이 최대 개수) -> 가장 긴 강의 길이값
 * right: 가능한 블루레이의 최대 크기 (블루레이 최소 개수) -> 모든 강의를 더한 길이값
 */

int main() {
    int n, m, left = 0, right = 0; //n개의 강의, 블루레이의 수, 이분탐색을 위한 left,right 포인터

  
    cin >> n >> m;  //입력

    vector<int> lesson(n, 0); // 강의의 길이를 입력받을 컨테이너
    for (int i = 0; i < n; i++) { //n번의 강의
        cin >> lesson[i];  //각 강의의 길이가 분단위로 주어짐.
        left = max(left, lesson[i]); //가장 긴 강의 길이값 찾기
        right += lesson[i]; //모든 강의 길이 더하기
    }

    
    cout << lowerSearch(lesson, left, right, m);//연산 & 출력

    return 0;
}