// Given a string s, find the length of the longest without duplicate
// characters.

#include <cstdio>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int i = 0, j = 0, len = 0;
    unordered_map<char, int> hash_map;
    while (j < s.size()) {
      char current = s[j];
      if (hash_map.find(current) != hash_map.end() && hash_map[s[j]] >= i) {
        i = hash_map[current] + 1;
      }
      len = max(len, j - i + 1);
      hash_map[current] = j;
      j++;
    }
    return len;
  }
};

