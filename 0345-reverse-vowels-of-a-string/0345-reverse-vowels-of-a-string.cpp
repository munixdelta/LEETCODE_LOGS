class Solution {
public:
    string reverseVowels(string s) {
        vector<pair<char,int>> vowel;
        unordered_set<char> v={'a','A','e','E','i','I','o','O','u','U'};
        for(int i=0;i<s.size();i++){
            if(v.find(s[i])!=v.end())
                vowel.push_back({s[i],i});
        }
        int x=0,y=vowel.size()-1;
        while(x<=y){
            int index1=vowel[x].second;
            int index2=vowel[y].second;
            swap(s[index1],s[index2]);
            x++;
            y--;
        }
        return s;
    }
};