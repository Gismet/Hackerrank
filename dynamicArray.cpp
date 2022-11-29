#include <iostream>
#include <vector>

// Hing: just follow up the problem specifications

// 1. Declare a 2-dimensional array, arr , of n empty arrays
// 2. Declare an integer lastAnswer, and initialize it to 0

std::vector<int> dynamicArray(int n, std::vector<std::vector<int>> queries)
{
    // step 1. Declare a 2-dimensinal array and resize it to be of size n
    std::vector<std::vector<int>> arr;
    arr.resize(n);
    // step2
    int lastAnswer = 0;
    // answers array
    std::vector<int> ans;

    // arr[0] is either 1 or 2
    // arr[1] is x
    // arr[2] is y
    for (int i = 0; i < queries.size(); i++)
    {
        if (queries[i][0] == 1)
        {
            int idx = ((queries[i][1] ^ lastAnswer) % n);
            arr[idx].push_back(queries[i][2]);
        }
        else
        {
            int idx = ((queries[i][1] ^ lastAnswer) % n);
            lastAnswer = arr[idx][queries[i][2] % arr[idx].size()];
            ans.push_back(lastAnswer);
        }
    }
    return ans;
}

int main()
{

    // Query 1 x y
    //   let idx = ((x xor lastAnswer) % n)
    //  append y to arr[idx]

    // Query 2 x y
    //  let idx = ((x xor lastAnswer) % n)
    //  Assign the value arr[idx][y % size(arr[idx])] to lastAnswer
    //  Store lastAnswer to an answers array

    std::vector<std::vector<int>> queris = {
        {1, 0, 5},
        {1, 1, 7},
        {1, 0, 3},
        {2, 1, 0},
        {2, 1, 1}};

    int n = 2;
    int q = 5;

    std::vector<int> arr = dynamicArray(n, queris);

    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << std::endl;
    // 7
    // 3

    return 0;
}