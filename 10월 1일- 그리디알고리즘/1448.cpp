#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



//가장 긴 trangle의 길이 리턴
int maxLength(vector<int>& length, int n) {


	//빗변이 i일때 그 다음으로 긴 길이인 i+1.i+2로도 삼각형을 만들지 못한다면 더 작은 다음 길이들로는 당연히 만들 수 없다.

	for (int i = 0; i < n - 2; i++) {


		int side; //빗변
		int s1, s2; //나머지 두변

		side = length[i];
		s1 = length[i + 1];
		s2 = length[i + 2];

		if (side < s1 + s2)//삼각형을 만들 수 있다면
		{
			return side + s1 + s2;
		}
	}
	return -1;

}

int main() {

	int n; //빨대개수
	cin >> n;
	vector<int> length(n);


	for (int i = 0; i < n; i++) {

		cin >> length[i];
	}

	sort(length.begin(), length.end(), greater<int>()); //내림차순 정렬
	
	cout << maxLength(length, n);

}