#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 二分查找
 */
int binarySearch(int nums[], int len, int target) {
    int low = 0;
    int high = len - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int nums[]  = {1, 3, 4, 6, 7, 9, 11, 12};
    cout << binarySearch(nums, sizeof(nums) / sizeof(int), 11);
    return 0;
}
