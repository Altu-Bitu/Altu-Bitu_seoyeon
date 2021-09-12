#include <iostream>
#include <vector> 
#include <map> 



using namespace std;

int main() {

	int n;
	long k;
	
	

	vector <int> sum; //누적합
	map <int, int> m; // 누적합, 누적합이 나온 횟수

	cin >> n>> k;

	long long temp = 0;

	for (int i = 0; i < n; i++) {
		
		int a;
		cin >> a;
		temp += a;

		sum.push_back(temp); //i번째까지의 누적합을 i번째 요소에 저장.

	}

	long long cnt = 0; //cnt 는 최대  약 200,000 * 200,000 정도
	

	//i를 고정시켜놓고,  k = sum[i] - sum[x] 를 만족하는 sum[x]의 경우의 수를 구하자.
	// 이때, x도 같이 돌면서 확인작업을 거치면 o(n^2) 이어서 시간초과가 나온다.
	// 따라서 sum[x] = sum[i]-k 를 만족시키는 누적합 sum[x] 가 나온 횟수를 알기 위해서 map을 하나 만들어 저장시켜둔다.

	for (int i = 0; i < n; i++) {

		if (sum[i] == k) //i번째까지의 부분합이 k 자체라면
			cnt++; 

		cnt += m[sum[i] - k]; //sum[i] - x = k 를 만족하는 x의 경우의수는 m[sum[i]- k] 와 같다.

		m[sum[i]]++;


	}

	/* map확인용
	for (auto iter : m) {

		cout << iter.first << iter.second << '\n';
	}*/
	

	cout << cnt;


}