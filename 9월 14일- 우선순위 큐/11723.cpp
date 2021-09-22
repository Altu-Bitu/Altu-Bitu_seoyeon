#include <iostream>
#include <cstring>

using namespace std;


int main() {


    ios::sync_with_stdio(false);
    cin.tie(NULL);


	//집합은 원소가 중복될수없으므로 특정 숫자가 있는지(true) 없는지(false)에 대한 정보만 저장하면 됨 ---> bool배열 이용하자! 
	//O(1) 만에 거의 모든 연산이 가능하니 set보다 훨씬 효율적임!!!! 

    bool set[21] = { false }; //20개의 숫자의 존재유무를 저장해둘 bool배열
   
    string cmd; //명령
    int n; //수행해야하는 연산 수
    int x; 

    cin >> n;

    while (n--) {



        cin >> cmd;
        
      
		if (cmd == "add") {
			cin >> x;
			set[x] = true; 
		}
		if (cmd == "remove") {
			cin >> x;
			set[x] = false;
		}
		if (cmd == "check") {
			cin >> x;
			cout << set[x] << '\n';
		}
		if (cmd == "toggle") {
			cin >> x;
			set[x] = !set[x]; //x가 있다면 제거하고 없다면 추가한다. 
		}
		if (cmd == "all")
			memset(set, true, sizeof(set)); // 모든 숫자의 존재여부를 true로 

		if (cmd == "empty")
			memset(set, false, sizeof(set)); // 모든 숫자의 존재여부를 false로 


    }
}