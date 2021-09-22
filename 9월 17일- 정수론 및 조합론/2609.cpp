#include <iostream>
#include <vector> 

using namespace std;
  


int gcdRecursion(int a, int b) {

	// 앞자리에 b, 뒷자리에 a%b 넣는 작업 반복하기

	if (b == 0) {

		return a;
	}
	return gcdRecursion(b, a % b);


}

int main()
{
	int a, b;
    
	cin >> a >> b;

	/* 반복문으로 gcd 구현
	
	//GCD (a,b) = GCD (b,a%b)

	while (b) //b가 0일때 a가 최대공약수 
	{

		int tmp = a % b;
		a = b;
		b = tmp;
	}
	//반복문을 마쳤을때의 a값 = gcd

	
	*/
	int g = gcdRecursion(max(a, b), min(a, b)); //최대공약수 저장

	cout << g << '\n' << a * b / g;




}