#include <iostream>
#include <vector>
#include <string>

bool validPalindrome(std::string s) {
        int left = 0, right = s.size() - 1;
        while(left < right)
        {
            if(s[left] == s[right])
            {
                left++;
                right--;
            }
            else
            {
                if(s[left + 1] != s[right] && s[left] != s[right - 1]) return false;
                else if (s[left + 1] == s[right]) left++;
                else right--;
            }
        }
        return true;
}



int main()
{
    std::string s = "abc";
    std::cout << (validPalindrome(s) ? 1 : 0) << std::endl;
    return 0;
}