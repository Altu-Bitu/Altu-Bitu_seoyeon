#include <iostream>
#include <vector> 
#include <set> 

using namespace std;


int main() {


	

	int N,M; //각각 듣도, 보도 못한 사람의 수
	
	cin >> N >> M;
	//N,M 의 범위가 500,000 이하이므로 서치에 최적화 된 컨테이너인 set을 이용한다.

	
	set <string> s; //듣도 못한사람 저장.
	set <string> s_result;//듣도 보도 못한 사람 저장.


	
	while (N--) {

		string str;
		cin >> str;
		s.insert(str); //set은 사전순으로 저장됨.


      }


	while (M--) {

		string str;
		cin >> str;

		if (s.find(str) != s.end()) { //보도 못한사람이 듣도 못한 사람목록에도 있다면


			s_result.insert(str); //result에 추가
		}

	}


	cout << s_result.size()<<'\n';

	for (auto iter = s_result.begin(); iter != s_result.end(); iter++) {

		

		cout << *iter << '\n';

		
	}

	
}