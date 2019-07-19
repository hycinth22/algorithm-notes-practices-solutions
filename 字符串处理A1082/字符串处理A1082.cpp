// 字符串处理A1082.cpp
//

#include <iostream>
#include <string>
using namespace std;

const int k = 10000;

// only accpet non-zero, less than k
string smallRead(int n) {
	const int smallLength = 4;
	const string digits[10] = { "ling" , "yi" , "er", "san", "si", "wu",
		"liu", "qi", "ba", "jiu" };
	const string smallUnits[smallLength] = { " Qian", " Bai", " Shi", "" };
	if (n >= k) return "ILLGEAL smallRead";
	int s[smallLength];
	s[3] = n % 10;
	n /= 10;
	s[2] = n % 10;
	n /= 10;
	s[1] = n % 10;
	n /= 10;
	s[0] = n % 10;
	string result;
	bool first = true, lastzero = false;
	for (int i = 0; i < smallLength; i++) {
		int& t = s[i];
		if (first) {
			if (t != 0) {
				result = digits[t] + smallUnits[i];
				first = false;
			}
			// no read prefix zero
		}
		else {
			if (t != 0) {
				if (lastzero) {
					result += " ling";
					lastzero = false;
				}
				result += " " + digits[t] + smallUnits[i];
			}
			else {
				lastzero = true;
				// mark only, read zero before read non-zero
			}
		}
	}
	if (result.empty()) {
		return "ling";
	}
	return result;
}

string read(int n) {
	const int readMax = 3;
	if (n > 21*k*k || n < -21 * k * k) {
		return "Excced ReadRange Limit";
	}
	const string bigUnits[readMax] = { " Yi", " Wan", "" };
	string result;
	if (n < 0) {
		result = "Fu ";
		n = -n;
	}
	string readWords[readMax];
	int spilit[readMax];
	spilit[2] = n % k;
	n /= k;
	spilit[1] = n % k;
	n /= k;
	spilit[0] = n % k;
	readWords[0] = smallRead(spilit[0]);
	readWords[1] = smallRead(spilit[1]);
	readWords[2] = smallRead(spilit[2]);
	bool first = true, lastzero = false;
	for (int i = 0; i < readMax; i++) {
		string& t = readWords[i];
		if (first) {
			if (spilit[i] != 0) {
				result += t + bigUnits[i];
				first = false;
			}
			// no read prefix zero
		}
		else {
			if (spilit[i] != 0) {
				if (spilit[i] < k / 10) {
					lastzero = true;
				}
				if (lastzero) {
					result += " ling";
					lastzero = false;
				}
				result += " " + t + bigUnits[i];
			}
			else {
				lastzero = true;
				// mark only, read zero before read non-zero
			}
		}
	}
	if (result.empty()) {
		return "ling";
	}
	return result;
}

int main()
{
	int n; cin >> n;
	cout << read(n);
}

