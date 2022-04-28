class Solution {
    unordered_map<int, int> row, col, diag1, diag2;
    vector<vector<int>> mv={{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
public:
    struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};
    void turnOn(int i, int j, int n)
    {
        row[i]++;
        col[j]++;
        diag1[i+j]++;
        diag2[i-j]++;
    }
    void turnOff(int i, int j, int n)
    {
        row[i]--;
        col[j]--;

        diag1[i+j]--;
        diag2[i-j]--;
        
    }
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<pair<int, int>, int, pair_hash>lampPos;
        //vector<vector<char>> grid(n, vector<char>(n,'-'));
        for(auto &v:lamps)
        {
            int i=v[0];
            int j=v[1];
            //grid[i][j]='o';
            if(!lampPos[{i,j}])
            {
                lampPos[{i,j}]=1;
                turnOn(i,j,n);
            }
        }
        //cout<<diag2[2]<<endl;
        vector<int> res;
        for(auto &q:queries)
        {

            int i=q[0];
            int j=q[1];
            int d1=i+j,d2=i-j;
            
            /*
            cout<<i<<' '<<j<<' '<<d1<<' '<<d2<<endl;
            cout<<row[i]<<' '<<col[j]<<' '<<diag1[d1]<<' '<<diag2[d2]<<endl;
            */
            if(row[i] || col[j] || diag1[d1] || diag2[d2])
                res.push_back(1);
            else
                res.push_back(0);
            for(auto &m:mv)
            {
                int ni = i+m[0];
                int nj = j+m[1];
                
                if(ni>=0 && ni<n && nj>=0 && nj<n)
                {
                   
                    if(lampPos[{ni, nj}])
                    {
                        turnOff(ni, nj,n);
                        lampPos[{ni, nj}]=0;
                        //grid[ni][nj]='-';
                        
                    }
                }
            }
        }
        return res;
    }
};