#include <iostream>
#include <set> 
#include <map> 

using namespace std;

int main() {


	int N,M;// 집합 S에 속한 원소의 갯수 , 검사해야하는 문자열의 갯수

	int cnt = 0; //M개의 문자열 중 총 몇개가 집합 S에 포함되어있는지 저장.

	set <string> s; //집합의 종류 저장.


	cin >> N >> M;

	while (N--) {

		string str;
		cin >> str;
		s.insert(str);
	

	}

	//M개의 문자열이 집합에 속하는지 판단한다.
	while (M--) {

		string str;
		cin >> str;
		if (s.find(str) != s.end()) //집합에 속한 문자열이라면
			cnt++;

	}



	cout << cnt;

}