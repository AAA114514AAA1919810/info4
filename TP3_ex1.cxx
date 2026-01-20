#include <iostream>
using namespace std;

void saisirPoint(float *x, float *y){
    cout << "saisir x : ";
    cin >> *x;
    cout << "saisir y : ";
    cin >> *y;
}

void saisirDelta(float *dx, float *dy){
    cout << "saisir delta x : ";
    cin >> *dx;
    cout << "saisir delta y : ";
    cin >> *dy;
}

void saisirPointMesg(float *x, float *y, string mesgx, string mesgy){
    cout << mesgx;
    cin >> *x;
    cout << mesgy;
    cin >> *y;
}

void translater(float *x, float *y, float dx, float dy){
    *x += dx;
    *y += dy;
}

void afficherPoint(float x, float y){
    cout << "(" << x << ","<< y << ")" << endl;
}

int main(){
    float x, y ;

/*
    saisirPoint(&x, &y);
    cout << "x = " << x << " , y = " << y << endl;
*/
    float dx, dy;
/*
    saisirDelta( &dx, &dy);
    cout << "delta x = " << dx << " , delta y = " << dy << endl;
*/

    string mesgx = "abscisse du point ? ";
    string mesgy = "ordonne du point ? ";
    saisirPointMesg(&x, &y, mesgx, mesgy);

    string mesgdx = "abscisse de delta ? ";
    string mesgdy = "ordonne de delta ? ";
    saisirPointMesg(&dx, &dy, mesgdx, mesgdy);
    cout << "coordonnee xy : " ;
    afficherPoint(x, y);
    cout << endl << "vecteur delta xy : ";
    afficherPoint(dx, dy);

    translater(&x, &y, dx, dy);
    cout << endl << "coordonnee xy apres translation de vecteur delta : ";
    afficherPoint(x,y);
    cout << endl;

    return 0;
}