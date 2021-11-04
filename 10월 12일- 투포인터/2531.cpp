#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int getKinds(vector <int> check) { //check배열을 주면 초밥 가짓수 리턴

    int kinds = 0;
    for (int i = 1; i < check.size(); i++) {
        if (check[i] != 0) //해당 초밥 종류가 하나라도 있다면
            kinds++;
    
    }

    return kinds;

}

//슬라이딩 윈도우로 최대 스시가짓수를 구하고 리턴
int maxSushi(int n,int d, int k, int c, vector<int>& sushi) { //초밥접시수,가짓수, 연속수,쿠폰번호
    //윈도우 초기화
    int section = 0; // 구간의 접시수

    vector <int> check(d+1,false); // 해당 초밥의 개수 판단 (먹었는지 안먹었는지)

   

    //첫번째 윈도우
    for (int i = 0 ;i < k; i++)
      check[sushi[i]] ++;

    int ans = getKinds(check); //최대초밥 가짓수 초기화
   
    //슬라이딩
    for (int i = k; i < n + k-1; i++) {

        // 회전초밥이 원형으로 돈다 -> % 연산자 활용!

        check[sushi[(i - k) % n]] --;     //이번 윈도우에 제외되는 값
        check[sushi[i % n]] ++;         //이번 윈도우에 추가되는 값
     
        
        check[c] = 1; //쿠폰번호 초밥은 무조건 먹음.
     
            ans = max ( getKinds(check),ans); 
          
    }
    return ans;
}

int main() {

	int n, d, k, c; //접시수,초밥가짓수, 연속접시수,쿠폰번호


	cin >> n >> d >> k >> c;

	vector <int> sushi(n, 0);

	for (int i = 0; i < n; i++) {

		cin >> sushi[i];
	}

    cout << maxSushi(n,d,k, c, sushi);

}