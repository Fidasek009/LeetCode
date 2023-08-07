#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void mergeSort(vector<int> &arr, int low, int high){
        // range has only 1 element
        if(low+1 == high) return;
        // calculate mid
        int mid = low + (high - low)/2;

        // split
        mergeSort(arr, low, mid);
        mergeSort(arr, mid, high);

        vector<int> a(arr.begin()+low, arr.begin()+mid);
        vector<int> b(arr.begin()+mid, arr.begin()+high);
        // merge
        int i = low;
        int j = mid;
        int k = low;
        while(i < mid && j < high) arr[k++] = (a[i] < b[j]) ? a[i++] : b[j++];
        while(i < mid) arr[k++] = a[i++];
        while(j < high) arr[k++] = b[j++];
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size());
        return nums;
    }
};

int main()
{
    vector<int> a = {5,2,3,1};
    Solution s = Solution();
    auto res = s.sortArray(a);
    for(int x : res) cout << x << ", ";
    return 0;
}