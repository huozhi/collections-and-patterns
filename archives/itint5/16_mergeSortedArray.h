/*

有2个长度为n和m的有序的整型数组arr1和arr2，请将他们合并为一个n+m的有序数组。

注意：数组arr1包含足够的空间存放下n+m个元素，请直接将结果合并到数组arr1中。

*/

void mergeSortedArray(int arr1[], int arr2[], int n, int m) {
    int k = n + m - 1;
    int i = n-1, j = m-1;
    while (i>=0 && j>=0) {
        if (arr1[i] > arr2[j]) {
            arr1[k] = arr1[i];
            i--;
        }
        else {
            arr1[k] = arr2[j];
            j--;
        }
        k--;
    }
    while (i>=0) {
        arr1[k--] = arr1[i--];
    }
    while (j>=0) {
        arr1[k--] = arr2[j--];
    }
}