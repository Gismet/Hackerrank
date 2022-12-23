#include <iostream>

int main()
{
    int h[] = {3, 2, 3};
    int left = 0;
    int right = 2;

    int maxArea = -1;
    while (left <= right)
    {
        if (h[left] < h[right])
        {
            int currentArea = (right - left + 1) * h[left];
            left++;
            if (maxArea < currentArea)
            {
                maxArea = currentArea;
            }
        }
        else
        {
            int currentArea = (right - left + 1) * h[right];
            right--;
            if (maxArea < currentArea)
            {
                maxArea = currentArea;
            }
        }
    }
    std::cout << maxArea;

    return 0;
}