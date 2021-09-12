#include <iostream>
#include <string>
using namespace std;

int main() {

	// A,B의 범위가 LLONG_MAX를 훨씬 넘어가므로 문자열로 입력받아 처리해야한다..!

	string A ,B ;
	string result;

	cin >> A >> B;
	
	const int A_length = A.length(); //A의 초기 길이
	const int B_length = B.length(); //B의 초기 길이

	//자릿수가 더 적은 쪽의 빈 공간을 0으로 채우기. 
	//12 + 1234 를 0012+1234로 만듬.

	if (A_length > B_length) { 

		for (int i = 0; i < A_length - B_length; i++) 
		{
			//처음에 이부분 반복문을 A.length()-B.length()로 해놓고 왜안되지 헤맸다 ㅋㅋ..... 
			//for문 도는 동안 a,b의 길이가 변하니까 내가 원하는 수만큼 0 추가가 일어나지 않음에 유의! 
			B = '0' + B;
		}
		
	}

	else {

		for (int i = 0; i < B_length - A_length; i++)
		{
			A = '0' + A;
		}

	}

	/*for (int i = 0; i < A.length(); i++) {
		cout << A[i];

	}
	for (int i = 0; i < B.length(); i++) {
		cout << B[i];
	}*/


	
	int carry = 0, sum = 0;

	for (int i = A.length()-1; i >= 0; i--) {

		//디논설에서 배운거 써먹기

		int a = A[i] - '0'; //i번째 문자를 숫자로 바꿈.
		int b = B[i] - '0';
			

		int sum = (a + b + carry) % 10; //나머지수
        carry = (a + b + carry) / 10  ; //반올림수
		
		result= (char)(sum + '0') + result ; // 다시 숫자를 문자로 바꾸고 맨앞에 덧붙여줌.

		

	}
	if (carry == 1)  //마지막 반올림수가 1인채로 남아있으면
		result = '1'+ result; //1을 추가함.

	//result에 저장한 값 출력하기
	for (int i = 0; i< result.length(); i++) {
		cout << result[i];

	}
	
	
}