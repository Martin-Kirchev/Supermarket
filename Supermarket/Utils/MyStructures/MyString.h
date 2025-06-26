
#pragma once

#include <iostream>

#include "IntegerFunction.hpp"
#include "Vector.hpp"

using namespace std;


class MyString {

	char* data = nullptr;

	void free();
	void copy_from(const MyString& other);

public:

	static const size_t npos = -1;

	MyString();
	MyString(const char* MyString_data);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();

	bool isEmpty() const;

	size_t toInteger() const;
	double toDouble() const;
	MyString toMyString(size_t num);
	MyString toMyString(double num);

	MyString& reverse();

	const char* c_str() const;
	size_t get_length() const;

	// operator[] -> index

	char& operator[](size_t index);
	char operator[](size_t index) const;

	// operator+= -> concat

	MyString& operator+=(const MyString& other);

	// operator>> -> read from stream

	friend istream& operator>>(istream& in, MyString& str);

	MyString substring(size_t pos, size_t len = MyString::npos) const;
	Vector<MyString> split(char delimeter = ' ') const;

	void clear();

	void push(const char character);
	void push(const MyString& word);
	void push(const size_t& word);
	void push(const double& word);
};

MyString operator+(const MyString& lhs, const MyString& rhs);

ostream& operator<<(ostream& out, const MyString& str);

bool operator<(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);

std::istream& getline(std::istream& is, MyString& str, char delim);
std::istream& getline(std::istream& is, MyString& str);
std::istream& getline(std::istream& is,const size_t& str);
std::istream& getline(std::istream& is,const double& str);