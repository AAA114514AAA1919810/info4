#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

// EXERCICE 1
struct Point{
    float abs, ord;
};

Point saisirPoint(){
    Point Pa;
    cout << "absci :";
    cin >> Pa.abs;
    cout << "ord : ";
    cin >> Pa.ord;
   return Pa;
}

void afficherPoint(Point p){
    cout << p.abs << endl;
    cout << p.ord << endl; 
}

float calculerDistance(Point p1, Point p2){
    float res;
    res = sqrt((p2.abs - p1.abs) * (p2.abs - p1.abs) + (p2.ord - p1.ord) * (p2.ord - p1.ord));
    return res;
}

bool estTriangle(Point p1, Point p2, Point p3){ 
    double a = calculerDistance(p1, p2);
    double b = calculerDistance(p2, p3);
    double c = calculerDistance(p3, p1);
    if(a< b+c){
        if(b<a+c){
            if(c < a+b){
                return true;
            }
        }
    }
    return false;
}
/*
int main(){
    Point A;
    Point B;
    Point C;
    A = saisirPoint();
    B = saisirPoint();
    C = saisirPoint();
    afficherPoint(A);
    cout << calculerDistance(A,B) <<endl;
    if(estTriangle(A,B,C)==true){
        cout << "c'est un triangle"<<endl; 
    }
    else{
        cout <<"ce n'est pas triangle"<<endl;
    }
    return 0;
 }
*/
// EXERCICE2
struct Eleve{
    string nom, prenom;
    int annee;
    char sex;
    float moy;
};

struct Class{
    int nbe;
    Eleve eleves[25];
};

Eleve saisirEleve(){
    Eleve e;
    cout << "Nom : ";
    cin >> e.nom;

    cout << "Prenom : ";
    cin >> e.prenom;

    cout << "Age : ";
    cin >> e.annee;

    cout << "Sexe (M/F) : ";
    cin >> e.sex;
    while(e.sex != 'M' && e.sex != 'F'){
        cin>>e.sex;
    }
    cin>>e.moy;
    return e; 
}

int getCurrentYear() {
    // pour cette partie j'ai du chercher sur internet, je ne sais pas comment obtenir l'annee actuelle
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    return now->tm_year + 1900; // tm_year = annees depuis 1900
}

int calculerAge(int annee){
    int age = getCurrentYear() - annee;
    return age;
}
void afficherEleve(Eleve e){
    cout << "Nom : " << e.nom << endl;
    cout << "Prenom : " << e.prenom << endl;
    cout << "Annee de naissance : " << e.annee << endl;
    cout << "Sexe : " << e.sex << endl;
    cout << "Moyenne : " << e.moy << endl;
    cout << "Age : " << calculerAge(e.annee) << " ans" << endl;
}

Class saisirClasse(int n) {
    Class c;
    // au cas où la valeur rentree n'est pas dans l'intervalle autorisee d'eleves
    if (n < 1) n = 1;
    if (n > 25) n = 25;
    
    c.nbe = n;

    for (int i = 0; i < n; i++) {
        cout << "info Eleve " << i + 1 << endl;
        c.eleves[i] = saisirEleve();
    }

    return c;
}

void afficherClasse(Class c) {
    cout << "___ Classe (nombre d'eleves : " << c.nbe << ")___" << endl;
    for (int i = 0; i < c.nbe; i++) {
        cout << "info Eleve " << i + 1 << endl;
        cout << "Nom : " << c.eleves[i].nom << endl;
        cout << "Prenom : " << c.eleves[i].prenom << endl;
        cout << "Annee de naissance : " << c.eleves[i].annee << endl;
        cout << "Sexe : " << c.eleves[i].sex << endl;
        cout << "Moyenne : " << c.eleves[i].moy << endl;
        cout << "Age : " << calculerAge(c.eleves[i].annee) << " ans" << endl;
    }
}


