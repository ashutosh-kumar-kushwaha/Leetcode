class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        vector<string> result;
        if(digits.size() == 0){
            return result;
        }
        helper("", digits, mp, result);
        return result;
    }
    
    void helper(string p, string up, map<char, string> mp, vector<string> &v){
        if(up.size() == 0){
            v.push_back(p);
            return;
        }
        for(char c : mp[up[0]]){
            helper(p+c, up.substr(1), mp, v);
        }
    }
};