class Solution {
public:
    bool ispossible(string s,string p,vector<int>removable,int index){
        vector<bool> removed(s.size(),false);
        for(int i=0;i<=index;i++){
            removed[removable[i]]=true;
        }
        string newstr="";
        for(int i=0;i<s.size();i++){
            if(!(removed[i]))newstr+=s[i];
        }
        int i=0,j=0;
        while(i<newstr.size() && j<p.size()){
            if(newstr[i]==p[j]){
                j++;
            }
            i++;
        }
        return j==p.size();
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int low=0;
        int high=removable.size()-1;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ispossible(s,p,removable,mid)){
                low=mid+1;
                ans=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};