/*
Given an array of n objects with k different colors (numbered from 1 to k), sort them so that objects of the same color are adjacent, with the colors in the order 1, 2, ... k.

注意
You are not suppose to use the library's sort function for this problem.

样例
GIven colors=[3, 2, 2, 1, 4], k=4, your code should sort colors in-place to [1, 2, 2, 3, 4]. 

挑战
A rather straight forward solution is a two-pass algorithm using counting sort. That will cost O(k) extra memory.

Can you do it without using extra memory?

标签 Expand 
Sort Two Pointers

*/

class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        // use bucket sort, couter is negative
        for (int i = 0; i < colors.size(); i++) {
            while (colors[i] > 0) {
                int num = colors[i];
                // num -1 is the position of bucket
                if (colors[num - 1] > 0) {
                    // bucket is not a counter
                    colors[i] = colors[num - 1];
                    colors[num - 1] = -1;
                }
                else {
                    // bucket is now a counter
                    colors[num - 1]--;
                    colors[i] = 0;
                }
            }
        }
        
        int j = (int)colors.size() - 1;
        
        for (int i = k - 1; i >= 0; i--) {
            if (colors[i] == 0) continue;
            int cnt = -colors[i];
            
            while (cnt--) {
                colors[j--] = i + 1;
            }
        }
    }
};
