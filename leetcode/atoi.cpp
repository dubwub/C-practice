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
        if (str.size() == 0) return 0;
        int value = 0;
        bool negative = false;
        bool encounteredNumber = false;
        bool encounteredSign = false;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                encounteredNumber = true;
                if (value > INT_MAX / 10) return (negative ? INT_MIN : INT_MAX);
                if (value == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10 && !negative)
                    return INT_MAX;
                if (value == INT_MAX / 10 && str[i] - '0' > -1 * (INT_MIN % 10) && negative) {
                    // cout << str[i] - '0' << ", " << -1 * (INT_MIN % 10) << endl;
                    return INT_MIN;
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