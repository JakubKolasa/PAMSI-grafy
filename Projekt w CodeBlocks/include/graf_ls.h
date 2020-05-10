#include <dirent.h>
#include <string>
#include <fstream>
#include <Lista.h>
#include <e_graf_ls.h>

#ifndef GRAF_LS_H
#define GRAF_LS_H


class graf_ls
{
    public:
        //Metody dostepu
        /**
        *   @return Tablica dwoch koncowych wierzcholkow e
        */
        lista<wierzcholek_l*> endVertices(krawedz_l *e);

        /**
        *   @return Przeciwlegly wierzcholek do v wzgledem e
        */
        wierzcholek_l* opposite(wierzcholek_l *v, krawedz_l *e);

        /**
        *   @return true kiedy v1 i v2 sa wierzcholkami sasiednimi
        */
        bool areAdjacent(wierzcholek_l *v1, wierzcholek_l *v2);

        //Metody uaktualniajace

        /**
        *   @return dodaj wierzcholek przechowywujacy element o
        */
        void insertVertex(int o);

        /**
        *   @return dodaj krawedz od v1 do v2 przechowywujaca element o
        */
        void insertEdge(wierzcholek_l *v1, wierzcholek_l *v2 , int o);

        //Metody iterujace
        /**
        *   @return lista krawedzi przylegajacych do v
        */
        lista<krawedz_l*>* incidentEdges(wierzcholek_l *v);

        /**
        *   @return lista wierzcholkow
        */
        lista<wierzcholek_l>& vertices();

        /**
        *   @return lista krawedzi
        */
        lista<krawedz_l>& edges();

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
        graf_ls(int liczba_wierzcholkow, float procent_gestosci);


    private:
        int numer_pierwszego_wierzcholka = 0;
        lista<wierzcholek_l> V;
        lista<krawedz_l> E;
};

#endif // GRAF_LS_H
