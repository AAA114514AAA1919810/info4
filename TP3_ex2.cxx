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

void deplacer(int posMax, int *pos, int sens){
    int val = alea(1, 3);
    *pos += sens * val;
    if (*pos < 0){
        *pos = 0;
    }
    else if (*pos > posMax){
        *pos = posMax;
    }
}

int sensDeplacer(int sens, int pos, int posMax ){
    if ((pos == 0)&&(sens == -1)){
        return -sens;
    }
    if ((pos == posMax)&&(sens == 1)){
        return -sens;
    }
    return sens;
}

// l'enonce demande 4 arguments, mais je vois pas comment faire sans mettre ligMax et colMax
void nouvellePosition(int ligMax, int colMax,
                      int *lig, int *col,
                      int *sensLig, int *sensCol){
    // verifie que deplacement possible
    *sensLig = sensDeplacer(*sensLig, *lig, ligMax);
    *sensCol = sensDeplacer(*sensCol, *col, colMax);

    deplacer(ligMax, lig, *sensLig);
    deplacer(colMax, col, *sensCol);
}

void initGrille(int grille[10][10]) {
    // initialise la grille
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            grille[i][j] = 0;

    // on place A
    int ligA = alea(0, 9);
    int colA = alea(0, 9);
    grille[ligA][colA] = 1;
    cout << "A coordonne : (" << ligA << ", " << colA << ")" << endl;

    // on place B
    int ligB, colB;
    do {
        ligB = alea(0, 9);
        colB = alea(0, 9);
    } while(ligB == ligA && colB == colA);

    grille[ligB][colB] = 2;
    cout << "B coordonne : (" << ligB << ", " << colB << ")" << endl;
}


bool existeAB(int grille[10][10]) {
    bool existeA = false;
    bool existeB = false;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (grille[i][j] == 1) existeA = true;
            if (grille[i][j] == 2) existeB = true;

            // fonction doit verifier si A et B existent
            if (existeA && existeB) return true;
        }
    }
    // si l'un des deux n'existe pas
    return false;
}

int trouverLigne(int grille[10][10], int objet) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (grille[i][j] == objet) {
                return i; // ligne trouvée
            }
        }
    }
    return -1; // objet non trouvé
}

int trouverColonne(int grille[10][10], int objet) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (grille[i][j] == objet) {
                return j; // colonne trouvée
            }
        }
    }
    return -1; // objet non trouvé
}

int calculerDistance(int lig1, int col1, int lig2, int col2) {
    int lig = lig1 - lig2;
    if (lig < 0) lig = -lig; // transforme en positif

    int col = col1 - col2;
    if (col < 0) col = -col; // transforme en positif

    return lig + col; 
}

bool estEnCollision(int lig1, int col1, int rayon1, int lig2, int col2, int rayon2) {
    int distance = calculerDistance(lig1, col1, lig2, col2);

    // Collision si la distance <= somme des rayons
    return distance <= (rayon1 + rayon2);
}

void afficherGrille(int grille[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (grille[i][j] == 1)
                cout << "A ";
            else if (grille[i][j] == 2)
                cout << "B ";
            else
                cout << ". "; // case vide
        }
        cout << endl;
    }
}

int main(){
/*
    int val = alea(1, 3);
    cout << " nb random entre 1 et 3 : " << val << endl;
    int posMax = 9;
    int pos = 2;
    int sens = -1;
    deplacer(posMax, &pos, sens);
    cout << "Position apres deplacement : " << pos << endl;

    sens = sensDeplacer(sens, pos, posMax);
    cout << "sens apres verification : " << sens << endl;
*/

    // le tableau
    int ligMax = 9;
    int colMax = 9;

    // point depart
    int lig = 4;
    int col = 5;

    // sens deplacement depart
    int sensLig = 1;   // vers le bas
    int sensCol = -1;  // vers la gauche

    // affichage point depart
    cout << "Position depart : (" << lig << ", " << col << ")" << endl;
    cout << "Sens initial : ligne =" << sensLig << " colonne =" << sensCol << endl;

    // calcul point arrive
    nouvellePosition(ligMax, colMax, &lig, &col, &sensLig, &sensCol);

    // affichage point arrive
    cout << "Point d'arrive : (" << lig << ", " << col << ")" << endl;
    cout << "sens deplacement : ligne =" << sensLig << " colonne =" << sensCol << endl;

    int grille[10][10];
    // initialise la grille et place A, B aleatoire
    initGrille(grille);


    if (existeAB(grille))
        cout << "A et B existent tous les deux." << endl;
    else
        cout << "Au moins l'un des deux ecrase ou autre" << endl;

    int ligA = trouverLigne(grille, 1);
    int ligB = trouverLigne(grille, 2);

    if (ligA != -1)
        cout << "A se trouve sur la ligne : " << ligA << endl;
    else
        cout << "A n'existe pas" << endl;

    if (ligB != -1)
        cout << "B se trouve sur la ligne : " << ligB << endl;
    else
        cout << "B n'existe pas" << endl;


    int colA = trouverColonne(grille, 1);
    int colB = trouverColonne(grille, 2);

    if (colA != -1)
        cout << "A se trouve sur la colonne : " << colA << endl;
    else
        cout << "A n'existe pas" << endl;


    if (colB != -1)
        cout << "B se trouve sur la colonne : " << colB << endl;
    else
        cout << "B n'existe pas" << endl;


    if (ligA != -1 && ligB != -1) {
        int distance = calculerDistance(ligA, colA, ligB, colB);
        cout << "Distance entre A et B : " << distance << endl;
    } else {
        cout << "A ou B n'existe pas, calculer impossible " << endl;
    }


    // vu que dans les etapes precedentes on a jamais utiliser de rayon, j'ai donc defini un cas simple
    int rayonA = 1;
    int rayonB = 1;

    if (ligA != -1 && ligB != -1) {
        if (estEnCollision(ligA, colA, rayonA, ligB, colB, rayonB)) {
            cout << "Collision entre A et B" << endl;
        } else {
            cout << "Pas de collision entre A et B " << endl;
        }
    }

    cout << "Grille :" << endl;
    afficherGrille(grille);




    return 0;
}