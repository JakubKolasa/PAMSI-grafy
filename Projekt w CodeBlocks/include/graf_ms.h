#include <dirent.h>
#include <string>
#include <fstream>
#include <Lista.h>
#include <e_graf_ms.h>

#ifndef GRAF_MS_H
#define GRAF_MS_H




class graf_ms
{
    public:
        //Metody dostepu
        /**
        *   @return Tablica dwoch koncowych wierzcholkow e
        */
        lista<wierzcholek_m*> endVertices(krawedz_m *e);

        /**
        *   @return Przeciwlegly wierzcholek do v wzgledem e
        */
        wierzcholek_m* opposite(wierzcholek_m *v, krawedz_m *e);

        /**
        *   @return true kiedy v1 i v2 sa wierzcholkami sasiednimi
        */
        bool areAdjacent(wierzcholek_m *v1, wierzcholek_m *v2);

        //Metody uaktualniajace

        /**
        *   @return dodaj wierzcholek przechowywujacy element o
        */
        void insertVertex(int o);

        /**
        *   @return dodaj krawedz od v1 do v2 przechowywujaca element o
        */
        void insertEdge(wierzcholek_m *v1, wierzcholek_m *v2 , int o);

        //Metody iterujace
        /**
        *   @return lista krawedzi przylegajacych do v
        */
        lista<krawedz_m*> *incidentEdges(wierzcholek_m *v);

        /**
        *   @return lista wierzcholkow
        */
        lista<wierzcholek_m>& vertices();

        /**
        *   @return lista krawedzi
        */
        lista<krawedz_m>& edges();

        /**
        *   @return numer pierwszego wierzcholka
        */
        int numerPierwszegoWierzcholka();

        /**
        *   @brief zapisz graf do pliku o zadanej nazwie
        */
        void zapisDoPliku(std::string nazwa);

        /**
        *   @brief wczytaj graz z pliku
        */
        void wczytajZPliku(std::string nazwa);

        /**
        *   @brief konstruktor klasy graf_ls
        */
        graf_ms(int liczba_wierzcholkow, float procent_gestosci);



    private:
        int numer_pierwszego_wierzcholka = 0;
        wierzcholek_m *ostatniaIncydencja = nullptr; // w celu szybszego zdobywania incydencji
        lista<krawedz_m*> *listaIncydencji = nullptr; // w celu szybszego zdobywania incydencji
        macierz_sasiedztwa M;
        lista<wierzcholek_m> V;
        lista<krawedz_m> E;
};


#endif // GRAF_MS_H
