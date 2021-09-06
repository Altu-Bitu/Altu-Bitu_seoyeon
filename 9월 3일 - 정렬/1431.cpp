#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>


using namespace std;

int sum(string str) { //string에서 숫자만 더해서 그 값을 리턴하는 함수

	int sum=0;
	for (int i = 0; i < str.length(); i++) {

		if (isdigit(str[i]))
			sum += str[i]-'0';
	}
	return sum;
}

bool compare (string a, string b) {

	
	if (a.length() != b.length()) //길이 다를때

		return a.length() < b.length(); //길이가 짧은 순서대로

	else //길이 같을때 
	{
		int aSum = sum(a);
		int bSum = sum(b);
		
		
		if (aSum != bSum) //길이가 같은데 sum이 다를때
			return aSum < bSum; 

		else  //길이도 같고 sum도 같을때
		return  a < b; //사전순비교

	 }	
}


int main() {

	int n;

	cin >> n;

	vector <string> v(n);

	for (int i = 0; i < n; i++) {

		cin>>v[i];
	}
	

	sort(v.begin(), v.end(), compare);


	for (int i = 0; i < n; i++) {

		cout << v[i] << endl;
	}
}


