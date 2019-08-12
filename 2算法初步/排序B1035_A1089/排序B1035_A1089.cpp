// 排序B1035_A1089.cpp
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

vector<long long> isInsertSort(vector<long long> data, const vector<long long>& mid) {
	if (data.empty()) {
		return {};
	}
	bool yes = false;
	size_t edge = 1, n= data.size();
	while (edge <n) {
		// 由于只需简单模拟过程，无需保证是插入排序，因此可以偷懒写法，对于局部排序直接调用STL即可。
		// (此处偷懒最好用stable_sort而不是sort，因为sort是快排，快排对有序数据反而效率差)
		stable_sort(data.begin(), data.begin() + edge + 1); // 选择将edge外第一个元素排入到正确位置
		// 以下被注释的内容为选择排序的正确写法。可以替换上面的stable_sort。
		/*size_t i = 0;
		while (i < edge && data[i]<data[edge]) {
			i++;
		}
		assert(data[i]>=data[edge]);
		while (i < edge) {
			swap(data[i], data[edge]);
			i++;
		}
		assert(i == edge);
		*/
		edge++;
		if (yes) {
			clog << "nextTurn when edge " << edge << endl;
			return data;
		}
		if (data == mid) {
			yes = true;
			clog << "yes when edge " << edge << endl;
		}
	}
	return {};
}

vector<long long> isMergeSort(vector<long long> data, const vector<long long>& mid) {
	bool yes = false;
	size_t step = 2, n = data.size();
	// 注意归并排序终止条件的写法，不要写成step<data.size()，否则最后一轮排序未做就退出循环了 
	while(step/2 <= data.size()) {
		for (size_t i = 0; i < n; i += step) {
			auto begin = data.begin() + i;
			auto mid = (i + step/2 < n)? (begin + step / 2) : data.end(); // 注意要固定长度step/2，不能直接/2，元素长度不足时要尽量多取以接近step/2，否则模拟结果不一致。
			auto end = (i + step < n) ? (begin + step) : data.end();  // 不足以组成step长的区间，取剩余的
			if (mid != end) {
				// 这里没有自行实现merge操作，偷懒直接调用STL的归并函数，
				// [begin, mid), [mid, end)
				inplace_merge(begin, mid, end); // 当然也可以仿照上面插入排序调用排序算法完成局部排序。// stable_sort(begin, end);
			}
		}
		if (yes) {
			clog << "nextTurn in step " << step << endl;
			return data;
		}
		if (data == mid) {
			yes = true;
			clog << "yes in step " << step << endl;
		}
		step *= 2;
	}
	return {};
}

int main()
{
	int n; cin >> n;
	vector<long long> origin(n);
	for (auto& i : origin) {
		cin >> i;
	}
	vector<long long> mid(n);
	for (auto& i : mid) {
		cin >> i;
	}
	// 尝试插入排列
	vector<long long> nextTurn = isInsertSort(origin, mid);
	if (!nextTurn.empty()) {
		cout << "Insertion Sort" << endl;
	}
	else {
		// 	// 尝试归并排序
		nextTurn = isMergeSort(origin, mid);
		cout << "Merge Sort" << endl;
	}
	// 注意先检查是否为空再输出第一个
	if (!nextTurn.empty()) {
		cout << nextTurn.front();
	}
	for (size_t i = 1; i < nextTurn.size(); i++) {
		cout << " " << nextTurn[i];
	}
}

