#include <iostream>
#include <vector> 
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

/*
평균 ->
중앙값 -> 벡터로 정렬수행한다음 정 가운데 값 반환.
최빈값 -> 각 숫자가 나온 횟수를 저장하는 map
*/

int main() {


	int n_total;
	
	cin >> n_total;

	vector<int> v;

	map <int, int> m; // 숫자, 그 숫자가 나온 횟수

	int sum=0;
	int n;
	float median; //중앙값 
	int mode; //최빈값
	int range; //범위

	for (int i = 0; i < n_total; i++) {

		cin >> n;
		sum += n;
		v.push_back(n);
		m[n]++; //나온횟수 저장.
		
	}

	sort(v.begin(), v.end()); //오름차순 정렬

	//중앙값 구하기

		median = v[(n_total -1)/ 2];


	//평균구하기
	int average = round((float)sum / n_total); //round는 반올림을 수행하는 함수


	//최빈값 구하기

	//1. 가장 많이 나온 횟수 구하기 

	
	int max=0; // 가장 많이 나온 횟수 갱신
	for (auto iter : m) {
		
		if (max < iter.second)
		{
			max = iter.second;		
			mode = iter.first; 
		}

	}

	//2. 여러개일경우 ->  두번째로 작은 값이 최빈값이 됨.
	 
	bool is_second = false;
	for (auto iter : m) {

		if (max == iter.second) {
			
			if (is_second) {

				mode = iter.first;
				break;
			}
			is_second = true;
		}

	}

	// 범위구하기 -> 큰수 - 작은수
	int a = v[0]; // 제일 앞값
	int b = v.back(); // 제일 뒷값

	range = b - a;

	


	cout << average << '\n' << median << '\n' << mode << '\n' << range;

}