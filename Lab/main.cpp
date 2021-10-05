#include <iostream>

using namespace::std;

int euclides(int x,int y){
  if(!y){
    return x;
  }else{
    return euclides(y,x%y);
  }
}

int main()
{
  int x,y;
  cout << "Inserte los valores: " << endl;
  cout << "x: ";
  cin >> x;
  cout << "y: ";
  cin >> y;  
  cout << "MCD (euclides): " << euclides(x,y) << endl;
}