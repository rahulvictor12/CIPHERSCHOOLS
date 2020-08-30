 #include<iostream>
using namespace std;
class Solution {
public:
vector rel; //for storing the parent
vector ans;
int par(int i)
{
return (rel[i]==i)?i:par(rel[i]);
}

void grp(int i,int j)
{
	
    int ch=par(i);
    int ch1=par(j);
    
    if(ch!=ch1)
        rel[ch1]=ch;
    else
    {
        ans.push_back(i);
        ans.push_back(j);
    }
}
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    //for finding the redundant connection we must check if they are in the same set or not
	//through the union find we can check for this.
	if(edges.size()==0)
        return ans;
    int r=edges.size();
    rel.resize(edges.size()+1);
	//we will initialise the set here.
    for(int i=1;i<=edges.size();i++)
    {
        rel[i]=i;
    }
	
    for(int i=0;i<r;i++)
    {
        grp(edges[i][0],edges[i][1]);
    }
    
    return ans;
}
};
