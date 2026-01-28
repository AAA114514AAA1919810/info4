#include <iostream>
using namespace std;

int calculerProduit(int a, int b){
    if ((a == 0) || (b == 0)){
        return 0;
    }
    if (b < 0){
        return -calculerProduit(a, -b);
    }
    return a + calculerProduit(a,b-1);
}

/*
Trace de calculerProduit(5, 4) :

calculerProduit(5, 4) = 5 + calculerProduit(5, 3)
                            = 5 + calculerProduit(5, 2)
                                = 5 + calculerProduit(5, 1)
                                    = 5 + calculerProduit(5, 0)
                                    = 5 + 0
                                = 5 + 5
                            = 5 + 10
                        = 5 + 15
                      = 20
*/

int calculerProduitCpt(int a, int b, int nbAppel){
    nbAppel++;
    if ((a == 0) || (b == 0)){
        return 0;
    }
    if (b < 0){
        return -calculerProduitCpt(a, -b, nbAppel);
    }
    return a + calculerProduitCpt(a, b+1, nbAppel);
}

/* 
si a = 1000, b = 1 , alors nbAppel = 2
si a = 1; b = 1000 , alors nbAppel = 1001
*/

int valeurAbsolue( int x ){
    if (x < 0){
        return -x;
    }
    return x;
}

int calculerProduitCpt_2(int a, int b, int *nbAppel){
    *nbAppel +=1;
    if (valeurAbsolue(a) < valeurAbsolue(b)){
        calculerProduitCpt_2(b, a, nbAppel);
    }

    if ((a == 0) || (b == 0)){
        return 0;
    }
    if (b < 0){
        return -calculerProduitCpt_2(a, -b, nbAppel);
    }
    return a + calculerProduitCpt_2(a, b-1, nbAppel);
}


int main(){
    cout << " saisir deux entier " << endl;
    int x, y;
    cin >> x >> y ;
    cout << calculerProduit(x, y) << endl;

    int a = 4;
    int b = 5;
    int c = -4;
    int d = -5;
    cout << "test pour produit, reponse correct : 20, -20, -20, 20 " << endl << "reponse obtenu :" << endl;
    cout << calculerProduit(a, b) << endl << calculerProduit(c, b) << endl << calculerProduit(a, d) << endl << calculerProduit(c, d) << endl ;

    int nbAppel;

    cout << "test calculerProduitCpt_2 avec a = 4 et b = -5 : " << endl << "reponse obtenu : " << calculerProduitCpt_2(a, d, &nbAppel) << endl;

    return 0;
}