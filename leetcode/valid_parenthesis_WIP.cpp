class Solution {
public:
    bool isValid(string s) {
        int parenScore = 0;
        int curlyBraceScore = 0;
        int bracketScore = 0;
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
                case '(':
                    parenScore++;
                    break;
                case '{':
                    curlyBraceScore++;
                    break;
                case '[':
                    bracketScore++;
                    break;
                case ')':
                    parenScore--;
                    if (parenScore < 0) return false;
                case '}':
                    curlyBraceScore--;
                    if (curlyBraceScore < 0) return false;
                case ']':
                    bracketScore--;
                    if (bracketScore < 0) return false;
            }
        }
        if (parenScore == 0 && curlyBraceScore == 0 && bracketScore == 0) return true;
        return false;
    }
};