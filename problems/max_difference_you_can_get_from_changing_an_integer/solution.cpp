class Solution {
public:
    int maxDiff(int num) {
        int high=0, low=0;
        int ph[2]={-1,-1};
        int pl[2]={-1, -1};
        vector<int> digs;
        int curr=9;
        while(num)
        {
            digs.push_back(num%10);
            num/=10;
        }
        bool first=true;
        int i=digs.size()-1;
        while(i>=0)
        {
            int c=digs[i];
            --i;
            
            high*=10;
            low*=10;
            if(ph[0] == -1)
            {
                if(c!=9)
                {
                    ph[0]=c;
                    ph[1]=9;
                }
                high+=9;
                    
            }
            else if(ph[0]==c)
            {
                high+=ph[1];
            }
            else
            {
                high+=c;
            }
            if(pl[0] == -1)
            {
                if(first)
                {
                    if(c!=1)
                    {
                        pl[0]=c;
                        pl[1]=1;
                    }
                    low+=1;
                }
                else if(c!=0 && (c!=1 || digs[digs.size()-1]!=1))
                {
                    pl[0]=c;
                    pl[1]=0;
                }
                else
                {
                    low+=c;
                }
                
                    
            }
            else if(pl[0]==c)
            {
                low+=pl[1];
            }
            else
            {
                low+=c;
            }
            first=false;
            //cout<<pl[0]<<' '<<pl[1]<<endl;

        }
        //cout<<high<<' '<<low<<endl;
            return high-low;
    }
};