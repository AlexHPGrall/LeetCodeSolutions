class Solution {
public:
    int set2elem(int set, int size, int elem)
    {
        int count =0;
        for(int i =0; i<size; ++i)
        {
            if(set &(1<<i))
                count++;
            if(count == elem)
                return i;
        }
        return -1;
           
    }
    int removeFromSet(int set, int elem)
    {
                return (set & ~(1<<elem));
        
        
    }
    int solve(int set, int end,vector<vector<int>>& graph, vector<string>& A, int size, vector<vector<int>> &dp,
      vector<vector<int>> &path          )
    {
        
        if(size == 1)
        {
            return A[end].size();
           //return pair<vector<int>, int>({end},A[end].size());
        }
        if(dp[set][end] != -1)
            return dp[set][end];
        int minl = INT_MAX;
        int check;
        
            for(int j =0; j<size; ++j){
                int nextend=set2elem(set,  A.size(),j+1);
                if(end == nextend )
                continue;
                
                 int temp = solve(set & ~(1<<end), nextend,graph, A, size-1, dp, path) + graph[nextend][end];
                
                if(temp< minl)
                {
                    minl = temp;
                    
                        path[set][end] = nextend;
                    
                   
                    
                    
                   
                }
       
            }
        dp[set][end] =minl;        
        return minl; 
    }
     
    string shortestSuperstring(vector<string>& A) {
        
        int n = A.size();
        vector<vector<int>> dp((1<<n), vector<int>(n, -1));
         vector<vector<int>> path((1<<n), vector<int>(n));
        vector<vector<int>> graph(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if( i==j)
                    continue;
                int m = min(A[i].size(), A[j].size());
                for (int k = m; k >= 0; --k) {
                    if (A[i].substr(A[i].size() - k) == A[j].substr(0, k)) {
                        graph[i][j] = A[j].size()-k;
                        
                        break;
                    }
                    if(!graph[i][j])
                    {
                        graph[i][j] = A[j].size();
                        
                    }
                }
            }
        }
        
      
        
            int min=INT_MAX;
        
        int res, entry;
        for(int i= 0; i<n; ++i)
        {
            int tmp = solve((1<<n) -1, i, graph, A, n, dp, path);
            if(tmp<min)
            {
                res =tmp;
                min=tmp;
                entry = i;
            }
        }
        
        stack<int> st;
        vector<int> vec;
        st.push(entry);
       
        int set = (1<<n) -1;
        for(int i=1; i<n; ++i)
        {
            int tmp = entry;
            
            entry = path[set][entry];
            
            st.push(entry);
            set = removeFromSet(set, tmp);
        }
        while(!st.empty())
        {
            vec.push_back(st.top());
            
            st.pop();
        }
        
        
        string shortest = A[vec[0]];
        
        for(int i =1; i<n; ++i)
        {
            
            int k = vec[i-1];
            int l =  vec[i];
            int m = A[l].size();
            shortest.append(A[l].substr(m-graph[k][l]));
           
        }
        
       
        
        
        return shortest;
    }
};