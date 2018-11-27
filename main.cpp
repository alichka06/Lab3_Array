#include <bits/stdc++.h>
#include "lab3_3.h"

using namespace std;

int main()
{
    bool check;
    Array *ar;
    setlocale(LC_ALL,"Ukrainian");
    cout << "������ ��i��. ����������� ������ 2-3 \"��i�� ������\"\n\n";
    do
    {
        int t=indicator();
        switch (t)
        {
            case 1:
                int n;
                do{
                    cout << "����i�� ������� ������� ������: ";
                    cin >> n;
                } while (n<1);
                ar=new Array(n); check=1; break;
            case 2: ar=new Array(); check=ar->keyboard(cin); break;
            case 3: ar=new Array(); check=file_in(ar); break;
            case 9: cout << "������ ���i�����"; return 0;
            break;
        }
    }while (!check);
    //ar->out(cout);
    ar->processing();
    int out=out_indicator();
    if (out==1) ar->out(cout); else file_out(ar);
    ar->~Array();
    cout << "\n������ ���i�����";
    return 0;
}

int indicator()
{
    int p;
    cout << "������� ���������� ������: \n   1 � ��������� ����� ����������������� �������\n";
    cout << "   2 � ������ ����� �� ��������� ����i����� \n   3 - �������� � �����\n   9 � ���i����� ������ \n";
    do{
        cout << "����i�� ���� i� �������������� ������i�: ";
        cin >> p;
        if (cin.fail()) {cin.clear(); cin.sync();}
    } while (p!=1 && p!=2 && p!=3 && p!=9);
    return p;
}

int out_indicator()
{
    int p;
    cout << "������� ��������� ������: \n   1 � ��������� �� �����\n   2 � ��������� � ���� \n";
    do{
        cout << "����i�� ���� i� �������������� ������i�: ";
        cin >> p;
        if (cin.fail()) {cin.clear(); cin.sync();}
    } while (p!=1 && p!=2);
    return p;
}

bool file_in(Array* & ar)
{
    string FN;
    ifstream fi;
    cout << "����i�� ���� �� ��i����� �����: ";
    cin.clear(); cin.sync();
    getline(cin, FN);
    if (FN=="") FN="input.txt";
    fi.open(FN);
    if (!fi) return cout<<"���� �� ��������\n",0;
    bool ch=ar->keyboard(fi);
    fi.close();
    return ch;
}

void file_out(Array* & ar)
{
    ofstream f;
    string FN;
    cout << "����i�� ���� �� ���i����� �����: ";
    cin.clear(); cin.sync();
    getline(cin, FN);
    if (FN=="") FN="output.txt";
    f.open(FN);
    ar->out(f);
    f.close();
    return;
}