bool existeEleve(Class c, string nom, string prenom) {
    for (int i = 0; i < c.nbe; i++) {
        if (c.eleves[i].nom == nom && c.eleves[i].prenom == prenom) {
            return true; // dans la class
        }
    }
    return false; // pas dans la class
}

int indiceEleve(Class c, string nom, string prenom) {
    for (int i = 0; i < c.nbe; i++) {
        if (c.eleves[i].nom == nom && c.eleves[i].prenom == prenom) {
            return i;
        }
    }
    return -1;
}

Class ajouterEleve(Class c, Eleve e) {
    if (c.nbe < 25) {          // verifie que class non complete
        c.eleves[c.nbe] = e;   // ajouter l'eleve
        c.nbe++;               // nb eleves + 1
    } 
    else {
        cout << "Erreur : la classe est pleine " << endl;
    }
    return c;                  // renvoie classe modifiee
}

Class supprimerEleve(Class c, string nom, string prenom) {
    int indice = -1;

    // Chercher indice eleve
    for (int i = 0; i < c.nbe; i++) {
        if (c.eleves[i].nom == nom && c.eleves[i].prenom == prenom) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        cout << "L'eleve " << nom << " " << prenom << " non trouve " << endl;
        return c; // on ne change pas la classe si eleve non trouve
    }

    // remplace l'info de chaque eleve par l'eleve suivant
    for (int i = indice; i < c.nbe - 1; i++) {
        c.eleves[i] = c.eleves[i + 1];
    }

    c.nbe--; // nb eleve - 1
    cout << "L'eleve " << nom << " " << prenom << " a ete supprime" << endl;

    return c;
}

int compterNb(Class c, char s) {
    int n= 0;
    for (int i = 0; i < c.nbe; i++) {
        if (c.eleves[i].sex == s) {
            n++;
        }
    }
    return n;
}

float calculerMoyenne(Class c) {

    float somme = 0.0;
    for (int i = 0; i < c.nbe; i++) {
        somme += c.eleves[i].moy;
    }

    return somme / c.nbe;
}



int main(){
    int n;
    cout << "nb eleves de la classe : " << endl;
    cin >> n;

    // Saisie eleves

    // pour l'etape de création des eleves, lorsque je rentre le sexe, le programme freeze, je ne sais pas pourquoi,
    // donc je n'ai pas pu tester le reste
    Class maClasse = saisirClasse(n);

    // Affichage eleves
    cout << endl << "___ Affichage des eleves de la classe ___" << endl;
    afficherClasse(maClasse);

    // Saisie + ajout nouvel eleve s'il n'existe pas
    cout << endl << "___ Ajouter un nouvel eleve ___" << endl;
    Eleve nouveau = saisirEleve();
    if (!existeEleve(maClasse, nouveau.nom, nouveau.prenom)) {
        maClasse = ajouterEleve(maClasse, nouveau);
        cout << "Nouvel eleve ajoute." << endl;
    } else {
        cout << "Cet eleve existe dejà dans la classe !" << endl;
    }

    // Saisie ou suppression eleve s'il existe
    cout << endl << "___ Supprimer un eleve ___" << endl;
    string nomSuppr, prenomSuppr;
    cout << "Nom de l'eleve à supprimer : " << endl;
    cin >> nomSuppr;
    cout << "Prenom de l'eleve à supprimer : " << endl;
    cin >> prenomSuppr;
    maClasse = supprimerEleve(maClasse, nomSuppr, prenomSuppr);

    // Affichage eleves apres modifications
    cout << endl << "=== Classe apres modifications ===" << endl;
    afficherClasse(maClasse);

    // nb filles garçons
    int nbFilles = compterNb(maClasse, 'F');
    int nbGarcons = compterNb(maClasse, 'M');
    cout << endl << "Nombre de filles : " << nbFilles << endl;
    cout << "Nombre de garçons : " << nbGarcons << endl;

    // Moy generale classe
    cout << "Moyenne generale de la classe : " << calculerMoyenne(maClasse) << endl;

    return 0;
}