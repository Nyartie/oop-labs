#include <cstddef>
#include <limits>
#include <array>

template <class T, std::size_t N>
class Allocator {
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;

    template <class U>
    struct rebind {
        using other = Allocator<U, N>;
    };

    Allocator() noexcept = default;

    template <class U>
    Allocator(const Allocator<U, N>&) noexcept {}

    pointer allocate(size_type n) {
        if (n > max_size()) throw std::bad_alloc();
        return reinterpret_cast<pointer>(std::allocator<T>{}.allocate(n));
    }

    void deallocate(pointer p, size_type n) noexcept {
        std::allocator<T>{}.deallocate(reinterpret_cast<T*>(p), n);
    }

    size_type max_size() const noexcept {
        return std::numeric_limits<size_type>::max() / sizeof(T);
    }

private:
    std::array<std::byte, N * sizeof(T)> storage_;
};
