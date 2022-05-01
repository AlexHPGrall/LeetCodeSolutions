class Solution {
public:

    string removeDigit(string number, char digit) {
        int dcount=0;
        set<string> st;
      for(int i=0; i<number.size();++i)
      {
          char c=number[i];
          if(c==digit)
          {
              st.insert(number.substr(0,i)+number.substr(i+1));
              
          }
              
      }
        return (*st.rbegin());

    }
};