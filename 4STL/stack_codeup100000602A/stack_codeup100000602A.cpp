// stack_codeup100000602A.cpp
//

#include <iostream>
#include <iomanip>
#include <stack>
#include <string>
using namespace std;

struct op {
	op(const char& c) : type(c) {
		switch (c) {
		case '+':
		case '-':
			prior = 0;
			break;
		case '*':
		case '/':
			prior = 1;
			break;
		default:
			prior = 0;
		}
	}
	double execBinary(double n1, double n2) {
		switch (type) {
		case '+':
			return n1 + n2;
		case '-':
			return n1 - n2;
		case '*':
			return n1 * n2;
		case '/':
			return n1 / n2;
		default:
			return 0.0;
		}
	}
	char type;
	int prior;
};

double calc(const string& expr) {
	stack<double> nums; stack<op> ops;
	bool appendNum = false;
	for (auto& obj : expr) {
		if (obj == ' ') {
			if (appendNum) {
				appendNum = false;
			}
		}
		if (obj == '+' || obj == '-' || obj == '*' || obj == '/') {
			op theop(obj);
			// 由于数值栈只能存储int，因此必须把当前操作符的左操作数(按左结合)中所有更高优先级的运算符，
			// 计算出来最终结果(int)，才能继续计算。
			// 也即，将所有高优先级运算符(* /)先计算出来。
			while (!ops.empty() && ops.top().prior >= theop.prior)
			{
				op t = ops.top(); ops.pop();
				double n1, n2;
				// 特别注意，栈顶的是n2，然后才是n1
				n2 = nums.top(); nums.pop();
				n1 = nums.top(); nums.pop();
				nums.push(t.execBinary(n1, n2));
			}
			ops.push(theop);
		}
		else if (obj >= '0' && obj <= '9') {
			if (appendNum) {
				nums.top() = nums.top() * 10 + (obj - '0');
			}
			else {
				nums.push(obj - '0');
				appendNum = true;
			}
		}
	}
	// 计算所有剩余的操作符运算。
	while (!ops.empty()) {
		op t = ops.top(); ops.pop();
		double n1, n2;
		// 特别注意，栈顶的是n2，然后才是n1
		n2 = nums.top(); nums.pop();
		n1 = nums.top(); nums.pop();
		nums.push(t.execBinary(n1, n2));
	}
	if (nums.empty()) {
		return -1;
	}
	return nums.top();
}

int main()
{
	string str;
	while (1) {
		getline(cin, str);
		if (str == "0") {
			break;
		}
		cout << fixed << setprecision(2) << calc(str) << endl;
	}
}

