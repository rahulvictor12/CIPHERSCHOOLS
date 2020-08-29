#include<iostream>
using namespace std;

class Solution {
public:
    
    int calc_trib(int n, int result[]) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        if (result[n] == -1) {
            int curr_sum = calc_trib(n-1, result) + calc_trib(n-2, result) + calc_trib(n-3, result);
            result[n] = curr_sum;
        }
        else {
            return result[n];
        }
        return result[n];
        
    }
    int tribonacci(int n) {
        
        int result[38];
        fill_n(result, 38, -1);
        
        return calc_trib(n, result);
        
    }
};
