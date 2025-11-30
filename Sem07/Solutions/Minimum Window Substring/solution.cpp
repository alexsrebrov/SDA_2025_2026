#include <string>
#include <unordered_map>
#include <climits>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.size() < t.size()) return "";

        // requiredFreq: колко пъти всеки символ трябва да се появи (от t)
        std::unordered_map<char, int> requiredFreq;

        // windowFreq: колко пъти символът се среща в текущия прозорец
        std::unordered_map<char, int> windowFreq;

        // Попълваме нужните честоти според t
        for (char c : t) {
            requiredFreq[c]++;
        }

        int satisfiedChars = 0;                    // колко различни символа вече са удовлетворени в прозореца
        int totalRequiredDistinct = requiredFreq.size(); // колко различни символа трябват общо

        int windowStart = 0;                      // ляв край на прозореца
        int bestWindowLen = INT_MAX;              // дължина на най-добрия (най-малък) прозорец
        int bestWindowStart = 0;                  // откъде започва най-добрият прозорец

        // Разширяваме прозореца с десния индекс windowEnd
        for (int windowEnd = 0; windowEnd < s.size(); windowEnd++) {
            char endChar = s[windowEnd];
            windowFreq[endChar]++;

            // Ако този символ е нужен и го имаме в нужната честота в прозореца → увеличаваме satisfiedChars
            if (requiredFreq.count(endChar) && 
                windowFreq[endChar] == requiredFreq[endChar]) {
                satisfiedChars++;
            }

            // Когато всички нужни символи са налични → опитваме да свием прозореца отляво
            while (satisfiedChars == totalRequiredDistinct) {

                int currentWindowLen = windowEnd - windowStart + 1;

                // Ако намерим по-малък валиден прозорец → обновяваме резултата
                if (currentWindowLen < bestWindowLen) {
                    bestWindowLen = currentWindowLen;
                    bestWindowStart = windowStart;
                }

                // Опитваме да изместим левия край надясно, за да минимизираме прозореца
                char startChar = s[windowStart];

                // Ако премахваме символ, който е нужен, и точно нарушаваме условието → намаляваме satisfiedChars
                if (requiredFreq.count(startChar) &&
                    windowFreq[startChar] == requiredFreq[startChar]) {
                    satisfiedChars--;
                }

                // Намаляваме честотата в прозореца и местим left pointer
                windowFreq[startChar]--;
                windowStart++;
            }
        }

        // Ако не е намерен валиден прозорец
        if (bestWindowLen == INT_MAX) return "";

        // Връщаме най-малкия прозорец
        return s.substr(bestWindowStart, bestWindowLen);
    }
};
