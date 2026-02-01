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

string initChaine(int nbLettres, char charMin, char charMax) {
    if (nbLettres == 0) {
        return "";
    }

    char c = alea(charMin, charMax);

    return c + initChaine(nbLettres - 1, charMin, charMax);
}

// je n'arrive pas a faire la fonction verifChaine

void afficher(int nbLettres, const char* chaine) {
    if (nbLettres == 0) return;

    cout << *chaine << " ";
    afficher(nbLettres - 1, chaine + 1);
}

string saisir(int nbLettres) {
    if (nbLettres == 0) return "";
    char c;
    cin >> c;
    return c + saisir(nbLettres - 1);
}

// vue que j'ai pas reussi a faire verifChaine, je ne peux pas faire la fonction estGagne

int main(){
/* 
    int a = saisirNbLettres();
    cout << "Controle ok, nb saisi : " << a << endl;

    char charMin, charMax;
    cout << "Caractere mini ?" << endl;
    cin >> charMin;
    bool res =saisirCharMax(charMin, &charMax);
    cout << "1 = valable, 0 = non valable : " << res << endl;
    if (res){
        for (int i = 1; i <= 10; i++) {
            cout << initChaine(i, charMin, charMax) << endl;
        }
    } 
    else {
        cout << "La partie ne peut etre jouee !" << endl;
    }
*/

    afficher(4, "toto");   cout << endl;
    afficher(4, "t*t*");   cout << endl;
    afficher(4, "*o*o");   cout << endl;
    afficher(4, "****");   cout << endl;

    cout << "Saisir 4 caractères : ";
    string chaine = saisir(4);
    cout << chaine << endl;



    return 0;
}