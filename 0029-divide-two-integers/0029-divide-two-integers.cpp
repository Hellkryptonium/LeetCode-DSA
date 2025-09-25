class Solution {
public:
    int divide(int dividend, int divisor) {
       if(dividend == INT_MIN && divisor == -1) return INT_MAX;

       bool negative = (dividend < 0) ^ (divisor < 0);

       long long dvd =  dividend;
       long long dvs = divisor;
       dvd = dvd < 0 ? -(long long)dvd : dvd;
       dvs = dvs < 0 ? -(long long)dvs : dvs;

       long long quotient = 0;

       while(dvd >= dvs) {
        long long temp = dvs;
        long long multiple = 1;

        while((temp<<1) <= dvd) {
            temp <<= 1;
            multiple <<= 1;
        }
        dvd -= temp;
        quotient += multiple;
       } 

       return negative ? -quotient : quotient;
    }
};