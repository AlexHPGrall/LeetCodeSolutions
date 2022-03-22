class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        auto cmp=[](string s1, string s2){
            int i1=0;
            int i2=0;
            while(s1[i1]!=' ')
                ++i1;
            while(s2[i2]!=' ')
                ++i2;
            if(s1[i1+1]>='0'&& s1[i1+1]<='9' && s2[i2+1]>='a')
                return false;
            if(s2[i2+1]>='0'&& s2[i2+1]<='9' && s1[i1+1]>='a')
                return true;
            if(s1[i1+1]>='0'&& s1[i1+1]<='9' &&s2[i2+1]>='0'&& s2[i2+1]<='9')
                return false;
            if(s1.substr(i1)==s2.substr(i2))
                return s1.substr(0,i1)<s2.substr(0,i2);
            return s1.substr(i1)<s2.substr(i2);
        };
        stable_sort(logs.begin(),logs.end(), cmp);
        return logs;
    }
};