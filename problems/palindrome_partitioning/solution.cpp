class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        
        backtracing(cur,ans,0,s);
        return ans;
    }
    
    void backtracing(vector<string>& cur, vector<vector<string>>& ans, int start, string& s){
        if(start==s.size()){
            ans.push_back(cur);
            return;
        }
        
        for(int i=start; i<s.size();i++){
            if(isPalindrome(s,start,i))
            {
                cur.push_back(s.substr(start,i-start+1));
                backtracing(cur,ans,i+1,s);
                cur.pop_back();
            }
        }
        
    }
    
    
    
    bool isPalindrome(string &s, int low, int high) {
        while (low < high) {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }
};
