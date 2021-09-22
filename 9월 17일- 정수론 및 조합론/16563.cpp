#include <iostream>
#include <vector> 
#include <cmath>//sqrt제곱근함수

using namespace std;


const int SIZE = 5000000;

//소수판단 여부 정보가 아닌 어느 소수의 배수로 지워졌는지 저장. 
vector <int> isPrime() {

	
	vector<int> prime(SIZE + 1, 0);
	//Q SIZE가 아니라 SIZE +1 인이유? index와 숫자를 일치시키기 위함(계산의 편리함).


	//먼저 모든 수를 소수라고 가정하고, i번째 인덱스에 i값 저장
	for (int i = 2; i <= SIZE; i++) {

		prime[i] = i;
	}

	for (int i = 2; i <= sqrt(SIZE); i++) {
		 
		if (prime[i]==i) { //i가 소수라면
			//cout << i << '\n';//디버깅용


			for (int j = i * i; j <= SIZE; j += i) { //i의 배수만큼 배수에 소수저장

				if (prime[j] == j) //아직 지워지지 않았을 경우에만 
					prime[j] = i; //자신을 지운 소수의 경로 저장
			}
		}
	}

	return prime;
}

//본 함수를 마쳤을때 prime[i]=i 라면 i는 소수인것. 

int main() {
	//입출력 속도 향상
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;

	//입력
	cin >> n;

	//미리 최대 크기까지의 소수 경로 저장.
	vector<int> prime = isPrime();


	while (n--) {

		//소인수분해할 수 입력
		cin >> k;

			//소인수분해 결과 출력
			while (k > 1) {
				cout << prime[k] << ' ';
				k = k / prime[k]; //마지막 소인수에 도달하게 되면(k가 소수가 되면) k/prime[k]값이 1이되어 반복문을 빠져나감.
			}
			cout << '\n';

	}
		return 0;
	
}

