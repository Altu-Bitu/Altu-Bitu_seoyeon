#include <iostream>
#include <vector>


using namespace std;
const int SIZE = 10001;

int front_pointer = 0, rear_pointer = 0;
vector<int> queue_vec(SIZE);

//empty
bool empty() {
    return front_pointer == rear_pointer; // front rear가 같은곳을 가리킬때 큐가 비어있다.
}

//full
bool full() {
    return (rear_pointer + 1) % SIZE == front_pointer;
}

//push
void push_back(int k) {
    rear_pointer = (rear_pointer + 1) % SIZE; //rear포인터를 먼저 하나 증가시키고
    queue_vec[rear_pointer] = k; //그위치에 k를 삽입
}

//pop
int pop_front() { // 큐에서의 default pop
    front_pointer = (front_pointer + 1) % SIZE; //front포인터를 먼저 하나 증가시키고
    return queue_vec[front_pointer]; // 그위치에 있는 값 반환.

    //이때 어짜피 비어있는 상태로 치기때문에 값을 굳이 삭제해줄필요 X

}

//size
int size() { 
    int tmp = (rear_pointer - front_pointer);

    
    if (tmp < 0)
        tmp += SIZE;
    return tmp;
}

//front
int front() { //가장 나중에 들어온 값.
    int tmp = (front_pointer + 1) % SIZE; //단순히 맨 앞 값을 가져오기만 하는것이므로 front를 증가시킬 필요 X
    return queue_vec[tmp];
}

//back
int back() { //가장 최근에 들어온 값.
    return queue_vec[rear_pointer]; //rear포인터가 가리키는 값이 가장 최근에 들어온값.
}

//덱에 추가되는 기능 두가지

//1. 가장 뒤쪽에서 빼기 -> rear 출력 및 rear --
int pop_back() {

    int temp = rear_pointer--;

    // index 에러 방지.
    if (rear_pointer  < 0)
    {
        rear_pointer += SIZE;
    }
   

    return queue_vec[temp];
}

//2. 가장 앞쪽에 수 삽입하기 -> front출력 및 front -- 
void push_front(int k) { 

    int temp = front_pointer--;


    // index 에러 방지.
    if (front_pointer  < 0)
    {
        front_pointer += SIZE;

    }
  queue_vec[temp] = k; 

}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k;
    string cmd;




    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == "push_front") {
            cin >> k;
            if (!full())
                push_front(k);
            continue;
        }

        if (cmd == "push_back") {
            cin >> k;
            if (!full()) //라이브러리 사용시 필요 없음
  
                push_back(k);
            continue;
        }
        if (cmd == "pop_front") {
            if (empty())
                cout << -1 << '\n';
            else {
                cout << pop_front() << '\n';

            }
            continue;
        }

        if (cmd == "pop_back") {
            if (empty())
                cout << -1 << '\n';
            else
                cout << pop_back() << '\n';
            continue;
        }

        if (cmd == "size") {
            cout << size() << '\n';
            continue;
        }
        if (cmd == "empty") {
            cout << empty() << '\n';
            continue;
        }
        if (cmd == "front") {
            if (empty())
                cout << -1 << '\n';
            else
            {
                cout << front() << '\n';

            }
            continue;
        }

        if (cmd == "back") {
            if (empty())
                cout << -1 << '\n';
            else
            {
                cout << back() << '\n';

            }
            continue;

        }
    }

    /*
     * 덱 순회
     *
    while (!empty()) {
        cout << front() << ' ';
        pop();
    }
    */
}


