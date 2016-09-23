// find needle in the haystack

// KMP
class Solution {
public:
    vector<int> preprocessNeedle(string needle) {
        vector<int> preprocess(needle.size(), 0);
        int substr_len = 0;
        for (int i = 1; i < needle.size(); i++) {
            if (needle[i] == needle[substr_len]) { // can we keep going?
                substr_len++;
                preprocess[i] = substr_len;
            }
            else { // no match
                if (substr_len == 0) {
                    continue;
                }
                substr_len = preprocess[substr_len-1];
                i--;
            }
        }
        return preprocess;
    }
    int strStr(string haystack, string needle) {
        if (haystack == needle || needle.size() == 0) return 0;
        vector<int> preprocess = preprocessNeedle(needle);
        int substr_len = 0;
        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[substr_len]) {
                substr_len++;
                if (substr_len == needle.size()) return i-substr_len+1;
            }
            else {
                if (substr_len == 0) {
                    continue;
                }
                substr_len = preprocess[substr_len-1];
                i--;
            }
        }
        return -1;
    }
};