#include <iostream>
#include <cmath>
using namespace std;

//  EXERCICE 1
// struct Point{
//     float abs, ord;
// };

// Point saisirPoint(){
//     Point Pa;
//     cout << "absci :";
//     cin >> Pa.abs;
//     cout << "ord : ";
//     cin >> Pa.ord;
//     return Pa;
// }

// void afficherPoint(Point p){
//     cout << p.abs << endl;
//     cout << p.ord << endl;
// }

// float calculerDistance(Point p1, Point p2){
//     float res;
//     res = sqrt((p2.abs-p1.abs)**2+(p2.ord-p1.ord)**2);
//     return res;
// }

// bool estTriangle(Point p1, Point p2, Point p3){
//     double a = calculerDistance(p1, p2);
//     double b = calculerDistance(p2, p3);
//     double c = calculerDistance(p3, p1);
//     if(a< b+c){
//         if(b<a+c){
//             if(c < a+b){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// int main(){
//     Point A;
//     Point B;
//     Point C;
//     A = saisirPoint();
//     B = saisirPoint();
//     C = saisirPoint();
//     cout << A << endl;
//     cout<< calculerDistance(A,B) <<endl;
//     if(estTriangle(A,B,C)==true){
//         cout<< "c'est un triangle"<<endl;
//     }
//     else{
//         cout<<"ce n'est pas triangle"<<endl;
//     }
//     return 0;
// }

// EXERCICE2
struct Eleve{
    string nom, prenom;
    int an;
    char se;
    float moy;
}
struct Class{
    int ne;
    Eleve class[25]
}
int Nbel;
Eleve class[Nbel];
Eleve saisirEleve(){
    Eleve e;
    cin>>e.nom;
    cin>>e.prenom;
    cin>>e.an;
    cin>>e.se;
    while(e.se=! "M" or "F"){
        cin>>e.se;
    }
    cin>>e.moy;
    return e; 
}

int calculerAge(int e.an){
    int age = getCurrentYear() - e.an;
    return age;
}
void afficherEleve(Eleve e){
    cout<<e <<endl;
    cout<<calculerAge(e.an)<<endl;
}

Class saisirClass(int n){
    
}

int main(){
    cin>> Nbel;
    while(Nbel>25){
        cin>> Nbel;
}
    return 0;
}