/*

Binary search is a famous question in algorithm.

For a given sorted array (ascending order) and a target number, 
find the first index of this number in O(log n) time complexity.

If the target number does not exist in the array, return -1.

样例
If the array is [1, 2, 3, 3, 4, 5, 10], for given target 3, return 2.

挑战
If the count of numbers is bigger than MAXINT, can your code work properly?

标签 Expand 

*/

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        int i = 0, j = (int)array.size() - 1;
        while (i < j) {
            int mid = i + (j - i) / 2;
            if (array[mid] >= target) {
                j = mid;
            }
            else {
                i = mid + 1;
            }
        }
        if (array[i] == target) {
            return i;
        }
        return -1;
    }
};
