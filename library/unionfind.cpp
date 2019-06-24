// rank無しなのでlog n
class UnionFind{
public:
  vi data;

  UnionFind(int size){
    data.resize(size,-1);
    //rep(i, size) data[i] = -1;
  }

  bool unite(int x,int y){
    x = root(x);
    y = root(y);
    if(x != y){
      if(data[y] < data[x]) swap(x,y);
      data[x] += data[y];
      data[y] = x;
    }
    return x != y;
  }

  bool find(int x, int y){
    return root(x) == root(y);
  }

  int root(int x){ // どの集合か
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }

  int size(int x){
    return -data[root(x)];
  }

  void print(){
    cout << "i :\t";
    rep(i, data.size()) cout << i << "\t";
    cout << endl;
    cout << "data :\t";
    rep(i, data.size()) cout << root(i) << "\t";
    cout << endl;
  }
};
