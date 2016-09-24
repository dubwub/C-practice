/*
    ATOI (took way longer than it should've)

    specs:
    ignore whitespace at beginning
    read 0-9 characters until first non-numeric character, then break
    handle INT_MIN/INT_MAX properly
    +/- at beginning of number is accepted
*/

class Solution {
public:
    int myAtoi(string str) {
        stringstream ss;
        string strIntMax, strIntMin;
        ss << INT_MAX;
        ss >> strIntMax;
        ss.clear();
        ss << INT_MIN;
        ss >> strIntMin;
        if (str.size() == 0) return 0;
        int value = 0;
        bool negative = false;
        bool encounteredNumber = false;
        bool encounteredSign = false;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                if (encounteredNumber == false) {
                    encounteredNumber = true;
                    int numberLength = 1;
                    for (int j = i+1; j < str.size(); j++) { // slow way of implementing INT_MAX/INT_MIN checking, but it works
                        if (str[j] >= '0' && str[j] <= '9')
                            numberLength++;
                        else
                            break;
                    }
                    if (numberLength > strIntMax.size()) {
                        if (negative) return INT_MIN;
                        else return INT_MAX;
                    }
                    else if (numberLength == strIntMax.size()) {
                        string numberSubStr = str.substr(i, numberLength);
                        if (numberSubStr >= strIntMax && !negative) {
                            return INT_MAX;
                        }
                        else if (numberSubStr >= strIntMin.substr(1) && negative) {
                            return INT_MIN;
                        }
                    }
                }
                value *= 10;
                value += str[i] - '0';
            }
            else if (!encounteredNumber && !encounteredSign && str[i] == '-') {
                encounteredSign = true;
                negative = true;
            }
            else if (!encounteredNumber && !encounteredSign && str[i] == '+') {
                encounteredSign = true;
            }
            else if (!encounteredNumber && !encounteredSign && str[i] == ' ') continue;
            else break;
        }
        if (negative) return -1 * value;
        else return value;
    }
};