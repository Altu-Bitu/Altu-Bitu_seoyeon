#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


int recommend[101] = { 0 }; //추천수
int  rtime[101] = { 1001 }; //추천받은 시각 
int n=0; // 현재 프레임에 존재하는 후보 수

using namespace std;

void post(int id,int prame,int t) {
	

	if (recommend[id]) { // 이미 후보로 올라와있는경우

		recommend[id]++; //추천수 증가


	}
	else { //후보에 없는경우 새로 올림.

		if (n == prame) { //최대정원에 도달하면

			//가장적은추천수 가진후보 찾음. 
			int min = 0; 
			recommend[0] = 1001;
			rtime[min] = 1001;
			for (int i = 1; i <= 100; i++) {

				if (recommend[i]==0 ) //받은 추천이 없다면
					continue; 
	
				if (recommend[min] > recommend[i]) { // 추천수가 더 적으면 
					min = i; //교체
				}
				else if (recommend[min] == recommend[i]) { // 추천수가 같으면
					
					if (rtime[min] > rtime[i]) //추천 받은 시각이 더 이를때만
						min = i; //교체

					
				}
			
		
			}

			//추천수 제일적고 오래된사람 한명 제외시키기
			recommend[min] = 0; 
			rtime[min] = 0;
			

			//이번에 추천받은 사람 추가하기
			recommend[id] = 1;
			rtime[id] = t;
			



		}
		else { // 액자 프레임 여유분이 남은경우

			recommend[id] =1;
			rtime[id] = t; 
			n++;
		}


	}


}

int main() {

	int prame, r, id; //사진틀개수, 추천수, 추천인
	int t = 1;


	cin >> prame >> r;
	while (r--) {

		cin >> id;
		post(id, prame,t);
		t++;
	}

	
	//최종 후보 출력
	for (int i = 1; i <= 100; i++) {
		if (recommend[i])
			cout << i<<' ';
	}


}