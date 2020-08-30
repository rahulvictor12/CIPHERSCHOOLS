 #include<iostream>
using namespace std;
class Solution {
public:
    
    bool w_union(int x, int y, vector<int> &parent) {
        int x_idx;   
        int xr = find(x,parent,x_idx);  
        
        int y_idx; 
        int yr = find(y,parent,y_idx);
        
      
        if ( xr < yr ) {  
           
            parent[x_idx] = xr + yr;       
            parent[y_idx] = x_idx;         // collapsing path
        } else if ( yr < xr ) {
            parent[y_idx] = xr + yr;
            parent[x_idx] = y_idx;
        } else { // (xr == yr) 
            
            if (x_idx == y_idx){
                return false;
            } 
            else {
                parent[x_idx] = xr + yr;
                parent[y_idx] = x_idx;
            }
        }
        
        return true;
    }
    
    int find(int x,vector<int> &parent, int & i) //  
    {
        i = x;
        return parent[x]<0?parent[x]:find(parent[x],parent,i);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        vector<int> parent (N+1,-1);  
        
        for(auto &x:edges) {
            if(!w_union(x[0], x[1], parent)) return {min(x[0],x[1]),max(x[0],x[1])};
        }
        return {};
    }
};
