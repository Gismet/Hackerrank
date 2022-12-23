#include <iostream>
#include <string>

int camelcase(std::string s)
{
    int numOfWords = 1;

    int i = 0;
    while (i < s.length())
    {
        if ((int)s[i] < 97)
        {
            numOfWords += 1;
        }
        i++;
    }
    return numOfWords;
}

int main()
{
    std::string s = "oneTwoThree";

    std::cout << camelcase(s);

    return 0;
}