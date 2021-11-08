#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef pair<int,int> ci; // 좌표저장

/** 
* 
T : 한 칸 위로
B : 한 칸 아래로
L : 한 칸 왼쪽으로
R : 한 칸 오른쪽으로
RT : 오른쪽 위 대각선으로
LT : 왼쪽 위 대각선으로
RB : 오른쪽 아래 대각선으로
LB : 왼쪽 아래 대각선으로

*/

map<string, ci> direction = { {"T",  {0,1}},  //상
                              {"B",  {0,-1}},  //하
                              {"L",  {-1,0}},  //좌
                              {"R",  {1,0}},  //우
                              {"RT", {1,1}},  //우상향
                              {"LT", {-1,1}},  //좌상향
                              {"RB", {1,-1}},  //우하향
                              {"LB", {-1,-1}} }; //좌하향


pair<string,string> getFinal(vector <string> command, string king, string rock){ //마지막 위치 구하기
    

   
    pair<string, string> ans;
    for (int i = 0; i < command.size(); i++) {

        ci move = direction[command[i]]; // 이동할 방향 

        int nc_king = king[0] + move.first; // king이 다음에 방문하게 될 열
        int nr_king = king[1] + move.second;// king이 다음에 방문하게 될 행
 


        if (nr_king < '1' || nr_king > '8' || nc_king < 'A' || nc_king > 'H') //king 이 범위를 벗어나면 (1<=nr<=8, a<=nc<=h )
            continue;

       
  
        if (nc_king != rock[0] || nr_king != rock[1]) { // king이 움직이려는 방향에 돌이 없다면

            king[0] = nc_king;
            king[1] = nr_king;
            continue;
        }

   

        //king 이 움직이려는 방향에 돌이 있고, king이 범위 내라면

                //돌을 킹이 움직인 방향과 같은 방향으로 한 칸 이동시킨다.
                int nc_rock = rock[0] + move.first;
                int nr_rock = rock[1] + move.second;


                if (nr_rock < '1' || nr_rock > '8' || nc_rock < 'A' || nc_rock > 'H')  // rock이 범위를 벗어난다면
                    continue;
          
         
                king[0] = nc_king;
                king[1] = nr_king;
                rock[0] = nc_rock;
                rock[1] = nr_rock;

    }

    ans.first = king;
    ans.second = rock;

    return ans;

}

int main() {


	string king_init, rock_init;// king,rock의 초기 위치
	int n;

	cin >> king_init >> rock_init>>n;


   
    // vector <string> command(n,NULL); -> 이문장 이상종료 이유?
    vector <string> command(n); // 이동명령

   
    for(int i=0;i<n;i++){

      cin >> command[i];

   }
    
   
    pair<string, string> ans = getFinal(command, king_init, rock_init);

   
        cout << (char)ans.first[0];
        cout << ans.first[1];
        cout << '\n';
        cout << (char)ans.second[0];
        cout << ans.second[1];

    

}