#include <iostream>
#include <vector> 


//asdfasdf
using namespace std;

int main() {

	int N, K;


	vector <int> v; 

	int sum=0;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		
		int k;
		cin >> k;
		v.push_back(k); //i번째까지의 누적합을 i번째 요소에 저장.

		//cin >> v[i]; -> 이렇게 입력받으면 공간이 할당되지 않은 상태이므로 오류남!!


	}


	
	//v[0] + v[1] +v[2]...v[n-1]
	// v[1] + v[2] ...v[n-1]
	//  ..
	// v[n-2] + v[n-1] 

	// 방법 1
	// 바깥포문 -> i를 포함해서 만들 수 있는 부분합.
	// 안쪽포문 -> j가 i+1 ~ N 까지 돌면서 수를 더해감. 이때  값을 하나 더할때마다 K가 되는지 확인하고 맞다면 cnt++

	int sum; //부분합을 저장해놓을 공간
	int cnt = 0; //부분합의 갯수

	for (int i = 0; i < N; i++) {

		sum = 0; // 부분합 초기화 

		for (int j = i; j < N; j++) {

			sum += v[j];
			if (sum == K)
				cnt++;


		}
	}

	//하지만 배열에 값을 저장하고 지정된 인덱스부터 하나씩 더해가는 방식은 최악의 경우O(n ^ 2)의 시간복잡도를 갖기 때문에 입력의범위가 클 때 사용할 수 없다.
	// N이 최대 200,000이므로 O(N)안으로 끝내야한다.
	// 힌트-> 부분합 공식 활용해서 나중에 다시 풀기. 
	


	cout << cnt;


}