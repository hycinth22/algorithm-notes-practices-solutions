// 递归-全排列.cpp
//

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <functional>
#include <codecvt>
#include <locale>
using namespace std;

vector<wstring> p(const wstring& chars) {
	vector<wstring> r; wstring str(chars);
	const function<void(size_t)> f = [&f, &r, &str](size_t i) {
		if (str.length() - 1 == i) {
			// end case
			r.push_back(str);
		}
		else {
			for (size_t j = i; j < str.length(); ++j) {
				// select from s[i, len), and fill into s[j]
				swap(str[i], str[j]);
				f(i + 1);
				// undo the fill, then we can try other selection in str[i]
				swap(str[i], str[j]);
			}
		}
	};
	f(0);
	return r;
}

void setupChinese() {
	static locale locChinese("Chinese");
	locale::global(locChinese);
}

int main()
{
	for (;;) {
		wstring s;
		getline(wcin, s);
		auto r = p(s);
		for (const wstring& s : r) {
			wcout << s << endl;
		}
	}
}

