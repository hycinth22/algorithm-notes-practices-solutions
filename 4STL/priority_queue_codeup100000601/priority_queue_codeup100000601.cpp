// priority_queue_codeup100000601.cpp
//

#include <iostream>
#include <queue> // 注意头文件名称，priority_queue与普通队列queue同一文件。
#include <string>
#include <map>
using namespace std;

struct task {
	string name;
	int prio;
	// 注意优先级队列默认使用less比较元素，但输出的是最大元素。
	// 因此，先输出的应当返回false
	bool operator<(const task& rhs) const {
		if (prio != rhs.prio) {
			return prio > rhs.prio; // 优先级数字小的先输出
		}
		return name > rhs.name; // 名字字典序小的先输出
	}
};
int main()
{
	int n; cin >> n; cin.get();
	map<string, int> prios;
	priority_queue<task> q;
	while (n--) {
		string input; getline(cin, input);
		size_t left = input.find('('), right = input.find(')', left+1);
		task p; p.name = input.substr(0, left);
		if (prios.count(p.name)) {
			// 如果已被指定prio，说明它是某个前置任务的子任务
			p.prio = prios[p.name]; // 接受此优先级
		}
		else {
			p.prio = 0;
			q.push(p);
			prios[p.name] = p.prio;
		}
		
		size_t begin = left+1, d = 0;
		while (d != string::npos) {
			task c;
			d = input.find(',', begin);
			if (d != string::npos) {
				c.name = input.substr(begin, d-begin);
				begin = d + 1;
			}
			else if (right != string::npos){
				c.name = input.substr(begin, right-begin);
				if (c.name == "NULL") {
					break;
				}
			}
			c.prio = p.prio + 1;
			if (!prios.count(p.name)) {
				prios[c.name] = c.prio;
				q.push(c);
			}
		}
	}
	while (!q.empty()) {
		cout << q.top().name << " ";
		q.pop();
	}
}

