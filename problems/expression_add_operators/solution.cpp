class Solution {
public:
    string s;
    vector<string> res;
    int64_t n, t;

    void rec(int index, int64_t val, int64_t preval, int64_t curr, char op)
    {
       //cout<<index<<endl;
       
        {
            
            curr=curr*10 +(s[index]-'0');
            if(index<(2*n)-2 &&( s[index]!='0' || (index >0 && s[index-1]==' ')))
            {   s[index+1] =' ';
                rec(index+2,val,preval, curr,op);
            }
            if(op=='+')
            {
                val +=curr;
                preval= -curr;
            }
                
                
            else if(op =='-')
            {
                val -=curr;
                preval=curr;
                
            }
               
            else if(op == '*')
            {
                val = val +preval -(preval*curr);
               
                preval=(preval*curr);
            }
            
            if(index == (2*n)- 2 && val==t)
            {
                //cout<<s<<endl;
                string tmp;
                for(char c:s)
                    if(c!=' ')
                        tmp.push_back(c);
                    res.push_back(tmp);
            }
            else if(index <2*n-2)
            {
                s[index+1] ='+';
                rec(index+2,val,preval,0,'+');
                s[index+1] ='-';
                rec(index+2,val,preval,0,'-');
                s[index+1] ='*';
                rec(index+2,val,preval,0,'*');
            }
            
            
        }
        
            
    }
    vector<string> addOperators(string num, int target) {
        n =num.size();
        t=target;
        for(int i=0;i<n-1;i++)
        {
            s.push_back(num[i]);
            s.push_back('.');
        }
        s.push_back(num[n-1]);
       
        rec(0,0,0,0,'+');
        return res;
    }
};