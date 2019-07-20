// 排序A1055.cpp
//

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm> 
using namespace std;

struct RichMan {
	string name;
	int age;
	int worth;
};

int main()
{
	int n, k; cin >> n >> k;
	vector<RichMan> v; v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].name >> v[i].age >> v[i].worth;
	}
	sort(v.begin(), v.end(), [](const RichMan& a, const RichMan& b) {
		if (a.worth != b.worth) {
			return a.worth > b.worth;
		}
		if (a.age != b.age) {
			return a.age < b.age;
		}
		return a.name < b.name;
		});
	for (int i = 1; i <= k; i++) {
		int maxNum, minAge, maxAge; cin >> maxNum >> minAge >> maxAge;
		cout << "Case #" << i << ":" << endl;
		int cnt = 0;
		for (RichMan& person : v) {
			if (cnt >= maxNum) {
				break;
			}
			if (person.age >= minAge && person.age <= maxAge) {
				cout << person.name << " " << person.age << " " << person.worth << endl;
				cnt++;
			}
		}
		if (cnt == 0) {
			cout << "None" << endl;
		}
	}
}
