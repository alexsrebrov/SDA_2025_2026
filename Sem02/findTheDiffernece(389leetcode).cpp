#include <iostream>

char findTheDifference(std::string s, std::string t) {
    int a = 0;
    for(size_t i = 0; i < s.length(); i++){
        a^=s[i];
    }
    for(size_t i = 0; i < t.length(); i++){
        a^=t[i];
    }
    return a;
}

int main(){
    std::string s = "abcd";
    std::string t = "abcde";
    std::cout<< findTheDifference(s,t);
}