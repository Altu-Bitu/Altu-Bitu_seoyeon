#include <iostream>
#include <set>

using namespace std;



set<int> allSet = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
// all 연산을 위해 1~20 set을 미리 선언


void add (set<int>&s ,int x){

    //if (s.find(x) == s.end()) set은 어짜피 중복제거 되니까 필요 X
        s.insert(x);
  
}

void remove(set<int>& s, int x) {

    s.erase(x);


}
void check(set<int>& s, int x) {


    if (s.find(x) == s.end())
        cout << 0 <<'\n';

    else
        cout << 1 <<'\n';



}
void toggle(set<int>& s, int x) {

    if (s.find(x) == s.end()) //x가 없으면
        s.insert(x);
    else 
        s.erase(x);




}


void all(set<int>& s) {
 
   /*  
    s.clear();
    for (int i = 1; i <= 20; i++)
    {

        s.insert(i);
    }
    */

    // 이부분을 아래와 같이 고치니까 시간초과 해결.
    // 아래와 같이 식을쓰면 s가 allSet을 가리키게 되는거라서 allSet의 값에 직접적으로 접근하게 되므로 일회용(?)으로밖에 사용을 못할거라고 생각했는데
    // 그게 아니라 그냥 s에 들어있는 값만 allSet과 똑같이 대입해주는거임. 



    s = allSet;


}

void empty(set<int>& s) {


    
    s.clear(); //clear함수의 시간복잡도는 O(N)


}


// 집합은 원소가 반복될수 없으며 탐색이 주를 이루므로 set을 활용하자.

int main() {




    ios::sync_with_stdio(false);
    cin.tie(NULL);



    set<int> s;
   
    string cmd; //명령
    int n; //수행해야하는 연산 수
    int x; 

    cin >> n;

    while (n--) {



        cin >> cmd;
        
       


        if (cmd == "add") {
            cin >> x;
            add(s, x);
        }
        else if (cmd == "remove") {
            cin >> x;
            remove(s, x);

        }

        else if (cmd == "check" ) {
            cin >> x;
            check(s, x);
           
            
        }
        else if (cmd == "toggle") {

            cin >> x;
            toggle(s,x);

        }
        else if (cmd == "all") {

            all(s);
            

        }
        else if (cmd == "empty") {

            empty(s);

        }
       /* for (auto iter : s)
            cout << iter;
        cout << '\n';*/

    }
}