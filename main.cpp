#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <fstream>
#include <sstream>

using namespace std;

size_t len;
vector<size_t>* adj;

void ReadD(){
  ifstream file("input.txt");
  file >> len;
  adj = new vector<size_t>[len];
  size_t i=0;
  int tmp = 0;
  while(!file.eof() && len -1 !=i){
    file >> i;
    while(file.peek() != '\n'){
      file >> tmp;
      adj[i].push_back(tmp);
      if(file.eof())
        break;
      }
    }

  }

void BFS(size_t item){

  vector<int> D(len+1, -1);
  vector<int> prev(len+1, -1);
  D[0] = 0;
  queue<int> Q;
  Q.push(0);
  while(!Q.empty()){
    int u = Q.front();
    Q.pop();
    for(auto v : adj[u])
      if(D[v] == -1){
        prev[v] = u;
        D[v]= D[u]+1;
        Q.push(v);
      }
  }

  vector<int> ans;
  int curr = item;
  size_t cnt =0;
  while(curr != -1){
    cnt++;
    ans.push_back(curr);
    curr = prev[curr];
  }
  for (int i = cnt-1; 0 <= i; --i) {
    cout << " -> " << ans[i];
  }
  cout << endl;
}
int main() {
  setlocale(LC_ALL, "RUS");
  ReadD();
  BFS(2);
  delete[] adj;
  return 0;
}
