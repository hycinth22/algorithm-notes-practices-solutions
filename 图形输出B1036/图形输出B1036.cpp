	// 图形输出B1036.cpp
	//

	#include <iostream>
	using namespace std;

	int main()
	{
		int n; cin >> n;
		char c; cin >> c;
		int line = (int)round(n / 2);
		for (int i = 0; i < line; i++) {
			for (int j = 0; j < n; j++) {
				cout << ((i==0||i== line -1||j==0||j==n-1)?c:' ');
			}
			cout << endl;
		}
	}

