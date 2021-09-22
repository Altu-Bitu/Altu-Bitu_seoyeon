#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <deque>
#include <cstring>
#include <string>


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

string dqToString(deque<int> dq)   // 상태에 따라 덱에 들어있는 숫자를 스트링으로 반환하는 함수
{
	string s = "";

	s += '[';

	if (!isreverse) //정상상태라면
	{
		while (dq.size())
		{

			s += to_string (dq.front()); //숫자를 문자로
			dq.pop_front();

			if (!dq.empty())
				s += ',';

		}
	}

	else //뒤집힌 상태라면
	{

		while (dq.size())
		{

			s += to_string( dq.back());
			dq.pop_back();

			if (!dq.empty())
				s += ',';

		}
	}

	s += ']';

	return s;


}


int main() {



	int n_testcase;


	string command; //명령 저장
	int size; // 배열에 들어있는 수의 개수
	string array;//배열

	bool error; //에러발생여부

	cin >> n_testcase;

	while (n_testcase--) {

		deque <int> dq; //숫자 저장하고 연산을 수행할 컨테이너

		isreverse = false;

		error = false;

		cin >> command;

		cin >> size;

		cin >> array;

		//구분자를 이용해 숫자를 분리하고 큐에 푸쉬.
		//c++은 split함수가 없어서 만들어 써야함.


		dq = split(array, "[],"); //[ ] , 를 구분자로 문자열을 분리.


		for (int i = 0; i < command.length(); i++)
		{
			switch (command[i])

			{
			case  'R':
				isreverse = !isreverse; //지금상태와 반대로.
				break;

			case 'D':

				if (dq.empty()) //더이상 버릴 숫자가 없는데 D라는 명령이 들어오면
				{
					error = true;

				}
				else {

					if (isreverse) //뒤집힌상태라면 
						dq.pop_back(); //뒤에서 pop

					else //정상상태라면
						dq.pop_front(); //앞에서 pop
				}

				break;
			}

		}



		if (error)

		{
			cout << "error" << '\n';
			continue; //에러가 발생했다면 아래 출력문은 시행 X
		}

		cout << dqToString(dq) << '\n';

	}


}