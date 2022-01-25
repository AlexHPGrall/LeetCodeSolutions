class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i=1;
        int n=arr.size();
        if(n<3)
            return false;
        while(i<n&&arr[i-1]<arr[i])
            ++i;
        
        if(i==n || arr[i-1]==arr[i]||i==1)
            return false;
        while(i<n && arr[i-1]>arr[i])
            ++i;
        if(i!=n)
            return false;
        
        return true;
        
    }
};