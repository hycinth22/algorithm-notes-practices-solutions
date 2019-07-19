// 查找元素A1036.cpp
//

#include <iostream>
#include <string>
using namespace std;

string boyname, boyid; int boyscore = 999; 
string girlname, girlid; int girlscore = -999;

void output(string name, string id) {
	if (id.empty()) {
		cout << "Absent" << endl;
		return;
	}
	cout << name << " " << id << endl;
}

int main()
{
	int n; cin >> n;
	while (n--) {
		string name, id, sex; int score;
		cin >> name >> sex >> id >> score;
		if (sex == "M" && score < boyscore) {
			boyname = name;
			boyid = id;
			boyscore = score;
		}
		if (sex == "F" && score > girlscore) {
			girlname = name;
			girlid = id;
			girlscore = score;
		}
	}
	output(girlname, girlid);
	output(boyname, boyid);
	if (!boyid.empty() && !girlid.empty()) {
		cout << girlscore-boyscore << endl;
	}
	else {
		cout << "NA" << endl;
	}
}

