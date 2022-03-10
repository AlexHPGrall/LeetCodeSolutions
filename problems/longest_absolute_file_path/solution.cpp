class Solution {
public:
    int lengthLongestPath(string input) {
        int res=0;
        unordered_map<int,int > mp;
        mp[0]=0;
        int currdepth=0;
        int currpath=0;
        for(int i=0;i<input.size();++i)
        {
            
            if(input[i]=='\n')
            {
                
                
                i+=1;
                int depth=0;
                while(input[i]=='\t')
                {i+=1; depth++;}
                //cout<<depth<<endl;
                if(depth >currdepth)
                {mp[depth]=currpath; currdepth=depth;}
                else
                {
                  currpath=mp[depth];
                    currdepth=depth;
                    
                }
            }
            if(input[i]=='.')
            {
                while(i<input.size() && input[i]!='\n')
                {++i;++currpath;}
                --i;
                currpath+=currdepth;
                res=max(res,currpath);
            }
            else
              currpath++;
            
        }
        return res;
    }
};