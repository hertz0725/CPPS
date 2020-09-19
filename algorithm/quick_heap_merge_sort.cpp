#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arry, int lo, int hi);
void qsort(vector<int> &arry, int lo, int hi);
void qsort_3way(vector<int> &arry, int lo, int hi);
void sink(vector<int> &arry, int k, int N);
void heap_sort(vector<int> &arry);
void merge_sort(vector<int> &array, int lo, int hi);
void merge(vector<int> &array, int lo, int mid, int hi);

int main() {
    vector<int> v = {8, -4, -45, -1, -1, -1, -1,
        12, -12, -12, -12, -12, 12, 12};

    merge_sort(v,0,v.size()-1);
    //qsort(v, 0, v.size()-1);
    //qsort_3way(v, 0, v.size()-1);
    //heap_sort(v);

    for (auto x : v) {
        cout<<x<<" ";
    }
    cout << endl;

    return 0;
}

void qsort(vector<int> &arry, int lo, int hi) {
    //递归出口 && 注意是等于
    if(lo >= hi) { return; }

    //获取j的位置，分区
    int j = partition(arry, lo, hi); 

    qsort(arry, lo, j - 1);  //左区分治
    qsort(arry, j + 1, hi);  //右区分治
}

int partition(vector<int> &arry, int lo, int hi) {
    int i = lo, j = hi + 1;
    int pivot = arry[lo];

    while (true) {
        while (j > lo && arry[--j] > pivot ) {} //从后面找比pivot小的元素
    
        while (i < hi && arry[++i] < pivot ) {} //从前面找比pivot大的元素

        if (i >= j) { break; } //注意是等于号，break

        swap(arry[i], arry[j]);
    }

    swap(arry[lo], arry[j]); //确定j的位置

    return j;
}

void qsort_3way(vector<int> &arry, int lo, int hi) {
    if(lo >= hi) return;

    int lt = lo, i = lo + 1, gt = hi;
    int pivot = arry[lo];

    while (i <= gt) {
        if (arry[i] < pivot) {
            //i++, 应为 lt->pivot, 交换后lt++ -> pivot, i++处理新数
            swap(arry[lt++], arry[i++]); 
        } else if (arry[i] > pivot) {
            //注意i不变，因为从后面换过来，不知道大小 
            swap(arry[gt--], arry[i]); 
        } else {
            i++;
        }
    }

    //[lo..lt-1] < pivot
    qsort_3way(arry, lo, lt - 1);

    //[gt+1..hi] > pivot, [lt..gt]==pivot
    qsort_3way(arry, gt + 1, hi); 
}

void heap_sort(vector<int> &arry) {
    int n = arry.size() - 1; // n为最后一个下标 [0..n]上操作

    for (int k = n / 2; k >= 0; k--) {
        sink(arry, k, n);
    }

    while (n > 0) {
        swap(arry[n--], arry[0]);
        sink(arry, 0, n);
    }

}

void sink(vector<int> &arry, int k, int n) {
    // 数组为[0..n]
    while (2*k + 1 <= n) {
        int j = 2*k + 1;
        if (j < n && arry[j] < arry[j + 1]) { j++; }
        
        if (arry[k] >= arry[j]) { break; }

        swap(arry[k], arry[j]);

        k = j; //继续下沉
    }
}

void merge_sort(vector<int> &array, int lo, int hi) {
    if (lo >= hi) { return; }

    int mid = lo + (hi-lo) / 2;

    merge_sort(array, lo, mid);
    merge_sort(array, mid + 1, hi);
    merge(array, lo, mid, hi);
}


void merge(vector<int> &array, int lo, int mid, int hi) {
    vector<int> aux(array);
    int i = lo, j = mid + 1;

    for(int k = lo; k <= hi; k++) {
        if (i > mid) {
            array[k]=aux[j++];
        } else if (j > hi) {
            array[k]=aux[i++];
        } else if (aux[i] < aux[j]) {
            array[k]=aux[i++];
        } else {
            array[k]=aux[j++];
        }
    }
}
