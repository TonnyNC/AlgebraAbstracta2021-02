#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int gcd(int a, int b) {
   int t;
   while(1) {
      t= a%b;
      if(t==0)
      return b;
      a = b;
      b= t;
   }
}

int exp_modular(int base, int exp, int mod)
{
    int x = 1;
    base %= mod;
    while (exp>0) {
        if (exp & 1){x = (x%mod * base%mod) % mod;}
        exp >>= 1;
        base = (base%mod * base%mod)%mod;
    }

    return x;
}

vector<double> rsa(){
  double p = 3;
  double q = 11;
  double n=p*q;
  double track;
  double phi= (p-1)*(q-1);

  double e=7;

  while(e<phi) {
    track = gcd(e,phi);
    if(track==1)
        break;
    else
        e++;
  }
  double d1=1/e;
  double d=fmod(d1,phi);
  cout<<"p = "<<p<<endl;
  cout<<"q = "<<q<<endl;
  cout<<"n = pq = "<<n<<endl;
  cout<<"phi = "<<phi<<endl;
  cout<<"e = "<<e<<endl;
  cout<<"d = "<<d<<"\n\n\n";

  return {n,e,d};
}

int main() {

  vector<double> v_ = rsa();

  double tabla[2][int(v_[0])];

  cout<<"Tabla: "<< endl;

  for(int m{0}; m<v_[0]; m++){
    int c = exp_modular(m, v_[1], v_[0]);
    std::cout << m << " : " << c << "\n";
  }

  
   
} 
