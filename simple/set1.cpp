class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s,re;
        for(int i=0;i<nums1.size();i++)
            s.insert(nums1[i]);
        for(int i=0;i<nums2.size();i++)
            if(s.count(nums2[i]))
                re.insert(nums2[i]);
        vector<int> ans(re.begin(),re.end());
        return ans;
    }
};
