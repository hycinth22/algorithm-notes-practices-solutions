// stack_codeup100000602B.cpp
//

#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;

bool legalExpr(const string& str) {
	// () [] {}
	map<char, char> pair;
	pair[')'] = '(';
	pair[']'] = '[';
	pair['}'] = '{';
	stack<char> right;
	for (auto& c : str) {
		for (auto& p : pair) {
			if (c == p.second) {
				right.push(p.first);
			}
		}
		if (pair.count(c)) {
			if (!right.empty() && right.top()==c) {
				right.pop();
			}
			else {
				if (right.empty()) {
					clog << "Redundant " << c << endl;
				}
				else {
					clog << "Missing " << right.top() << endl;
				}
				return false;
			}
		}
	}
	if (!right.empty()) {
		clog << "Missing " << right.top() << endl;
	}
	return right.empty();
}

int main()
{
	int n; cin >> n; cin.get();
	while (n--) {
		string expr; getline(cin, expr);
		cout << (legalExpr(expr) ? "yes" : "no") << endl;
	}
}

