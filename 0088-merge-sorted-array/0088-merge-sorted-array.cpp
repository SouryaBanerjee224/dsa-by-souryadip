class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0 ; 
        int j = 0 ; 
        int k = 0  ;
        vector<int> nums3(m+n);
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){ nums3[k] = nums1[i] ; i++ ; k++ ; }
            else {nums3[k] = nums2[j] ; j++ ; k++ ; }
        }
        if(j==n){
            for(int l = i ; l<m ; l++){ nums3[k] = nums1[l] ; k++ ; }
        }

        else if(i==m){
            for(int l = j ; l<n ; l++){ nums3[k] = nums2[l] ; k++ ; }
        }
        nums1 = nums3 ; 
        return ;
    }
};