// Bourdon Benoit 12/01/2026


#include <iostream>
#include <random>

using namespace std;

/* Exercice 1 */

int additionner(int a, int b){
    return a + b;
}



void initTab(int T[50]){
    int a=1 , b=50;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<> dist(a,b);
    for (int i = 0; i < 50 ; i++)
    {
        int val;
        val = dist(rng); //génère un nombre aléatoire entre a et b,
                         //peut être répété plusieurs fois
        T[i] = val;
    }
}


void printTab(int T[50] , int nbCol ){
    int i;
    for (int i = 0; i < 50 ; i++ ){
        /* && = and en python */
        if (i%10 == 0 && i != 0){
            cout << T[i] << endl;
        }
        else{
            cout << T[i];
        }
    }
cout << endl;
}

int addElementTab(int T[50])
{
    int somme = 0;

    initTab(T);

    for (int i = 0; i < 50; i++)
    {
        somme = additionner(somme, T[i]);
    }

    return somme;
}


/* Exercice 2 */

int arrondiSup(double n)
{       /* pourquoi parenthèse sur int sur c++ ??? aucun sense */
    int arrondi = (int)n;  // on garde partie entière, (int) donne arrondi inférieur

    if (n == arrondi){
        return arrondi;
    }
    else{
        return arrondi + 1;
    }
}

int tempsDeReaction(bool fatigue, bool alcool)
{
    int temps = 1; 

    if (fatigue)
    {
        temps = temps + 1;
    }

    if (alcool)
    {
        temps++;
        temps = temps * 2;
    }

    return temps;
}

int kmh2ms(double vitesseKmh)
{
    double vitesseMs = vitesseKmh / 3.6;  //  m/s = km/h ÷ 3.6
    return arrondiSup(vitesseMs);
}

int distanceReaction(double vitesseKmh, bool fatigue, bool alcool)
{
    int vitesseMs = kmh2ms(vitesseKmh);
    int tempsReac = tempsDeReaction(fatigue, alcool);

    double distance = vitesseMs * tempsReac;
    return arrondiSup(distance);
}

int distanceFreinage(double vitesseKmh)
{   // d = (v/10)**2, mais ** ne marche pas en c++, donc * soi-même
    double distance = (vitesseKmh / 10.0) * (vitesseKmh / 10.0); 
    return arrondiSup(distance);
}

int distanceTotaleSec(double vitesseKmh, bool fatigue, bool alcool)
{
    int distanceReac = distanceReaction(vitesseKmh, fatigue, alcool);
    int distanceFrein = distanceFreinage(vitesseKmh);

    int distanceTotale = distanceReac + distanceFrein;
    return distanceTotale;
}

int distanceTotaleHum(double vitesseKmh, bool fatigue, bool alcool)
{
    int distanceReac = distanceReaction(vitesseKmh, fatigue, alcool);
    int distanceFrein = distanceFreinage(vitesseKmh);

    int distanceTotale = distanceReac + 2 * distanceFrein;
    return distanceTotale;
}

int distanceEtage(int distance)
{
    double nbetages = distance / 2.5;
    return arrondiSup(nbetages);
}

int main(){
// Exercice 1
/*  int a, b ,som;
    cout << "saisir 2 entiers :";
    cin >> a >> b;
    cout << a << " + " << b << " = ";
    som = additionner(a, b);
    cout << som << endl;
*/
/* 
    int T[50];
    initTab(T);

    int nbCol = 10;
    printTab( T, nbCol);
    return 0;
*/
/*
    int T[50];
    int somme = addElementTab(T);

    printTab(T, 10);
    cout << "Somme du tableau : " << somme << endl;

    return 0;
*/

// Exercice 2
    double vitesseKmh;
    bool fatigue, alcool;

    cout << "Estimation simplifiee de la distance d'arret d'un vehicule" << endl;
    // \t sert à passer de colonne dans un tab (pour une fois c++ plus pratique que python)
    cout << "km/h\t(a)\t(b)\t(1)\t(2)\t(3)\t(4)\t(5)" << endl;

    //vitesses de 20 à 130 km/h par pas de 10
    for (vitesseKmh = 20; vitesseKmh <= 130; vitesseKmh += 10)
    {
        // Ligne du tableau
        cout << (int)vitesseKmh << "km/h\t";

        // (a) distance de réaction normale : ni fatigue ni alcool
        fatigue = false;
        alcool = false;
        cout << distanceReaction(vitesseKmh, fatigue, alcool) << "m\t";

        // (b) distance freinage
        cout << distanceFreinage(vitesseKmh) << "m\t";

        // (1) distance normale
        cout << distanceTotaleSec(vitesseKmh, false, false) << "m\t";

        // (2) fatigue
        cout << distanceTotaleSec(vitesseKmh, true, false) << "m\t";

        // (3) alcool
        cout << distanceTotaleSec(vitesseKmh, false, true) << "m\t";

        // (4) fatigue + alcool
        cout << distanceTotaleSec(vitesseKmh, true, true) << "m\t";

        // (5) humide + fatigue + alcool
        cout << distanceTotaleHum(vitesseKmh, true, true) << "m\t";

        // Distance en étages
        cout << "( " << distanceEtage(distanceTotaleHum(vitesseKmh, true, true)) << " etages ! )";

        cout << endl;
    }

    
    cout << "(a) reaction" << endl
         << "(b) freinage" << endl
         << "(1) normal" << endl
         << "(2) fatigue" << endl
         << "(3) alcool" << endl
         << "(4) fatigue+alcool" << endl
         << "(5) + route humide" << endl
         << "autres : freins, pneus ou amortisseurs deficients/masse du vehicule/etc." << endl;

    return 0;
}