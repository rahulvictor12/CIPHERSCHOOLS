#include <bits/stdc++.h> 
using namespace std; 
  
int countSubsequences(string s) 
{ 
    int aCount = 0; 
  
    int bCount = 0; 
  
    int cCount = 0; 
  
    int dCount = 0; 
  
    for (unsigned int i = 0; i < s.size(); i++) { 
                //aCount subsequences. */
        if (s[i] == 'a') 
            aCount = (1 + 2 * aCount); 
  
                //bCount subsequences. */
        else if (s[i] == 'b') 
            bCount = (aCount + 2 * bCount); 
  
        else if (s[i] == 'c') 
            cCount = (bCount + 2 * cCount); 
        
        else if (s[i] == 'd') 
            dCount = (cCount + 2 * dCount); 
        
    } 
  
    return dCount; 
} 
  
int main() 
{ 
    string s = "abbcdd"; 
    cout << countSubsequences(s) << endl; 
    return 0; 
}
