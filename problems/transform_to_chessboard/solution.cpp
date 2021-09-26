class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n=board.size();
        unordered_map<uint32_t, uint8_t> rows, cols;
        vector<uint32_t> R(n);
        vector<uint32_t> C(n);
        int rowCount =0, colCount = 0, maxCol=0, oddCount=0, curr=0, maxRow=0;
        uint32_t prev=0;
        int k=0;
        for(vector<int>v:board)
        {
            
            uint32_t row=0, sum=0;
            for(int i=0; i<n; ++i)
            {
                
                if(v[i])
                {
                    ++sum;
                    row |=(1<<i);
                }
                    
            }
            if(n%2 ==0 && sum!=n/2)
                return -1;
            if(n%2 ==1)
            {
                if(sum != n/2 && sum != (n/2)+1)
                    return -1;
                if(sum==(n/2)+1 && oddCount==(n/2)+1)
                    return -1;
                else if(sum==(n/2)+1)
                    oddCount++;
            }
            
            
            if(!rows.count(row))
            {
               if(rowCount!=2)
               {
                   rowCount++;
                   rows[row] =1;
               }
               else
               {
                   
                   return -1;
               }
                
            }
            else
            {
                rows[row]++;
                
            }
            if(row == prev)
            {
                ++curr;
            }
            else
            {
                curr =0;
            }
            prev=row;
            maxRow = max(curr, maxRow);
            R[k++]=row;
        }
        if(rowCount !=2)// || (n%2 ==1)) && oddCount != (n/2)+1) )
        {
            //cout<<"test"<<endl;
            return -1;
        }
            
        
        oddCount =0;
        prev = 0;
        curr=0;
        for(int j =0; j<n; ++j)
        {
            uint32_t col=0, sum=0;
            for(int i=0; i<n; ++i)
            {
                
                if(board[i][j])
                {
                    ++sum;
                    col |=(1<<i);
                }
                    
            }
            if(n%2 ==0 && sum!=n/2)
                return -1;
            if(n%2 ==1)
            {
                if(sum != n/2 && sum != (n/2)+1)
                    return -1;
                if(sum==(n/2)+1 && oddCount==(n/2)+1)
                    return -1;
                else if(sum==(n/2)+1)
                    oddCount++;
            }
            
            
            if(!cols.count(col))
            {
               if(colCount!=2)
               {
                   colCount++;
                   cols[col] =1;
               }
               else
               {
                   
                   return -1;
               }
                
            }
            else
            {
                cols[col]++;
                
            }
            if(col == prev)
            {
                ++curr;
            }
            else
            {
                curr =0;
            }
            prev =col;
            maxCol = max(curr, maxCol);
            C[j]=col;
        }
        if(colCount !=2)// || (n%2 ==1)) && oddCount != (n/2)+1) )
            return -1;
        
        
        if(n%2==0)
        {
            int res=0, m=0, res2=0;
            uint32_t c=C[0], c2;
            for(int i=0; i<n;++i)
            {
                
                if(C[i] ==c  && i%2!=0)
                    ++res;
                if(C[i] != c)
                    c2 = C[i];
            }
            m=res;
            res=0;
            for(int i=0; i<n;++i)
            {
                
                if(C[i] ==c2  && i%2!=0)
                    ++res;
                
            }
            res = min(res, m);
            uint32_t r=R[0], r2;
             for(int i=0; i<n;++i)
            {
                
                if(R[i] == r && i%2!=0)
                    ++res2;
                 if(R[i] != r)
                    r2 = R[i];
            }
            m=res2;
            res2=0;
            for(int i=0; i<n;++i)
            {
                
                if(R[i] == r2 && i%2!=0)
                    ++res2;
                 
            }
            res2 = min(res2 ,m);
            return res+res2;
        }
        else
        {
            int res=0;
            for(int i=0; i<n;++i)
            {
                uint32_t c=C[i];
                if(cols[c] == (n/2)+1 && i%2!=0)
                    ++res;
            }
             for(int i=0; i<n;++i)
            {
                uint32_t r=R[i];
                if(rows[r] == (n/2)+1 && i%2!=0)
                    ++res;
            }
            return res;
        }
    }
};