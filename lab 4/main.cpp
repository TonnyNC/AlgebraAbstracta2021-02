#include<bits/stdc++.h>

using namespace std;

bool ifPrimo(int n) { //Evalua si es primo o no
   if (n <= 1) return false;
   if (n <= 3) return true;
   if (n%2 == 0 || n%3 == 0) return false;
   for (int i=5; i*i<=n; i=i+6)
      if (n%i == 0 || n%(i+2) == 0)
         return false;
   return true;
}
int power(int x, int y, int p) { // Evaluara los numero primos en busca de sus potencias que componen el primo p
   int res = 1;
   x = x % p;
   while (y > 0){
      if (y & 1)
      res = (res*x) % p;
      y = y >> 1;
      x = (x*x) % p;
   }
   return res;
}
void generadorPrimos(unordered_set<int> &s, int n) { // Genera los numeros primos para evaluarlos luego
   while (n%2 == 0){
      s.insert(2);
      n = n/2;
   }
   for (int i {3}; i <= sqrt(n); i+=2){
      while (n%i == 0){
         s.insert(i);
         n = n/i;
      }
   }
   if (n > 2)
   s.insert(n);
}
int raicesPrimitivas(int n) { //Busca las raices primitivas del numero primo n y devuelve la menor
   unordered_set<int> s;
   if (ifPrimo(n)==false)
   return -1;
   int phi = n-1;
   generadorPrimos(s, phi);
   for (int r=2; r<n; r++){
      bool indicador = false;
      for (auto it = s.begin(); it != s.end(); it++){
         if (power(r, phi/(*it), n) == 1){
            indicador = true;
            break;
         }
      }
      if (indicador == false)
      return r;
   }
   return -1;
}
int main() {
   int n = 7;
   cout<<" Smallest primitive root of "<<n<<" is "<<raicesPrimitivas(n);
   return 0;
}