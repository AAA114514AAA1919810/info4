#include <iostream>
using namespace std;

struct joueur{
    string nom;
    bool titulaire;
    int numero, point;
};

joueur saisirJoueur(){
    joueur j;
    cout << "nom : " << endl;
    cin >> j.nom;
    cout << endl << "titulaire ? : " << endl;
    cin >> j.titulaire;
    cout << endl << "numero : " << endl;
    cin >> j.numero;
    cout << endl << "point: " << endl;
    cin >> j.point;
    cout << endl;
    return j;
}

int main(){


    return 0;
}