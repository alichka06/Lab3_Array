#include <bits/stdc++.h>
#include "lab3_3.h"

using namespace std;

void Array::reset()
{
    int *t=new int [lenMax*2];
    for (int i=0; i<len; ++i)
        t[i]=p[i];
    delete [] p;
    lenMax+=10000;
    /*p=new int [lenMax];
    for (int i=0; i<len; ++i)
        p[i]=t[i];
    delete [] t;*/
    p=t;
}
Array::Array(): p(nullptr), lenMax(0), len(0){};
Array::Array(int n): p(new int [n+1]), lenMax(n+1), len(n)
{
    srand(time(NULL));
    for (int i=0; i<n; i++)
        p[i]=int (rand()*99/RAND_MAX);
}
Array::~Array()
{
    if (p!=nullptr) {delete [] p; p=nullptr;}
}

bool Array::keyboard(istream& f)
{
    if (lenMax==0)
    {
        lenMax=10000;
        p=new int [lenMax];
    }
    bool flag;
    while (!(f.eof()) && !flag)
    {
        if (len==lenMax) this->reset();
        if (f==cin) cout << "¬ведiть " << len+1 << "-ий елемент: ";
        f >> p[len];
        if (f.fail()) flag=1; else ++len;
    }
    f.clear(); f.sync();
    if (len==0) return 0; return 1;
}

void Array::out(ostream& f)
{
    for (int i=0; i<len; ++i)
    {
        f << setw(11) << p[i];
        if (i%4==3 && i!=len-1) f << "\n";
    }
}

void Array::processing()
{
    int t;
    bool flag=0, getT=0;
    cout << "\n";
    cin.clear(); cin.sync();
    do{
        cout << "¬ведiть значенн€: ";
        cin >> t;
        if (cin.fail()) {cin.clear(); cin.sync();}
        else getT=1;
    }while (!getT);
    if (len==lenMax) reset();
    p[len]=t;
    for (int i=0; i<len && !flag; ++i)
        if (is_prime(p[i]))
        {
            for (int j=len; j>i; --j)
                p[j+1]=p[j];
            p[i+1]=t;
            flag=1;
        }
    len++;
    return;
}

bool is_prime(int a)
{
    bool flag=0;
    if (a==1) flag=1;
    if (a%2==0 && a/2>1) flag=1;
    for (int i=3; i<100 && !flag; i+=2)
        if (a%i==0 && a/i>1) flag=1;
    return flag;
}
