#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


int main() {



	int n, m_my; // 과목수, 내 마일리지
	int p, limit; //지원자, 수강정원

	priority_queue <int, vector<int>, greater<int>> q; //최소 힙 (가장 작은 값부터 꺼내오기 위함.)
	//각 과목별로 이 정도 점수면 그 과목 신청하는데 성공할 수 있다하는 값 담기.


	cin >> n >> m_my;

	while (n--) {


		int m_min;// 내가 현재 과목을 수강하기위해서 배팅해야할 최소 마일리지
		vector<int> v; // 사람들이 그 과목에 배팅한 마일리지 저장해둘 컨테이너 

		cin >> p >> limit;


		//다른사람이 배팅한 마일리지 입력받기
		for (int i = 0; i < p; i++) {

			int c;

			cin >> c;

			v.push_back(c);

			//vector 로 입력 n + 정렬 + 0(nlogn) + 찾기 O(1)  VS  우선순위큐로 입력  O(nlog n) + 찾기 O(logN) 
			//n개의 숫자를 입력받고 n번째 숫자를 찾을때에는 우선순위큐 쓰는게 더 효율적인가요?
		}


		sort(v.begin(), v.end(), greater<int>()); //내림차순 정렬

		if (p >= limit)// 신청인원 >= 수강정원
			m_min = v[limit - 1]; // 경쟁상대들이 배팅한 마일리지들중에 limit번째로 큰 값 = 그 과목을 듣기위해 필요한 최소 마일리지

		else// 신청인원 < 수강정원 
			m_min = 1;

		q.push(m_min); //우선순위 큐에 넣는다.



	}

	/*
	// 디버깅용
	while (!q.empty()){

		cout << q.top() <<' ';
	q.pop();

	}*/
	

	int cnt = 0; //들을수 있는 최대 과목수


	// 배팅할 과목이 더 없거나(=큐가 비었거나),  내 마일리지가 모자라면 반복문 종료

	while (!q.empty()) {

		int k = q.top(); //각 과목당 최소 배팅 마일리지를 담은 최소 힙에서 가장 작은 값

		if (m_my >= k) //보유 마일리지가 그 과목이 요구하는  마일리지보다 크다면
			m_my -= k; //그만큼 마일리지 차감

		else //보유 마일리지가 모자라다면
			break; // 더 많은 마일리지를 요구할 그 다음과목도 신청할 수 없으므로 반복문 종료

		q.pop();


		cnt++;
	}
	//cout << m_my;
	cout << cnt;
	

}