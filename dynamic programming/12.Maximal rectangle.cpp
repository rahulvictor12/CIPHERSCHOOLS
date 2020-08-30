 #include<iostream>
using namespace std;
class Solution {
public:
    int area_under_histogram(int histogram[], int cols) {
        if (cols == 0) {
            return 0;
        }
        stack<int>st;
        st.push(0);
        int area, res = 0, i;
        for (i = 1; i<cols; i++) {
            if (histogram[i] >= histogram[st.top()]) {
                st.push(i);
                continue;
            }
            
            while(!st.empty() and histogram[i] < histogram[st.top()]) {
                int current_bar = st.top();
                st.pop();
                if (st.empty()) {
                    area = histogram[current_bar] * i;
                }
                else {
                    area = histogram[current_bar] * (i - st.top() - 1);
                 }
                res = max(res, area);
            }
            st.push(i);
        }
        
        while(!st.empty()) {
             int current_bar = st.top();
                st.pop();
                if (st.empty()) {
                    area = histogram[current_bar] * i;
                }
                else {
                    area = histogram[current_bar] * (i - st.top() - 1);
                }
            res = max(res, area);
        }
        return max(area, res);
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) {
            return 0;
        }
        int cols = matrix[0].size();
        if (cols == 0) {
            return 0;
        }
        int histogram[cols];
        memset(histogram, 0, sizeof(histogram));
        int res = 0;
        for (int i = 0; i<rows; i++) {
            for (int j = 0; j<cols; j++) {
                if (matrix[i][j] == '0') {
                    histogram[j] = 0;
                }
                else {
                    histogram[j] += (matrix[i][j] - '0');
                }
            }
            int area = area_under_histogram(histogram, cols);
            res = max(area, res);
        }
        return res;
    }
};
