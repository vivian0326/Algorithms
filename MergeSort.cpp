#include<iostream>
using namespace std;

void Merge(int *arr, int l, int r){
    int len = r-l+1;
    int *subarr = new int [len];

    int mid = (l+r)/2;
    int i = 0, l_i = l, r_i = mid+1;
    while(l_i <= mid && r_i <= r){
        if(arr[l_i] <= arr[r_i]){
            subarr[i] = arr[l_i];
            l_i++;
        }
        else{
            subarr[i] = arr[r_i];
            r_i++;
        }
        i++;
    }

    for(;i < len;i++){
        if(l_i <= mid){
            subarr[i] = arr[l_i];
            l_i++;
        }
        else{
            subarr[i] = arr[r_i];
            r_i++;
        }
    }

    for(i = 0;i < len;i++){
        arr[l+i] = subarr[i];
    }

    delete subarr;
}

void MergeSort(int *arr, int l, int r){
    if(l < r){
        int mid = (l+r)/2;

        /*Sort the left and right subarray*/
        MergeSort(arr, l, mid);
        MergeSort(arr, mid+1, r);

        /*Merge the sorted left and right subarray*/
        Merge(arr, l, r);
    }
}

int main(){
    int n;
    int *arr;

    /*initial array length*/
    cout << "Array length : ";
    cin >> n;
    arr = new int [n];
    cout << "Elements : ";
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }

    /*Merge Sort*/
    MergeSort(arr, 0, n-1);

    cout << "Sorted array : ";
    for(int i = 0;i < n;i++){
        cout << arr[i] << " ";
    }

    delete arr;

    return 0;
}
