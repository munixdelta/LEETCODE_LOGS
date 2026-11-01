class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int left=0;
        int right=arr.size()-1;
        while(right-left+1>k){
            if(abs(arr[left]-x)<abs(arr[right]-x)){
                right--;
            }
            else if(abs(arr[left]-x)==abs(arr[right]-x) && arr[left]<arr[right]){
                right--;
            }
            else{
                left++;
            }
        }
        for(int i=left;i<=right;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};