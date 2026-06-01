#include<iostream>

template<typename E>
class LinkedList {
public:
    LinkedList() {
        head_ = new Node(E());
        tail_ = head_;
        size_ = 0;
    }

    ~LinkedList() {
        Node* cur = head_;
        while(cur != nullptr) {
            Node* next = cur->next;
            delete cur;
            cur = next;
        }
    }

    E get(int index) {
        Node* cur = head_;
        int cur_idx = 0;
        while(cur->next != nullptr) {
            if (cur_idx == index) {
                return cur->next->val;
            }
            cur = cur->next;
            cur_idx++;
        }
        return -1;
    }

    void addAtHead(E val) {
        Node* newNode = new Node(val);
        newNode->next = head_->next;
        head_->next = newNode;
        if (size_ == 0) {
            tail_ = newNode;
        }
        size_++;
    }

    void addAtTail(E val) {
        Node* newNode = new Node(val);
        tail_->next = newNode;
        tail_ = newNode;
        size_++;
    }

    void addAtIndex(int index, E val) {
        if (index > size_) {
            return;
        }
        if (index == size_) {
            return addAtTail(val);
        }
        Node* prev = head_;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }
        Node* newNode = new Node(val);
        newNode->next = prev->next;
        prev->next = newNode;
        size_++;
    }

    void deleteAtIndex(int index) {
        if (index >= size_) {
            return;
        }

        Node* prev = head_;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }
        Node* delNode = prev->next;
        prev->next = delNode->next;
        delete delNode;
        if (index == size_ - 1) {
            tail_ = prev;
        }
        size_--;
    }

    void print() {
        Node* cur = head_->next;
        for(int i = 0; i < size_; i++) {
            std::cout << cur->val << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }

private:
    struct Node {
        E val;
        Node* next;
        
        Node(E val) : val(val), next(nullptr) {}
    };

    // dummy head
    Node* head_{nullptr};
    Node* tail_{nullptr};
    int size_{0};
};

template<typename E>
class DoublyLinkedList {
public:
    DoublyLinkedList() {
        head_ = new Node(E());
        tail_ = new Node(E());
        head_->next = tail_;
        tail_->prev = head_;
        size_ = 0;
    }

    ~DoublyLinkedList() {
        Node* cur = head_;
        while (size_ > 0) {
            Node* delNode = cur->next;
            cur->next = delNode->next;
            cur->next->prev = cur;
            delete delNode;
            size_--;
        }
        delete head_;
        delete tail_;
    }

    E get(int index) {
        if (index >= size_) {
            return -1;
        }
        Node* prev = head_;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }
        return prev->next->val;
    }

    void addAtHead(E val) {
        Node* newNode = new Node(val);
        newNode->next = head_->next;
        newNode->prev = head_;
        head_->next->prev = newNode;
        head_->next = newNode;
        size_++;
    }

    void addAtTail(E val) {
        Node* newNode = new Node(val);
        newNode->prev = tail_->prev;
        newNode->prev->next = newNode;
        newNode->next = tail_;
        tail_->prev = newNode;
        size_++;
    }

    void addAtIndex(int index, E val) {
        if (index > size_) {
            return;
        }
        if (index == size_) {
            return addAtTail(val);
        }
        Node* prev = head_;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }
        Node* newNode = new Node(val);
        newNode->next = prev->next;
        newNode->next->prev = newNode;
        newNode->prev = prev;
        prev->next = newNode;
        size_++;
    }

    void deleteAtIndex(int index) {
        if (index >= size_) {
            return;
        }
        Node* cur = head_->next;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        delete cur;
        size_--;
    }

    void print() {
        Node* cur = head_->next;
        for(int i = 0; i < size_; i++) {
            std::cout << cur->val << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }

private:
    class Node {
    public:
        E val;
        Node* next{nullptr};
        Node* prev{nullptr};
    
        explicit Node(E element) : val(element) {}
        ~Node() {
            next = nullptr;
            prev = nullptr;
        }
    };

    // dummy head and tail
    Node* head_{nullptr};
    Node* tail_{nullptr};
    int size_{0};
};

class MyLinkedList {
public:
    MyLinkedList() {
        head_ = new Node(0);
        tail_ = new Node(0);
        head_->next = tail_;
        tail_->prev = head_;
        size_ = 0;
    }

    ~MyLinkedList() {
        while (size_ > 0) {
            Node* delNode = head_->next;
            head_->next = delNode->next;
            if (head_->next != nullptr) {
                head_->next->prev = head_;
            }
            delete delNode;
            size_--;
        }
        delete head_;
        delete tail_;
    }
    
    int get(int index) {
        if (index >= size_) {
            return -1;
        }
        Node* prev = head_;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }
        return prev->next->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head_->next;
        newNode->prev = head_;
        newNode->next->prev = newNode;
        head_->next = newNode;
        size_++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        newNode->prev = tail_->prev;
        newNode->prev->next = newNode;
        newNode->next = tail_;
        tail_->prev = newNode;
        size_++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size_) {
            return;
        }
        if (index == size_) {
            return addAtTail(val);
        }
        Node* prev = head_;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }
        Node* newNode = new Node(val);
        newNode->next = prev->next;
        newNode->next->prev = newNode;
        newNode->prev = prev;
        prev->next = newNode;
        size_++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= size_) {
            return;
        }
        Node* cur = head_->next;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        delete cur;
        size_--;
    }

    void print() {
        Node* cur = head_->next;
        for(int i = 0; i < size_; i++) {
            std::cout << cur->val << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }

private:
    class Node {
    public:
        int val{-1};
        Node* next{nullptr};
        Node* prev{nullptr};
    
        explicit Node(int element) : val(element) {}
        ~Node() {
            next = nullptr;
            prev = nullptr;
        }
    };

    // dummy head and tail
    Node* head_{nullptr};
    Node* tail_{nullptr};
    int size_{0};
};

int main() {
    // auto list = new MyLinkedList();
    // auto list = new DoublyLinkedList<int>();
    auto list = new LinkedList<int>();
    list->print();
    list->addAtHead(1);
    list->print();
    list->addAtTail(3);
    list->print();
    list->addAtIndex(1, 2);
    list->print();
    std::cout << list->get(1) << std::endl;
    list->deleteAtIndex(1);
    list->print();
    std::cout << list->get(1) << std::endl;
    delete list;
}