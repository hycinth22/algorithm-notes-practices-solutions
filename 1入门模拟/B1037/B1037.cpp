// B1037.cpp
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

money operator-(const money &lhs, const money &rhs) {
	money diff;
	if (lhs<rhs) {
		diff = rhs - lhs;
		diff.galleon = -diff.galleon;
		return diff;
	}
	int borrow = 0;
	diff.kunt = lhs.kunt - rhs.kunt;
	if (diff.kunt < 0) {
		diff.kunt += 29;
		borrow--;
	}
	diff.sickle = lhs.sickle + borrow - rhs.sickle;
	borrow = 0;
	if (diff.sickle < 0) {
		diff.sickle += 17;
		borrow--;
	}
	diff.galleon = lhs.galleon + borrow - rhs.galleon;
	borrow = 0;
	return diff;
}

int main()
{
	money should, paid, back;
	scanf_s("%d.%d.%d", &should.galleon, &should.sickle, &should.kunt);
	scanf_s("%d.%d.%d", &paid.galleon, &paid.sickle, &paid.kunt);
	back = paid - should;
	printf("%d.%d.%d", back.galleon, back.sickle, back.kunt);
}

