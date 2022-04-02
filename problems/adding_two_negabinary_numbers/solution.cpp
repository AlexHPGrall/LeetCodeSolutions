class Solution {
public:
    
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        int carry=0;
        for(int i=arr1.size()-1, j=arr2.size()-1; i>=0 || j>=0;i-=2, j-=2)
        {
            int tres=0;
            if(i>=0)
                tres+=arr1[i];
            if(i>=1&&arr1[i-1])
                tres-=2;
            if(j>=0)
                tres+=arr2[j];
            if(j>=1&&arr2[j-1])
                tres-=2;
            tres+=carry;
            res.push_back(0);
            res.push_back(0);
            carry=0;
            //cout<<tres<<endl;
            switch(tres)
            {
                case 1:
                    res[res.size()-2]=1;
                    break;
                case -1:
                    res[res.size()-1]=1;
                    res[res.size()-2]=1;
                    break;
                case 2:
                    res[res.size()-1]=1;
                    carry=1;
                    break;
                case -2:
                    res[res.size()-1]=1;
                    break;
                case 3:
                    carry=1;
                    res[res.size()-1]=1;
                    res[res.size()-2]=1;
                    break;
                case -3:
                    carry =-1;
                    res[res.size()-2]=1;
                    break;
                case 4:
                    carry =1;
                    break;
                case -4:
                    carry=-1;
                    break;
                case -5:
                    carry=-1;
                    res[res.size()-1]=1;
                    res[res.size()-2]=1;
                    break;
            }
        }
        res.push_back(0);
        res.push_back(0);
        if(carry ==1)
            res[res.size()-2]=1;
        if(carry ==-1)
        {
            res[res.size()-1]=1;
            res[res.size()-2]=1;
        }
        while(res.size()>1 && res.back() ==0)
            res.pop_back();
        reverse(res.begin(), res.end());
          

        return res;
                
                
        
    }
};