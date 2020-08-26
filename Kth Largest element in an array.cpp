class myHeap{
    public:
    vector<int>array;
    int parent(const int&child){return (child==0)? -1 : (child-1)/2;}
    int left(const int&parent){
        int ret = parent*2+1;
        return (ret<array.size())? ret : -1;
    }
    int right(const int&parent){
        int ret = parent*2+2;
        return (ret<array.size())? ret : -1;
    }
    void push(const int&value){
        array.push_back(value);
        moveUp(array.size()-1);
    }
    void pop(){
        array[0] = array.back();
        array.pop_back();
        moveDown(0);
    }
    int top(){return array.front();}
    void moveDown(int index){
        int bigIndex=index,leftIndex=left(index),rightIndex=right(index);
        if(leftIndex!=-1&&array[leftIndex]>array[bigIndex]){bigIndex=leftIndex;}
        if(rightIndex!=-1&&array[rightIndex]>array[bigIndex]){bigIndex=rightIndex;}
        if(bigIndex!=index){
            swap(array[bigIndex],array[index]);
            moveDown(bigIndex);
        }
    }
    void moveUp(int index){
        int parentIndex = parent(index);
        if(parentIndex!=-1&&array[parentIndex]<array[index]){
            swap(array[parentIndex],array[index]);
            moveUp(parentIndex);
        }
    }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        myHeap helper;
        for(int i=0;i<nums.size();i++){helper.push(nums[i]);}
        for(int i=1;i<k;i++){helper.pop();}
        return helper.top();
    }
};
