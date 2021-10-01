#include <iostream>
#include <vector>

#define MAX 11

using namespace std;

int n; // 도시의 수
int min_cost = 987654321; //최소비용



int cost[MAX][MAX]; //비용을 담을 2차원배열

bool check[MAX] = { false }; // 방문한 장소를 기록해놓는 배열



//모든 지점을 다 탐색하나, 중복장소는 방문하지 않는다. (백트래킹)

void tour(int start,int current, int cnt,int sum) { //시작위치, 현재 위치한 도시의 인덱스, 탐색하지 못한 남은 도시의 수, 비용

	//cout << current;
	if (cnt== n-1) //모든 도시의 투어를 마치고, (n개중에 n-1개의 숫자를 뽑고 => 원순열)
	{  
		if (cost[current][start] != 0) //현재도시 -> 시작점 사이에 길이 존재한다면
		{	
			min_cost = min (sum + cost[current][start],min_cost);//최소비용 갱신.
		}
		 return; // 일단 투어를 마치면 무조건 리턴하게끔


	}

	//n개의 도시 중 다음 투어할 곳 모색(가지 뻗는 부분)
	for (int i = 0; i < n; i++) { 

		if (cost[current][i]==0) continue;// 연결이 끊어져 있거나, 자기자신을 방문하는경우 탐색 진행 X
		

		if (!check[i] ) //그 도시에 방문한 적이 없다면

		{
			//cout << i;
			sum += cost[current][i]; //current -> i 로가는 비용
			check[i] = true; // 그 도시를 방문했음을 표시

			if (sum <= min_cost)// sum이 현재 최소비용보다 작은 경우만 탐색 (가지치기 추가)

			{
				tour(start, i, cnt + 1, sum);//현재위치를 i로 다시 투어시작.
			}

			//다음번 탐색을 위해 방문한 기록과 합 초기화시켜두기.
			check[i] = false; 
			sum -=cost[current][i];
		}

	}
	

}

int main() {


	cin >> n;

	for (int i = 0; i < n;i++) {

		for (int j = 0; j < n; j++) {

			cin >> cost[i][j];
		}
	}

	for (int i = 0; i < n; i++) {


		check[i] = true; //시작도시 방문한 이력 추가 
		
		//각각 n개의 도시에서 탐색을 시작.
		tour(i, i, 0, 0);

		check[i] = false; //다음탐색을 위해 다시 원래대로

	}
	

	cout << min_cost;

}