// valid anagram (check if s and t are anagrams)
// problem desc says input are all just lowercase chars, so we can avoid hashing

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> firstCount(26, 0);
        vector<int> secondCount(26, 0);
        for (int i = 0; i < s.size(); i++) {
            firstCount[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            secondCount[t[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (firstCount[i] != secondCount[i]) return false;
        }
        return true;
    }
};