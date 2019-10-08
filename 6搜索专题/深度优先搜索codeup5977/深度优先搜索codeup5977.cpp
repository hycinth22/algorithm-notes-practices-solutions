// 深度优先搜索codeup5977.cpp
//

#include <iostream>
#include <stack>
#include <list>
using namespace std;

// 按格式输出的工具函数
template<class iterator>
void output(const char* name, iterator begin, const iterator& end, bool newline = true) {
	clog << name;
	bool first = true;
	for (auto& it = begin; it != end; ++it) {
		if (first) {
			clog << *it;
			first = false;
		}
		else {
			clog << " " << *it;
		}
	}
	if (newline)
		cout << endl;
}


int cnt = 0;  
// 由于可能存在复制元素的大时间开销，通过引用共享一份内存，自行管理状态的前进后退
// 结束条件：in为空
void dfs(list<int>& s, list<int>& in, list<int>& out) {
	// 输入序列为空
	if (in.empty()) {
		/*
		output("", out.cbegin(), out.cend(), false);
		if (!out.empty()) {
			cout << " ";
		}
		output("", s.crbegin(), s.crend());
		*/
		cnt++;
		return;
	}
	// 可以出栈则出一个元素，并递归求子情况
	if (!s.empty()) {
		out.push_back(s.back()); s.pop_back(); // 出栈到out
		dfs(s, in, out); // 递归求子情况
		s.push_back(out.back()); out.pop_back(); // 撤销出栈
	}
	// 如果可以进栈则进一个元素，并递归求子情况
	s.push_back(in.front()); in.pop_front(); // 从队列in入栈
	dfs(s, in, out); // 递归求子情况
	in.push_front(s.back()); s.pop_back(); // 撤销入栈
}

void search(list<int> &dataset) {
	list<int> s;
	list<int> in(dataset);
	list<int> out;
	cnt = 0;
	dfs(s, in, out);
	return;
}

int main()
{
	int n; cin >> n;
	list<int> dataset;
	for (int i = 1; i <= n; i++) {
		dataset.push_back(i);
	}
	search(dataset);
	cout << cnt << endl;
}

