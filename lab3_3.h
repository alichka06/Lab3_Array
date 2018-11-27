#ifndef LAB3_3_H_INCLUDED
#define LAB3_3_H_INCLUDED
using namespace std;

class Array
{
    private:
        int *p;
        int lenMax;
        int len;
        void reset();
    public:
        Array();
        Array(int n);
        ~Array();
        bool keyboard(istream& f);
        void out(ostream& f);
        void processing();
};

bool is_prime(int a);
int indicator();
int out_indicator();
bool file_in(Array* & ar);
void file_out(Array* & ar);

#endif // LAB3_3_H_INCLUDED
