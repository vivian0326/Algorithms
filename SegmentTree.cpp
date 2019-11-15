#include<iostream>
using namespace std;

class SegmentTree{
public:
    int n;
    int *arr;

    SegmentTree();

    /*initial array*/
    void InputNum(int n);

    /*modify num[idx] to val*/
    void update(int idx, int val);

    /*return the maximum element in [left, right]*/
    int FindMax(int left, int right);

private:
    int *index, *tree;


    int ParentTreeIndex(int idx);
    /*return the children index of the given element*/
    int LeftTreeIndex(int idx);
    int RightTreeIndex(int idx);

    /*return num[idx] index in the tree
    since element of num are on the leaf of the tree*/
    int GetIndex(int numidx);

    /*construct segment tree*/
    int BuildTree(int left, int right, int TreeIdx);

    /*update the internal node of the tree*/
    void UpdateTree(int idx);

    /*return the maximum value of the given range*/
    int FindMax(int idx, int TreeLeft, int TreeRight, int left, int right);
};

int main(){
    int n, m;
    SegmentTree seg;

    cout << "Number of array : ";
    cin >> n;
    cout << "Number of query : ";
    cin >> m;
    seg.InputNum(n);

    int i, j, k;
    while(m--){
        cin >> i >> j >> k;

        switch(i){
        case 1:
            seg.update(j, k);
            break;
        case 2:
            cout << seg.FindMax(j, k) << endl;;
            break;
        default:
            break;
        }
    }

    return 0;
}

SegmentTree::SegmentTree(){
    n = 0;
    arr = NULL;
    index = NULL;
    tree = NULL;
}

void SegmentTree::InputNum(int n){
    this->n = n;
    arr = new int [n];
    index = new int [n];
    tree = new int [4*n];

    cout << "Array Elements : ";
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }

    BuildTree(0, n-1, 0);
}

int SegmentTree::ParentTreeIndex(int idx){
    return (idx-1)/2;
}

int SegmentTree::LeftTreeIndex(int idx){
    return 2*idx+1;
}

int SegmentTree::RightTreeIndex(int idx){
    return 2*idx+2;
}

int SegmentTree::BuildTree(int left, int right, int TreeIdx){
    if(left == right){
        tree[TreeIdx] = arr[left];
        index[left] = TreeIdx;
        return arr[left];
    }

    int mid = (left+right)/2;
    int LeftChild = BuildTree(left, mid, LeftTreeIndex(TreeIdx));
    int RightChild = BuildTree(mid+1, right, RightTreeIndex(TreeIdx));

    tree[TreeIdx] = max(LeftChild, RightChild);
    return tree[TreeIdx];
}

int SegmentTree::GetIndex(int numidx){
    return index[numidx];
}

void SegmentTree::update(int idx, int val){
    int TreeIdx = GetIndex(idx);

    arr[idx] = val;
    tree[TreeIdx] = val;
    UpdateTree(ParentTreeIndex(TreeIdx));
}

void SegmentTree::UpdateTree(int idx){
    int LeftChild = tree[LeftTreeIndex(idx)];
    int RightChild = tree[RightTreeIndex(idx)];

    tree[idx] = max(LeftChild, RightChild);
    if(idx != 0) UpdateTree(ParentTreeIndex(idx));
}

int SegmentTree::FindMax(int left, int right){
    return FindMax(0, 0, n-1, left, right);
}

int SegmentTree::FindMax(int idx, int TreeLeft, int TreeRight, int left, int right){
    if(TreeLeft == left && TreeRight == right){
        return tree[idx];
    }

    int mid = (TreeLeft+TreeRight)/2;
    if(left >= (mid+1)){
        return FindMax(RightTreeIndex(idx), mid+1, TreeRight, left, right);
    }
    else if(right <= mid){
        return FindMax(LeftTreeIndex(idx), TreeLeft, mid, left, right);
    }

    int LeftSubtree = FindMax(LeftTreeIndex(idx), TreeLeft, mid, left, mid);
    int RightSubtree = FindMax(RightTreeIndex(idx), mid+1, TreeRight, mid+1, right);

    return max(LeftSubtree, RightSubtree);
}
