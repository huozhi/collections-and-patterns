/*
Given string A representative a positive integer which has N digits, remove any k digits of the number, the remaining digits are arranged according to the original order to become a new positive integer. 
N <= 240 and k <=N, 
样例
Given an integer A = 178542, k = 4

return a string "12"
*/

class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        // wirte your code here
        if (A.empty() || k == A.length()) return 0;
        if (k == 0) return A;
        string ans; // monotonous stack
        int i = 0;
        while (k && i < A.length()) {
            if (!ans.empty()) {
                // pop
                if (k && A[i] >= ans.back()) {
                    ans.push_back(A[i]);
                    i++;
                }
                else if (k && A[i] < ans.back()) {
                    ans = ans.substr(0, ans.length()-1); // pop
                    k--;
                }
            }
            else {
                ans.push_back(A[i]);
                i++;
            }
        }
        if (i < A.length()) ans += A.substr(i);
        ans = ans.substr(0, ans.length() - k);
        int j = 0;
        while (ans[j] == '0') j++;
        return ans.substr(j);
    }
};

