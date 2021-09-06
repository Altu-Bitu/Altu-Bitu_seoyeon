#include <iostream>
#include <vector> 

using namespace std;


int main() {


	int n; //단어의 개수
	int cnt=0;// 그룹단어의 개수 
	int i, j, k;
	

	cin >> n;

	string words; 

	while (n) {
		n--;
		cin >> words;
		
		bool check=true;// 그룹단어인지 확인용

		for (i = 0; i < words.length(); i++) {

			//cout << "i : " <<words[i]<<endl;

			for (int j = i+1 ; j < words.length();j++ )
			{
				//cout << words[j]<<" ";

				if (words[i] == words[j] && words[j] != words[j - 1]) // 같은 문자가 또 등장했는데 바로 이전문자도 같지 않다면
				{
					check = false; //그룹단어가 아니다.
					break;
				}
					//if문에 걸리지 않으면 check가 true인 상태로 유지되므로 그룹단어가 맞다는 판단.	
				
			}
			//cout << endl;
		}

		if (check)
			cnt++; //for문을 다 돌았는데도 check가 true상태이면 그룹단어임.
	}

	cout << cnt;


}