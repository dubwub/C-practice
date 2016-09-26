/*
    https://leetcode.com/problems/additive-number/

    additive numbers are defined as:
    A + B + (A + B) + ... with each subsequent number being concatenated to the end being the sum of the previous two numbers
    in the sequence

    for instance:
    112358 --> 1 + 1 = 2, 1 + 2 = 3, etc
    also 199100 --> 1 + 99 = 100
    
    0 is a valid number, but numbers can't have preceding 0s (i.e. 00 or 09)

    this is O(n^3), apparently this is really slow LOL (beat 3% of solutions)
*/

class Solution {
public:
    // first determine valid firstnumber (~n choices)
    // then determine valid secondnumber (~n choices)
    // then verify if it works (~n?)
    // probably O(n^3), ouch
    // could implement this recursively, doing iterative solution to improve performance
    bool verifySolution(string& num, int firstLen, int secondLen) {
        // cout << num.substr(0, firstLen) << ", " << num.substr(firstLen, secondLen) << endl;
        if ((num[0] == '0' && firstLen > 1) || (num[firstLen] == '0' && secondLen > 1)) return false;
        if (firstLen + secondLen >= num.size()) return false;
        string rebuildNum = num.substr(0, firstLen) + num.substr(firstLen, secondLen);
        unsigned int first, second, third;
        stringstream ss;
        ss << num.substr(0, firstLen);
        ss >> first;
        ss.clear();
        ss << num.substr(firstLen, secondLen);
        ss >> second;
        ss.clear();
        if (first > UINT_MAX - second) return false; // break out for overflow
        while (num.size() > rebuildNum.size()) {
            third = first + second;
            ss << third;
            string thirdStr;
            ss >> thirdStr;
            ss.clear();
            rebuildNum += thirdStr;
            cout << rebuildNum << endl;
            first = second;
            second = third;
        }
        if (num.size() == rebuildNum.size() && num.compare(rebuildNum) == 0)
            return true;
        else return false;
    }
    
    bool isAdditiveNumber(string num) {
        if (num.size() < 3) return false;
        for (int firstLen = 1; firstLen < num.size() - 1; firstLen++) {
            for (int secondLen = 1; secondLen < num.size() - firstLen; secondLen++) {
                if (verifySolution(num, firstLen, secondLen)) return true;
            }
        }
        return false;
    }
};