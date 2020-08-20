//perfect squares
class Solution {
public:
    inline constexpr int numSquares( int n) const noexcept
    {
        int m = n;
        
        while (m % 4 == 0) m/= 4;
        
        if (m % 8 == 7) return 4;
        
        bool p3 = false;
        bool p2 = false; 
        for (int x = 2; x*x <= n; ++x){
            if (n % x == 0) {
                int d = 0;
                while (n %x == 0) n /= x, ++d;
                p3 = p3 || (x % 4 == 3 && d % 2 == 1);
                p2 = p2 || (d % 2 == 1);
            }
        }
        if (n>1){
           p3 = p3 || (n % 4 == 3);
            p2 = p2 || (1 % 2 == 1);
        }
        return 1 + p2 + p3;
    }
};
