/* ALGO POKER COMBI
Romain SCOHY DUT INFORMATIQUE ORSAY 09/01/2015 21:45 fini
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int NBTIRAGE = 5;
const int NBCOULEURS = 4;
const int NBHAUTEURS = 13;
const int NBCARTES = NBCOULEURS*NBHAUTEURS;




/* NOS FONCTIONS */
/* Fonction CREER PAQUET CARTE */
void creer_paquet(int tabcarte[],int nb)
{
    for (int i=0;i<nb;i++)
    {
        tabcarte[i] = i;
    }
}

// --------------------------------------------------------------

/* 1 Fonction TRI : Tri par insertion*/
void fct_tri(int tabmain[],int nb)
{
    int valeur_tri;
    int j;
    for (int i=0;i<nb;i++)
    {
        valeur_tri = tabmain[i];
        j = i;
        while (j>0 and tabmain[j-1]>valeur_tri)
        {
            tabmain[j] = tabmain[j-1];
            j = j-1;
        }
        tabmain[j] = valeur_tri;
    }
}

/* 2 - Fonction TraductionTableau */
void fct_trad(int tabmain[],int taille,int couleur[],int rang[])
{
    for (int i=0;i<taille;i++)
    {
        couleur[i] = tabmain[i]/13;
        rang[i] = tabmain[i]%13;
    }
}

//---------------------------------------------------------------

/* 3 - Fonction Suite RETOURNE vrai si carte suivante correspond à celle du rang suivant*/
bool fct_suite(int tab[], int pos)
{
    bool suite_ok=false;
    suite_ok = ((tab[pos+1]%13) == ((tab[pos]+1)%13));
    return(suite_ok);
}

/* 4 - Fonction Couleur RETOURNE vrai si couleur suivante est la meme que couleur actuelle*/
bool fct_couleur(int tab[], int pos)
{
    bool couleur_ok=false;
    couleur_ok = ((tab[pos+1]/13) == (tab[pos]/13));
    return(couleur_ok);
}

/* 5 - Fonction MemeRang RETOURNE vrai si carte suivante possede le meme rang que la carte actuelle*/
bool fct_memerang(int tab[], int pos)
{
    bool pair_ok=false;
    pair_ok = ((tab[pos+1]%13) == (tab[pos]%13));
    return(pair_ok);
}

/* 6 - Fonction Affiche MAIN*/
void affiche_main(int tab[],int nb)
{
    int rang[nb];
    int couleur[nb];

    for (int i=0;i<nb;i++)
    {
        rang[i]=tab[i]%13;
        couleur[i]=tab[i]/13;
    }
    for (int i=0;i<nb;i++)
    {
        cout << "CARTE "<< i+1 << " COULEUR " <<couleur[i] << "| RANG :  "<< rang[i]+2 << endl; //+2 necesaire pour rang "propre"

    }
}

/* 7 - Fonction Affiche Grade */
void affiche_grade(int grade)
{
    switch(grade)
    {
    case 1 :
        {
           cout << "Vous avez un Highcard"<<endl;
        }
        break;
    case 2 :
        {
            cout << "Vous avez une Paire"<<endl;
        }
        break;
    case 3 :
        {
            cout << "Vous avez une Double Paire"<<endl;
        }
        break;
    case 4 :
        {
            cout << "Vous avez un Brelan"<<endl;
        }
        break;
    case 5 :
        {
            cout << "Vous avez une Quinte"<<endl;
        }
        break;
    case 6 :
        {
            cout << "Vous avez une Couleur"<<endl;
        }
        break;
    case 7 :
        {
            cout << "Vous avez un Full"<<endl;
        }
        break;
    case 8 :
        {
            cout << "Vous avez un Carre"<<endl;
        }
        break;
    case 9 :
        {
            cout << "Vous avez une Quinte Flush"<<endl;
        }
        break;
    case 10 :
        {
            cout << "Vous avez une Quinte Flush Royale"<<endl;
        }
        break;
    }
}


