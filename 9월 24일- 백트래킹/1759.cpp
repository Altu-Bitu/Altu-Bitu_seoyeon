#include <iostream>
#include <algorithm>

# define MAX 15

using namespace std;

int L, C; //암호의 글자수, 알파벳 종류

char letter[MAX]; // 사용할수 있는 알파벳
char password[MAX]; // 암호 

//길이가 L인 모든 중복 x 오름차순 조합을 구하고 , 조건에 맞는지 확인하고 출력한다.


bool isPromising() {



	int consonant = 0; //자음개수
	int vowel = 0; //모음개수


	//만들어진 비밀번호의 자음,모음개수 확인
	for (int i = 0; i < L; i++) {

		if (password[i] == 'a' || password[i] == 'e' || password[i] == 'i' || password[i] == 'o' || password[i] == 'u')
			vowel++;

		consonant = L - vowel;
	}

	
	//최소모음 한개, 최소 두개 자음을 포함하고 있다면 
	if ((consonant >= 2) && (vowel >= 1))

	{
		return true;
	}

	return false;
}

void findPassword(int cnt, int start) { //cnt는 비밀번호 인덱스, start는 오름차순 구현을 위한 시작 인덱스


	
	if (cnt == L) //비밀번호의 길이가 L이 되면,
	{

		if (isPromising()) { //비밀번호가 유효할 경우에만

			for (int i = 0; i < L; i++) {

				cout << password[i];
			}
			cout << '\n';
		}

		return;
	}

	//여기서 최소모음 한개, 최소 자음 두개 조건 어떻게 추가?
	for (int i = start; i < C; i++) {

		password[cnt] = letter[i]; 

		findPassword(cnt + 1,i + 1); //오름차순으로 중복없이 출력할 수 있도록 start지점을 i +1 로.

		// 어짜피 덧대서 채워지니까 원상복구 해놓을 필요 X
	}



}


int main() {


	cin >> L >> C; 

	for (int i = 0; i < C; i++) {


		cin >> letter[i];
		
	}

	sort(letter, letter + C); //문자 오름차순 정렬


	findPassword(0,0);


}