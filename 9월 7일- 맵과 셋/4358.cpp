#include <iostream>
#include <set> 
#include <map> 
#include <iomanip>

using namespace std;

int main() {

	
	
	ios_base::sync_with_stdio(false); cin.tie(NULL); 


	map <string, int> m; // 종의 이름, 수

	char name[31]; //null자리까지 포함.

	int total = 0; //총 생물의 수

	// 입력받을 생물의 개수가 주어지지 않았는데 어떻게 끝인걸 알지..? -> EOF ! 

	while (cin.getline(name, 31)) {
		
	
		total++;

			m[name]++ ; //종 갯수를 하나 늘린다.

	}

	
	double ratio; //각 종이 차지하는 비율


	cout << fixed;
	cout.precision(4); //소숫점 4자리까지 출력

	
		for (auto iter : m) {

			cout << iter.first << ' ';
			ratio = (double)iter.second / total * 100;


			cout << ratio << '\n';
		}

	

}