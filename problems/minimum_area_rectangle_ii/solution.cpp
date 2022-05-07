#define epsilon 0.000001f
struct point
{
    int x;
    int y;
};
struct diag
{
    double len;
    double x;
    double y;
    point p1;
    point p2;
};

class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        vector<diag> dlist;
        double res=-1;
        for(int i=0; i< points.size()-1;++i)
        {
            for(int j =i+1; j<points.size();++j)
            {
                diag d={};
                d.x=(points[i][0]+points[j][0])/2.0f;
                d.y=(points[i][1]+points[j][1])/2.0f;
                d.len=(points[i][0]-points[j][0])*(points[i][0]-points[j][0])
                        +(points[i][1]-points[j][1])*(points[i][1]-points[j][1]);
                d.p1={points[i][0], points[i][1]};
                d.p2={points[j][0], points[j][1]};
                dlist.push_back(d);
                
            }
        }
        //cout<<dlist.size()<<endl;
         for(int i=0; i< dlist.size()-1;++i)
        {
            for(int j =i+1; j<dlist.size();++j)
            {
                diag d1=dlist[i], d2=dlist[j];
                //cout<<d1.x<<' '<<d1.y<<' '<<d1.len<<' '<<d2.x<<' '<<d2.y<<' '<<d2.len<<endl;
                if(abs(d1.x-d2.x)<epsilon && abs(d1.y-d2.y)<epsilon && abs(d1.len-d2.len)<epsilon)
                {
                    double area=(d1.p1.x-d2.p1.x)*(d1.p1.x-d2.p1.x) + (d1.p1.y-d2.p1.y)*(d1.p1.y-d2.p1.y);
                    area *=(d1.p1.x-d2.p2.x)*(d1.p1.x-d2.p2.x) + (d1.p1.y-d2.p2.y)*(d1.p1.y-d2.p2.y);
                    //cout<<area<<endl;
                    if(res==-1)
                        res=area;
                    else
                        res=min(res, area);

                }
            }
        }
        if(res==-1)
            return 0.0f;
        return sqrt(res);
    }
};