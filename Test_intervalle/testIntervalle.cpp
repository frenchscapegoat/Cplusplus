#include <iostream>
#include "intervalle.h" // DANS LE MAIN, TOUJOURS AJOUTER LE .h et pas le .cpp
using namespace std;

int main()
{
    bool test_ok;
    int numA;
    int numB;
    cout << "Bonjour, donnez moi 2 entiers, je vais verifier si ils forment un intervalle !"<< endl;
    cin >> numA;
    cin >> numB;
    test_ok=estIntervalle(numA,numB);
    if (test_ok)
        cout << "C'est un intervalle !" << endl;
    else
        cout << "Non, ce n'est pas un intervalle" << endl;
    return 0;
}
