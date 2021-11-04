#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


// limit을 넘어가면 왼쪽 포인터 ++. ~조건만족할때까지
// 왼쪽 포인터 ++하다가 조건 넘으면 오른쪽 포인터++


bool isUpperLimit(map<int, int> m,int limit) { // 원소의 개수가 상한선을 넘었는지 확인해주는 함수

    for (int i = 0; i < m.size(); i++) {

        if (m[i] > limit)
            return true;
    }

    return false;
}



int max_Partial(vector<int>& arr, int limit) {

    int left = 0, right = 0, size = arr.size();
    int ans = 1;

    map<int, int> m; // 숫자,숫자 등장횟수 -> 각 원소가 k번 넘게 등장했는지 체크

   
    m[arr[left]]++; //초기 구간 (0,0)

    //left는 항상 right의 왼쪽 또는 같은 위치에 있어야 함
    while (left <= right && right < size) {

       // cout << left <<' '<< right << ' '<<ans<<'\n';

        if (!isUpperLimit(m, limit)) { //상한선을 넘지 않았다면
            right++; //구간을 길게하기 위해 right 이동
                ans = max(right - left, ans);
                if (right == size) //런타임 에러 방지
                    break;

                m[arr[right]]++; // 원소 추가
               
        }
        else //상한선을 넘었다면
        {
            m[arr[left]]--; // 원소 제거

            if (m[arr[left]] == 0)
                m.erase(arr[left]);

            left++; //구간을 짧게하기 위해 left 이동

        }
    }
  
    return ans;
}


int main() {



    int n, k; // 수열 길이 , 연속제한

    cin >> n >> k;

    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << max_Partial(arr, k); // 조건을 만족하는 최장 연속 부분 수열의 길이

}