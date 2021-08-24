class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        string r1, r2, i1, i2;
        int i=0;
        while(num1[i] != '+')
        {
            r1.push_back(num1[i]);
            ++i;
        }
        ++i;
        while(num1[i] != 'i')
        {
            i1.push_back(num1[i]);
            ++i;
        }
        i=0;
        while(num2[i] != '+')
        {
            r2.push_back(num2[i]);
            ++i;
        }
        ++i;
        while(num2[i] != 'i')
        {
            i2.push_back(num2[i]);
            ++i;
        }
        int real1, im1, real2, im2;
        real1=stoi(r1); real2 = stoi(r2); im1=stoi(i1);im2=stoi(i2);
        int real=real1*real2 - (im1*im2);
        int im=(real1*im2)+(im1*real2);
        return to_string(real) + "+" + to_string(im) + "i";
    }
};