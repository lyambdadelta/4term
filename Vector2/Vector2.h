#pragma once
#include "pch.h"
#include <iostream>
using namespace std;

class Vector2 {
public:
	float x, y;
	Vector2();
	Vector2(float a);
	Vector2(float a, float b);
	bool operator== (const Vector2& other) const;
	Vector2 operator+(const Vector2& other) const;
	Vector2& operator+=(const Vector2& other);
	Vector2 operator-(const Vector2& other) const;
	Vector2& operator-=(const Vector2& other);
	Vector2 operator-() const;
	Vector2 operator/(float f) const;
	Vector2 operator*(float f) const;
	Vector2 norm() const;
	Vector2 perpen() const;
	float operator*(const Vector2& other) const;
	float operator^(const Vector2& other) const;
	float len() const;
	float squareLen() const;
	Vector2& rotate(const float degree);
	Vector2 getRotated(const float degree) const;
};

ostream& operator<< (ostream &out, const Vector2& vector);
istream& operator>> (istream &inp, Vector2& vector);
Vector2 operator*(float f, Vector2 vector);
