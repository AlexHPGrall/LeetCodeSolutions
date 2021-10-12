/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int mid = n/2;
        int left =0,right=n;
        for(int k =guess(mid); k; k=guess(mid))
        {
            if(k==1)
            {
                left = mid +1;
            }
            else
            {
                right=mid-1;
            }
            
            mid=left +(right-left)/2;
        }
        
        return mid;
            
    }
};