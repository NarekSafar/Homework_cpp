#include <iostream>

template<typename T>
class CircularDeque {
	T* _data{};
	int _size = 0;
	int _capacity = 0;
	int head = 0;
	int rear = 0;
public:
	explicit CircularDeque(int n = 5) : _capacity(n) {
		_data = static_cast<T *>(::operator new(n * sizeof(T)));
	}

	bool isEmpty() const {
		return _size == 0;
	}

	int getSize() const {
		return _size;
	}

	void push_back(const T &var) {
		if (_size + 1 > _capacity) {
			CircularDeque temp(2 * _size);
			for (int i = 0; i < _size; ++i) {
				temp.push_back(_data[i]);
			}
			std::swap(*this, temp);
		}

		new(_data + rear) T(var);
		_size++;
		rear++;
		rear = rear % _capacity;
	}

	void pop_back() {
		rear--;
		rear = (rear + _capacity) % _capacity;
		_data[rear].~T();
		_size--;
	}

	void push_front(const T &var) {
		if (_size + 1 > _capacity) {
			CircularDeque temp(2 * _size);
			for (int i = 0; i < _size; ++i) {
				temp.push_back(_data[i]);
			}
			std::swap(*this, temp);
		}

		head--;
		head = (head + _capacity) % _capacity;
		new(_data + head) T(var);
		_size++;
	}

	void pop_front() {
		_data[head].~T();
		head++;
		head = head % _capacity;
		_size--;
	}

	T front() const {
		return _data[head % _capacity];
	}

	T back() const {
		return _data[(head + _size - 1) % _capacity];
	}

	T &operator[](int i) {
		return _data[(head + i) % _capacity];
	}

	const T &operator[](int i) const {
		return _data[(head + i) % _capacity];
	}

	~CircularDeque() {
		for (int i = 0; i < _size; ++i) {
			_data[(head + i) % _capacity].~T();
		}
		::operator delete(_data);
	}

};

int main() {
	CircularDeque<int> dq;
	dq.push_back(1);
	dq.push_back(2);
	dq.push_front(0);

	std::cout << "Size: " << dq.getSize() << '\n';
	std::cout << "Front: " << dq.front() << '\n';
	std::cout << "Back: " << dq.back() << '\n';
	dq.pop_front();
	std::cout << "Size: " << dq.getSize() << '\n';
	return 0;
}
