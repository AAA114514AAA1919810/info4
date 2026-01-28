#include <iostream>
#include <random>
using namespace std;


int alea(int a, int b){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<> dist(a,b);
 
    int val;
    val = dist(rng);
    return val;
}

int saisirNbLettres(){
    cout << "Nombre de lettres (entre 1 et 10) ? " ;
    int a;
    cin >> a ;
    if ((a >= 1) && (a<= 10)){
        return a;
    }
    cout <<"Erreur !";
    return saisirNbLettres();
}

bool saisirCharMax( char charMin, char *charMax ){

    cout << "Caractere maxi ?" << endl;
    cin >> *charMax;
    if (charMin < *charMax){
        return true;
    }
    cout << "Erreur ! Voulez-vous saisir un nouveau caractere <O/N> ? " ;
    char res;
    cin >> res ;
    if (res == 'O'){
        return saisirCharMax(charMin , charMax);
    }
    return false;
}

int main(){
    int a = saisirNbLettres();
    cout << "Controle ok, nb saisi : " << a << endl;

    char charMin, charMax;
    cout << "Caractere mini ?" << endl;
    cin >> charMin;
    cout << saisirCharMax(charMin, &charMax);


    return 0;
}