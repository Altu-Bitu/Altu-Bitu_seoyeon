#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;



// 단어가 일치하는지 확인하는게 아니라 구성을 비교하자!


// 알파벳 구성을 주면 비슷한단어인지 유무 판단
bool checkSimilar(map<char, int> check_original, map<char, int> check_cmp) {

	//길이차이가 최대 1인 string만 입력받음

	int diff = 0; // 차이점

	// diff 0 : 구성이 같음 ex) DOG DOG
	// diff 1 : 하나의 단어를 추가하거나 삭제함으로서 같은 구성을 만들 수 있음 ex)DOG DOOG
	// diff 2 : 하나의 단어를 교체함으로서 같은 구성을 만들수 있음. ex) DOG DOH

	
	for (int i = 0; i < 26; i++) {

		if (abs(check_original[i + 'A'] - check_cmp[i + 'A']) >= 2) // 한 알파벳에 두개이상의 차이가 나면
			return false; // 한단어 교체,추가,삭제로는 같은구성을 가지도록 만들수 없음.

			diff += abs(check_original[i+'A'] - check_cmp[i+'A']); //알파벳 차이
					
	}

	if (diff <=2) 
		return true;

	else  //diff >=3
		return false;


}
int main() {

	

	int n;
	cin >> n;

	string original,cmp; //첫단어,비교대상; 
	int cnt=0; //비슷한 단어 카운트
	cin >> original;	

	
	map<char, int> check_original; //original string의 알파벳의 등장횟수 저장
	for (int i = 0; i < original.length(); i++) {
		check_original[original[i]]++;
	}

	for (int i = 1; i < n; i++) {
		cin >> cmp;

		int len_diff = original.length() - cmp.length();
		len_diff = abs(len_diff); 
		
		//string의 길이차이가 1이하인 경우만 비슷한 단어일수 있음.
		if (len_diff <= 1) {
			
			map<char, int> check_cmp;  //비교할 string의 알파벳의 등장횟수 저장


			for (int i = 0; i < cmp.length(); i++) {
				check_cmp[cmp[i]]++;
			}
		


			cnt += checkSimilar(check_cmp, check_original);
			//cout << cnt;
		}
			
	}

	cout << cnt;
	 
}