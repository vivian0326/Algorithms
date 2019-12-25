#include<iostream>
using namespace std;

struct Node{
    int parent;
    int children;
};

class DisjointSet{
public:
    int elementNum;
    Node *element;

    DisjointSet();

    /*Input elementNum and initialize the elements*/
    void SetInitialize();
    /*Merge two different sets that contain u and v*/
    void Merge(int u, int v);
    /*return the representation of the set that contains u*/
    int FindParent(int u);
};

int main(){
    DisjointSet ds;
    int edges, u, v;

    cout << "Input the number of element : ";
    ds.SetInitialize();
    cout << "Input the number of connection : ";
    cin >> edges;
    cout << "Input u, v which u, v are connected with each other :" << endl;
    cout << "(Index ranges from 0 to " << ds.elementNum-1 << ")" << endl;
    for(int i = 0;i < edges;i++){
        cin >> u >> v;
        ds.Merge(u, v);
    }

    for(int i = 0;i < ds.elementNum;i++){
        u = ds.FindParent(i);
        cout << "There are " << ds.element[u].children << " elements in the set with " << i << endl;
    }

    return 0;
}

DisjointSet::DisjointSet(){
    elementNum = 0;
    element = NULL;
}

void DisjointSet::SetInitialize(){
    cin >> elementNum;
    element = new Node [elementNum];
    for(int i = 0;i < elementNum;i++){
        element[i].parent = i;
        element[i].children = 0;
    }
}

void DisjointSet::Merge(int u, int v){
    int uParent = FindParent(u);
    int vParent = FindParent(v);

    if(uParent == vParent) return;

    /*Merge the smaller set into the other set*/
    if(element[uParent].children > element[vParent].children){
        element[vParent].parent = uParent;
        element[uParent].children += (element[vParent].children+1);
    }
    else{
        element[uParent].parent = vParent;
        element[vParent].children += (element[uParent].children+1);
    }
}

int DisjointSet::FindParent(int u){
    if(element[u].parent == u){
        return u;
    }

    element[u].parent = FindParent(element[u].parent);
    return element[u].parent;
}
