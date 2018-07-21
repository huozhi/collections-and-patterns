/**

给k个字符串，求出他们的最长公共前缀(LCP)

样例
在 "ABCD" "ABEF" 和 "ACEF" 中,  LCP 为 "A"

在 "ABCDEFG", "ABCEFG", "ABCEFA" 中, LCP 为 "ABC"

there may be some empty string in the set, take care!

*/


class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
     
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        string prefix;
        if (strs.empty()) return prefix;
        prefix = strs[0];
        int maxlen = prefix.length();
        for (int i = 1; i < strs.size(); i++) {
            int tmplen = 0;
            string &target = strs[i];
            if (target.empty()) return target;
            for (int j = 0; j < target.length(); j++) {
                if (prefix[j] == target[j])
                    ++tmplen;
                else {
                    maxlen = min(maxlen, tmplen);
                    break;
                }
            }
        }
        return prefix.substr(0, maxlen);
        
    }
};
