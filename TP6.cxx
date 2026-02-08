#include <iostream>
#include <random>
using namespace std;

const int MAX_PILE = 20;

int alea(int a, int b){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<> dist(a,b);
    int val;
    val = dist(rng); 
    return val;
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
    na.empl = new Case[nbCases];
    na.touche = new bool[nbCases];
    for(int i=0;i<nbCases;i++) na.touche[i] = false;

    bool placeOk = false;

    while(!placeOk){
        int startLig = alea(0, 9);
        int startCol = alea(0, 9);
        int direction = alea(1, 4); // 1=haut, 2=bas, 3=gauche, 4=droite
        placeOk = true;

        // Vérifier que toutes les cases du navire sont libres et dans la grille
        for(int i=0; i<nbCases; i++){
            int lig = startLig;
            int col = startCol;

            if(direction == 1) lig = startLig - i; // haut
            if(direction == 2) lig = startLig + i; // bas
            if(direction == 3) col = startCol + i; // gauche
            if(direction == 4) col = startCol - i; // droite

            if(lig < 0 || lig > 9 || col < 0 || col > 9){ 
                placeOk = false; 
                break; 
            }

            if(grille[lig*10 + col]){ // case déjà occupée
                placeOk = false; 
                break;
            }
        }

        // Si placement possible, remplir le navire et marquer la grille
        if(placeOk){
            for(int i=0; i<nbCases; i++){
                int lig = startLig;
                int col = startCol;

                if(direction == 1) lig = startLig - i; // haut
                if(direction == 2) lig = startLig + i; // bas
                if(direction == 3) col = startCol + i; // gauche
                if(direction == 4) col = startCol - i; // droite

                na.empl[i].lig = lig;
                na.empl[i].col = col;
                grille[lig*10 + col] = true; // marquer la case comme occupee
            }
        }
    }

    na.coule = false;
    return na;
}

Case coupOrdinateur(bool* joue, Case* pile, int &sommet){
    Case coup;

    if(sommet >= 0){ // pile non vide
        Case dernier = pile[sommet];
        bool trouve = false;

        int dl[4] = {-1, 1, 0, 0}; // N, S, E, O
        int dc[4] = {0, 0, 1, -1};

        for(int i=0; i<4; i++){
            int lig = dernier.lig + dl[i];
            int col = dernier.col + dc[i];

            if(lig >= 0 && lig < 10 && col >= 0 && col < 10 && !joue[lig*10 + col]){
                coup.lig = lig;
                coup.col = col;
                trouve = true;
                break;
            }
        }

        if(!trouve){
            // aucun voisin dispo, dépiler et recommencer
            sommet--;
            return coupOrdinateur(joue, pile, sommet);
        }
    } else {
        // pile vide, tir aléatoire
        do {
            coup.lig = alea(0, 9);
            coup.col = alea(0, 9);
        } while(joue[coup.lig*10 + coup.col]);
    }

    // marquer la case comme jouée
    joue[coup.lig*10 + coup.col] = true;
    return coup;
}

int reponseOrdinateur(Case coup, navire* flotte, int nbNavires){
    for(int i=0; i<nbNavires; i++){
        navire &n = flotte[i];

        for(int j=0; j<n.taille; j++){
            if(n.empl[j].lig == coup.lig && n.empl[j].col == coup.col){
                if(!n.touche[j]){
                    n.touche[j] = true;
                    n.nbTouche++;

                    if(n.nbTouche == n.taille){
                        n.coule = true;
                        return 2; // coulé
                    }
                    return 1; // touché
                } else {
                    return 0; // déjà touchée avant
                }
            }
        }
    }
    return 0; // rien
}

void miseAjour(Case coup, int reponse, bool* grilleJouee, Case* pile, int &sommet){
    // Marque case deja jouee
    grilleJouee[coup.lig*10 + coup.col] = true;

    //  empiler la case Si coup touche ou coule
    if(reponse == 1 || reponse == 2){
        if(sommet < MAX_PILE - 1){ // eviter de dépasser la pile
            pile[++sommet] = coup; // empiler la case
        } else {
            cout << "Attention : pile pleine !" << endl;
        }
    }
}


//j'ai pas reussi à faire fonction Jouer, donc j'ai mis des exemples dans main
int main(){
    bool* grilleOrdi = initTab();      // cases occupées par navire
    bool* grilleJouee = initTab();     // cases déjà jouées par l'ordi
    Case pile[20]; int sommet=-1;   

    // Placement navire de taille 3
    navire ordi = initNavireOrdi(3, grilleOrdi);
    navire flotteOrdi[1]={ordi};

    cout<<"Debut du jeu !"<<endl;

    // Exemple tour humain
    Case cHum = coupHumain();
    int rep = reponseOrdinateur(cHum, flotteOrdi, 1);
    cout<<"Reponse ordinateur : "<<rep<<endl;

    // Exemple tour ordinateur
    Case cOrdi = coupOrdinateur(grilleJouee,pile,sommet);
    cout<<"Ordinateur joue : ("<<cOrdi.lig<<","<<cOrdi.col<<")"<<endl;
    // On simule la reponse humaine
    int repHum=0; // 0=rien, 1=touche, 2=coule
    miseAjour(cOrdi, repHum, grilleJouee, pile, sommet);

    return 0;
}
