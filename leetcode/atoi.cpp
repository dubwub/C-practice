/*
    Not working
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
        cout << value << " " << (value > 0) << " " << negative << endl;
        if (value < 0 && negative == false) return INT_MAX; // for INT_MAX
        else if (value == -1 * INT_MAX && negative == true) return INT_MIN;
        else if (value > 0 && negative) return INT_MIN;
        if (negative) return -1 * value;
        else return value;
    }
};