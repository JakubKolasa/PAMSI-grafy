#include <iostream>
#ifndef LISTA_H
#define LISTA_H

/**
*   @file Z powodu problemów podczas przenoszenia template klasy nie stworzono pliku cpp dla Listy.h
*/

/**
*   @brief Element listy
*/
template <class typ>
struct element
{
    typ _dane;
    element<typ> *_nastepnyElement = nullptr;
};

/**
*   @brief Klasa realizujaca strukture danych typu lista
*/
template <class typ>
class lista
{
    public:
        /**
        *   @brief Dodaje element na koniec listy
        */
        void dodajElement(typ Element){
            _rozmiar++;
            element<typ> *wsk = new element<typ>;
            wsk->_dane = Element;
            if(_pierwszyElement == nullptr)
            {
                _pierwszyElement = wsk;
                _ostatniElement = wsk;
                _wskaznik = wsk;
            }
            else
            {
                _ostatniElement->_nastepnyElement = wsk;
                _ostatniElement = wsk;
            }
        }

        /**
        *   @brief Zwraca wzkaznik na ostatni element
        */
        typ *wskOstatniElement(){return &_ostatniElement->_dane;}

        /**
        *   @brief Ustawia _wskaznik listy na element o zadanym indeksie (pierwszy element ma indeks 0)
        *   @return Wskazywany element
        */
        typ &wskazElement(int indeks){
            int iloscKrokow; // Aby lista nie musiala za kazdym razem startowac od poczatku wprowadzono dwa przypadki
            element<typ> *wsk;
            if(indeks>=_inxWskaznika){ // Szukany element jest dalej niz ostatnio poszukiwany przez iteracje mozna zaczac od _wskaznik
                iloscKrokow = indeks - _inxWskaznika;
                wsk = _wskaznik;
            }
            else{                     // Szukany element jest wczesniej, iteracje nalezy zaczac od poczatku
                iloscKrokow = indeks;
                wsk = _pierwszyElement;
            }
            for(int i = 0; i<iloscKrokow; i++){
                wsk = wsk->_nastepnyElement;
            }
            _wskaznik = wsk;
            _inxWskaznika = indeks;
            return wsk->_dane;
        }


         /**
        *   @brief Ustawia _wskaznik listy na pierwszy element listy
        *   @return Wskazywany element
        */
        typ &wskazPierwszyElement(){
            _wskaznik = _pierwszyElement;
            _inxWskaznika = 0;
            return _wskaznik->_dane;
        }


         /**
        *   @brief Ustawia _wskaznik listy na nastepny element
        *   @return Wskazywany element
        */
        typ &wskazKolejnyElement(){
            _wskaznik = _wskaznik->_nastepnyElement;
            _inxWskaznika++;
            return _wskaznik->_dane;
        }

        /**
        *   @return Wskazywany element
        */
        typ &wskazanyElement(){
            return _wskaznik->_dane;
        }

        /**
        *   @return Liczba elementow listy
        */
        int rozmiar(){return _rozmiar;}


         /**
        *   @brief Sprawdza czy _wskaznik wskazuje na ostatni element listy
        *   @return true gdy _wskaznik wskazuje na ostatni element listy
        *   @return flase gdy _wskaznik nie wskazuje na ostatni element listy
        */
        bool czyOstatniElement(){
            if(_wskaznik == _ostatniElement) return true;
            else return false;
        }

        /**
        *   @brief Usuwa zawartosc listy, powrot do stanu poczatkowego
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
        *   @brief Wyswietla liste w konsoli (dziala tylko dla elementow typu int oraz string)
        */
        void wyswietlListe(){
            std::cout << _pierwszyElement->_dane << std::endl;
            for( int i = 0; i<_rozmiar; i++){
                _wskaznik = _pierwszyElement->_nastepnyElement;
                std::cout<<_wskaznik->_dane<< std::endl;

            }
        }


         /**
        *   @brief Destruktor zwalniajacy wykorzystywane przez liste dynamiczne elementy
        */
        ~lista(){
            for( int i = 0; i<_rozmiar; i++){
                _wskaznik = _pierwszyElement->_nastepnyElement;
                delete _pierwszyElement;
                _pierwszyElement = _wskaznik;
            }
        }

    private:
       int _rozmiar = 0;
       element<typ> *_pierwszyElement = nullptr;
       element<typ> *_ostatniElement = nullptr;
       element<typ> *_wskaznik = nullptr;
       int _inxWskaznika = 0;
};
#endif // LISTA_H
