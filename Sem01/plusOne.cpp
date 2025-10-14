#include <iostream>
#include <vector>


std::vector<int> plusOne(std::vector<int>& digits) {
    for (int i = digits.size() - 1; i >= 0; --i) {
        if(digits[i] < 9) {
            digits[i]++;
            return digits;
        }
        else if(digits[i] == 9) {
            digits[i] = 0;
            if(i == 0) {
                digits.insert(digits.begin(), 1);
                return digits;
            }
        }
    }
    return digits;
}

int main(){
    std::vector<int> digits = {9, 9};
    std::vector<int> result = plusOne(digits);
    for (int i : result) {
        std::cout << i << " ";
    }
    return 0;
}