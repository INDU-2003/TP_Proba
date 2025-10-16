class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return solve(nums1,nums2,nums1.size(),nums2.size());
    }
    double solve(vector<int>& a, vector<int>& b, int m, int n){
        if(m>n) return solve(b,a,n,m);
        int s=0;
        int e=m;        
        while(s<=e){
            int c1=(s+e)/2;
            int c2=(m+n+1)/2-c1;
            int l1=(c1-1<0)? INT_MIN : a[c1-1];
            int r1=(c1==m)? INT_MAX : a[c1];
            int l2=(c2-1<0)? INT_MIN : b[c2-1];
            int r2=(c2==n)? INT_MAX : b[c2];
            if(l1<=r2 and l2<=r1){
            if((m+n)%2==0) return (max(l1,l2)+min(r1,r2))/2.0;
            else return max(l1,l2);
        }
        else if (l2>r1) s=c1+1;
        else e=c1-1;
    }
    return -1;
    }
};

// TC => O(log(min(m,n)))
// SC => O(1)
