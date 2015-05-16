#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

class Bitmap {
private:
    vector<char> buffer;
    static const int bytesize;
public:

    Bitmap(int *arr, int len) {
        int maxbytes = 1;
        for (int i = 0; i < len; i++)
            while (arr[i] >= maxbytes * Bitmap::bytesize)
                maxbytes++;
        buffer.resize(maxbytes);
        for (int i = 0; i < len; i++) {
            set_bit(arr[i]);
        }
    }

    Bitmap(vector<int> arr) {
        int maxbytes = 1;
        for (size_t i = 0; i < arr.size(); i++)
            while (arr[i] >= maxbytes * Bitmap::bytesize)
                maxbytes++;
        buffer.resize(maxbytes);
        for (size_t i = 0; i < arr.size(); i++) {
            set_bit(arr[i]);
        }
    }

    void set_bit(int val) {
        int offset = val / Bitmap::bytesize;
        val -= offset * Bitmap::bytesize; // faster mod
        buffer[offset] |= (0x01 << (val % Bitmap::bytesize));

    }

    bool operator[](int val) {
        return has_value(val);
    }

    bool has_value(int val) {
        int offset = val / Bitmap::bytesize;
        val -= offset * Bitmap::bytesize;
        return buffer[offset] & (0x01 << (val % Bitmap::bytesize));
    }
};

const int Bitmap::bytesize = 8;


int main() { _
    vector<int> A = {1, 10, 12, 23, 5, 45, 234, 252, 123};
    vector<int> B = {1, 10, 12, 123, 52, 100, 130, 5};
    vector<int> &big = (B.size() < A.size()) ? A : B;
    vector<int> &small = (B.size() < A.size()) ? B : A;
    Bitmap bm(small);
    vector<int> intersction;
    for (int i = 0; i < big.size(); i++) {
        if (bm[ big[i] ]) {
            intersction.push_back(big[i]);
        }
    }
    for (int v : intersction) {
        cout << v << endl;
    }
    return 0;
}
