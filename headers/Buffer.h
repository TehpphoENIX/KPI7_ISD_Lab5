#pragma once
#include <array>

/**
 * @brief allows to store data with ability to retrieve last N stored items.
 * 
 * @tparam T -- type of items that are stored in buffer.
 * @tparam N -- size of a buffer.
 */
template<typename T, int N>
class Buffer
{
    std::array<T,N> array;
    unsigned long next;

public:
    Buffer();
    /**
     * @brief add item to the buffer.
     * 
     * @param value -- item to be added.
     */
    void add(T value);
    /**
     * @brief show contents of the buffer In order they were added (last - first).
     * 
     * @return std::array<T,N> -- resulting array.
     */
    std::array<T,N> output();
    /**
     * @brief empty the buffer.
     * 
     */
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
