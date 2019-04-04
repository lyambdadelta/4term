#include "Vector2.h"
#include <cmath>
using namespace std;

Vector2::Vector2() {
	x = 0;
	y = 0;
}

Vector2::Vector2(float a) {
	x = a;
	y = 0;
}

Vector2::Vector2(float a, float b) {
	x = a;
	y = b;
}

bool Vector2::operator==(const Vector2 & other) const
{
	if (x == other.x && y == other.y) {
		return true;
	}
	else {
		return false;
	}
}

Vector2 Vector2::operator+(const Vector2& other) const {
	return Vector2(x + other.x, y + other.y);
}

Vector2& Vector2::operator+=(const Vector2 & other)
{
	x += other.x;
	y += other.y;
	return *this;
}

Vector2 Vector2::operator-(const Vector2 & other) const
{
	return Vector2(x - other.x, y - other.y);
}

Vector2& Vector2::operator-=(const Vector2 & other)
{
	x -= other.x;
	y -= other.y;
	return *this;
}

Vector2 Vector2::operator-() const
{
	return Vector2(-x, -y);
}

Vector2 Vector2::operator/(float f) const
{
	return Vector2(x/f, y/f);
}

Vector2 Vector2::operator*(float f) const
{
	return Vector2(x * f, y * f);
}

Vector2 Vector2::norm() const
{
	float q = len();
	if (q == 0) {
		return Vector2(0, 0);
	}
	return Vector2(x / q, y / q);
}

Vector2 Vector2::perpen() const
{
	return Vector2(y, -x);
}

float Vector2::operator*(const Vector2 & other) const
{
	return x * other.x + y * other.y;
}

float Vector2::operator^(const Vector2 & other) const
{
	return x * other.y - y * other.x;
}

float Vector2::len() const
{
	return sqrt(x * x + y * y);
}

float Vector2::squareLen() const
{
	return x * x + y * y;
}

Vector2& Vector2::rotate(const float degree)
{
	float tempx = x * cos(degree) - y * sin(degree);
	y = x * sin(degree) + y * cos(degree);
	x = tempx;
	return *this;
}

Vector2 Vector2::getRotated(const float degree) const
{
	return Vector2(x * cos(degree) - y * sin(degree), x * sin(degree) + y * cos(degree));
}

ostream& operator<< (ostream &out, const Vector2& vector)
{
	cout << vector.x << " " << vector.y << " ";
	return out;
}

istream& operator>> (istream &inp, Vector2& vector)
{
	cin >> vector.x >> vector.y;
	return inp;
}

Vector2 operator*(float f, Vector2 vector) {
	return Vector2(f * vector.x, f * vector.y);
};
