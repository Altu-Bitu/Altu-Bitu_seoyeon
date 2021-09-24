#include <iostream>
#include <vector> 
#include <string>

using namespace std;

//gcd (a,b) = gcd (b,a%b)
int gcdRecursion(int a, int b) {
	
	if (b == 0) {

		return a;
	}
	return gcdRecursion(b, a % b);


}


int main() {

	string s;

	cin >> s;

	// n:m이 주어졌을때 n과 m을 int형으로 추출하기

	int index = s.find(':'); //:이 들어있는 인덱스

	//substr (a,b) -> a이상 b미만 영역의 스트링 추출 
	int n = stoi(s.substr(0, index)); //0부터 index 전까지 서브스트링추출하고 숫자로 변환.
	int m = stoi(s.substr(index + 1, s.length())); // index +1 부터 length전까지 서브스트링 추출하고 숫자로 변환.


	int g= gcdRecursion(n, m);//두수의 최대공약수

	//n,m을 최대공약수 g로 나눠준다면 n/g와 m/g는 서로소가 됨. 
	cout << n / g << ':' << m / g;   


}

