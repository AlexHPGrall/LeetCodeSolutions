/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> a1(101,0),a2(10100,0);
        int m=0,n=0;
        ListNode* curr=l1;
        while(curr)
        {
            a1[m]=curr->val;
            m++;
            curr=curr->next;
        }
        curr=l2;
        while(curr)
        {
            a2[n]=curr->val;
            n++;
            curr=curr->next;
        }
        vector<int> res;
        if(n>m)
        {swap(a1,a2);swap(m,n);}
        int rem=0;
        //cout<<m<<" "<<n<<endl;
        for(int i=m-1, j=n-1;i>=0||j>=0;--i,--j)
        {
            //cout<<i<<" "<<j<<endl;
            int tres=a1[i]+rem;
            rem=0;
            if(j>=0)
                tres+=a2[j];
            if(tres>9)
            {tres-=10;rem=1;}
            res.push_back(tres);
        }
        if(rem)
            res.push_back(rem);
        ListNode *sum=nullptr;
        ListNode *ret;
        for(int i=res.size()-1;~i;--i)
        {
            if(!sum)
            {sum=new ListNode(res[i]);ret=sum;continue;}
            sum->next=new ListNode(res[i]);
            sum=sum->next;
        }
        
        return ret;
    }
};