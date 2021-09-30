#include <iostream>
#include <vector>
#include <stdlib.h>
#define MAX 10

using namespace std;

int n; // 도시의 수
int min_cost = 9999; //최소비용



int cost[MAX][MAX]; //비용을 담을 2차원배열

bool check[MAX] = { false }; // 방문한 장소를 기록해놓는 배열

int sum = 0; //비용축적을 저장

//모든 지점을 다 탐색하나, 중복장소는 방문하지 않는다. (백트래킹)

void tour(int start,int current, int cnt) { //시작위치, 현재 위치한 도시의 인덱스, 탐색하지 못한 남은 도시의 수

	//cout << "o";
	if (cnt==0 && start==current) //모든 도시의 투어를 마쳤고, 다시 시작도시로 돌아온경우
	{
		
		if(min_cost >sum) 
		 min_cost = sum;//최소비용 갱신.
		 return;

	}

	//n개의 도시 중 다음 투어할 곳 모색(가지 뻗는 부분)
	for (int i = 0; i < n; i++) { 

		if (cost[current][i]==0) continue;// 연결이 끊어져 있거나, 자기자신을 방문하는경우 탐색 진행 X
		

		if (!check[i] ) //그 도시에 방문한 적이 없다면

		{
			
			sum += cost[current][i]; //current -> i 로가는 비용
			check[i] = true; // 그 도시를 방문했음을 표시

			tour(start, i, cnt-1); //현재위치를 i로 다시 투어시작.

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

		//각각 n개의 도시에서 탐색을 시작.
		tour(n, n, n);

	}
	
	

	cout << min_cost;

}