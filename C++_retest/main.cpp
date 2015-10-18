/*
EX1 TP3 : Tableau 1D
ROMAIN SCOHY | Info AS
Derniere modification : 25/09/2015 00:07
*/

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

const int MAXS=20; // nombre de cases reservées en mémoire

int main()
{
    /* DECLARATION DES VARIABLES */

    //lesSports[0] -> lesSports[19]

    string lesSports[MAXS]={"TENNIS","FOOTBALL","BADMINTON","JUDO","HANDBALL","GYMNASTIQUE"};
    // TAILLE EFFECTIVE = nombre de cases remplies
    int nbSports=6;

    //
    /* QUESTION 2 : AFFICHAGE 1er et DERNIER Sport */
    //

    cout << lesSports[0] <<endl;
    cout << lesSports[nbSports-1] << endl;

    //
    /* QUESTION 3 : AFFICHAGE LISTE SPORTS */
    //

    int i; // INUTILE de déclarer 2fois

    // On parcourt le tableau entier, donc boucle POUR, puis on affiche
    for (int i=0;i<=nbSports;i++)
    {
        cout << lesSports[i] <<endl;
    }

    //
    /* QUESTION 4 : AFFICHAGE DANS L'ORDRE INVERSE */
    //

    for (int i=nbSports;i>=0;i--)
    {
        cout << lesSports[i] <<endl;
    }

    //
    /* QUESTION 5 : AJOUTER SPORTS */
    //

    int nbAjouter;

    cout << "Combien de sports voulez-vous ajouter ?" <<endl;
    cin >> nbAjouter;

    // On ne peut rajouter des noms uniquement si on ne depasse pas MAXS. On boucle avec TANT QUE pour ne pas dépasser la taille maximum du tableau
    while (nbAjouter+nbSports>MAXS)
    {
        cout << "Rentrez une valeur comprise entre 1 et "<< MAXS-nbSports <<endl;
        cin >> nbAjouter;
    }

    // AJOUT
    string sport;
    int futurtaille = nbSports+nbAjouter;
    for (int i=nbSports;i<futurtaille;i++)
    {
        cout << "Svp, rentrez le nouveau sport de la case n°" << i <<endl;
        cin >> sport;
        lesSports[i]=sport;
        nbSports=nbSports+1;
    }

    // Affichage
    cout << "TABLEAU FINAL" <<endl;
    for (int i=0;i<nbSports;i++)
    {
      cout << lesSports[i] <<endl;
    }

    //
    /* QUESTION 6 : SUPPRESSION 1ER SPORT */
    //
//
//    for (int i=0;i<nbSports;i++)
//    {
//        lesSports[i]=lesSports[i+1];
//    }
//    nbSports=nbSports-1;
//    // Affichage Post Suppression
//    cout <<"---- Apres Suppression du 1er sport---"<<endl;
//    for (int i=0;i<=nbSports;i++)
//    {
//        cout << lesSports[i] <<endl;
//    }

    //
    /* QUESTION 7 : RECHERCHE SPORT CA MERDE */
    //

    int pos;
    int ind=0;
    string chaine_test;
    int b_chaine_test=0;

    cout << "Rentrez un nom de sport, je tacherai de verifier s'il est present dans le tableau" << endl;
    cin >> chaine_test;

    while (b_chaine_test==0 and ind<nbSports)
    {
        if (chaine_test == lesSports[ind])
        {
            pos = ind;
            b_chaine_test=1;
        }
        ind=ind+1;
    }

    // AFFICHAGE
    if (b_chaine_test=1)
    {
        cout << "Ce sport est bien present a la case " << pos << endl;
        cout << lesSports[pos] << endl;
    }
    else
    {
        cout << "Ce sport est inconnu" << endl;
    }

//    //
//    /* QUESTION 8 : RETOUR AJOUT SPORT | Commentez svp la question 5 */
//    //
//
//    int nbAjouter;
//
//    cout << "Combien de sports voulez-vous ajouter ?" <<endl;
//    cin >> nbAjouter;
//
//    // On ne peut rajouter des noms uniquement si on ne depasse pas MAXS. On boucle avec TANT QUE pour ne pas dépasser la taille maximum du tableau
//    while (nbAjouter+nbSports>MAXS)
//    {
//        cout << "Rentrez une valeur comprise entre 1 et "<< MAXS-nbSports <<endl;
//        cin >> nbAjouter;
//    }
//
//    // AJOUT
//    string sport;
//    string sportmaj; // Sert de variable temporaire pour le passage en MAJ
//    int futurtaille = nbSports+nbAjouter;
//    for (int i=nbSports;i<futurtaille;i++)
//    {
//        cout << "Svp, rentrez le nouveau sport de la case n°" << i <<endl;
//        cin >> sport;
//
//        // PASSAGE EN MAJUSCULES
//        for (int j=0;j<sport.length()-1;j++) // Peut etre sans le -1
//        {
//            sportmaj[j] = toupper(sport[j]);
//        }
//        sport=sportmaj;
//
//        //
//        lesSports[i]=sport;
//        nbSports=nbSports+1;
//    }
//
//    // Affichage
//    cout << "TABLEAU FINAL" <<endl;
//    for (int i=0;i<nbSports;i++)
//    {
//      cout << lesSports[i] <<endl;
//    }
//
//    //
//    /* Question 9 : SUPPRESSION MULTIPLE | Commentez la question 6 svp*/
//    //
//    char avis;
//    bool b_suppression=true;
//    cout << "Je vais supprimer la contenu de la 1ere case" << endl;
//
//    while (nbSports>0 and b_suppression)
//    {
//        for (int i=0;i<nbSports;i++)
//        {
//            lesSports[i]=lesSports[i+1];
//        }
//        nbSports=nbSports-1;
//
//        // Affichage Post Suppression
//        cout <<"---- Apres Suppression---"<<endl;
//        for (int i=0;i<=nbSports;i++)
//        {
//            cout << lesSports[i] <<endl;
//        }
//
//        cout << "Voulez vous continuer (o/n)?" << endl;
//        cin >> avis;
//        b_suppression = (avis='o');
//    }
//
//    // Quand le tableau est VIDE
//    if (nbSports=0)
//    {
//        cout << "Desole, il n'y a plus rien a supprimer : le tableau est vide !" << endl;
//    }
//
//	system("PAUSE");
    return 0;
}
