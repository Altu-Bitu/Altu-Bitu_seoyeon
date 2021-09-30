#include <iostream>
#include <string>
#include <cstring>
using namespace std;



//뭐가 잘못된걸까 ㅠㅠ . 
int main() {

	bool possible[1000]; //1 ~ 999 까지를 후보군에 두고 제외시키자.
	memset(possible, true, sizeof(possible)); // true로 초기화


	int n; // 숫자개수
	cin >> n;


	//숫자를 중복해서 쓰거나, 0이 들어간 숫자는 제외.
	for (int i = 123; i < 1000; i++) {


		string s = to_string(i);

		if (s.find("0") != string::npos) //0이 포함되어있는 수라면
			possible[i] = false; // 후보군에서 제외




		if (s[0] == s[1] || s[1] == s[2] || s[2] == s[0]) //숫자를 중복해서 썼다면

			possible[i] = false; // 후보군에서 제외


	}



	string guess; // 추측한숫자
	int ball, strike; // 비교할 볼,스트라이크 개수
	int ball_cnt = 0; // 가상의 볼 개수 
	int strike_cnt = 0; // 가상의 스트라이크 개수


	for (int i = 0; i < n; i++) {

		cin >> guess >> strike >> ball;


		for (int i = 123; i < 1000; i++) {


			//283이 왜 살아있을까.
			if (possible[i]) { // 아직 후보군에 있는 수라면

				//후보군에 있는 수(i)가 실제 정답이라고 가정할때 스트라이크,볼 값이 일치하는지 확인
				//cout << i << '\n';
				ball_cnt = 0; // 가상의 볼 개수 
				strike_cnt = 0; // 가상의 스트라이크 개수


				string answer = to_string(i);


				//각 자리수가 일치하면 strike 개수+1
				if (guess[0] == answer[0])
					strike_cnt++;
				if (guess[1] == answer[1])
					strike_cnt++;
				if (guess[2] == answer[2])
					strike_cnt++;



				for (int i = 0; i < 3; i++) {

					//answer에 숫자는 존재하나, 자릿수가 일치하지 않으면 ball개수 +1
					if (answer.find(guess[i]) != string::npos && answer.find(guess[i]) != i)
						ball_cnt++;

				}




				if (ball != ball_cnt || strike != strike_cnt) //개수가 맞지 않다면
					possible[i] = false;//후보군 제외



			}


		}
	}


	int possible_cnt = 0; //가능한 수의 개수
	for (int i = 123; i < 1000; i++) {

		if (possible[i]) {
			possible_cnt++;
			//cout << i<<'\n';
		}

	}


	cout << possible_cnt;
}

	