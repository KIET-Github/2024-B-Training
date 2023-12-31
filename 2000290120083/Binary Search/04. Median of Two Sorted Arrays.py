# https://leetcode.com/problems/median-of-two-sorted-arrays/


class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        n1 = len(nums1); n2 = len(nums2)
        mid = (n1 + n2) // 2  
        i = 0; j = 0
        val, preVal = 0, 0
        
        for k in range(mid+1):
            if i < n1 and j < n2:
                if nums1[i] <= nums2[j]:
                    val = nums1[i]  
                    i += 1
                else:
                    val = nums2[j]
                    j += 1
            elif i < n1:
                val = nums1[i]
                i += 1
            else:
                val = nums2[j]
                j += 1
            
            if k == mid - 1:
                preVal = val
        
        if (n1+n2) % 2 == 0:
            return (val + preVal) / 2
        return float(val)
    
# Timw: O(N)
# Space: O(1)

