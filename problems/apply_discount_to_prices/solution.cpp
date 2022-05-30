class Solution {
public:
    string discountPrices(string s, int discount) {
        string res;
        for(int i=0; i<s.size();++i)
        {
            if(s[i]=='$'&&(i==0 || s[i-1]==' '))
            {
                int j=i;
                ++i;
                if(!(s[i]>='0'&&s[i]<='9'))
                {--i;res.push_back(s[i]);continue;}
                while(i<s.length()&&s[i]>='0'&&s[i]<='9')
                    ++i;
                if(i<s.length() && s[i]!=' ')
                {
                    i=j;
                    res.push_back(s[i]);
                    continue;
                }
                long long val=stoll(s.substr(j+1,i-j));
                
                double d=(double)val-((double)val*((double)(discount)/100.0f));
                
                stack<int> st;
                if(d==0.0f)
                {
                    res+="$0.00";
                    goto end;
                }
                
                val=(long long)round(d*100);
                
                while(val)
                {
                    st.push(val%10);
                    val/=10;
                }
                res.push_back('$');
                if(st.size()<=2)
                    res.push_back('0');
                while(st.size()>2)
                {
                    res.push_back(st.top()+'0');
                    st.pop();
                }
                res.push_back('.');
                if(st.size()<2)
                    res.push_back('0');
                while(!st.empty())
                {
                    //cout<<st.top()<<endl;
                    res.push_back(st.top()+'0');
                    st.pop();
                }
                //cout<<i<<endl;
end:                if(i<s.size())
                {res.push_back(s[i]);continue;}
                    
            }
            else
                res.push_back(s[i]);
        }
        return res;
    }
};