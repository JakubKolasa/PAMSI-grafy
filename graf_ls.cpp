#include "graf_ls.h"


lista<wierzcholek_l*> graf_ls::endVertices(krawedz_l *e){
            lista<wierzcholek_l*> v;
            v.dodajElement(e->wskWP());
            v.dodajElement(e->wskWK());
            return v;
        }
wierzcholek_l* graf_ls::opposite(wierzcholek_l *v, krawedz_l *e){
            if(e->wskWK() == v) return e->wskWP();
            if(e->wskWP() == v) return e->wskWK();
            std::cout <<"graf_ls.h:81 krawedz e nie posiada wierzcholka v"<<std::endl;
            return 0;
        }
bool graf_ls::areAdjacent(wierzcholek_l *v1, wierzcholek_l *v2){
            lista<krawedz_l*> *IncV1 = v1->dajListeIncydencji();
            lista<krawedz_l*> *IncV2 = v2->dajListeIncydencji();
            int r1 = IncV1->rozmiar();
            int r2 = IncV2->rozmiar();
            for(int i = 0; i<r1; i++){
                for(int j = 0; j<r2; j++){ if(IncV1->wskazElement(i) == IncV2->wskazElement(j)) return true; }} //Poszukiwanie wspolnego elementu list
            return false;
        }

void graf_ls::insertVertex(int o){V.dodajElement(wierzcholek_l(o));}

void graf_ls::insertEdge(wierzcholek_l *v1, wierzcholek_l *v2 , int o){E.dodajElement(krawedz_l(o, v1, v2));
                                                                      E.wskazElement(E.rozmiar()-1).DodajIncydencje();}
lista<krawedz_l*>* graf_ls::incidentEdges(wierzcholek_l *v){return v->dajListeIncydencji();}

lista<wierzcholek_l>& graf_ls::vertices(){return V;}

lista<krawedz_l>& graf_ls::edges(){return E;}

int graf_ls::numerPierwszegoWierzcholka(){return numer_pierwszego_wierzcholka;}

void graf_ls::zapisDoPliku(std::string nazwa){
            remove(nazwa.c_str());
            std::ofstream plik(nazwa, std::ios::app);
            plik<<E.rozmiar()<<"\t"<<V.rozmiar()<<"\t"<<V.wskazPierwszyElement().dajDane()<<std::endl;
            int r = E.rozmiar();
            for(int i = 0; i<r; i++){
                plik << E.wskazElement(i).wskWP()->dajDane()<<"\t";
                plik << E.wskazElement(i).wskWK()->dajDane()<<"\t";
                plik << E.wskazElement(i).dajDane()<<std::endl;
            }
        }

void graf_ls::wczytajZPliku(std::string nazwa){
            V.wyczyscListe();
            E.wyczyscListe();
            std::ifstream plik;
            plik.open(nazwa.c_str());
            int liczba_wierzcholkow, liczba_krawedzi;
            int v1, v2, waga;
            plik >> liczba_krawedzi >> liczba_wierzcholkow >> numer_pierwszego_wierzcholka;
            for( int i = 0; i<liczba_wierzcholkow; i++) insertVertex(i);
            for( int j = 0; j<liczba_krawedzi; j++){
                plik>> v1 >> v2 >> waga;
                insertEdge(&V.wskazElement(v1), &V.wskazElement(v2), waga);
            }
        }

graf_ls::graf_ls(int liczba_wierzcholkow, float procent_gestosci){
            float lk = liczba_wierzcholkow * (liczba_wierzcholkow -1 )* procent_gestosci/2;
            numer_pierwszego_wierzcholka = liczba_wierzcholkow-1; // W celu najwiekszego ,,skaplikowania"
            int liczba_krawedzi = lk;
            int k,l;
            l=0;
            k=1;
            for( int i = 0; i<liczba_wierzcholkow; i++) insertVertex(i);
            for( int j = 0; j<liczba_krawedzi; j++){
                if(k+1 > liczba_wierzcholkow){l++; k = l+1;}
                insertEdge(&V.wskazElement(l), &V.wskazElement(k), 1+rand()%100);
                k++;
            }
        }
