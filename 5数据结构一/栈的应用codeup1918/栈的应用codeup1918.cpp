// 栈的应用codeup1918.cpp
//

#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
using namespace std;

/*
解1：即时计算。只有一步，但扩展性有限。
*/
#include <stack>
inline int priority(const char& c) {
	switch (c) {
	case '+':
	case '-':
		return 0;
	case '*':
	case '/':
		return 1;
	}
	return -1;
}

inline double execOpr(const char& c, double a, double b) {
	switch (c) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	}
	return -1;
}

double calc(const string& expr) {
	stack<double> sN; stack<char> sO;
	double result = 0.0;
	string n;
	for (const char& c : expr) {
		if (isdigit(c)) {
			n.append(1, c);
		}
		else {
			if (!n.empty()) {
				sN.push(stod(n));
				n.clear();
			}
			if (c == '+' || c == '-' || c == '*' || c == '/') {
				// 保证左结合，必须>=而不能>
				while (!sO.empty() && priority(sO.top()) >= priority(c)) {
					auto op = sO.top(); sO.pop();
					auto n2 = sN.top(); sN.pop();
					auto n1 = sN.top(); sN.pop();
					sN.push(execOpr(op, n1, n2));
				}
				sO.push(c);
			}
			else if (c == ' ') {
				continue;
			}
			else {
				return -1;
			}
		}
	}
	if (!n.empty()) {
		sN.push(stod(n));
		n.clear();
	}
	// 计算剩余的
	while (!sO.empty()) {
		auto op = sO.top(); sO.pop();
		auto n2 = sN.top(); sN.pop();
		auto n1 = sN.top(); sN.pop();
		sN.push(execOpr(op, n1, n2));
	}
	return sN.top();
}

/*
解2：解析为后缀表达式队列，再运算。结合面向对象，易于扩展。
*/
#include <stack>
#include <queue>
struct obj {
	int type;
	union {
		double num;
		char op;
	} data;
};
// 1+2*3     1 2 3 * +
// 1+2*3+4   1 2 3 * + 4 +
// 30/90-26+97-5-6-13/88*6      30 90 / 26 - 97 + 5 - 6 - (13 88 / 6 *) -  
queue<obj> convert(const string& expr) {
	queue<obj> r;
	stack<char> sO;
	string n;
	for (const char& c : expr) {
		if (isdigit(c)) {
			n.append(1, c);
		}
		else {
			if (!n.empty()) {
				obj o;
				o.type = 1;
				o.data.num = stod(n);
				r.push(o);
				n.clear();
			}
			if (c == '+' || c == '-' || c == '*' || c == '/') {
				while (!sO.empty() && priority(sO.top()) >= priority(c)) {
					obj o;
					o.type = 0;
					o.data.op = sO.top(); sO.pop();
					r.push(o);
				}
				sO.push(c);
			}
			else if (c == ' ') {
				continue;
			}
			else {
				return queue<obj>{};
			}
		}
	}
	if (!n.empty()) {
		obj o;
		o.type = 1;
		o.data.num = stod(n);
		r.push(o);
		n.clear();
	}
	// 计算剩余的
	while (!sO.empty()) {
		obj o;
		o.type = 0;
		o.data.op = sO.top(); sO.pop();
		r.push(o);
	}
	return r;
}
// 1+2*3     1 2 3 * +         7
// 1+2*3+4   1 2 3 * + 4 +     11
// 30/90-26+97-5-6-13/88*6      30 90 / 26 - 97 + 5 - 6 - (13 88 / 6 *) -    59.44696969696969696969696969697‬
double calcQueue(queue<obj> q) {
	stack<double> sN;
	while (!q.empty()) {
		obj o = q.front(); q.pop();
		if (o.type == 1) {
			sN.push(o.data.num);
		}
		else if (o.type == 0) {
			double n2 = sN.top(); sN.pop();
			double n1 = sN.top(); sN.pop();
			sN.push(execOpr(o.data.op, n1, n2));
		}
		else {
			return -1;
		}
	}
	if (sN.empty()) {
		return -2;
	}
	return sN.top();
}


int main()
{
	string str; cout << fixed << setprecision(2);
	while (getline(cin, str) && str!="0") {
		cout << calcQueue(convert(str)) << endl;
	}

}

