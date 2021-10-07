#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// 10의 배수인 케이크부터 먼저잘라야 더 많이 길이가 10인 조각을 만들어낼 수 있다.
// ->10의배수가 먼저오도록 우선정렬
bool cmp(const int& a,const int& b) {
	//cmp가 false를 반환할때 swap됨.

	if (a % 10 == 0 && b % 10 == 0) 
		return a < b; // 둘다 10의 배수라면 더 작은 순서대로

	return (a % 10 == 0);  //a만 10의배수이면 swap하지 않음.

}

int main() {



	int n, m;


	cin >> n >> m;

	vector <int> cake(n); //케이크 길이

	for (int i = 0; i < n; i++) {

		cin >> cake[i];

	}
	
	sort(cake.begin(), cake.end(), cmp);
	/*
		for (int i = 0; i < n; i++) {

		cout << cake[i] <<' ';

	}
	*/
	
	int cnt = 0;// 길이가 10인 케이크 개수
	int cutting_cnt = 0; //케이스를 자르는 횟수 카운트


	
	//길이가 10인 케이크 개수 카운트
	for (int i = 0; i < n; i++) {

		if (cake[i] == 10)
			cnt++;
	}

	
	//길이가 10보다 큰 케이크는 될수있는대로 자른다.
	for (int i = 0; i < n; i++) { 
		
		if (cake[i] <= 10) //10보다 작다면 더자를수 X
			continue;

		if (cutting_cnt== m) {
			break;
		}
			
		
		int rest =cake[i];

		//케이크를 자를수 있는만큼 자른다.
		
		while (rest > 10 && cutting_cnt!=m) {
			//cout << "o";
			rest -= 10;
			cutting_cnt++;
			cnt++;
		}

		
		if (rest == 10) //10의 배수였다면 조각이 하나 더 추가됨 
			cnt++;
		
	}

	cout << cnt;

}