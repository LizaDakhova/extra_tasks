#include <cmath>


//template <typename T>
class Vector {
private:
	size_t _capacity;
	size_t _size;
	int* buffer;
public:
	typedef int* Iterator;

	Vector();
	Vector(size_t size);
	Vector(size_t size, const int &initial);
	Vector(const Vector &v);
	~Vector();

	size_t capacity() const;
	size_t size() const;
	bool empty() const;
	Iterator begin() const;
	Iterator end() const;
	int& front() const;
	int& back() const;
	void push_back(const int& value);
	void pop_back();

	void reserve(size_t capacity);
	void resize(size_t size);

	int & operator[](unsigned int index) const;
	Vector & operator = (const Vector &);
	void clear();
}; 