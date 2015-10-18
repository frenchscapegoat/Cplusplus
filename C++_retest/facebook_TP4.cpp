// HBM juillet 2013
// tableaux à 2 dimensions
// les lignes et les colonnes représentent des personnes
// chaque case (i,j) contient  un booléen
// indiquant si i et j sont des amis


#include <iostream>
using namespace std;
const int MAX=4;
//

int main(){
  bool tabAmis[][MAX]={
	    {true,false,true,true},
  		{false,true,true,false},
  		{true,true,true,true},
  		{true,false,true,true}
};


  int nbPersonnes=4;
  cout << "Voici le tableau" << endl;
  for (int i=0;i<MAX;i++)
  {
      for (int j=0;j<MAX;j++)
      {
           if (tabAmis[i][j])
          {
              cout << "La personne " << i << " est amie avec " << j << endl;
          }
      }
      cout << endl;
  }

  return 0;
}


