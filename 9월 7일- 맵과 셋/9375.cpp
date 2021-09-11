#include <iostream>
#include <set> 
#include <map> 

using namespace std;

int main() {



	int n_testcase;

	//어떤 옷을 입을지 알 필요는 없다. 부위의 종류와 각각의 부위에 해당하는 옷의 수가 몇개인지만 알면 된다.

	map <string, int> m; // 부위의 종류, 부위의 수.


	cin >> n_testcase;

	while (n_testcase--)
	{

		m.clear(); //모든 원소 제거

		int n; //가진 의상의 수
		cin >> n;

		for (int i = 0; i < n; i++) {


			string wear, part;
			
			cin >> wear >> part;
			
			if (m.find(part) == m.end())//새로운 부위라면
				m[part] = 1; // 부위 갯수를 1로 초기화
			
			else //이미 저장된 부위라면
			m[part] += 1; //갯수를 하나 늘린다.

		}
	

		// 총 입을 수 있는 조합의 갯수 = (부위1의 갯수 +1) * (부위2의 갯수 +1) ... (부위n의 갯수 +1) -1 , 이때 n은 부위의 갯수

		int comb = 1;

		for (auto iter = m.begin(); iter != m.end(); iter++) {

			comb *= (iter->second+1) ; //각각의 부위별 의상의 갯수에 1을 더한 값을 곱해줌.

				// +1을 해주는 이유는 그 부위를 입지 않는 경우의 수를 추가하는것. 

			

		}

		 comb-=1; // -1을 해주는 이유는 아무것도 안 입는 경우의 수를 제외시키기 위함.

			
		
		 cout << comb <<'\n';
	}

}