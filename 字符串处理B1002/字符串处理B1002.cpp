// 字符串处理B1002.cpp
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str; getline(cin, str);
	int sum = 0;
	for (char &c : str) {
		sum += c - '0';
	}
	const string table[10] = {"ling", "yi", "er", "san", "si", "wu", "liu" , "qi", "ba", "jiu"};
	string result = table[sum % 10];
	sum /= 10;
	while (sum > 0) {
		result.insert(0, table[sum%10]+" ");
		sum /= 10;
	}
	cout << result << endl;
}

