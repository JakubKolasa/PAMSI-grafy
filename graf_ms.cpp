#include "graf_ms.h"


lista<wierzcholek_m*> graf_ms::endVertices(krawedz_m *e){
            lista<wierzcholek_m*> v;
            v.dodajElement(e->wskWP());
            v.dodajElement(e->wskWK());
            return v;
}

wierzcholek_m* graf_ms::opposite(wierzcholek_m *v, krawedz_m *e){
            if(e->wskWK() == v) return e->wskWP();
            if(e->wskWP() == v) return e->wskWK();
            std::cout <<"graf_ls.h:81 krawedz e nie posiada wierzcholka v"<<std::endl;
            return 0;
        }

bool graf_ms::areAdjacent(wierzcholek_m *v1, wierzcholek_m *v2){
            return M.czyPrzylega(v1,v2);
        }

void graf_ms::insertVertex(int o){V.dodajElement(wierzcholek_m(o));}

void graf_ms::insertEdge(wierzcholek_m *v1, wierzcholek_m *v2 , int o){E.dodajElement(krawedz_m(o, v1, v2));
                                                                      M.dodajKrawedz(&E.wskazElement(E.rozmiar()-1));}
lista<krawedz_m*> *graf_ms::incidentEdges(wierzcholek_m *v){
            if( v == ostatniaIncydencja) return listaIncydencji;
            else ostatniaIncydencja = v;
            if(listaIncydencji != nullptr) delete listaIncydencji;
            listaIncydencji = new lista<krawedz_m*>;
            int nrV = v->dajDane();
            int iloscV = V.rozmiar();
            for (int i = 0; i<iloscV; i++){
                if(M.czyPrzylega(nrV,i)) listaIncydencji->dodajElement(M.wskKrawedz(nrV, i));
            }
            return listaIncydencji;
        }

lista<wierzcholek_m>& graf_ms::vertices(){return V;}

lista<krawedz_m>& graf_ms::edges(){return E;}

int graf_ms::numerPierwszegoWierzcholka(){return numer_pierwszego_wierzcholka;}

void graf_ms::zapisDoPliku(std::string nazwa){
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

void graf_ms::wczytajZPliku(std::string nazwa){
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

graf_ms::graf_ms(int liczba_wierzcholkow, float procent_gestosci): M(liczba_wierzcholkow){
            float lk = liczba_wierzcholkow * (liczba_wierzcholkow -1 )* procent_gestosci/2;
            numer_pierwszego_wierzcholka = liczba_wierzcholkow-1; // W celu najwiekszego ,,skaplikowania"
            int liczba_krawedzi = lk;
            int k,l;
            l=0;
            k=1;
            for( int i = 0; i<liczba_wierzcholkow; i++) insertVertex(i);
            for( int j = 0; j<liczba_krawedzi; j++){
                if(k +1 > liczba_wierzcholkow){l++; k = l+1;}
                insertEdge(&V.wskazElement(l), &V.wskazElement(k), 1+rand()%100);
                k++;
            }
        }


