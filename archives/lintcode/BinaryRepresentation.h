/*

给定一个数(如十进制数3.72),我们用字符串来表示这个数,同时我们也用字符串来表示二进制。
如果在不能用二进制来准确地表示这个数，则返回“ERROR”

样例
n = 3.72, return ERROR

n = 3.5, return 11.1

*/
class Solution {
public:

    /**
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
    string binaryRepresentation(string n) {
        // wirte your code here
        string intp, decp; // int part, decimal part
        int intv; // int value
        double decv; // decimal value
        string err = "ERROR";
        size_t dot = n.find('.');
        if (dot != string::npos) {
            intv = atoi(n.substr(0, dot).c_str()); // if use std::stoi will throw error
            decv = stod(n.substr(dot));
        }
        else {
            intv = stoi(n);
        }

        if (intv > 0) {
            while (intv > 0) {
                char c = (intv & 1) + '0'; // key point, + is higher than &
                intv >>= 1;
                intp.insert(intp.begin(), c);
            }
        }
        else intp = "0";

        while (decv > 0) {
            if (decp.length() > 32) return err;
            decv *= 2;
            char getInt = (int)(decv) + '0';
            decp += getInt;
            decv -= (double)(getInt - '0');
        }

        return !decp.empty() ? intp + '.' + decp : intp;
    }
};
