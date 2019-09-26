// 栈的应用codeup1982.cpp
// cid=100000605

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool valid(const string& str) {
	stack<char> s;
	for (const char& c : str) {
		switch (c) {
		case '(':
			s.push(')');
			break;
		case '[':
			s.push(']');
			break;
		case '{':
			s.push('}');
			break;
		case ')':
		case ']':
		case '}':
			if (s.empty() || s.top() != c) {
				return false;
			}
			s.pop();
			break;
		}
	}
	return s.empty();
}

int main()
{
	int n; cin >> n; cin.get();
	while (n--) {
		string str; getline(cin ,str);
		cout << (valid(str)?"yes":"no") << endl;
	}
}

