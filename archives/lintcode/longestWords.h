/**

给一个词典，找出其中所有最长的单词。

样例
在词典

{
  "dog",
  "google",
  "facebook",
  "internationalization",
  "blabla"
}
中, 最长的单词集合为 ["internationalization"]

在词典

{
  "like",
  "love",
  "hate",
  "yes"
}
中，最长的单词集合为 ["like", "love", "hate"]

挑战
遍历两次的办法很容易想到，如果只遍历一次你有没有什么好办法？

*/

class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        vector<string> res;
        for (string& s : dictionary) {
            if (res.empty() || s.length() == res.back().length()) {
                res.push_back(s);
            }
            else if (s.length() > res.back().length()) {
                res.clear();
                res.push_back(s);
            }
        }
        return res;
    }
};
