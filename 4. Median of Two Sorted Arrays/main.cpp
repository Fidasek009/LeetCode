#include <vector>
#include <iostream>

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    bool odd = true;
    int length = nums1.size() + nums2.size();
    std::vector<int> sorted;

    if(length%2 == 0) odd = false;

    int mid = length/2 + odd - 1;

    // return median if one array is empty
    if(nums1.size() == 0){
        if(odd) return nums2[mid];
        else return (nums2[mid] + nums2[mid+1])/2.0;
    }
    else if(nums2.size() == 0){
        if(odd) return nums1[mid];
        else return (nums1[mid] + nums1[mid+1])/2.0;
    }

    // merge the two arrays until the mid point (pointless to merge further)
    for(int i = 0; i < mid + 2; i++){
        if(nums1[0] < nums2[0]){
            sorted.push_back(nums1[0]);
            nums1.erase(nums1.begin());
        }
        else{
            sorted.push_back(nums2[0]);
            nums2.erase(nums2.begin());
        }

        if(nums1.size() == 0){
            sorted.insert(sorted.end(), nums2.begin(), nums2.begin()+mid-i+1);
            break;
        }
        else if(nums2.size() == 0){
            sorted.insert(sorted.end(), nums1.begin(), nums1.begin()+mid-i+1);
            break;
        }
        
    }

    // return median of sorted array
    if(odd) return sorted[mid];
    else return (sorted[mid] + sorted[mid+1])/2.0;
}


int main(){
    std::vector<int> num1 = {1,3};
    std::vector<int> num2 = {2,7};

    double median = findMedianSortedArrays(num1, num2);

    std::cout << median;
}