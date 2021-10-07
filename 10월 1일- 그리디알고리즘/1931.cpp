#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci; // 회의의 시작시간, 끝나는 시간을 담을 pair 컨테이너

bool cmp(const ci& a, const ci& b) {
    

    //1. 끝나는 순서가 빠른 순
    //2. 시작시간이 빠른 순

    if (a.second == b.second) //끝나는 시간이 같다면
        return a.first < b.first; //시작시간이 빠른순으로

        return a.second < b.second; //끝나는 시간이 같지 않다면 끝나는 시간이 빠른순으로
}

//사용할 수 있는 회의실의 최대 개수
int maxMeeting(int n, vector<ci> meeting) {
   

    int end = meeting[0].second; //첫번째 회의가 마쳐지는 시간
    int cnt = 1; //회의실 개수

   
    for (int i = 1; i < n; i++) {

        if (meeting[i].first >= end) //다음회의의 시작시간이 현재 회의의 끝나는 시간보다 클 경우 배치.
        {
            cnt++; //회의를 이어서

            end = meeting[i].second; //끝나는 시간 갱신

            
        }


           

    }
    //들어갈 자리가 있으면 이어서 넣는다
    
    //시작 시간과 끝나는 시간은 231-1보다 작거나 같은 자연수 또는 0이다.
}

int main() {

    int n; //회의 총 개수


    //입력
    cin >> n;
    vector<ci> meeting(n, ci(0, 0)); 

    for (int i = 0; i < n; i++)
        cin >> meeting[i].first >> meeting[i].second;

    //연산
    sort(meeting.begin(), meeting.end(), cmp);

    //연산 & 출력
    cout << maxMeeting(n, meeting);

    return 0;
}