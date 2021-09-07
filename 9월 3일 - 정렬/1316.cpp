#include <iostream>
#include <vector> 

using namespace std;

bool isGroup(string str) { //그룹단어인지 확인하는 함수

	bool alphabet[26] = { false };// 특정알파벳이 등장했는지 안했는지 저장

	for (int i = 0; i < str.length(); i++) {


		if (i && str[i] != str[i - 1] && alphabet[str[i] - 'a']) //전문자와 같지않은데 알파벳이 나온적 있다면
		{

			return false; //그룹단어가 아니다.	
		}

		alphabet[str[i] - 'a'] = true; //나온 알파벳 저장.

	}

	return true;
}

int main() {


	int n; //단어의 개수
	int cnt = 0;// 그룹단어의 개수 
	string words;



	cin >> n;



	while (n--) {

		cin >> words;

		if (isGroup(words))
			cnt++;

	}

	cout << cnt;


}