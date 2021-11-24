class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& iList, vector<vector<int>>& jList) {
        
        if(!iList.size() || !jList.size())
            return {};
        
        
        int i=0;
        int j=0;
        int sint, eint,curr;
        if(iList[i][0]>jList[j][0])
        {
            sint=i;
            curr=0;
        }
        else
        {
            sint =j;
            curr=1;
        }
        vector<vector<int>> res;
        while(i <=iList.size() -1 || j <= jList.size() -1 )
        {
           
            if(!curr)
            {
                if(j)
                    --j;
                while(j<jList.size()&&jList[j][1]<iList[i][0])
                    ++j;
                if(j<jList.size()&&jList[j][0]<=iList[i][0])
                {
                    res.push_back({iList[sint][0], min(iList[i][1], jList[j][1])});
                    ++j;
                    
                }
                
                    ++i;
                
            }
            else
            {
                if(i)
                    --i;
                while(i<iList.size()&&iList[i][1]<jList[j][0])
                    ++i;
                if(i<iList.size()&&iList[i][0]<=jList[j][0])
                {
                    res.push_back({jList[sint][0], min(iList[i][1], jList[j][1])});
                    ++i;
                }
                
                    ++j;
            }
            //cout<<j<<endl;
            if(i>=iList.size() &&  j>=jList.size())
                break;
            if(i<iList.size()&& j>=jList.size())
            {
                sint =i;
                curr=0;
            }
            else if(i>=iList.size())
            {
                sint=j;
                curr=1;
            }
            else if(iList[i][0]>jList[j][0])
            {
                sint=j;
                curr=1;
            }
            else
            {
                sint =i;
                curr=0;
            }
        }
        
        return res;
    }
};