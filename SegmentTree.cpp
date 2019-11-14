#include<iostream>
using namespace std;

class SegmentTree{
public:
    int n;
    int *num;

    SegmentTree();

    /*initial array*/
    void InputNum(int n);

    /*modify num[idx] to val*/
    void update(int idx, int val);

    /*return the maximum element in [left, right]*/
    int FindMax(int left, int right);

private:
    int *index, *tree;

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


    return 0;
}
