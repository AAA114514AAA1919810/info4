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
        *pos = 9;
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

int main(){
    int val = alea(1, 3);
    cout << " nb random entre 1 et 3 : " << val << endl;
    int posMax = 9;
    int pos = 2;
    int sens = -1;
    deplacer(posMax, &pos, sens);
    cout << "Position apres deplacement : " << pos << endl;

    sens = sensDeplacer(sens, pos, posMax);
    cout << "sens apres verification : " << sens << endl;


    return 0;
}