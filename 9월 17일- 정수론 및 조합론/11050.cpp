#include <iostream>
#include <vector> 

using namespace std;


int factorial(int n) {

	if (n == 0) return 1;
	else if (n == 1) return 1;
	else
		return n * factorial(n - 1);


}

int main() {

	int n, k;

	int nCk;

	cin >> n >> k;

	
	nCk = factorial(n) / (factorial(n - k) * factorial(k));



	cout << nCk;
}