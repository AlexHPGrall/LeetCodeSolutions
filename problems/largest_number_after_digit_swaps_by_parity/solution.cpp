class Solution {
public:
    int largestInteger(int num) {
        vector<int> odd, even;
        string map;
        while(num)
        {
            int rem=num%10;
            if(rem&1)
            {
                odd.push_back(rem);
                map.push_back('o');
            }
            else
            {
                even.push_back(rem);
                map.push_back('e');
            }
                
            num/=10;
        }
        sort(even.rbegin(), even.rend());
        sort(odd.rbegin(), odd.rend());
        int res=0;
        int i=0;
        int j=0;
        for(auto it=map.rbegin(); it<map.rend();++it)
        {
            char c=*it;
            //cout<<c<<endl;
            res*=10;
            if(c=='e')
                res+=even[i++];
            else
                res+=odd[j++];
        }
        return res;
    }
};