class Solution {
public:
    int wordCount(string &s)
    {
        if(s.empty())
            return 0;
        int res=1;
        for(char c:s)
        {
            if(c==' ')
                ++res;
        }
        return res;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> chatMap;
        int max=0;
        for(int i=0;i<messages.size();++i)
        {
            chatMap[senders[i]]+=wordCount(messages[i]);
            if(chatMap[senders[i]]>chatMap[senders[max]] || (chatMap[senders[i]]==chatMap[senders[max]] && senders[i]>senders[max]))
                max=i;
                
        }
        cout<<chatMap[senders[max]]<<endl;
        return senders[max];
    }
};