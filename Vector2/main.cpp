#include "Vector2.h"
using namespace std;

int main()
{
	Vector2 first, second, temp;
	float f, deg;
	cout << "Enter 2 2D vectors: ";
	cin >> first >> second;
	cout << "Enter f-number and degree number: ";
	cin >> f >> deg;
	cout << "You entered vectors: " << first << " and " << second << endl;
	{
		temp = first + second;
		first += second;
		if (temp == first) {
			cout << "Their sum is " << temp << endl;
		}
		first -= second;
	}
	{
		temp = first - second;
		first -= second;
		if (temp == first) {
			cout << "Their diff is " << temp << endl;
		}
		first += second;
	}
	cout << "The opposite vector for first: " << - first << endl;
	if (f * first == first * f) {
		cout << "The mul for first vector and f-number: " << first * f << endl;
	}
	cout << "The div for first vector and f-number: " << first / f << endl;
	cout << "The norm for first vector: " << first.norm() << endl;
	cout << "The perpen for first vector: " << first.perpen() << endl;
	cout << "The scalar product for vectors is: " << first * second << endl;
	cout << "The vector product for vectors is: " << (first ^ second) << endl;
	cout << "The len for first vector: " << first.len() << endl;
	cout << "And the square len for first vector: " << first.squareLen() << endl;
	{
		temp = first.getRotated(deg);
		first.rotate(deg);
		if (temp == first) {
			cout << "The rotated first vector: " << temp << endl;
		}
	}
	return 0;
}
