// 散列B1043.cpp
//

#include <cstdio>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_map<char, size_t> cnt;
	char c; scanf("%c", &c);
	size_t sum = 0;
	while (c != '\n') {
		switch (c)
		{
		case 'P':
		case 'A':
		case 'T':
		case 'e':
		case 's':
		case 't':
			cnt[c]++;
			sum++;
		default:
			break;
		}
		scanf("%c", &c);
	}
	const char cs[6] = { 'P', 'A', 'T', 'e', 's', 't' };
	while (sum) {
		for (const char& c : cs) {
			if (cnt[c]) {
				printf("%c", c);
				cnt[c]--;
				sum--;
			}
		}
	}
}

