#include "Vector.h"

//template <typename T>
Vector::Vector():
	_size(0),
	_capacity(0),
	buffer(0) {}

Vector::Vector(size_t size):
	_size(size),
	_capacity(size),
	buffer(new int[_capacity]) {}

Vector::Vector(size_t size, const int &initial):
	_size(size),
	_capacity(size),
	buffer(new int[_capacity]) {
	for (int i = 0; i < size; ++i)
		buffer[i] = initial;
}

Vector::Vector(const Vector &that):
	_size(that._size),
	_capacity(that._capacity),
	buffer(new int[this->_capacity]) {
	for (int i = 0; i < this->_size; ++i) 
		this->buffer[i] = that.buffer[i];
}

Vector::~Vector() {
	delete[] buffer;
}

size_t Vector::capacity() const {
	return _capacity;
}

size_t Vector::size() const {
	return _size;
}

bool Vector::empty() const {
	return bool(_size);
}

Vector::Iterator Vector::begin() const{
	return buffer;
}

Vector::Iterator Vector::end() const{
	return buffer + _size;
}

int & Vector::operator[](unsigned int index) const {
	return buffer[index];
}

int& Vector::front() const{
	return buffer[0];
}

int& Vector::back() const{
	return buffer[_size - 1];
}

void Vector::reserve(size_t capacity) {
	int *new_buffer = new int[capacity];
	for (int i = 0; i < this->_capacity; ++i)
		new_buffer[i] = this->buffer[i];
	delete[] this->buffer;
	this->buffer = new_buffer;
	this->_capacity = capacity;
}

void Vector::resize(size_t size) {
	if (_capacity < size)
		reserve(size + 10);
	_size = size;
}

void Vector::push_back(const int& value) {
	resize(_size + 1); 
	buffer[_size - 1] = value;
} 

void Vector::pop_back() {
	--_size;
}

Vector & Vector::operator = (const Vector &that) {
	if (this->_capacity > that._capacity)
		delete[] this->buffer;
	this->_size = that._size;
	this->_capacity = that._capacity;
	for (int i = 0; i < this->_size; ++i)
		this->buffer[i] = that.buffer[i];
	return *this;
}

void Vector::clear() {
	delete[] buffer;
}




