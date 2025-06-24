
#include "MyString.h"

#include <cassert>

void MyString::free() {
	delete[] data;
}

void MyString::copy_from(const MyString& other) {
	size_t other_data_length = strlen(other.data);
	data = new char[other_data_length + 1];
	strcpy_s(data, other_data_length + 1, other.data);
}

MyString::MyString() {
	data = new char[1];
	data[0] = '\0';
}

MyString::MyString(const char* MyString_data) {
	if (MyString_data == nullptr) {
		data = new char[1];
		data[0] = '\0';
	}
	else {
		size_t other_data_length = strlen(MyString_data);
		data = new char[other_data_length + 1];
		strcpy_s(data, other_data_length + 1, MyString_data);
	}
}

MyString::MyString(const MyString& other) {
	copy_from(other);
}

MyString& MyString::operator=(const MyString& other) {
	if (this != &other) {
		free();
		copy_from(other);
	}

	return *this;
}

MyString::~MyString() {
	free();
}

int MyString::toNumber() const {

	size_t size = get_length();

	if (size == 0)
	{
		return -1;
	}

	size_t result = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (data[i] < '0' || data[i] > '9')
			return -1;

		result = result * 10 + (this->data[i] - '0');
	}
}

MyString MyString::toMyString(size_t num)
{
	if (num == 0)
	{
		return MyString("0");
	}

	MyString result;
	while (num)
	{
		result.push((char) (num % 10 + '0'));
		num /= 10;
	}

	result.reverse();
	return result;
}

MyString MyString::toMyString(double num)
{
	if (num == 0.0)
	{
		return MyString("0.00");
	}

	MyString result;
	if (num < 0)
	{
		result.push('-');
		num = -num;
	}

	size_t integerPart = (size_t)num;
	double fractionalPart = num - (double)integerPart;

	result += MyString::toMyString(integerPart);
	result.push('.');

	fractionalPart *= 100;
	size_t fractionAsInt = (size_t)(fractionalPart + 0.5);

	if (fractionAsInt < 10)
		result.push('0');
	result += MyString::toMyString(fractionAsInt);

	return result;
}

MyString& MyString::reverse()
{
	for (size_t i = 0; i < this->get_length() / 2; i++)
	{
		char temp = this->data[i];
		this->data[i] = this->data[this->get_length() - i - 1];
		this->data[this->get_length() - i - 1] = temp;
	}
	return *this;
}

const char* MyString::c_str() const {
	return data;
}

size_t MyString::get_length() const {
	return strlen(data);
}

char& MyString::operator[](size_t index) {
	// index > size of MyString
	assert(index < get_length());	// -> if false: stop program

	return data[index];
}

char MyString::operator[](size_t index) const {
	assert(index < get_length());

	return data[index];
}

MyString& MyString::operator+=(const MyString& other) {
	// "Hello" += "Zero"
	// "HelloZero"
	
	size_t new_length = get_length() + other.get_length() + 1;

	char* new_data = new char[new_length];

	new_data[0] = '\0';

	strcat_s(new_data, new_length, data);
	strcat_s(new_data, new_length, other.data);

	free();
	data = new_data;

	return *this;
}

istream& operator>>(istream& in, MyString& str) {
	char buffer[1024];
	in.getline(buffer, 1024);

	size_t buffer_length = strlen(buffer);

	delete[] str.data;

	str.data = new char[buffer_length + 1];

	strcpy_s(str.data, buffer_length + 1, buffer);

	return in;
}

MyString operator+(const MyString& lhs, const MyString& rhs) {
	MyString result(lhs);

	result += rhs;
	
	return result;
}

ostream& operator<<(ostream& out, const MyString& str) {
	return out << str.c_str();
}

bool operator<(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}
bool operator>=(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}
bool operator>(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}
bool operator==(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}
bool operator!=(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}

void MyString::clear()
{
	data[0] = '\0';
}

void MyString::push(const char character) {

	char buffer[2] = { character, '\0' };

	operator+=(buffer);
}

void MyString::push(const MyString& word) {

	operator+=(word);
}

void MyString::push(const size_t& number) {

	MyString result = toMyString(number);

	operator+=(result);
}
void MyString::push(const double& number) {

	MyString result = toMyString(number);

	operator+=(result);
}

std::istream& getline(std::istream& is, MyString& line, char delimiter)
{
	line.clear();

	char ch;
	while (is.get(ch))
	{
		if (ch == delimiter)
			break;

		line.push(ch);
	}

	return is;
}

std::istream& getline(std::istream& is, MyString& line)
{
	return getline(is, line, '\n');
}