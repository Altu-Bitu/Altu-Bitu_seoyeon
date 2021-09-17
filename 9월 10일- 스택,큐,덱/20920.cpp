#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;


map <string, int> frequency; // 영단어,빈도수 저장


bool cmp(const string & s1, const string& s2) {

	if (frequency[s1] != frequency[s2]) //나온 빈도수가 다르다면
		return frequency[s1] > frequency[s2]; //자주나오는 것부터 먼저

	if (s1.length() != s2.length())//길이가 다르다면
		return	s1.length() > s2.length();  //길이가 긴것부터 먼저

			return s1 < s2; //사전순으로
		
}



int main() {

	
	vector <string> voca; //단어를 중복되지 않게 저장할 컨테이너
	cin.tie(nullptr); ios::sync_with_stdio(false);

	int i;
	int n; //단어의 개수
	int m; //외울 단어의 기준.

	string str;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {

		cin >> str;
		if (str.length() < m) continue; //길이가 m보다 짧으면 아래내용을 시행하지 않고 넘어감.


		if (frequency.find(str) == frequency.end()) //입력받은 단어가 단어장에 없는 단어일경우
			voca.push_back(str);

		frequency[str]++; //단어가 나온 횟수를 맵에 저장.

	}

	sort(voca.begin(), voca.end(), cmp);

	for (auto str : voca)
		cout << str <<'\n';

}





	

