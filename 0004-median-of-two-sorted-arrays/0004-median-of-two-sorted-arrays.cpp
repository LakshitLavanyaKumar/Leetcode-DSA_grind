class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       
         int n1 = nums1.size();
    int n2 = nums2.size();

    // Ensure nums1 is the smaller array
    if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

    int low = 0;
    int high = n1;
    int left = (n1 + n2 + 1) / 2;

    while (low <= high) {
        int mid1 = (low + high) >> 1; // mid point of nums1
        int mid2 = left - mid1; // mid point of nums2 to partition both arrays equally

        // Initialize left and right elements
        int l1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
        int l2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
        int r1 = (mid1 < n1) ? nums1[mid1] : INT_MAX;
        int r2 = (mid2 < n2) ? nums2[mid2] : INT_MAX;

        if (l1 <= r2 && l2 <= r1) {
            // Check if the total number of elements is even
            if ((n1 + n2) % 2 == 0) {
                return ((double)max(l1, l2) + min(r1, r2)) / 2.0;
            } else {
                return max(l1, l2);
            }
        } else if (l1 > r2) {
            high = mid1 - 1;
        } else {
            low = mid1 + 1;
        }
    }
    return 0;
    }
};