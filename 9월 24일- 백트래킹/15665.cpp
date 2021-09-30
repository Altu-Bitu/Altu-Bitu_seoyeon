#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

const int SIZE = 7;

int n, m; 
int sequence[SIZE]; //수열
vector<int> num; //주어진 수를 중복하지 않고 오름차순으로 저장할 수열


//재귀함수로 구현한 백트래킹
//cnt : 수열의 인덱스 (= 현재 수열의 길이)
void backtracking(int cnt) {

    if (cnt == m) { //기저조건
        for (int i = 0; i < cnt; i++)
            cout << sequence[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i <num.size(); i++) {
      
        sequence[cnt] = num[i]; //수열 저장
            
            backtracking(cnt + 1); //호출
        
    }
}

int main() {
    //입력
    cin >> n >> m;

    while (n--) {

        int t;
        cin >> t;
        num.push_back(t);
        
    }
   
    sort(num.begin(), num.end()); // 오름차순 정렬
    num.erase(unique(num.begin(), num.end()), num.end()); //중복원소를 vector의 제일 뒷부분으로 보낸다음 쓰레기 값 삭제.
  
   
    backtracking(0);


    return 0;
}