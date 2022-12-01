//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    
    public:
    
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
    
    vector<vector<int>> combinationSum(vector<int>& set, int target) {
        vector<vector<int>> result;
        sort(set.begin(), set.end());
        set.erase( unique(set.begin(), set.end()), set.end());
        findCombinationSum(0, {}, set, target, result);
        sort(result.begin(), result.end());
        return result;
    }
    
    
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends