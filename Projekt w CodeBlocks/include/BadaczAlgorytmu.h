#include <graf_ls.h>
#include <graf_ms.h>
#include <kolejka_priorytetowa.h>
#include <chrono>

#define inf 250000

#ifndef BADACZALGORYTMU_H
#define BADACZALGORYTMU_H

using namespace std;

/**
*   @brief Klasa realizujaca algorytm Dijkstry oraz analizujaca jego czas dzialania
*/
class BadaczAlgorytmu
{
    public:
        /**
        * @brief Test czasu dzialania algorytmu Dijkstry dla grafu realizowanego przy pomocy listy sasiedztwa
        * @return Czas realizacji algorytmu [s]
        */
        double Test_ls(graf_ls *Graf);

        /**
        * @brief Test czasu dzialania algorytmu Dijkstry dla grafu realizowanego przy pomocy macierzy sasiedztwa
        * @return Czas realizacji algorytmu [s]
        */
        double Test_ms(graf_ms *Graf);

    private:
        void AlgorytmDijkstry(graf_ls &Graf);
        void AlgorytmDijkstry(graf_ms &Graf);
};

#endif // BADACZALGORYTMU_H
