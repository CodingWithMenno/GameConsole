#pragma once

template <class T, unsigned int N>
struct Array 
{
    // Storage
    T data[N];

    static unsigned int length() { return N; }
    using type = T;

    // Item access
    T &operator[](unsigned int index) { return data[index]; }
    const T &operator[](unsigned int index) const { return data[index]; }

    // Iterators
    T *begin() { return &data[0]; }
    const T *begin() const { return &data[0]; }
    T *end() { return &data[N]; }
    const T *end() const { return &data[N]; }

    // Comparisons
    bool operator==(const Array<T, N> &rhs) const {
        if (this == &rhs)
            return true;
        for (size_t i = 0; i < N; i++)
            if ((*this)[i] != rhs[i])
                return false;
        return true;
    }
    bool operator!=(const Array<T, N> &rhs) const {
        return !(*this == rhs);
    }
};