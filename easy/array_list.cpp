#include <iostream>
#include <ostream>
#include <stdexcept>

template<typename E>
class MyVector {
public:
    explicit MyVector(int initCapacity)
        : data_(new E[initCapacity]),
        cap_(initCapacity) {}

    MyVector() : MyVector(INIT_CAP_) {}

    ~MyVector() { delete[] data_;}

    MyVector(const MyVector&) = delete;
    MyVector& operator=(const MyVector&) = delete;
    MyVector(MyVector&&) noexcept;
    MyVector& operator=(MyVector&&) noexcept;

    void add_last(E e) {
        if (size_ == cap_) {
            resize(2 * cap_);
        }

        data_[size_] = e;
        size_++;
    }

    void add(int index, E e) {
        check_pos(index);

        if (size_ == cap_) {
            resize(2 * cap_);
        }

        for(int i = size_ - 1; i >= index; i--) {
            data_[i + 1] = data_[i];
        }

        data_[index] = e;
        size_++;
    }

    void add_first(E e) {
        add(0, e);
    }

    E remove_last() {
        if (size_ == 0) {
            throw std::out_of_range("no such element exception");
        }

        if (size_ == cap_ / 4) {
            resize(cap_ / 2);
        }

        E del_val = data_[size_ - 1];
        data_[size_ - 1] = E();
        size_--;

        return del_val;
    }

    E remove(int index) {
        check_index(index);

        if(size_ == cap_ / 4) {
            resize(cap_ / 2);
        }

        E del_val = data_[index];

        for (int i = index + 1; i < size_; i++) {
            data_[i - 1] = data_[i];
        }

        data_[size_ - 1] = E();
        size_--;

        return del_val;
    }

    E remove_first() {
        return remove(0);
    }

    E get(int index) {
        check_index(index);
        return data_[index];
    }

    E set(int index, E element) {
        check_index(index);
        E old = data_[index];
        data_[index] = element;
        return old;
    }

    int size() {
        return size_;
    }

    bool is_empty() {
        return size_ == 0;
    }

    void resize(int newCap) {
        if (newCap == cap_) { return; }

        E* tmp = new E[newCap];
        for (int i = 0; i < size_; i++) {
            tmp[i] = data_[i];
        }

        delete[] data_;

        data_ = tmp;
        cap_ = newCap;
    }

    bool is_valid_index(int index) {
        return index >= 0 && index < size_;
    }

    bool is_valid_pos(int index) {
        return index >= 0 && index <= size_;
    }

    void check_index(int index) {
        if(!is_valid_index(index)) {
            throw std::out_of_range("index out of bounds");
        }
    }

    void check_pos(int index) {
        if(!is_valid_pos(index)) {
            throw std::out_of_range("index out of bounds");
        }
    }

    void display() {
        std::cout << "size = " << size_ << ", cap = " << cap_ << std::endl;
    }

private:
    static constexpr int INIT_CAP_{1};
    
    E* data_;
    int size_{0};
    int cap_{0};

};

int main() {
    MyVector<int> arr(3);

    for (int i = 1; i <= 5; i++) {
        arr.add_last(i);
    }

    arr.remove(3);
    arr.add(1, 9);
    arr.add_first(100);
    arr.remove_last();

    // 100 1 9 2 3
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr.get(i) << std::endl;
    }

    return 0;
}
