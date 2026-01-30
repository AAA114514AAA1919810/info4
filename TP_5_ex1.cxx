#include <iostream>
#include <random>
using namespace std;

int alea(int a, int b){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<> dist(a, b);

    int val;
    val = dist(rng);
    return val;
}

char* initChar(int N){
    char* T = new char[N];
    for (int i = 0; i < N; i++ ){
        char a = (char) ((int) ('a') + alea(0, RAND_MAX)%26);
        * (T+i) = a;
    }
    return T;
}

int* initint(int N){
    int* T = new int[N];
    for (int i = 0; i < N; i++ ){
        int a = alea(0, RAND_MAX);
        * (T+i) = a;
    }
    return T;
}

float* initfloat(int N){
    float* T = new float[N];
    for (int i = 0; i < N; i++ ){
        float a = 100*(float(alea(0, RAND_MAX))/RAND_MAX-0.5);
        * (T+i) = a;
    }
    return T;
}

double* initdouble(int N){
    double* T = new double[N];
    for (int i = 0; i < N; i++ ){
        double a = 100*(double(alea(0, RAND_MAX))/RAND_MAX-0.5);
        * (T+i) = a;
    }
    return T;
}

void printChar( char *T, int N){
    for (int i = 0; i < N; i++){
        cout << "T[" << i << "] : " << *(T+i)<< " , adresse : " << (void *)(T+i) << endl;
    }

}

void printInt( int *T_int, int N){
    for (int i = 0; i < N; i++){
        cout << "T_int[" << i << "] : " << *(T_int+i)<< " , adresse : " << T_int+i << endl;
    }
}

void printFloat( float *T_float, int N){
    for (int i = 0; i < N; i++){
        cout << "T_float[" << i << "] : " << *(T_float+i)<< " , adresse : " << T_float+i << endl;
    }
}

void printDouble( double *T_double, int N){
    for (int i = 0; i < N; i++){
        cout << "T_double[" << i << "] : " << *(T_double+i)<< " , adresse : " << T_double+i << endl;
    }
}

int main(){
    int N;
    cout << "taille du tableau ? " << endl;
    cin >> N ;
    char* T = initChar(N);
    printChar(T, N);

    int* T_int = initint(N);
    printInt(T_int, N);

    float* T_float = initfloat(N);
    printFloat(T_float, N);

    double* T_double = initdouble(N);
    printDouble(T_double, N);

    return 0;
}