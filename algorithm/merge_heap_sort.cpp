#include <iostream>
#include <vector>

// merge sort
void merge_sort(std::vector<int>& nums, int lo, int hi) {
    if (lo >= hi) {
        return;
    }

    int mid = lo + (hi-lo) / 2;

    merge_sort(nums, lo, mid);
    merge_sort(nums, mid+1, hi);
    
    merge(nums, lo, mid, hi);
}

void merge(std::vector<int>& nums, int lo, int mid, int hi) {
    std::vector<int> nums_left(nums.begin()+lo, nums.begin()+mid+1);
    std::vector<int> nums_right(nums.begin()+mid+1, nums.begin()+hi+1);

    int i = lo;
    int j = 0;
    int k = 0;

    while (j < nums_left.size() && k < nums_right.size()) {
        if (nums_left[j] < nums_right[k]) {
            nums[i++] = nums_left[j++];
        } else {
            nums[i++] = nums_right[k++];
        }
    }

    while (j < nums_left.size()) {
        nums[i++] = nums_left[j++];
    }

    while (k < nums_right.size()) {
        nums[i++] = nums_right[k++];
    }
}

// heap sort
void sink(std::vector<int>& arry, int k, int n) {
    while (true) {
        int left = k*2 + 1;
        int right = k*2 + 2;
        int max_idx = k;

        if (left <= n && arry[left] > arry[max_idx]) {
            max_idx = left;
        }

        if (right <= n && arry[right] > arry[max_idx]) {
            max_idx = right;
        }

        if (max_idx == k) {
            break;
        }

        std::swap(arry[max_idx], arry[k]);
        k = max_idx;
    }
}

void heap_sort(std::vector<int>& arry) {
    int n = arry.size() - 1;

    for (int i = n / 2; i >= 0; --i) {
        sink(arry, i, n);
    }

    while (n) {
        std::swap(arry[0], arry[n]);
        sink(arry, 0, --n);
    }
    
    std::cout << "hello heap sort: " << std::endl;
    for (auto i : arry) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

// quick sort
int partition(std::vector<int>& arry, int lo, int hi) {
    int i = lo;
    int j = hi + 1;

    int pivot = arry[lo];

    while (true) {
        while (i < hi && arry[++i] < pivot) {}
        while (j > lo && arry[--j] > pivot) {}

        if (i >= j) {
            break;
        }

        std::swap(arry[i], arry[j]);
    }

    std::swap(arry[lo], arry[j]);

    return j;
}

void q_sort(std::vector<int>& arry, int lo, int hi) {
    if (lo >= hi) {
        return;
    }

    int j = partition(arry, lo, hi);
    std::cout << "hello quick sort, partition j: " << j << std::endl;
    q_sort(arry, lo, j-1);
    q_sort(arry, j+1, hi);
}

void quick_sort(std::vector<int>& arry) {
    q_sort(arry, 0, arry.size() -1);
    
    std::cout << "hello quick sort: " << std::endl;
    for (auto i : arry) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arry = {4,5,7,6,2,1,9,10};
    
    //heap_sort(arry);
    quick_sort(arry);

    return 0;
}
