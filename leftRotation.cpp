#include <iostream>
#include <vector>

std::vector<int> rotateLeft(int d, std::vector<int> arr)
{

    int n = arr.size();

    // a new array to store rotated elements
    std::vector<int> ans;
    ans.resize(n);

    for (int i = 0; i < n; i++)
    {
        // when index gets lower than 0 add the size to rotate it to correct position
        // for example in an array of size 5 , when the element at index 0 is rotated by 2
        // it ends up being at the index 0 - 2 + 5 = 3.
        if (i - d < 0)
        {
            ans[i - d + n] = arr[i];
        }
        else
        {
            ans[i - d] = arr[i];
        }
    }
    return ans;
}

int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 5};
    int d = 2;

    arr = rotateLeft(d, arr);

    for (int i : arr)
        std::cout << i << " ";

    return 0;
}