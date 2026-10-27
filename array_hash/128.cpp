#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;

        for (int x : nums) {
            s.insert(x);
        }

        int longest = 0;

        for (int x : s) {
            if (s.find(x - 1) != s.end()) {
                continue;
            }

            int current = x;
            int count = 1;

            while (s.find(current + 1) != s.end()) {
                current++;
                count++;
            }

            longest = max(longest, count);
        }

        return longest;
    }
};
