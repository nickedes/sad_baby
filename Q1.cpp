#include <bits/stdc++.h>
using namespace std;

class Complex
{   public:
    int real;
    int imag;
    
    Complex()//default constructor
    {   this->real=0;
        this->imag=0;
    }
    Complex(int real, int imag)//making a complex number
    {   this->real=real;
        this->imag=imag;
    }
    Complex operator + (Complex const &b)//add 2 complex numbers
    {   Complex c;
        c.real=real+b.real;
        c.imag=imag+b.imag;
        return c;
    }
    Complex& operator * (Complex const &b)//multiply 2 complex numbers
    {   int temp;
        temp=((real * b.real)-(imag * b.imag));
        imag=((real * b.imag)+(imag * b.real));
        real=temp;
        return *this;
    }
    operator float() const//cast into float form as per c part
    {   float i=0;
        float s=real/abs(real);
        i+=abs(real); //real part will retain it's sign that is -4+2i will become -4.2
        if(imag==0)
        return i*s;
        
        int digits =log10(abs(imag))+1;//incase imaginary part is negative we will ignore that like for 2-3i we will show 2.3
        float temp=(float)(abs(imag))/(float)pow(10,digits);//incase imaginary part has zero behind it, we will ommit them like for 2+10i we will show 2.1
        i+=temp;
        return i*s;
    }
};

int main()
{   int x1,y1,x2,y2;
    cout<<"Enter Real and Imaginary parts of the first Complex Number : ";
    cin>>x1>>y1;
    cout<<"\nEnter Real and Imaginary parts of the second Complex Number : ";
    cin>>x2>>y2;
    Complex a(x1,y1);
    Complex b(x2,y2);
    Complex c=a+b;
    Complex t=a;
    a =a* b;
    cout<<"a.) Result for Addition = "<<c.real<<"+("<<c.imag<<")i\n";
    cout<<"b.) Result for Multiplication = "<<a.real<<"+("<<a.imag<<")i\n";
    float f=t;
    cout<<"c.) Casting first Complex Number to a float variable = "<<t<<"\n";
    return 0;
}