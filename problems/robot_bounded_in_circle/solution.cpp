class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dir =0;
        int posx=0;
        int posy=0;
        for(char c : instructions)
        {
            if(c == 'G')
            {
                switch(dir)
                {
                    case 0:
                        posy+=1;
                        break;
                    case 90:
                        posx +=1;
                        break;
                    case 180:
                        posy -=1;
                        break;
                    case 270:
                        posx-=1;
                        break;
                }
            }
            else if(c=='L')
                dir= ((dir - 90)%360 + 360)%360;
            else
                dir=((dir + 90)%360 +360)%360;
        }
        if(dir != 0 ||(posx==0 && posy ==0))
            return true;
        return false;
    }
};