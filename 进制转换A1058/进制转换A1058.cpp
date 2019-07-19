// A1058.cpp
//

#include <cstdio>
using namespace std;

struct money {
	int galleon, sickle, kunt;
public:
	bool operator<(const money& rhs) const {
		if (this->galleon != rhs.galleon) {
			return this->galleon < rhs.galleon;
		}
		if (this->sickle != rhs.sickle) {
			return this->sickle < rhs.sickle;
		}
		return this->kunt < rhs.kunt;
	}
};

money operator+(const money& lhs, const money& rhs) {
	money sum;
	int carry = 0;
	sum.kunt = lhs.kunt + rhs.kunt;
	if (sum.kunt >= 29) {
		carry = sum.kunt / 29;
		sum.kunt %= 29;
	}
	sum.sickle = lhs.sickle + rhs.sickle + carry;
	carry = 0;
	if (sum.sickle >= 17) {
		carry = sum.sickle / 17;
		sum.sickle %= 17;
	}
	sum.galleon = lhs.galleon + rhs.galleon + carry;
	carry = 0;
	return sum;
}

int main()
{
	money should, paid;
	scanf("%d.%d.%d", &should.galleon, &should.sickle, &should.kunt);
	scanf("%d.%d.%d", &paid.galleon, &paid.sickle, &paid.kunt);
	money sum = paid + should;
	printf("%d.%d.%d", sum.galleon, sum.sickle, sum.kunt);
}


