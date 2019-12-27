#include<iostream>
#include<queue>
using namespace std;

class Graph{
public:
    Graph();

    void Input();
    void BFS(int start);
    void DFS(int start);

private:
    int vertexNum, edgeNum;
    int **AdjList;

    void DFS(int start, bool *tag);
};

int main(){
    Graph g;

    g.Input();

    cout << "Breadth-first search" << endl;
    g.BFS(0);
    cout << "Depth-first search" << endl;
    g.DFS(0);

    return 0;
}

Graph::Graph(){
    vertexNum = 0;
    edgeNum = 0;
    AdjList = NULL;
}

void Graph::Input(){
    cout << "Input number of vertices : ";
    cin >> vertexNum;
    cout << "Input number of edges : ";
    cin >> edgeNum;

    AdjList = new int* [vertexNum];
    for(int i = 0;i < vertexNum;i++){
        AdjList[i] = new int [vertexNum];

        for(int j= 0;j < vertexNum;j++){
            AdjList[i][j] = 0;
        }
    }

    int u, v, w;
    cout << "Input connected vertices(u, v, w):" << endl;
    for(int i = 0;i < edgeNum;i++){
        cin >> u >> v >> w;
        if(AdjList[u][v] < w) AdjList[u][v] = w;
    }
}

void Graph::BFS(int start){
    bool *visited = new bool [vertexNum];
    for(int i = 0;i < vertexNum;i++){
        visited[i] = false;
    }

    queue<int> q;
    q.push(start);

    int u;
    while(!q.empty()){
        u = q.front();
        q.pop();
        visited[u] = true;

        for(int i = 0;i < vertexNum;i++){
            if(!visited[i] && AdjList[u][i] != 0){
                q.push(i);
            }
        }

        cout << u << " ";
    }

    cout << endl;
}

void Graph::DFS(int start){
    bool *tag = new bool [vertexNum];
    for(int i = 0;i < vertexNum;i++){
        tag[i] = false;
    }

    DFS(start, tag);
    cout << endl;
}

void Graph::DFS(int start, bool* tag){
    cout << start << " ";
    tag[start] = true;

    for(int i = 0;i < vertexNum;i++){
        if(AdjList[start][i] && !tag[i]){
            DFS(i, tag);
        }
    }
}
