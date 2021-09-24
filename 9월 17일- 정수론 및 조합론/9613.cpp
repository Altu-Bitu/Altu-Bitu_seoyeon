#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;



int gcd(int a, int b) {

	if (b == 0) {

		return a;
	}
	return gcd(b, a % b);


}

int main() {


	int n_testcase;

	int n; //주어질 수의 개수 

	cin >> n_testcase;

	while (n_testcase--)
	{

		cin >> n;
		vector<int> v(n);

		for (int i = 0; i < n; i++) {

			int a;
			cin >> a;
			v.push_back(a);
		}

		sort(v.begin(), v.end(), greater<int>());//내림차순 정렬

		long long sum = 0; //가능한 모든 쌍의 gcd의 합 
		//1,000,000 이 n개가 들어오는 경우 sum은 n(n-1)/2 * 1,000,000 까지 커질수 있다. 따라서 long long 으로 선언해주자.

		for (int i = 0; i < n-1; i++) {
			for (int j = i+1; j < n; j++) {

				sum += gcd(v[i], v[j]);
			}

		}

		cout << sum <<'\n';



	}

}