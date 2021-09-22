
#include <iostream>
# include <vector>

using namespace std;
const int SIZE = 10000;

int top_pointer = -1; // 스택의 맨 윗 상단을 가리킬 포인터
vector<int> stack_vec(SIZE);

//empty
bool empty() {
    return top_pointer == -1;
}

//full
bool full() {
    
    return top_pointer == SIZE - 1; //top포인터가 max로 가리킬수있는 인덱스는 size-1.
}

//push
void push(int k) {

   stack_vec[++top_pointer]=k;
}

//pop
int pop() {


    //pop 할때 벡터에 있는 값을 실질적으로 삭제시키지 않아도됨.
    //어짜피 다음번 push할때 그 인덱스가 사용자가 입력한 값으로 바꿔치기 되기 때문.
    return stack_vec[top_pointer--];
   
}

//size
int size() {
    return top_pointer + 1;
} 

//top
int top() {

    return stack_vec[top_pointer];
}

int main() {

    cin.tie(NULL);
    ios_base:: sync_with_stdio(false);

    int n, k;
    string cmd;
   

    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> k;

           // if (!full())
            // push(k);         
           push(k);
            continue;
        }
        if (cmd == "pop") {

            if (empty()) //스택이 비었다면

                cout << -1 << '\n';
            else {

                cout << pop() << '\n';
            }
            continue;
        }
        if (cmd == "size") {
            cout<< size() << '\n';
            continue;
        }
        if (cmd == "empty") {
            cout << empty() << '\n';
            continue;
        }
        if (cmd == "top") {

            if (empty())
                cout << -1 << '\n';
            else
            cout << top() << '\n';
                continue;
        }
    }

    
      //스택 순회
     
    while (!empty()) {
        cout << top() << ' ';
        pop();
    }
    
}