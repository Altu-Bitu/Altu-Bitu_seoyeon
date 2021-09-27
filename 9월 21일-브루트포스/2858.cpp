#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;



int main() {

	int inside, outside;
	int L, W;

	int outside_needed;



	cin >> outside >> inside;

	//inside를 두수의 곱(a * b)으로 나타내기
	int a, b;
	for (int i = 1; i <= sqrt(inside); i++) {

		if (inside % i == 0)

			a = i;
			b = inside / i;


		outside_needed = a * 2 + b * 2 + 4;

		if (outside_needed == outside) //inside를 기준으로 필요한 outside 블럭의 개수가 맞아떨어지면,
		{
			L = max(a + 2, b + 2);
			W = min(a + 2, b + 2);
			break;
		}

	}




	cout << L << ' ' << W;



}