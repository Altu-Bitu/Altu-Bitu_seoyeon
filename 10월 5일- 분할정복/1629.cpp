#include <iostream>

using namespace std;
typedef long long ll;


//Q.이 함수의 리턴형은 왜 ll 이어야하나.. c로 나눈 나머지를 저장하니까 int여도 괜찮지 않나?
//A. sub_probelm * sub_problem 이라는 문장때문! 만일 int형으로 한다면 INT_MAX *INT_MAX는 오버플로우가 발생할것 !

//분할 정복으로 곱셈을 하는 함수
ll divide(int a, int b, int c) { 
   
    //Conquer 
    if (b == 1)
        return a % c;

    //Divide : 제곱 수 나누기
    if (b % 2 == 0) { //b가 짝수일 때
        ll sub_problem = divide(a, b / 2, c);
        return (sub_problem * sub_problem) % c; //Combine : 곱셈 결과 리턴
    }
    //b가 홀수일 때
    return (a * divide(a, b - 1, c)) % c; //Combine : 곱셈 결과 리턴
}


// INT_MAX^INT_MAX는 long long으로도 담을 수 없는 큰값. 
// 따라서 a^b를 계산한 결과를 가지고 c로 나눈 나머지를 구하는 것은 불가능.
// - > 중간중간 나머지 연산을 처리해줌으로서 오버 플로우가 발생하지 않도록 하자!
// ex) 7^4 %10 = (7^2 %10) * (7*2%10 ) %10  = ((7^1*7^1 %10) %10) * ((7^1*7^1 %10) ) %10 =1


int main() {
    int a, b, c;

    //입력
    cin >> a >> b >> c;

    //연산 & 출력
    cout << divide(a, b, c);
}