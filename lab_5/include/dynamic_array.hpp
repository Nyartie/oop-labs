#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

#include <algorithm>
#include "allocator.hpp"

template <typename T, size_t N>
class DynamicArray {
public:
    using value_type = T;
    using allocator_type = Allocator<T, N>;
    using size_type = size_t;
    using iterator = T*;
    using const_iterator = const T*;

    DynamicArray() : data_{nullptr}, size_{0}, capacity_{N}, allocator_{} {
        data_ = allocator_.allocate(capacity_);
    }

    ~DynamicArray() {
        allocator_.deallocate(data_, capacity_);
    }

    void push_back(const value_type& value) {
        if (size_ >= capacity_) {
            reallocate();
        }
        data_[size_++] = value;
    }

    size_type size() const {
        return size_;
    }

    iterator begin() {
        return data_;
    }

    iterator end() {
        return data_ + size_;
    }

    const_iterator begin() const {
        return data_;
    }

    const_iterator end() const {
        return data_ + size_;
    }

private:
    void reallocate() {
        size_type new_capacity = capacity_ * 2;
        pointer new_data = allocator_.allocate(new_capacity);
        std::copy(data_, data_ + size_, new_data);
        allocator_.deallocate(data_, capacity_);
        data_ = new_data;
        capacity_ = new_capacity;
    }

    using pointer = typename allocator_type::pointer;

    pointer data_;
    size_type size_;
    size_type capacity_;
    allocator_type allocator_;
};

#endif // DYNAMIC_ARRAY_HPP
