#include<iostream>
using namespace std;

class MinHeap{
public:
    int n;
    int *arr;

    MinHeap();

    /*give the number of array elements and input the array*/
    void Input();

    /*extract the min of the array, arr[0],
    and then do MinHeapify on the array with the remaining element*/
    int ExtractMin();

private:
    int len;

    /*return index of parent for the given index*/
    int Parent(int idx);
    /*return index of left child for the given index*/
    int LeftChild(int idx);
    /*return index of right child for the given index*/
    int RightChild(int idx);

    /*do MinHeapify on the initial array*/
    void BuildMinHeap();
    /*check the tree satisfies that the parent is smaller than its children,
    and call this function recursively to check all subtrees satisfy the condition*/
    void MinHeapify(int idx);
};

int main(){
    MinHeap arr;

    arr.Input();
    for(int i = 0;i < arr.n;i++){
        cout << arr.ExtractMin() << " ";
    }

    return 0;
}

MinHeap::MinHeap(){
    n = 0;
    arr = NULL;
    len = 0;
}

void MinHeap::Input(){
    cin >> n;
    len = n;
    arr = new int [n];

    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }

    BuildMinHeap();
}

int MinHeap::Parent(int idx){
    return (idx-1)/2;
}

int MinHeap::LeftChild(int idx){
    return 2*idx+1;
}

int MinHeap::RightChild(int idx){
    return 2*idx+2;
}

void MinHeap::BuildMinHeap(){
    int i = Parent(len-1);

    /*start from the internal node which has the largest index
    and thus the subtree has already been heapified*/
    for(;i >= 0;i--){
        MinHeapify(i);
    }
}

void MinHeap::MinHeapify(int idx){
    if(idx >= len) return;

    int MinIdx = idx;
    int left = LeftChild(idx), right = RightChild(idx);

    if(left < len && arr[left] < arr[MinIdx]){
        MinIdx = left;
    }
    if(right < len && arr[right] < arr[MinIdx]){
        MinIdx = right;
    }

    if(MinIdx != idx){
        swap(arr[MinIdx], arr[idx]);
        MinHeapify(MinIdx);
    }
}

int MinHeap::ExtractMin(){
    int rtn = arr[0];

    swap(arr[0], arr[len-1]);
    len--;
    MinHeapify(0);
    return rtn;
}
