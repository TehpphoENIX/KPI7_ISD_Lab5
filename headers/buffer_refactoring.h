#pragma once
#include <array>

template<int N>
class Buffer_bad
{
public:
    int array[N];
    unsigned long next;
    Buffer_bad();
    void add(int value);
    int* output();
    void clean();
};

template <int N>
inline Buffer_bad<N>::Buffer_bad()
{
    for(unsigned int i = 0; i < N; i++)
    {
        array[i] = T();
    }
    next = 0;
}

template <int N>
inline void Buffer_bad<N>::add(int value)
{
    array[next] = value;
    next++;
    if (next >= array.size()) next = 0;
}

template <int N>
inline int* Buffer_bad<N>::output(){
    T output[N];

    for(unsigned int i = 0, j = next; i < N; i++)
    {
        output[i] = array[j];
        j++;
        if(j >= array.size()) j = 0;
    }
    
    return &output[0];
}

template <int N>
inline void Buffer_bad<N>::clean()
{
    for(unsigned int i = 0; i < N; i++)
    {
        array[i] = T();
    }
    next = 0;
}


//The code above has multiple problems:
//- Primitive Obsession (usage of c style arrays)
//- Indecent Exposure (there is no need to access array and next from outside)
//- Dublicated Code (in constructor and clean for example)
//- Alternative Classes (potentially, if we want to store other types inside of container)

//Refactored class will look like this

#pragma once
#include <array>

template<typename T, int N>
class Buffer
{
private:
    std::array<T,N> array;
    unsigned long next;

public:
    Buffer();
    void add(T value);
    std::array<T,N> output();
    void clean();

private:
    unsigned long _add_n_fold(unsigned long x);
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
    _add_n_fold(next);
}

template <typename T, int N>
inline std::array<T, N> Buffer<T, N>::output()
{
    std::array<T, N> output;

    for(unsigned int i = 0, j = next; i < N; i++)
    {
        output[i] = array[j];
        _add_n_fold(j);
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

template <typename T, int N>
inline unsigned long Buffer<T, N>::_add_n_fold(unsigned long x)
{
    auto out = x++;
    if(x >= array.size()) x = 0;
    return x;
}
