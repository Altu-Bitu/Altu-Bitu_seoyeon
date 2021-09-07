#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct grade {

	int doc; //서류심사성적 
	int interview; //면접시험성적

};

bool cmp(const grade&  g1, const grade& g2)
{
	return g1.doc < g2.doc;//서류성적 오름차순 정렬 -> 1등이 먼저오도록

}



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n_testcase;
	int n; //지원자의 숫자
	int cnt; //신입사원으로 뽑힐수 있는 사람 수
	vector <grade> grades;
	
	cin >> n_testcase;

	while (n_testcase--) {

		cin>> n;

		grades.assign(n, {});

		for (int i = 0; i < n; i++) {

			cin >> grades[i].doc >> grades[i].interview;

		}

		
		
		sort(grades.begin(), grades.end(),cmp);//우선 서류심사 성적을 기준으로 순위(점수)가 높은 순서대로 정렬한다




		// 이제 자신보다 서류성적이 높은 사람들에 대해 면접성적이 높은지만 확인해주면 된다. 
	
		
		// ex. 서류순위 2등인사람은 서류순위 1등인사람의 면접순위 점수보다 높다면 뽑힐수있다.
		// ex. 서류순위 4등인사람은 서류순위 1,2,3 등 인 사람들보다 면접순위점수보다 높다면 뽑힐수 있다. 
		// -> 4등을 1,2,3등 각각과 비교하게 되면 O(N2)의 시간복잡도를 가지므로 시간초과. 따라서 max라는 변수를 선언하여 최고순위를 저장(1,2,3등중에서 가장 높은 순위)해두고 를 4등의 면접성적과 비교해준다.

		cnt = 1;  //서류1등은 무조건 뽑히므로

		int max_rank = grades[0].interview;

		for (int i = 0; i < n; i++) {

		
			if (max_rank>grades[i].interview)
			{
				//cout << grade[i].interview<< max_rank <<endl;
				max_rank = grades[i].interview; // 면접성적의 최고순위가 갱신된다는것 = i번째 사람은 0~ i-1번째사람보다 서류순위는 떨어지지만 그들 모두보다 면접순위는 높으므로 신입사원으로 채용될 수 있다는 것.
				cnt++; 
				
			}
			
		}
	
		cout << cnt <<'\n';	

	}

}