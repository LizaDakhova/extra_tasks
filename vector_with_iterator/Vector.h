#include <cmath>


template <typename T>
class Vector {
private:
	size_t _capacity;
	size_t _size;
	T* buffer;
public:
	typedef T* Iterator;

	Vector();
	Vector(size_t size);
	Vector(size_t size, const T &initial);
	Vector(const Vector &v);
	~Vector();

	size_t capacity() const;
	size_t size() const;
	bool empty() const;
	Iterator begin() const;
	Iterator end() const;
	T& front() const;
	T& back() const;
	void push_back(const T& value);
	void pop_back();

	void reserve(size_t capacity);
	void resize(size_t size);

	int & operator[](unsigned int index) const;
	Vector<T> & operator = (const Vector<T> &);
	void clear();
}; 

template <typename T>
Vector<T>::Vector() :
	_size(0),
	_capacity(0),
	buffer(0) {}

template <typename T>
Vector<T>::Vector(size_t size) :
	_size(size),
	_capacity(size),
	buffer(new int[_capacity]) {}

template <typename T>
Vector<T>::Vector(size_t size, const T &initial) :
	_size(size),
	_capacity(size),
	buffer(new T[_capacity]) {
	for (int i = 0; i < size; ++i)
		buffer[i] = initial;
}

template <typename T>
Vector<T>::Vector(const Vector<T> &that) :
	_size(that._size),
	_capacity(that._capacity),
	buffer(new T[this->_capacity]) {
	for (int i = 0; i < this->_size; ++i)
		this->buffer[i] = that.buffer[i];
}

template <typename T>
Vector<T>::~Vector() {
	delete[] buffer;
}

template <typename T>
size_t Vector<T>::capacity() const {
	return _capacity;
}

template <typename T>
size_t Vector<T>::size() const {
	return _size;
}

template <typename T>
bool Vector<T>::empty() const {
	return bool(_size);
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::begin() const {
	return buffer;
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::end() const {
	return buffer + _size;
}

template <typename T>
int & Vector<T>::operator[](unsigned int index) const {
	return buffer[index];
}

template <typename T>
T& Vector<T>::front() const {
	return buffer[0];
}

template <typename T>
T& Vector<T>::back() const {
	return buffer[_size - 1];
}

template <typename T>
void Vector<T>::reserve(size_t capacity) {
	int *new_buffer = new T[capacity];
	for (int i = 0; i < this->_capacity; ++i)
		new_buffer[i] = this->buffer[i];
	delete[] this->buffer;
	this->buffer = new_buffer;
	this->_capacity = capacity;
}

template <typename T>
void Vector<T>::resize(size_t size) {
	if (_capacity < size)
		reserve(size + 10);
	_size = size;
}

template <typename T>
void Vector<T>::push_back(const T& value) {
	resize(_size + 1);
	buffer[_size - 1] = value;
}

template <typename T>
void Vector<T>::pop_back() {
	--_size;
}

template <typename T>
Vector<T> & Vector<T>::operator = (const Vector<T> &that) {
	if (this->_capacity > that._capacity)
		delete[] this->buffer;
	this->_size = that._size;
	this->_capacity = that._capacity;
	for (int i = 0; i < this->_size; ++i)
		this->buffer[i] = that.buffer[i];
	return *this;
}

template <typename T>
void Vector<T>::clear() {
	delete[] buffer;
}




