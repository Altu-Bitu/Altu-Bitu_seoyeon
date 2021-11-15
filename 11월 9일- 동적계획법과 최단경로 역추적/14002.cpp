#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

vector<int> back(int x, vector<int>& path) { // x : 역추적을 시작하는 위치
    vector<int> result(0); //Lis의 마지막 원소 인덱스부터 들어감
    while (x != -1) {
        result.push_back(x);
        x = path[x]; //다음 경로
    }
    return result;
}

//시간 복잡도 O(n^2) Lis
ci lis(int n, vector<int>& arr, vector<int>& path) {
    vector<int> dp(n, 1);
    ci ans = { 1, 0 }; //최장 길이, 마지막 원소 인덱스

    //본인의 원소보다 작으면서 dp값이 가장 큰 것을 찾아서 더하기.
    for (int i = 1; i < n; i++) {
        int index = -1; //경로 저장할 변수
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] <= dp[j]+1 ) { //증가하는 관계, 가장 큰 dp[j] 
                dp[i] = dp[j]+1;
                index = j;
            }
        }
        path[i] = index;
        if (ans.first < dp[i]) //최장 길이 + 마지막 원소 인덱스 갱신       
            ans = { dp[i], i };
    }
    return ans;
}

/**
 * 동적계획법 역추적
 * - 기본 문제: 가장 긴 증가하는 부분 수열
 */

int main() {
    int n;

    //입력
    cin >> n;
    vector<int> arr(n); //수열
    vector<int> path(n, -1); //경로 저장 배열
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //연산
    ci ans = lis(n, arr, path); //first: 최장 길이, second: 최장 길이의 마지막 원소 인덱스
    vector<int> result = back(ans.second, path);

    //출력
    cout << ans.first << '\n';
    for (int i = result.size() - 1; i >= 0; i--)
        cout << arr[result[i]] << ' ';
    return 0;
}