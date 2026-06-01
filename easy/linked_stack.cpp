#include <list>
#include <iostream>

template<typename E>
class LinkedStack {
public:
    void push(const E &e) {
        list.push_back(e);
    }

    E pop() {
        E value = list.back();
        list.pop_back();
        return value;
    }

    E peek() const {
        return list.back();
    }

    int size() const {
        return list.size();
    }

private:
    std::list<E> list;
};

template<typename E>
class LinkedQueue {
public:
    void push(const E &e) {
        list.push_back(e);
    }

    E pop() {
        E front = list.front();
        list.pop_front();
        return front;
    }

    E peek() {
        return list.front();
    }

    int size() {
        return list.size();
    }

private:
    std::list<E> list;
};

int main() {
    LinkedStack<int> stack;
    for(int i = 0; i < 3; i++) {
        stack.push(i);
    }
    while (stack.size() > 0) {
        std::cout << stack.pop() << " ";
    }
    std::cout << std::endl;

    LinkedQueue<int> queue;
    for(int i = 0; i < 3; i++) {
        queue.push(i);
    }
    while (queue.size() > 0) {
        std::cout << queue.pop() << " ";
    }
    std::cout << std::endl;

    return 0;
}