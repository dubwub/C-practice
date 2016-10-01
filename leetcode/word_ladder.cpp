// word ladder
// assuming you can only change one letter at a time and all words have to be in a wordlist
// find quickest way (or if its possible) to go from one word to another
// tried optimizing by making things chars, but was still too slow
// now will try dijkstra'ing from both directions, maybe this will speed up performance?

class Solution {
public:
    int dijkstra(string beginWord, string endWord, unordered_set<string>& wordList) {
        unordered_map<string, int> distances;
        distances[beginWord] = 1;
        distances[endWord] = -1;
        int shortestDistance = INT_MAX;
        vector<vector<string>> traverse(2); // traverse[0] starts from beginning, traverse[1] from end
        traverse[0].push_back(beginWord);
        traverse[1].push_back(endWord);
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = 0; j < 2; j++) {
                if (i < traverse[j].size()) { // change each character with a-z, see what sticks
                    string tmp = traverse[j][i];
                    for (int wordIt = 0; wordIt < tmp.size(); wordIt++) {
                        for (char replace = 'a'; replace <= 'z'; replace++) {
                            tmp[wordIt] = replace;
                            if (wordList.find(tmp) == wordList.end()) continue; // skip non real words
                            if (distances.count(tmp) == 0 ||
                                (distances.count(tmp) > 0 && 
                                (j == 0 && distances[tmp] > distances[traverse[j][i]] + 1) ||
                                (j == 1 && distances[tmp] < distances[traverse[j][i]] - 1))) {
                                distances[tmp] = (j == 0 ? distances[traverse[j][i]] + 1 : distances[traverse[j][i]] - 1);
                                traverse[j].push_back(tmp);
                            }
                            else if ((j == 0 && distances[tmp] < 0) || (j == 1 && distances[tmp] > 0)) {
                                shortestDistance = min(shortestDistance, abs(distances[tmp]) + abs(distances[traverse[j][i]]));
                            }
                        }
                        tmp = traverse[j][i];
                    }
                }
            }
        }
        if (shortestDistance != INT_MAX) return shortestDistance;
        else return 0;
    }
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if (beginWord == endWord) return 1;
        if (wordList.size() == 0) return 0;
        wordList.insert(beginWord);
        wordList.insert(endWord);
        return dijkstra(beginWord, endWord, wordList);
    }
};