class Solution {
public:
    string pushDominoes(string d) {
        int n= d.length();
        for(int i =0; i<n; ++i)
        {
            if(d[i] == '.')
            {
                int j=i;
                while(d[j]== '.')
                {
                    ++j;
                }
                
                if(i==0 && j==n)
                    return d;
                else if((i==0 && d[j] =='R') ||(j==n &&d[i-1]=='L'))
                    i=j;
                else if(i==0 || j==n || d[i-1]==d[j])
                {
                    char c = (i==0)?d[j]:d[i-1];
                    for(;i<j;++i)
                        d[i] =c;
                }
                else
                {
                    int count=j-i;
                    char c1= d[i-1], c2 = d[j];
                    if(c1 == 'L' && c2=='R')
                        i=j;
                    else
                    {
                        for(int k=0; i<j;++i, ++k)
                        {
                            if(k<(count/2))
                                d[i]=c1;
                            else if(k>(count/2))
                                d[i] =c2;
                            else
                            {
                                if(count%2 ==0)
                                    d[i]=c2;
                            }
                        }
                    }
                }
            }
        }
        return d;
    }
};