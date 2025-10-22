#include <iostream>
#include <vector>
#include <algorithm>

std::string frequencySort(std::string s) {
    int asciSymbols[128] {0};
    std::string res = "";
    int min = s[0];
    int max = s[0];
    for(size_t i = 0; i < s.length(); i++){
        asciSymbols[s[i]]++;
        if(min > s[i]) min = s[i]; 
        if(max < s[i]) max = s[i]; 
    }

    std::vector<std::pair<char, int>> char_cnt;
    for(size_t i = min; i <= max; i++){
        if(asciSymbols[i]){
            char_cnt.push_back({i, asciSymbols[i]});
        }
    }

    sort(char_cnt.begin(), char_cnt.end(),[](std::pair<char,int>& lhs, std::pair<char,int>& rhs){
        return lhs.second > rhs.second;
    });

    for(size_t i = 0; i < char_cnt.size(); i++){
        while(char_cnt[i].second > 0){
            char_cnt[i].second--;
            res += char_cnt[i].first;
        }
    }
    return res;
}

int main(){
    std::string s = "tree";
    std::cout<< frequencySort(s);
}
