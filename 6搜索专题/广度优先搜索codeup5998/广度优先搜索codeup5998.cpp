// 广度优先搜索codeup5998.cpp
//

#include <iostream>
#include <array>
#include <queue>
#include <list>
#include <unordered_map>
#include <utility>
using namespace std;

using plate = array<array<int, 4>, 2>;
struct plateBFSInfo {
	plate p;
	int step;
	list<char> ops;
};

constexpr auto valMax = 8;
int myhash(const plate& p) {
	int hash = 0;
	for (auto& row : p) {
		for (auto& data : row) {
			hash += data;
			hash *= valMax + 1;
		}
	}
	return hash;
}

// 配合STL的哈希函数，由unordered_map调用此函数进行哈希。
// 但此处不使用这种方法，因为unordered_map会存储key以访问key和处理哈希冲突，此处并不需要这一特性且浪费空间与复制时间。
/*
namespace std {
	template<> // 显式实例化模板
	struct hash<plate> {
		size_t operator()(const plate& p) const  {
			size_t hash = 0;
			for (auto& row : p) {
				for (auto& data : row) {
					hash += data;
					hash *= (valMax + 1);
				}
			}
			return hash;
		}
	};
};
*/

// 广搜最先找到的，必定就是最短路径
int bfs(plate& target, list<char>& resultOps) {
	static constexpr const plate basicSituation = {
		array<int, 4>
		{1, 2, 3, 4},
		{8, 7, 6, 5}
	};
	queue<plateBFSInfo> q; q.push({ basicSituation , 0});
	unordered_map<int, bool> visited; visited[myhash(basicSituation)] = true;
	while (!q.empty()) {
		plateBFSInfo& ss = q.front();
		plate& s = ss.p;
		if (s == target) {
			resultOps = move(ss.ops);
			return ss.step;
		}
		/*
		for (auto& row : s) {
			for (auto& data : row) {
				clog <<  data << " ";
			}
		}
		clog << endl;
		*/
		// op A
		{
			plate ns{ s[1], s[0] }; 
			if (!visited[myhash(ns)]) {
				auto nextops = ss.ops; nextops.push_back('A');
				q.push({ move(ns), ss.step + 1, move(nextops) });
				visited[myhash(ns)] = true;
				
			}
		}
		// op B
		{
			plate ns = s;
			for (int i = 0; i < 2; i++) {
				int t = ns[i].back();
				for (int j = ns[i].size()-1; j > 0; j--) {
					ns[i][j] = ns[i][j-1];
				}
				ns[i].front() = t;
			}
			if (!visited[myhash(ns)]) {
				auto nextops = ss.ops; nextops.push_back('B');
				q.push({ move(ns), ss.step + 1, move(nextops) });
				visited[myhash(ns)] = true;
			}
		}
		// op C
		{
			plate ns = s;
			int t = ns[0][1];
			ns[0][1] = ns[1][1];
			ns[1][1] = ns[1][2];
			ns[1][2] = ns[0][2];
			ns[0][2] = t;
			if (!visited[myhash(ns)]) {
				auto nextops = ss.ops; nextops.push_back('C');
				q.push({ move(ns), ss.step + 1, move(nextops) });
				visited[myhash(ns)] = true;
			}
		}
		q.pop();
	}
	return -1;
}

int main()
{
	plate target;
	while (cin) {
		// 坑：1 2 3 4 5 6 7 8 代表
		// 1 2 3 4（第一行*顺*序）
		// 5 6 7 8（第二行*逆*序）
		for (auto idata = target[0].begin(); idata != target[0].end(); ++idata) {
			cin >> *idata;
		}
		for (auto idata = target[1].rbegin(); idata != target[1].rend(); ++idata) {
			cin >> *idata;
		}
		// 坑：读取完再检测是否无数据。否则会有一组空数据。

		// 取完最后一组数据之后，再次尝试读取，才会置fail/eof。
		// 因此必须保证读取完最后一组数据与检测流有效性之间，还进行了尝试读取。
		// 理想情况在cin >> x就借助返回值检查流，如while(cin >> x >> y >> z)
		if (cin.fail()) {
			break;
		}
		list<char> ops;
		cout << bfs(target, ops) << endl;
		int cnt = 0;
		for (auto& op : ops) {
			cout << op;
			if (++cnt % 60 == 0) {  // 先自增再判断
				cout << endl;
			}
		}
		cout << endl;
	}
}

