
#pragma once

#include <iostream>
#include "IntegerFunction.hpp"

using namespace std;


class my_string {

	char* data = nullptr;

	void free();
	void copy_from(const my_string& other);

public:

	my_string();
	my_string(const char* string_data);
	my_string(const my_string& other);
	my_string& operator=(const my_string& other);
	~my_string();

	int toNumber() const;
	my_string toString(size_t num);
	my_string toString(double num);

	my_string& reverse();

	const char* c_str() const;
	size_t get_length() const;

	// operator[] -> index

	char& operator[](size_t index);
	char operator[](size_t index) const;

	// operator+= -> concat

	my_string& operator+=(const my_string& other);

	// operator>> -> read from stream

	friend istream& operator>>(istream& in, my_string& str);

	Vector<my_string> split(char delimeter = ' ') const;

	void clear();

	void push(const char character);
	void push(const my_string& word);
	void push(const size_t& word);
	void push(const double& word);
};

my_string operator+(const my_string& lhs, const my_string& rhs);

ostream& operator<<(ostream& out, const my_string& str);

bool operator<(const my_string& lhs, const my_string& rhs);
bool operator<=(const my_string& lhs, const my_string& rhs);
bool operator>=(const my_string& lhs, const my_string& rhs);
bool operator>(const my_string& lhs, const my_string& rhs);
bool operator==(const my_string& lhs, const my_string& rhs);
bool operator!=(const my_string& lhs, const my_string& rhs);

std::istream& getline(std::istream& is, my_string& str, char delim);
std::istream& getline(std::istream& is, my_string& str);