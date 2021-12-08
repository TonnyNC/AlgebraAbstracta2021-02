#include <iostream>
#include <vector>

using namespace std;

vector<unsigned long long> eucExt(unsigned long long a, unsigned long long b)
{
    if (b == 0)
        return {a, 1, 0};

    auto temp = eucExt(b, a%b);
    return {
        temp[0],
        temp[2],
        temp[1] - temp[2] * (a / b)
    };
}

int main() {
  unsigned long long a, n;
  cout<<"Ingrese el modulo:  ";
  cin>>n;
  cout<<"Ingrese el valor para hallar su inversa modulo "<<n<< " : ";
  cin>>a;
  auto b = eucExt(a, n);

  if (b[0] != 1)
  {
      puts("No se encontró un inverso modular");
  }
  else
  {
      unsigned long long x = (b[1] % n + n) % n;
      cout<< "El inverso modular de " << a << " modulo " << n << " es: "<< x;
  }

	return 0;

} 