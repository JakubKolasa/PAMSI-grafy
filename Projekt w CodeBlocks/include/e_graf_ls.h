#include <Lista.h>

#ifndef E_GRAF_LS_H
#define E_GRAF_LS_H

/**
*   @file Elementy grafu_ls
*   Klasa wierzcholek_l oraz krawedz_l jest na tyle male, ze
*   rozsiewanie ich po kilku plikach zmniejszalo czytelnosc
*/

class krawedz_l;

class wierzcholek_l
{
    public:
        wierzcholek_l(){} // Konstruktor umozliwiajacy utworzenie nowego obiektu w liscie
        wierzcholek_l(int dane){_dane = dane;}
        lista<krawedz_l*> *dajListeIncydencji(){return &_incydencje;}
        int dajDane(){return _dane;}
        int& dajOdleglosc(){return _odleglosc;}
    private:
    int _dane; // Iterator
    int _odleglosc = 0;
    lista<krawedz_l*> _incydencje;
};

class krawedz_l
{
    public:
        krawedz_l(){} // Konstruktor umozliwiajacy utworzenie nowego obiektu w liscie
        krawedz_l(int dane, wierzcholek_l *v1, wierzcholek_l *v2){
            _dane = dane;
            _wPoczatkowy = v1;
            _wKoncowy = v2;
            _wP_incydencje = v1->dajListeIncydencji();
            _wK_incydencje = v2->dajListeIncydencji();
        }

        /**
        *   @return wage wierzcholka
        */
        int dajDane(){return _dane;}

        /**
        *   @return wskaznik na wierzcholek poczatkowy
        */
        wierzcholek_l *wskWP(){return _wPoczatkowy;}

        /**
        *   @return wskaznik na wierzcholek koncowy
        */
        wierzcholek_l *wskWK(){return _wKoncowy;}

        void DodajIncydencje(){
            _wP_incydencje->dodajElement(this);
            _wK_incydencje->dodajElement(this);
            }
    private:
        int _dane;
        wierzcholek_l *_wPoczatkowy;
        wierzcholek_l *_wKoncowy;
        lista<krawedz_l*> *_wP_incydencje;
        lista<krawedz_l*> *_wK_incydencje;
};

#endif // E_GRAF_LS_H

