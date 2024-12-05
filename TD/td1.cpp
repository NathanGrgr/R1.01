#include <iostream>

using namespace std;



void exo2()
{
    cout << "Bonjour" << endl;
}



void exo3()
{
    for (unsigned i(0); i < 10; i=i+1)
    {
        cout << i << '\t';
    }
}

void exo4()
{
    for (unsigned i(0); i < 200; i=i+1)
    {
        cout << i << '\t';
    }
}

void exo5()
{
    unsigned N;
    cin >> N;
    for (unsigned i=0;i<N; i=i+1)
    {
        cout << i << '\t';
    }
}



void AffichNPremiersEntiersNat(const unsigned & N, const char & Sep)
{
    for (unsigned i=0; i < N; i=i+1)
    {
        cout << i << Sep;
    }
}


void exo6()
{
    unsigned N;
    cin >> N;
    char Sep;
    cin >> Sep;
    AffichNPremiersEntiersNat(N,Sep);
}



bool isdigit(const char & car)
{
    return ('0'<= car && car <= '9');
}



int main()
{
    exo5();
    cout << '\n';
    //cout << "au revoir" << endl;
    return 0;
}


