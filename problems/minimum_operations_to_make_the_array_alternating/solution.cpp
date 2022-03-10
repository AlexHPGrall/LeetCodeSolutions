class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 0;
        int even1=nums[0], even2=nums[0];
        int odd1=nums[1], odd2=nums[1];
        unordered_map<int ,int> evenmp,oddmp;
        for(int i=0; i<n;++i)
        {
            if(i%2==0)
            {
                evenmp[nums[i]]++;
                if(even2==even1 && nums[i]!=even1)
                    even2=nums[i];
                if(evenmp[nums[i]]>evenmp[even1])
                {even2=even1;even1=nums[i];}
                else if(evenmp[nums[i]]>evenmp[even2] && nums[i]!=even1)
                    even2=nums[i];        
            }
            else
            {
                oddmp[nums[i]]++;
                if(odd2==odd1 && nums[i]!=odd1)
                    odd2=nums[i];
                
                if(oddmp[nums[i]]>oddmp[odd1])
                {odd2=odd1;odd1=nums[i];}
                else if(oddmp[nums[i]]>oddmp[odd2]&&nums[i]!=odd1)
                    odd2=nums[i];        
                
            }
        }
       
        if(odd1!=even1)
            return (n/2-oddmp[odd1]) +(n/2-evenmp[even1]) +(n%2);
        else if(odd1 != odd2 && even1!=even2)
            return min((n/2-oddmp[odd2]) +(n/2-evenmp[even1]) +(n%2),(n/2-oddmp[odd1]) +(n/2-evenmp[even2]) +(n%2));
        else if(odd2==odd1 && even2==even1)
            return n/2;
        else if(odd1==odd2)
            return (n/2-oddmp[odd1]) +(n/2-evenmp[even2]) +(n%2);
        else if(even1==even2)
            return (n/2-oddmp[odd2]) +(n/2-evenmp[even1]) +(n%2);
        return 0;
    }
};