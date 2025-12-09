#include <iostream>
#include <string>

template<typename T>
void my_swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
class Vector {
    T* data = nullptr;
    int size = 0, capacity = 0;
    
public:
    Vector(std::initializer_list<T> list) : size(list.size()), capacity(list.size()) {
        if (size > 0) {
            data = new T[size];
            int i = 0;
            for (const T& item : list) {
                data[i++] = item;
            }
        }
    }
    
    ~Vector() { delete[] data; }
    
    void swap(Vector& other) {
        T* temp_data = data;
        data = other.data;
        other.data = temp_data;
        
        int temp_size = size;
        size = other.size;
        other.size = temp_size;
        
        int temp_cap = capacity;
        capacity = other.capacity;
        other.capacity = temp_cap;
    }
    
    void print() const {
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
    }
};

template<typename T>
void swap(Vector<T>& a, Vector<T>& b) {
    a.swap(b);
}

int main() {
    Vector<double> v1 = {1, 2, 3};
    Vector<double> v2 = {4, 5, 6, 7};
    
    std::cout << "До: v1 = "; v1.print();
    std::cout << " v2 = "; v2.print();
    std::cout << "\n";
    
    swap(v1, v2);
    
    std::cout << "После:  v1 = "; v1.print();
    std::cout << " v2 = "; v2.print();
    std::cout << "\n";
    
    Vector<std::string> vs1 = {"hello", "world"};
    Vector<std::string> vs2 = {"world", "hello"};
    
    std::cout << "До: vs1 = "; vs1.print();
    std::cout << " vs2 = "; vs2.print();
    std::cout << "\n";
    
    swap(vs1, vs2);
    
    std::cout << "После:  vs1 = "; vs1.print();
    std::cout << " vs2 = "; vs2.print();
    
    return 0;
}
