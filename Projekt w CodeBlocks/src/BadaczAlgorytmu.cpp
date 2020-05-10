#include "BadaczAlgorytmu.h"

double BadaczAlgorytmu::Test_ls(graf_ls *Graf){
            auto start = std::chrono::steady_clock::now();
            AlgorytmDijkstry(*Graf);
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> czas = end-start;
            return czas.count();

        }

double BadaczAlgorytmu::Test_ms(graf_ms *Graf){
            auto start = std::chrono::steady_clock::now();
            AlgorytmDijkstry(*Graf);
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> czas = end-start;
            return czas.count();
        }

void BadaczAlgorytmu::AlgorytmDijkstry(graf_ls &Graf){  //Zgodnie z prezentacja
            int liczbaWierzcholkow = Graf.vertices().rozmiar();
            wierzcholek_l* u;
            wierzcholek_l* z;
            int liczbaIncydencji, r;
            kolejka_priorytetowa<wierzcholek_l*> kolejka;
            for ( int i = 0; i<liczbaWierzcholkow ; i++){
                if(Graf.vertices().wskazElement(i).dajDane() == Graf.numerPierwszegoWierzcholka()) Graf.vertices().wskazElement(i).dajOdleglosc() = 0;
                else{
                        Graf.vertices().wskazElement(i).dajOdleglosc() = 999999; // Jakakolwiek kombinacja drog nie bedzie mogla byc wieksza
                }
                kolejka.insert(Graf.vertices().wskazElement(i).dajOdleglosc(), &Graf.vertices().wskazElement(i));
            }
            while ( !(kolejka.czyOstatniElement())){
                u = kolejka.removeMin();
                liczbaIncydencji = Graf.incidentEdges(u)->rozmiar();
                for(int i = 0; i<liczbaIncydencji; i++){
                     z = Graf.opposite(u,Graf.incidentEdges(u)->wskazElement(i));
                     r = u->dajOdleglosc() + Graf.incidentEdges(u)->wskazElement(i)->dajDane();
                     if(r < z->dajOdleglosc()){
                        z->dajOdleglosc() = r;
                        kolejka.replaceKey(z,r);
                     }
                }
            }
        }


void BadaczAlgorytmu::AlgorytmDijkstry(graf_ms &Graf){  //Zgodnie z prezentacja
            int liczbaWierzcholkow = Graf.vertices().rozmiar();
            wierzcholek_m* u;
            wierzcholek_m* z;
            int liczbaIncydencji, r;
            kolejka_priorytetowa<wierzcholek_m*> kolejka;
            for ( int i = 0; i<liczbaWierzcholkow ; i++){
                if(Graf.vertices().wskazElement(i).dajDane() == Graf.numerPierwszegoWierzcholka()) Graf.vertices().wskazElement(i).dajOdleglosc() = 0;
                else{
                        Graf.vertices().wskazElement(i).dajOdleglosc() = 999999; // Jakakolwiek kombinacja drog nie bedzie mogla byc wieksza
                }
                kolejka.insert(Graf.vertices().wskazElement(i).dajOdleglosc(), &Graf.vertices().wskazElement(i));
            }
            while ( !(kolejka.czyOstatniElement())){
                u = kolejka.removeMin();
                liczbaIncydencji = Graf.incidentEdges(u)->rozmiar();
                for(int i = 0; i<liczbaIncydencji; i++){
                     z = Graf.opposite(u,Graf.incidentEdges(u)->wskazElement(i));
                     r = u->dajOdleglosc() + Graf.incidentEdges(u)->wskazElement(i)->dajDane();
                     if(r < z->dajOdleglosc()){
                        z->dajOdleglosc() = r;
                        kolejka.replaceKey(z,r);
                     }
                }
            }
        }
