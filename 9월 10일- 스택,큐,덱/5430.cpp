#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <deque>
#include <cstring>


using namespace std;


bool isreverse; // 뒤집힌 상태인지 아닌지

deque<int> split(string s, string divid) { //구분자를 바탕으로 문자열을 나누고, 토큰(숫자)들을 저장한 덱 리턴.
	
	deque<int> temp;
	char* c = strtok((char*)s.c_str(), divid.c_str());
	while (c) {
		temp.push_back(atoi(c)); //문자를 숫자로 바꾸어 덱에 푸쉬.
		c = strtok(NULL, divid.c_str());
	}
	return temp;
}


//이 reverse함수는 왜 제대로 동작하지 않을까. 
void reverse() { 

	if (isreverse) //이미 뒤집힌 상태라면
	isreverse = false; //정상상태로 돌려놓기

	else //정상상태라면
		isreverse = true; //뒤집기

}

//reverse상태라면 pop_back, 아니라면 pop_front
void pop(deque <int> &q) {


	if (isreverse)
		q.pop_back();

	else
		q.pop_front();
}


int main() {

	

	int n_testcase; 
	

	string command; //명령 저장
	int size; // 배열에 들어있는 수의 개수
	string array;//배열

	bool error; //에러발생여부

	cin >> n_testcase;

	while (n_testcase--) {

		deque <int> q; //숫자 저장하고 연산을 수행할 컨테이너

		isreverse = false;

		error = false;

		cin >> command;

		cin >> size;

		cin >> array;

		//구분자를 이용해 숫자를 분리하고 큐에 푸쉬.
		//c++은 split함수가 없어서 만들어 써야함.


		q = split(array, "[],"); //[ ] , 를 구분자로 문자열을 분리.
	

		for (int i = 0; i < command.length(); i++)
		{
			switch (command[i])

			{
			case  'R':
				reverse();
				break;

			case 'D':

				if (q.empty()) //더이상 버릴 숫자가 없는데 D라는 명령이 들어오면
				{
					error = true;
					
				}
				else
					pop(q); //상태에 따라 pop하는 값을 달리하는 함수 호출.

				break;
			}

		}

	

		if (error)

		{
			cout << "error" << '\n';
			continue; //에러가 발생했다면 아래 출력문은 시행 X
		}

		cout << '[';
		if (!isreverse) //정상상태라면
		{
			while (q.size())
			{

				cout << q.front();
				q.pop_front();

				if (!q.empty())
					cout << ',';

			}
		}

		else
		{

			while (q.size())
			{

				cout << q.back();
				q.pop_back();

				if (!q.empty())
					cout << ',';

			}
		}

		cout <<']'<<'\n';
			
	}


}