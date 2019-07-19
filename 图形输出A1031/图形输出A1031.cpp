// 图形输出A1031.cpp
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str; getline(cin, str);
	auto it = str.cbegin();
	int cntchar = str.size();
	int row = (cntchar + 2) / 3;
	int col = (cntchar + 2) - 2 * row;
	char** image = new char*[row];
	for (int i = 0; i < row; i++) {
		image[i] = new char[col];
		for (int j = 0; j < col; j++) {
			image[i][j] = ' ';
		}
	}

	for (int i = 0; i < row; i++) {
		image[i][0] = *it++;
	}
	for (int i = 1; i < col-1; i++) {
		image[row-1][i] = *it++;
	}
	for (int i = row - 1; i >= 0; i--) {
		image[i][col-1] = *it++;
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << image[i][j];
		}
		cout << endl;
	}
	// todo: free image
}

