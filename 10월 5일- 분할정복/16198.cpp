#include <iostream>
#include <vector>

using namespace std;


/*https://astrid-dm.tistory.com/315 */

//매순간 최대의 에너지를 모을 수 있는 방법을 선택하는 그리디식 풀이 . .? -> 순간최적해!=전체최적해 임으로 불가능!
//그럼 어떻게? 가능한 모든 경우의 수를 구해보자! (브루트포스)
//구슬개수=n 일때 에너지 모으는 기회를 선택하는 것은 (n-2)! 가지 경우의 수가 있음

int max_energy = -1;

//모을 수 있는 에너지 양의 최댓값 리턴.
void makeEnerge(vector <int> energy,int sum) {

	//conquer
	if (energy.size() == 2) {// 첫번째와 마지막 에너지 구슬만 남으면
		//cout <<sum ;
		max_energy = max(sum, max_energy); //에너지 최댓값 갱신
			return;
	}
		
	//divide 
	for (int i = 1; i <= energy.size()-2; i++) { // 1,2,3...n-2번째 구슬을 지우고 나서 다시 함수 호출 (0,n-1번째는 지울수 없으니 포함시키지 X)

		int temp = energy[i]; //i번째 값 keep.
		int e = energy[i - 1] * energy[i + 1];
		energy.erase(energy.begin()+i); //i번째 값 삭제
		makeEnerge(energy, sum+e); //i번째 값이 삭제된 벡터, 추가에너지더한채로 함수 다시 호출
		energy.insert(energy.begin() + i, temp); //i번째 값 돌려놓기

	}

}

int main() {



	vector <int> energy;

	int n; 
	cin >> n;
	energy.assign(n,0);

	
	//입력
	for (int i = 0; i < n; i++) {

		cin >> energy[i];
	}

	//연산
	makeEnerge(energy, 0);

	//출력
	cout << max_energy;

}