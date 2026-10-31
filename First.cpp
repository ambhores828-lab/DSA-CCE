// Programe for operator overloading
#include <iostream>
using namespace std;

class Complex
{
private:
  float real;
  float imag;

public:
  // Default constructor in program
  Complex()
  {
    real = 0;
    imag = 0;
  }

  // Parameterized constructor in programe
  Complex(float r, float i)
  {
    real = r;
    imag = i;
  }

  // Display function
  void display()
  {
    cout << real << " + " << imag << "i" << endl;
  }

  // Addition
  Complex operator+(Complex c2)
  {
    return Complex(real + c2.real, imag + c2.imag);
  }

  // Subtraction
  Complex operator-(Complex c2)
  {
    return Complex(real - c2.real, imag - c2.imag);
  }

  // Multiplication
  Complex operator*(Complex c2)
  {
    float r = real * c2.real - imag * c2.imag;
    float i = real * c2.imag + imag * c2.real;

    return Complex(r, i);
  }
};

int main()
{
  Complex c1(3, 2);
  Complex c2(1, 7);

  cout << "First Complex Number: ";
  c1.display();

  cout << "Second Complex Number: ";
  c2.display();

  Complex sum = c1 + c2;
  cout << "Addition: ";
  sum.display();

  Complex diff = c1 - c2;
  cout << "Subtraction: ";
  diff.display();

  Complex prod = c1 * c2;
  cout << "Multiplication: ";
  prod.display();

  return 0;
}

// OUTPUT:
// PS D:\Atharva_Dighe> cd "d:\Atharva_Dighe\" ; if ($?) { g++ First.cpp -o First } ; if ($?) { .\First }
// First Complex Number: 3 + 2i
// Second Complex Number: 1 + 7i
// Addition: 4 + 9i
// Subtraction: 2 + -5i
// Multiplication: -11 + 23i
// PS D:\Atharva_Dighe> 