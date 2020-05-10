#include <iostream>

#ifndef KOLEJKA_PRIORYTETOWA_H
#define KOLEJKA_PRIORYTETOWA_H

/**
*   @file Z powodu problemów podczas przenoszenia template klasy nie stworzono pliku cpp dla kolejka_priorytetowa.h
*/

template <class typ>
struct element_kolejki{
    int _klucz ; // odleglosc
    typ _elem;  // wierzcholek
    element_kolejki<typ> *_nastepnyElement = nullptr;
};



/**
*   @brief Klasa realizujaca strukture danych typu kolejka_priorytetowa
*/
template <class typ>
class kolejka_priorytetowa
{
    public:
        /**
        *   @brief Dodaje element do kolejki.
        */
        void insert(int klucz, typ elem){
            _rozmiar++;
            element_kolejki<typ> *wsk = new element_kolejki<typ>;
            element_kolejki<typ> *pomocniczy;
            wsk->_klucz = klucz;
            wsk->_elem = elem;

           if(_pierwszyElement == nullptr || klucz < _pierwszyElement->_klucz)
            {
                wsk->_nastepnyElement = _pierwszyElement;
                _pierwszyElement = wsk;
            }
            else
            {
                pomocniczy = _pierwszyElement;
                while(pomocniczy->_nastepnyElement!= nullptr && pomocniczy->_nastepnyElement->_klucz <= klucz )
                    pomocniczy = pomocniczy->_nastepnyElement;
                wsk->_nastepnyElement = pomocniczy->_nastepnyElement;
                pomocniczy->_nastepnyElement = wsk;
            }
        }


        /**
        *   @return Liczba elementow kolejki.
        */
        int rozmiar(){return _rozmiar;}


         /**
        *   @brief Sprawdza czy _wskaznik wskazuje na ostatni element kolejki
        *   @return true gdy _wskaznik wskazuje na ostatni element kolejki
        *   @return flase gdy _wskaznik nie wskazuje na ostatni element kolejki
        */
        bool czyOstatniElement(){
            if(_pierwszyElement == nullptr ) return true;
            else return false;
        }

        /**
        *   @brief Usuwa zawartosc kolejki, powrot do stanu poczatkowego
        */
        void wyczyscListe(){
            for( int i = 0; i<_rozmiar; i++){
                _wskaznik = _pierwszyElement->_nastepnyElement;
                delete _pierwszyElement;
                _pierwszyElement = _wskaznik;
            }
            _rozmiar = 0;
            _pierwszyElement = nullptr;
            _ostatniElement = nullptr;
            _wskaznik = nullptr;
        }

        /**
        *   @brief Usuwa ostatni element kolejki
        *   @return Zawartosc ostatniego elementu
        */
        typ removeMin(){
            _rozmiar--;
            typ wsk = _pierwszyElement->_elem;
            element_kolejki<typ> *wska = _pierwszyElement;
            _pierwszyElement = _pierwszyElement ->_nastepnyElement;
            delete wska;
            if(_rozmiar == 0) this->wyczyscListe();
            return wsk;
        }

       /**
       *    @brief Zmienia klucz przy wybranym elemencie
       */
        void replaceKey(typ szukany, int newKey){
            element_kolejki<typ> *wska = _pierwszyElement;
            for(int i = 0; i<_rozmiar;i++){
                    if(wska->_elem == szukany){
                        wska->_klucz = newKey;
                        return;
                    }
            }
        }

         /**
        *   @brief Destruktor zwalniajacy wykorzystywane przez liste dynamiczne elementy
        */
        ~kolejka_priorytetowa(){
            for( int i = 0; i<_rozmiar; i++){
                _wskaznik = _pierwszyElement->_nastepnyElement;
                delete _pierwszyElement;
                _pierwszyElement = _wskaznik;
            }
        }

    private:
       int _rozmiar = 0;
       element_kolejki<typ> *_pierwszyElement = nullptr;
       element_kolejki<typ> *_ostatniElement = nullptr;
       element_kolejki<typ> *_wskaznik = nullptr;
};

#endif // KOLEJKA_PRIORYTETOWA_H


