#pragma once

struct DLinkedNode {
    int key_{0};
    int value_{0};
    DLinkedNode* prev_{nullptr};
    DLinkedNode* next_{nullptr};

    DLinkedNode() {}
    DLinkedNode(int key, int value): key_(key), value_(value) {}
};

// use dummy head and tail to reduce complexity of moving
class LRUCache {
public:
    LRUCache(int capacity): capacity_(capacity) {
        head_ = new DLinkedNode();
        tail_ = new DLinkedNode();
        head_->next_ = tail_;
        tail_->prev_ = head_;
    }

    // return -1 if not exists
    int get(int key) {
        if (!cache_.count(key)) {
            return -1;
        }
        DLinkedNode* node = cache_[key];
        removeNode(node);
        addToHead(node);
        return node->value_;
    }

    void put(int key, int value) {
        if (!cache_.count(key)) {
            DLinkedNode* node = new DLinkedNode(key, value);
            cache_[key] = node;
            addToHead(node);
            ++size_;

            if (size_ > capacity_) {
                DLinkedNode* removed = removeTail();
                cache_.erase(removed->key_);
                delete removed;
                --size_;
            }
        } else {
            DLinkedNode* node = cache_[key];
            node->value_ = value;
            removeNode(node);
            addToHead(node);
        }
    }

private:
    void removeNode(DLinkedNode* node) {
        node->next_->prev_ = node->prev_;
        node->prev_->next_ = node->next_;
    }

    void addToHead(DLinkedNode* node) {
        node->next_ = head_->next_;
        node->prev_ = head_;
        head_->next_->prev_ = node;
        head_->next_ = node;
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = tail_->prev_;
        removeNode(node);
        return node;
    }

    unordered_map<int, DLinkedNode*> cache_;
    DLinkedNode* head_{nullptr};
    DLinkedNode* tail_{nullptr};
    int capacity_{0};
    int size_{0};
};
