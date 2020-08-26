#include<iostream>
using namespace std;
auto x = ([](){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    return 0;
})();

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;
                
        unordered_map<int, int> table;
        for(auto &num: nums)
            table[num] = 1;
        cout << table.size() << endl;         
        auto count = 1;
            
        for(auto &entry: table){
            
            int val = entry.first - 1;
            for(; table.find(val) != table.end() && table[val] == 1; val--){
                    
                entry.second++;
                            
                table.erase(val);
            }
            
            if(table.find(val) != table.end()){
                entry.second += table[val];
                table.erase(val);
            }
            
            count = max(count, entry.second);
        }
        
        return count;
    }
};
