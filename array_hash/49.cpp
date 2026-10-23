class Solution
{
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string,vector<string>> groups;

        for(const string& s : strs)
        {
            string key = s;
            sort(key.begin(),key.end());
            groups[key].push_back(s);
        }

        vector<vector<string>> result;

        for(const auto& item :groups)//it是哈希表的元素，这里是键值对，所以要用auto
        {
            result.push_back(item.second);//把哈希表当前分组中的字符串数组，添加到最终结果 result 中
        }

        return result;
    }
};
//时间复杂度：nO(klogk)也即O(nklogk)
//n：输入字符串的数量。
//k：输入中最长字符串的长度
//空间复杂度：nO(k) 也即O(nk)