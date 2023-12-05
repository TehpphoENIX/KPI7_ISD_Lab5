#include <assert.h>
#include "../headers/buffer.h"

int main()
{
    const int n = 3;
    std::array<int, 8> array = {1,3,4,5,6,7,8};
    Buffer<int, n> buffer;

    for(int el : array)
    {
        buffer.add(el);
    }

    std::array<int, n> evaluation;
    for(int i = 0; i < n; i++)
    {
        evaluation[i] = array[array.size() - n + i];
    }

    assert((std::array<int,n>(buffer.Output()) == evaluation));
}