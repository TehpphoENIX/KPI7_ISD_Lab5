#include <cassert>

#include "../headers/buffer.h"

int main()
{
    const int n = 3;
    const int m = 3;
    Buffer<int,n> buffer;

    for (unsigned int i = 0; i < n*m; i++)
    {
        buffer.add(i);
    }
    
}