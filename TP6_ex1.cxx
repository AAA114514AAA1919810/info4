#include <iostream>
#include <random>
using namespace std;

int alea(int a, int b){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<> dist(a,b);
    int val;
    val = dist(rng); 
    return val
}

struct Case{
    int lig, col;
};

struct navire{
    int taille;
    Case* empl = new Case[taille];
    bool* touche = new bool[taille];
    int nbTouche = 0;
    bool coule; 
};

bool* initTab(){
    bool* tab = new bool[100];
    for (int i = 0; i < 100; i++ ){
        tab[i] = false;
    }
    return tab;
}

void afficher_tab_10(bool* T,int N){
    if(N > 0){
        afficher_tab_10(T,N-1);
        cout << T[N-1];
        if(N%10 == 0){
            cout << endl;
        }
        else{
        cout << " ";
        }
    }
}

Case coupHumain(){
    Case empl;
    cout << "choisir un emplacement :" << endl;
    cout << "ordonnee ? (0 - 9) : ";
    cin >> empl.lig; 
    cout << "abscisse ? (A - J ) : ";
    char c;
    cin >> c;
    cout << endl;
    empl.col = (int)(c) - (int)('A');
    return empl;
}

int reponseHumain(Case empl){
    char c = (char)(empl.col+(int)('A'));
    cout << "Case ( " << empl.lig << ", " << c << " ) attaque, navire touche ? " << endl;
    cout << "( 0 : rien, 1 : touche, 2 : coule, -1 :autre )" << endl;
    int res;
    cin >> res;
    return res;
}

navire initNavireOrdi(int nbCases, bool *grille){
    navire na;
    na.taille = nbCases;
    na.empl[0].lig = alea(0,9);
    na.empl[0].col = alea(0,9);
    int direction = alea(1,2);
    //1 = droite, 2 = bas
    if (direction = 1){
        while (nbCases > 0){
            na.empl->col
        }
    }
//calcule pour tester si on ne depasse pas le tab
// soit x,y coordonnee, x*10 + y donne empl Case, deplacement = (x + nbCases)*10 + y < 100 ou 10x + y + nb < 100

    na.coule = false

    return na;
}

int main(){
    bool* tab = initTab();
    afficher_tab_10(tab,100);
    cout << endl;
    Case c = coupHumain();
    int n = reponseHumain(c);
    return 0;
}