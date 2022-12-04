#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

int main()
{
    std::unordered_map<std::string, int> occurrencesCount;
    std::vector<std::string> stringList = {"ab", "ab", "abc"};
    std::vector<std::string> queries = {"ab", "abc", "bc"};
    std::vector<int> result;

    for (std::string str : stringList)
    {
        occurrencesCount[str]++;
    }

    for (std::string q : queries)
    {
        result.push_back(occurrencesCount[q]);
    }

    for (int i : result)
    {
        std::cout << i << " ";
    }

    return 0;
}