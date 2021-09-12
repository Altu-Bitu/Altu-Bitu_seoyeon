#include <iostream>
#include <vector> 

using namespace std;


//정렬할 배열
vector<int> arr;


void bubbleSortAdv(int n) {
    int cnt = 0;

    for (int i = 0; i < n-1; i++) {
        bool flag = true;
        //0 ~ n-1까지 정렬 -> 0 ~ n-2까지 정렬 -> ... -> 0 ~ 1까지 정렬
        for (int j = 1; j < n - i; j++) {
            if (arr[j - 1] > arr[j]) {
                flag = false;
                swap(arr[j - 1], arr[j]);
            }
            cnt++;
        }
        //출력할게 아니라면 return 으로 수정해도 됨


        for (int i = 0; i < n; i++)
            cout << arr[i];

            cout << endl;

        if (flag)
            break;
    }
    cout << "Count : " << cnt << '\n';
}

int main() {


    int n;

    //입력
    cin >> n;
    arr.assign(n, 0); //크기를 n만큼 할당하고 값을 0으로 초기화함.
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    bubbleSortAdv(n);


    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;

}