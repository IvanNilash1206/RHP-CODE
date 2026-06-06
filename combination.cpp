#include <iostream>
using namespace std;

int main(){
  string s;
  cin>>s;
  int L = s.length();

  for(int ctr = 1;ctr<(1<<L);ctr++){
    string comb="";

    for(int sh=1;sh<L;sh++){
      if((ctr&(1<<sh))>0){
        comb+=s[sh];
      }
    }
    cout << comb<<endl;
  }
}
