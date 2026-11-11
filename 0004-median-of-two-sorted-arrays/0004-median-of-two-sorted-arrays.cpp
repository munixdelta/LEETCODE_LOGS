class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<int> newarr;
        int i=0,j=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                newarr.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i]>nums2[j]){
                newarr.push_back(nums2[j]);
                j++;
            }
            else{
                newarr.push_back(nums1[i]);
                newarr.push_back(nums2[j]);
                i++;
                j++;
            }
        }
        while(i<m){
            newarr.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            newarr.push_back(nums2[j]);
            j++;
        }
        double ans=-1;
        if(newarr.size()%2!=0){
            ans=newarr[newarr.size()/2];
        }
        else{
            ans=(newarr[newarr.size()/2-1]+newarr[newarr.size()/2])/2.0;
        }
        return ans;
    }
};