#include <Lista.h>

#ifndef E_GRAF_MS_H
#define E_GRAF_MS_H

/**
*   @file Elementy grafu_ms
*   Klasa wierzcholek_m oraz krawedz_m jest na tyle male, ze
*   rozsiewanie ich po kilku plikach zmniejszalo czytelnosc
*/

class krawedz_m;

class wierzcholek_m
{
    public:
        wierzcholek_m(){} // Konstruktor umozliwiajacy utworzenie nowego obiektu w liscie
        wierzcholek_m(int dane){_dane = dane;}
        int dajDane(){return _dane;}
        int& dajOdleglosc(){return _odleglosc;}
    private:
    int _dane; // Iterator
    int _odleglosc;
};

class krawedz_m
{
    public:
        krawedz_m(){} // Konstruktor umozliwiajacy utworzenie nowego obiektu w liscie
        krawedz_m(int dane, wierzcholek_m *v1, wierzcholek_m *v2){
            _dane = dane;
            _wPoczatkowy = v1;
            _wKoncowy = v2;
        }

        /**
        *   @return wage wierzcholka
        */
        int dajDane(){return _dane;}

        /**
        *   @return wskaznik na wierzcholek poczatkowy
        */
        wierzcholek_m *wskWP(){return _wPoczatkowy;}

        /**
        *   @return wskaznik na wierzcholek koncowy
        */
        wierzcholek_m *wskWK(){return _wKoncowy;}

    private:
        int _dane;
        wierzcholek_m *_wPoczatkowy;
        wierzcholek_m *_wKoncowy;
};

/**
*   @brief Klasa realizujaca macierz sasiedztwa
*   Wiersze to wierzcholki poczatkowe, a kolumny to wierzcholki koncowe.
*/
class macierz_sasiedztwa{
    public:
        /**
        *   @brief Konstruktor macierzy sasiedztwa
        *   @param iloscV - liczba wierzcholkow w grafie
        */
        macierz_sasiedztwa(int iloscV){
            _iloscV = iloscV;
             macierz = new krawedz_m  ** [iloscV];
                for ( int i = 0; i<iloscV; i++){
                    macierz[i] = new krawedz_m  * [iloscV];
                    for ( int j = 0; j<iloscV; j++) macierz[i][j] = nullptr;
                }
        }

        /**
        *   @brief Destruktor zwalniajacy pamiec
        */
        ~macierz_sasiedztwa(){
            for ( int i = 0; i<_iloscV; i++) delete macierz[i];
            delete macierz;
        }

        /**
        *   @brief Dodanie krawedzi do macierzy
        */
        void dodajKrawedz(krawedz_m *e){
            int Vp = e->wskWP()->dajDane();
            int Vk = e->wskWK()->dajDane();
            macierz[Vp][Vk] = e;
            macierz[Vk][Vp] = e;
        }

        /**
        *   @return true gdy wierzcholki maja wspolna krawedz
        */
        bool czyPrzylega(wierzcholek_m *v1, wierzcholek_m *v2){
            int Vp = v1->dajDane();
            int Vk = v2->dajDane();
            if(macierz[Vp][Vk] == nullptr) return false;
            else return true;
        }

        /**
        *   @return true gdy wierzcholki maja wspolna krawedz
        */
        bool czyPrzylega(int v1, int v2){
            if(macierz[v1][v2] == nullptr) return false;
            else return true;
        }

        /**
        *   @return Wskaznik na krawedz z macierzy
        */
        krawedz_m* wskKrawedz(int vp, int vk){return macierz[vp][vk];}

    private:
        krawedz_m ***macierz;
        int _iloscV;
};

#endif // E_GRAF_MS_H
