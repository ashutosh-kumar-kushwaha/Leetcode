class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        findCombinationSum(0, {}, candidates, target, result);
        return result;
    }
    
    void findCombinationSum(int i, vector<int> p, vector<int> set, int target, vector<vector<int>> &result){
        if(target == 0){
            result.push_back(p);
            return;
        }
        if(target < 0){
            return;
        }
        if(i==set.size()){
            return;
        }
        findCombinationSum(i+1, p, set, target, result);
        p.push_back(set[i]);
        findCombinationSum(i, p, set, target-set[i], result);
    }
};