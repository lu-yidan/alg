#include <vector>
#include <string>
#include <unordered_map>
#include <array>
#include <iostream>
#include <sstream>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> map;
        for (string &s : strs)
        {
            array<int,26> counts{};
            for(char c : s){
                counts[c-'a']++;
            }
            string key;
            for(int i =0;i<26;i++){
                key+='#';
                key+=to_string(counts[i]);
            }
            map[key].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto pair:map)
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