int main()
{
    int tabmain [NBTIRAGE];
    int tabcarte [NBCARTES];
    int vrainbcartes = NBCARTES;
    int maincarte=0;
    srand(time(NULL));

    /* 1E PARTIE = INITIALISATION MAIN */
    creer_paquet(tabmain,NBTIRAGE);


    /* On cree la main. */
    /*
    On initialise la valeur des cartes a -1 pour avoir une "fausse main"
    Puis on pioche et on redifini le paquet de carte a chaque fois
    */
    for (int i=0;i<vrainbcartes;i++)
    {
        tabcarte[i] = i;
    }
    for (int i=0;i<maincarte;i++)
    {
        tabmain[i] = -1;
    }
    while (maincarte < vrainbcartes and maincarte< NBTIRAGE)
    {
        int atirer;
        atirer = rand()%vrainbcartes; // Variable qui donne la case du tableau a tirer
        tabmain[maincarte] = tabcarte[atirer]; // On le place dans la main.

        /* Maintenant, il faut enlever cette carte du vrainbcartes. */
        /* Pour cela, on la remplace par la valeur de la derniere case du tableau, puis on reduit le tableau. */
        tabcarte[atirer]=tabcarte[vrainbcartes];

        vrainbcartes=vrainbcartes-1;
        maincarte=maincarte+1;
    }

    /* J'ai regroupe ici tous les jeux de tests, il n'y a que UNCOMMENT la combinaison voulue */

//    /* Highcard */
//    tabmain[0]= 50;
//    tabmain[1]= 9;
//    tabmain[2]= 21;
//    tabmain[3]= 43;
//    tabmain[4]= 27;
//    maincarte=5;
//    /* PAIR */
//    tabmain[0]= 51;
//    tabmain[1]= 25;
//    tabmain[2]= 6;
//    tabmain[3]= 43;
//    tabmain[4]= 26;
//    maincarte=5;
//    /* DOUBLEPAIR */
//    tabmain[0]= 34;
//    tabmain[1]= 21;
//    tabmain[2]= 4;
//    tabmain[3]= 17;
//    tabmain[4]= 37;
//    maincarte=5;
//    /* BRELAN */
//    tabmain[0]= 22;
//    tabmain[1]= 48;
//    tabmain[2]= 35;
//    tabmain[3]= 16;
//    tabmain[4]= 32;
//    maincarte=5;

//    /* QUINTE */
//    tabmain[0]= 26;
//    tabmain[1]= 14;
//    tabmain[2]= 2;
//    tabmain[3]= 29;
//    tabmain[4]= 17;
//    maincarte=5;
//    /* COULEUR */
//    tabmain[0]= 23;
//    tabmain[1]= 19;
//    tabmain[2]= 17;
//    tabmain[3]= 15;
//    tabmain[4]= 14;
//    maincarte=5;
//    /* FULL */
//    tabmain[0]= 50;
//    tabmain[1]= 24;
//    tabmain[2]= 11;
//    tabmain[3]= 47;
//    tabmain[4]= 21;
//    maincarte=5;

//    /* CARRE */
//    tabmain[0]= 51;
//    tabmain[1]= 25;
//    tabmain[2]= 12;
//    tabmain[3]= 38;
//    tabmain[4]= 19;
//    maincarte=5;
//    /* QF  */
//    tabmain[0]= 16;
//    tabmain[1]= 17;
//    tabmain[2]= 18;
//    tabmain[3]= 19;
//    tabmain[4]= 20;
//    maincarte=5;
//    /* QFR */
//    tabmain[0]= 8;
//    tabmain[1]= 9;
//    tabmain[2]= 10;
//    tabmain[3]= 11;
//    tabmain[4]= 12;
//    maincarte=5;



    /* 2E PARTIE TESTS */

    /* On commence par tester la combinaison la plus forte : QFR. */
    /* Pour cela on teste si on a 5 cartes qui se suivent */
    /* On teste aussi la couleur */
    /* Enfin, on regarde si la 1e carte est un 10 (donc 8 dans rang [i]) */

    /* LISTE DES GRADES */
    /*
    QFR = 10
    QF = 9
    CARRE = 8
    FULL = 7
    COLOR = 6
    QUINTE = 5
    BRELAN = 4
    DOUBLEPAIRE = 3
    PAIRE = 2
    HIGHCARD = 1
    */

    int grade=0;
    bool continu=true;
    int cpt=0;
    while (continu and cpt<maincarte-1)
    {
        continu=fct_suite(tabmain,cpt);
        cpt=cpt+1;
    }
    if (continu)
    {
        /* On affecte QUINTE, et on teste si on a QF */
        grade=5;
        cpt=0;
        while (continu and cpt<maincarte-1)
        {
            continu=fct_couleur(tabmain,cpt);
            cpt=cpt+1;
        }
        if (continu)
            {
                /* On affecte QF, et on teste QF */
                grade=9;
                // On teste juste la 1ere valeur, puisqu'on a trié notre tableau. Si j'ai un 10 sur la 1e valeur, forcement le reste correspond a V D R AS
                if (tabmain[0]==8)
                {
                    grade=10;
                }
            }

    }
    /*
    On a terminé avec 3 combinaisons dont les cartes forment une suite.
    Si on a une QUINTE, on ne peut avoir de combinaison qui découle de la fonction PAIRE
    Des lors, on vérifie si grade=0; on cherche une paire, sinon, on cherche la highcard
    */
    if (grade==0)
    {
        bool une_pair=false;
        int cpt=0;
        while (not une_pair and cpt<maincarte-1)
        {
            une_pair=fct_memerang(tabmain,cpt);
            cpt=cpt+1;
        }
        if(une_pair and cpt <maincarte)
        {
            grade=2;
            /* Il nous reste les combinaison suivantes :
            CARRE
            FULL
            BRELAN
            DOUBLE PAIR
            On teste d'abord si on peut trouver un carre (plus haut grade), puis le reste apres

            On ne reinitialise pas le compteur car inutile de faire des tests en trop
            */
            une_pair=fct_memerang(tabmain,cpt);
            cpt=cpt+1; // PAS SUR QUE CA FONCTIONNE

            /* Des lors
            Si une_pair est false et cpt > maincarte, on ne peut plus rien trouver de grade supérieur à PAIRE
            Si une_pair est false et cpt < maincarte, on peut encore trouver DOUBLEPAIRE.
            Si une_pair est true et cpt >= maincarte, on a trouvé BRELAN et on ne peut plus rien trouver de grade supérieur
            Si une_pair est true et cpt < maincarte, on peut encore trouver FULL ou CARRE
            */
            if (not une_pair and cpt<maincarte)
            {
                /* On teste DOUBLEPAIRE */
                une_pair=fct_memerang(tabmain,cpt);
                if (une_pair)
                {
                    grade=3;
                }
            }

            else if (une_pair and cpt>=maincarte)
            {
                /* On affecte BRELAN */
                grade=4;
            }
            else if (une_pair and cpt<maincarte)
            {
                /* On affecte BRELAN */
                grade=4;
                /* On teste si carte suivante=carte */
                une_pair=fct_memerang(tabmain,cpt);
                if (une_pair)
                {
                    /* On affecte CARRE */
                    grade=8;
                }
                else
                {
                    /* On teste si FULL */
                    cpt=cpt+1;
                    bool full=true;
                    full=fct_memerang(tabmain,cpt);
                    if(full)
                    {
                        /* On affecte FULL */
                        grade=7;
                    }
                }

            }
        }
        else if (une_pair and cpt== maincarte)
        {
            grade=2;
        }
        else
        {
            /* TEST COLOR */
            bool bcolor=true;
            cpt=0;
            while ( bcolor and cpt<maincarte-1)
            {
                bcolor=fct_couleur(tabmain,cpt);
                cpt=cpt+1;
            }
            if (bcolor)
            {
                grade=6;
            }
            else
            {
                /* Recherche HIGHCARD */
                grade=1;
                cpt=0;
                int max_highcard=tabmain[0]%13;

                for (int i=1;i<maincarte;i++)
                {
                    if ((max_highcard%13)<(tabmain[i]%13))
                    {
                        max_highcard=tabmain[i];
                    }
                }
            }
        }

    }


    /* 3E PARTIE = Affichage main */
    /* J'ai choisi de l'afficher à l'écran, car cela prend moins de ressources que de tests sur les 5 cartes */
    cout << "Les couleurs vont de 0 a 3 :" << endl;
    cout << "0 = PIQUE"<< endl;
    cout <<"1 = TREFLE"<< endl;
    cout <<"2 = CARREAU"<< endl;
    cout <<"3 = COEUR"<< endl;
    cout <<" "<< endl;
    cout <<"Les rangs vont de 0 a 12, 0 correspond a un 2, le 12 correspond a l'As"<< endl;
    cout <<"0= 2"<< endl;
    cout <<"1= 3"<< endl;
    cout <<"2= 4"<< endl;
    cout <<"3= 5"<< endl;
    cout <<"4= 6"<< endl;
    cout <<"5= 7"<< endl;
    cout <<"6= 8"<< endl;
    cout <<"7= 9"<< endl;
    cout <<"8= 10"<< endl;
    cout <<"9= Valet"<< endl;
    cout <<"10= Dame"<< endl;
    cout <<"11= Roi"<< endl;
    cout <<"12= As"<< endl;
    cout <<" "<< endl;
    cout <<" "<< endl;

    affiche_main(tabmain,maincarte);

    /* 4E PARTIE = AFFICHAGE DE LA COMBINAISON TROUVE */
    affiche_grade(grade);
    return 0;
}
