#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> map;
        for (string &s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            map[key].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto &pair : map)
        {
            anagrams.push_back(pair.second);
        }
        return anagrams;
    }
};

int main()
{
    Solution solution;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = solution.groupAnagrams(strs);
    for (const auto &group : result)
    {
        for (const auto &word : group)
        {
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}

// This code first sorts each string in the input vector and uses the sorted string as a key in a hash map. The value in the hash map is a vector of strings that are anagrams of each other. After processing all strings, it returns the vectors in the hash map as the result. The main function tests the groupAnagrams function with a test case.