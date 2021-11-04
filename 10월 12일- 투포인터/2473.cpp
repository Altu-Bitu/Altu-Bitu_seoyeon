#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

//값하나를 고정해놓고, 나머지 용액들로 target에 가깝도록 용액의 합을 구하자! 
pair<ll, ll> liquid(vector<int>& arr, int left, int right,int target) {
    pair<ll, ll> ans;
    int min_diff = 2 * 1e9 + 1 + abs(target); 

  
    while (left < right) {
        int mix = arr[left] + arr[right]; //두 용액을 혼합
        if (mix == target) //그 값이target이라면 이보다 더 target에 가까워질 수 없기 때문에 바로 리턴
            return make_pair(arr[left], arr[right]);

        // target에 가까운 값을 갱신할 수 있는지 확인.
        // 두 용액의 합이 target에 가깝다 => | 두 용액의 합 - target| 가 더 적다.
        if (abs(mix- target) < min_diff) {
            min_diff = abs(mix - target);
            ans = make_pair(arr[left], arr[right]);
        }
        if (mix > target) //target보다 크면 더 작은 값을 만들어야 함
            right--;
        else if (mix < target) //target보다 작으면 더 큰 값을 만들어야 함
            left++;
    }
    return ans;
}


int main() {

    int n; //용액의 수

    //입력
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //연산
    sort(arr.begin(), arr.end());

    int sum = 3 * 1e9 + 1;
    vector <ll> ans(3,0);
    for (int i = 0; i < n; i++) {

        //arr[i]를 고정해놓고 i+1 ~ n-1까지 두 용액의 합이 -arr[i]가 되도록하자! 
        pair<ll, ll> ans_sub = liquid(arr, i, i+1,-arr[i]);

        int temp = abs(ans_sub.first + ans_sub.second + arr[i]);
        if (temp < sum)
        {
            sum = temp; //0에 가까운 값 갱신

            ans[0] = arr[i];
            ans[1] = ans_sub.first;
            ans[2] = ans_sub.second;
        }
    }
   
    //출력
    cout << ans[0] << ' ' << ans[1]<<' '<<ans[2]; 
}