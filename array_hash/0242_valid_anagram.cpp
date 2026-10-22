#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // 1. 如果长度不同，返回 false
        if(s.size() != t.size())
        {
            return false;
        }

        unordered_map<char, int> count;

        // 2. 遍历 s，将每个字符的计数加 1
        for(char c : s)//遍历string和遍历vector差不多，只是将int改为char即可
        {
            count[c]++;
        }

        // 3. 遍历 t，将每个字符的计数减 1
        //    如果某个字符的计数小于 0，返回 false
        for(char c : t)
        {
            count[c]--;
            if(count[c] < 0)
            {
                return false;
            }
        }
        // 4. 如果没有发现问题，返回 true
        return true;
    }
};
//// 时间复杂度：平均 O(n)
// 空间复杂度：O(1)，因为本题只包含小写英文字母

//sort
// #include <string>
// #include <algorithm>
// using namespace std;

// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if (s.size() != t.size()) {
//             return false;
//         }

//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());

//         return s == t;
//     }
// };

// 时间复杂度：O(n log n)
// 空间复杂度：通常为 O(log n)，用于排序的辅助栈

