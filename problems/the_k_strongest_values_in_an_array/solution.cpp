class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<int> res;
        int i=0;
        int j=arr.size()-1;
        int m=arr[(arr.size()-1)/2];
        while(res.size()<k)
        {
            
            if(abs(arr[i]-m)<abs(arr[j]-m))
            {
                res.push_back(arr[j]);
                --j;
            }
            else if(abs(arr[i]-m)>abs(arr[j]-m))
            {
                res.push_back(arr[i]);
                ++i;
            }
            else if(arr[i]<arr[j])
            {
                res.push_back(arr[j]);
                --j;
            }
            else
            {
                res.push_back(arr[i]);
                ++i;
            }
        }
        return res;
    }
};