#include <iostream>
#include <string>
#include <vector>

using namespace std;


const string ERROR = "Error!";

//인수로 받은 문자열이 Java 형식의 변수명인지 판단하는 함수
bool isJava(string str) { 	//str은 _가 없는 상태
	

	return !isupper(str[0]);

}

//인수로 받은 문자열이 C++ 형식의 변수명인지 판단하는 함수
bool isCpp(string str) {

	// cpp예외처리  


	if (str[0] == '_' || str[str.length() - 1] == '_') // 처음 or 마지막글자가 _라면
		return false;


	if (str.find("__") != string::npos)// _가 연속해서 두번이상 나오면
		return false;


	for (char c : str) {
		if (isupper(c)) //대문자가 있다면
			return false;
	}


	return true;


}





string javaToCpp(string str) { 

	for (int i = 1; i < str.length(); i++) {

		if (isupper(str[i])) //대문자라면
		{
			str[i]=tolower(str[i]); //소문자로 바꿔주고
			str.insert(i , "_"); // 바로 앞에 _추가		

		}

	}

	return str;
}

string cppToJava(string str) {

	for (int i = 0; i< str.length(); i++) {

		if (str[i] == '_')
		{
			str.erase(i,1); // _를 지우고
		   str[i]= toupper(str[i]);// 다음글자를 대문자로 바꾼다. (_가 지워지면 index가 하나 앞당겨지므로 i+1이 아님)

		}

	}

	return str;
}

int main() {


	
		string str;


		cin >> str;

		//우선 _가 있는지 없는지로 어떤 언어 형식으로 인식될수있는지 구분한다.
		//그리고 str이 그 언어형식조건에 맞는지 확인한다.



		if (str.find("_") != string::npos) { // str에 '_'가 있다면

			
			//str은 java형태로 인식될수없으니 cpp형식으로 쓰여졌는지 확인과정을 거친다. 
			if (isCpp(str)) //cpp로 제대로 쓰여진게 맞다면
				cout << cppToJava(str); //cpp ->java

			else
				cout << ERROR ;


		}
		else { //'_'가 없다면  

			
			//str은 cpp형태로 인식될수없으니 java형식으로 쓰여졌는지 확인과정을 거친다.  
			if (isJava(str)) //java로 제대로 쓰여진게 맞다면
				cout << javaToCpp(str) ; // java -> cpp

			else
				cout << ERROR;

		}
	

		// + 오직 소문자로 이루어진 경우는 java +cpp 모두에 해당하지만 여기선 java 형식으로 분류되고 isjava검사를 받는다. 그래도 결과는 같다.
}

