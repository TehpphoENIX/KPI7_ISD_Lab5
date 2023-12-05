#include <cassert>

#include "../headers/buffer.h"

int main()
{
    const int n = 3;
    Buffer<int,n> buffer;
    for (unsigned int i = 0; i < n; i++)
    {
        buffer.add(i);
    }

    buffer.Clean();
    
    std::array<int,n> evaluation;
    for (unsigned int i = 0; i < n; i++)
    {
        evaluation[i] = 0;
    }
    assert(buffer.Output() == evaluation);
}