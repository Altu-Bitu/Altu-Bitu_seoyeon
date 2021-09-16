#include <iostream>
#include <stack>
#include <map>
#include <vector>

using namespace std;


map <char, int> m;// 알파벳 - 숫자 연관지어 저장할 map


// 후위표기식을 계산해주는 함수
double calculate(string str, vector<int> v) { 

	//숫자는 무조건 push, 기호를 만나면 맨 위의 상수 두개를 pop하여 계산한다음 계산한 결과 push.

	stack<double> s;
	double a=0,b=0,c=0;
	

	for (int i = 0; i < str.length(); i++) {

		if (str[i] >= 'A' && str[i] <= 'Z') //영문이라면
		{ 

			s.push(m[str[i]]); //알파벳에 해당하는 숫자로 바꿔서 push
			//cout << "push"<< m[str[i]];
		}

		else //기호라면
		{

			//스택의 맨 위에서 상수 두개를 꺼낸다.
			a = s.top(); s.pop();
			b = s.top(); s.pop();

			switch (str[i])
			{

			case '+':
				c = a + b;
				break;
			case '-':
				c = b - a;
				break;
			case '/':
				c = b / a;
				break;
			case '*':
				
				c = a * b;
				break;


			}
			s.push(c); //계산 결과 c를 스택에 다시 넣는다.
			//cout << "push" << c;
		}
	}
	return s.top(); // 모든 계산을 마치고 남은 나머지 원소 하나가 연산 결과값이된다.

}

int main() {

	


	int n; //피연산자의 개수
	string str; //후위표기식

	cin >> n;

	cin >> str;

	vector <int> v (n);

	for (int i=0;i< n;i++){

		int n;
		cin >> n;
		
		m['A' + i] = n;
	}
	cout << fixed;
	cout.precision(2);
	cout << calculate(str, v);

}
