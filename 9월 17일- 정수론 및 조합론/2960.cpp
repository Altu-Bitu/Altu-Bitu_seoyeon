#include <iostream>
#include <vector> 

using namespace std;





//에라토스테네스의 체에서 k번째 지우는 수를 구하는 함수

int isPrime(int n, int k) {

	vector<bool> is_prime(n + 1, true); // 다 소수라고 생각

	int cnt = 0;//횟수 카운트


	// Q. 루트 N까지가 아니라 N까지 검사하는이유?
	
	// A. bool배열로 구현했던 에라토스테네스의 체와는 다르게, 본 함수는 `소수도 포함하여 지운다`. 
	// 즉, 제곱근까지 검사할 경우 반례( k번째 지워지는 수가 제곱근 이상의 소수일 경우)가 생기므로  꼭 n까지 모두 돌려야한다. 
	// ex) 2~30 까지 검사하는데 k번째 지워지는 수가 만일 29라면 제곱근까지 검사했을때에는 29를 지우지 못한다. 

	for (int i = 2; i <= n; i++) {

		if (is_prime[i]) { //i가 소수라면

		
			for (int j = i; j <= n; j+=i) {

				if (!is_prime[j]) //이미 지워졌다면 
					continue; //카운트하지않음

				is_prime[j] = false;// i의 배수를 제거
				//cout << j << '\n';//디버깅용

				if (++cnt == k)
				     return j; //k번째 지우는 수 리턴

			}
			

		}
	}


}


int main() {



	int n, k;

	cin >> n >> k;


	cout << isPrime(n, k);


	 
}