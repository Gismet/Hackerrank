#include <iostream>
#include <string>

std::string superReducedString(std::string s)
{
    std::string result = "";
    result.push_back(s[0]);

    int i = 1;
    while (i < s.length())
    {
        if (result.back() == s[i])
        {
            result.pop_back();
        }
        else
        {
            result.push_back(s[i]);
        }
        i++;
    }
    std::string emptyString = "Empty String";
    return result.length() == 0 ? emptyString : result;
}

int main()
{
    std::string s = "abba";

    std::cout << superReducedString(s);

    return 0;
}