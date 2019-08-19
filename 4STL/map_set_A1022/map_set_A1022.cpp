// map_set_A1022.cpp
//

#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

using BookID = string; // 如果使用int存储，记得是7位，输出补0
map<string, set<BookID>> index_title, 
index_author, index_keyword,
index_publisher, index_year;

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string id; cin >> id; cin.get(); // ignore the enter
		string title; getline(cin, title);
		string author; getline(cin, author);
		set<string> keywords;
		while (cin.get() != '\n') {
			cin.unget();
			string key;
			cin >> key; keywords.insert(key);
		}
		string publisher; getline(cin, publisher);
		string year; getline(cin, year);
		index_title[title].insert(id);
		index_author[author].insert(id);
		for (auto& key : keywords) {
			index_keyword[key].insert(id);
		}
		index_publisher[publisher].insert(id);
		index_year[year].insert(id);
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int k; cin >> k;
		cin.get(); // ignore: ":"
		while (cin.get()==' ') {
		}
		cin.unget();
		string str; getline(cin, str);
		cout << k << ": " << str << endl;
		map<string, set<BookID>>* tables[] = { 
			&index_title, &index_author, &index_keyword, 
			&index_publisher, &index_year
		};
		auto& index = *tables[k-1];
		auto& result = index[str];
		if (!result.empty()) {
			for (auto& id : result) {
				cout << id << endl;
			}
		}
		else {
			cout << "Not Found" << endl;
		}
	}

}

