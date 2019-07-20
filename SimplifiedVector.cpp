#include <iostream>
#include <exception>

template <typename T>
class SimpleVector {
public:
    SimpleVector(size_t size) {
        data = new T[size];
        _end = data + size;
        this->size = size;
    }
    T& operator[] (size_t index) {
        if (index >= size) {
            throw std::out_of_range ("Index out of range");
        }
        return data[index];
    }
    T* begin() {
        return data;
    }
    T* end() {
        return _end;
    }
    const T* begin() const {
        return data;
    }
    const T* end() const {
        return _end;
    }
    ~SimpleVector() {
        delete[] data;
    }
private:
    T* data;
    T* _end;
    int size;
};

template <typename T>
void PrintVector(const SimpleVector<T>& v) {
    for (T i : v) {
        std::cout << i << " ";
    }
}

int main() {
    SimpleVector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2]= 234;
    PrintVector(v);
    v[11] = 12;
}
