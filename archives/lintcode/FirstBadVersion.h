/*
The code base version is an integer and start from 1 to n. One day, someone commit a bad version in the code case, so it caused itself and the following versions are all failed in the unit tests.
You can determine whether a version is bad by the following interface: 

Java:
    public VersionControl {
        boolean isBadVersion(int version);
    }
C++:
    class VersionControl {
    public:
        bool isBadVersion(int version);
    };
Python:
    class VersionControl:
        def isBadVersion(version)

Find the first bad version.
注意
You should call isBadVersion as few as possible. 

Please read the annotation in code area to get the correct way to call isBadVersion in different language. For example, Java is VersionControl.isBadVersion.

样例
Given n=5

Call isBadVersion(3), get false

Call isBadVersion(5), get true

Call isBadVersion(4), get true

return 4 is the first bad version

挑战
Do not call isBadVersion exceed O(logn) times.

标签 Expand 
Binary Search LintCode Copyright

*/

class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        int i = 1, j = n, mid;
        int bad = n;
        while (i < n) {
            mid = (i + j) / 2;
            if (!VersionControl::isBadVersion(mid)) {
                i = mid + 1;

            }
            else {
                if (mid == bad) break;
                bad = mid;
                j = mid;
            }
        }
        if ((i <= bad) && VersionControl::isBadVersion(i))
            return i;
        return bad;
    }
};
