//squares of sorted array
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        
        int i=0, j=A.size()-1;
		//Creating result vector
        vector<int> result;
        while(i<=j)
        {
            if(pow(A[i],2) > pow(A[j],2))
                result.push_back(pow(A[i++],2));
            else
                result.push_back(pow(A[j--],2));
        }
		
		//To arrange result in increasing order
        reverse(result.begin(), result.end());
        
        return result;
    }
};
