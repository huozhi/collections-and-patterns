/**
Excel中的行列数用A~Z 26个字母表示，A, B, C, D, …, Z, AA, AB, …, AZ, BA, BB, … 
分别表示10进制数1, 2, 3, 4, …, 26, 27, 28, …, 52, 53, 54…。

请实现2个函数decToExcel和excelToDec，将10进制数转换为Excel数，以及将Excel数转换为10进制数。

*/

//将十进制数转换为excel数
string decToExcel(int decNum) {
    string ans;
    while (decNum) {
        --decNum;
        ans.insert(ans.begin(), decNum % 26 + 'A');
        decNum /= 26;
    }
    return ans;
}

//将excel数转换为十进制数
int excelToDec(string excelNum) {
    int val = 0, factor = 1;
    for (int i = (int)excelNum.length() - 1; i >= 0 ; i--) {
        val += (excelNum[i] - 'A' + 1) * factor;
        factor *= 26;
    }
    return val;
}