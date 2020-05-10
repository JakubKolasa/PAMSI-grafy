#include <iostream>
#include <graf_ls.h>
#include <graf_ms.h>
#include <kolejka_priorytetowa.h>
#include <BadaczAlgorytmu.h>
#include <ctime>

using namespace std;

int main()
{
    srand( time( NULL ) );
    BadaczAlgorytmu B;
    graf_ls *G_ls;
    graf_ms *G_ms;
    double czas_ls = 0;
    double czas_ms = 0;
    remove("Excel2.csv");
    ofstream file("Excel2.csv", ios::app);
    int LiczbaWierzcholkow[5] = {400, 500, 600, 700, 800};
    float GestoscGrafu[4] = {0.25, 0.5, 0.75, 1};

    for( int a = 0; a < 5; a++){
        for ( int b = 0; b < 4; b++ ){
            for( int i = 0; i<50; i++){
                    G_ls = new graf_ls(LiczbaWierzcholkow[a], GestoscGrafu[b]);
                    czas_ls += B.Test_ls(G_ls);
                    delete G_ls;

                    G_ms = new graf_ms(LiczbaWierzcholkow[a], GestoscGrafu[b]);
                    czas_ms += B.Test_ms(G_ms);
                    delete G_ms;
            }
            file << czas_ls <<";"<< czas_ms <<";"<<LiczbaWierzcholkow[a]<<";"<<GestoscGrafu[b]<<endl;
            czas_ls = 0;
            czas_ms = 0;
        }
    }

    cout << "Complete!" << endl;
    return 0;
}
