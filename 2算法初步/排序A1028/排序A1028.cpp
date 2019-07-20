// 排序A1028.cpp
//

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm> 
using namespace std;

struct student {
	string id;
	string name;
	int score;
	
};

int main()
{
	int n, col; cin >> n >> col;
	vector<student> v; v.resize(n);
	for(int i=0; i<n;i++) {
		cin >> v[i].id >> v[i].name >> v[i].score;
	}
	sort(v.begin(), v.end(), [col](const student& a, const student& b) {
		switch (col)
		{
		case 1:
			return a.id < b.id;
		case 2:
			if (a.name != b.name) {
				return a.name < b.name;
			}
			return a.id < b.id;
		case 3:
			if (a.score != b.score) {
				return a.score < b.score;
			}
			return a.id < b.id;
		default:
			return a.id < b.id;
		}
	});
	for (student& s : v) {
		cout << s.id << " " << s.name << " " << s.score << endl;
	}
}

