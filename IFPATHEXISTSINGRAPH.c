int pa[200001];
int find(int x){
    while (x!=pa[x]){
        pa[x]=pa[pa[x]];
        x=pa[x];
    }
    return x;
}
void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x!=y)pa[y]=x;
}
bool validPath(int n, int** restrict edges, int edgesSize, int* edgesColSize, int source, int destination) {
    for(int i=0;i<n;i++)pa[i]=i;
    for(int i=0;i<edgesSize;i++){
        unite(edges[i][0],edges[i][1]);
    }
    return find(source)==find(destination);
}
