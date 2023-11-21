#pragma once
#include <array>

template<typename T, int N>
class Buffer
{
    std::array<T,N> array;
    unsigned long next;

public:
    Buffer();
    void add(T value);
    std::array<T,N> output();
    void clean();
};

template <typename T, int N>
inline Buffer<T, N>::Buffer()
{
    clean();
}

template <typename T, int N>
inline void Buffer<T, N>::add(T value)
{
    array[next] = value;
    next++;
    if (next >= array.size()) next = 0;
}

template <typename T, int N>
inline std::array<T, N> Buffer<T, N>::output()
{
    std::array<T, N> output;

    for(unsigned int i = 0, j = next; i < N; i++)
    {
        output[i] = array[j];
        j++;
        if(j >= array.size()) j = 0;
    }
    
    return output;
}

template <typename T, int N>
inline void Buffer<T, N>::clean()
{
    for(unsigned int i = 0; i < N; i++)
    {
        array[i] = T();
    }
    next = 0;
}
