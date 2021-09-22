#include <iostream>
#include <cmath>//sqrt제곱근함수

using namespace std;


/*

A를 GCD로 B를 LCM으로 하는 두개의 자연수 X,Y는 다음 식을 만족하여야한다. 

X * Y  = GCD * LCM 

X = GCD * m
Y = GCD * n 
(이때 m,n은 서로소) 이라고하면 

gcd * m * n = lcm

즉
m * n = lcm/gcd 을 만족하는


서로소 m , n 쌍을 찾고 그 값을 원래 식에 대입하여  X , Y를 구하자.

*/


int gcdRecursion(int a, int b) {

	if (b == 0) {

		return a;
	}
	return gcdRecursion(b, a % b);


}
int main() {


	
	int gcd, lcm;
	int m, n;
	int mn; //m * n 값을 저장해둘 변수

	cin >> gcd >> lcm;

	mn = lcm / gcd;



	// X + Y = gcd (m + n) 이므로
	//두 자연수의 합이 최소가 되려면 m + n의 합이 최소가 되어야함. 


	// m * n = mn 이면서 m + n = 최소로하는 서로소 m,n값을 찾자. 
	// m,n이 루트mn에 근접할수록 m+n값이 최소가 된다고 가정. -> 증명은 나중에 찾아보기

	for (int i = sqrt(mn); i >= 1; i--) {


		if (mn % i == 0)
		{
			m = i;
			n = mn / i;
			
			//m,n이 서로소인지 확인 
			if (gcdRecursion(n, m) ==1) //n,m의 최대공약수가 1이라면 (=서로소라면)
			{
				break; //반복문을 빠져나간다.

			}
		}

	}


	int x = gcd * m;
	int y = gcd * n;

	cout << x << ' ' << y;
}

