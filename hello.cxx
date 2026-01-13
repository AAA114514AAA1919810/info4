// Bourdon Benoit 12/01/2026


#include <iostream>
#include <random>

using namespace std;



int additionner(int a, int b){
    return a + b;
}



void initTab(int T[50]){
    int a=1 , b=50;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<> dist(a,b);
int i = 0;
for (int i ; i < 50 ; i++)
{
    int val;
    val = dist(rng); //génère un nombre aléatoire entre a et b,
                     //peut être répété plusieurs fois
    T[i] = val;
}
}


int printTab(int T[50] , int nbCol ){
    int i;
    for (int i = 0; i < 50 ; i++ ){
        
        if (i%10 == 0){
            cout << T[i] << endl;
        }
        else{
            cout << T[i];
        }
    }


}


int main(){
/*  int a, b ,som;
    cout << "saisir 2 entiers :";
    cin >> a >> b;
    cout << a << " + " << b << " = ";
    som = additionner(a, b);
    cout << som << endl;
*/
    int T[50];
    initTab(T);

    int nbCol = 10;
    cout << printTab( T, nbCol);
    return 0;
}