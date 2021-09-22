#include <iostream>
#include <stack>
#include <map>


using namespace std;

//괄호의 짝을 저장할 맵
map <char, char> bracket; 


//괄호 짝이 맞는지 확인.
bool isBalanced(string input) { 

    //스택에 넣고, 맨 위의 것과 짝이 맞을때 pop한다.
    stack <int> s;

    for (int i = 0; i < input.size(); i++) {

        switch (input[i]) {
        case '(': case '[': //여는 괄호
            s.push(input[i]);
            break;

        case ')': case ']': //닫는 괄호
            if (!s.empty() && s.top() == bracket[input[i]])
                s.pop();

            else  return false; //스택이 비어있거나 짝이 맞지 않을경우


        }
    }

    return s.empty(); // 모든 string이 끝났는데 아직 남아있는것이 있으면 false반환.

}


int main() {

    string input;
    bracket[')'] = '(';
    bracket[']'] = '[';

    while (true) {

        //입력
       getline(cin, input); //띄어쓰기 포함 입력 받기                                                                                                                      
        if (input == ".")
            break;

        //연산 & 출력
        //input에 대해 괄호 맞는지 확인
        if (isBalanced(input))
            cout << "yes\n";
        else
            cout << "no\n";
    }
}