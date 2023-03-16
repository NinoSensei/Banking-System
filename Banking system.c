#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*The program is written in French*/

/*Structure du client contenant Quatre elements*/
struct client
{
    int NumDuCompte;
    char NomDuClient[20], PrenomDuClient[20];
    int Accounts; /*Nombre de comptes dans la banque*/
};

/*Liste chaînée des clients*/
struct client clients[1000];

/*Les operations sur les comptes*/
void AjoutDeClient();
void SupprimerClient();
void ModifierInfoClient();
void AfficherLesClients();

/*Le programme*/
int main()
{
    /*les variables utilisée dans cette section du programme*/
    int ind_for; /*indice de la boucle for*/
    int choix;   /*le choix de l'operation sur le compte du client*/
    /**/
    printf("_______Bienvenue chez la banque AMOA________\n");
    printf("Par defaut, vous devez entrer les donnees de 5 clients.\n");

    for (ind_for = 0; ind_for < 5; ind_for++)
    {
        AjoutDeClient();
    }
    /*les opérations sur les comptes*/
    do
    {
        printf("\nLes operations sur les comptes:\n");
        printf("\t1.Ajouter un client.\n");
        printf("\t2.Effacer un client.\n");
        printf("\t3.Modifier les informations d'un client.\n");
        printf("\t0.Quitter.\n");
        printf("Entrer votre choix: ");
        scanf("%d", &choix);
        fflush(stdin);

        switch (choix)
        {
        case 0:
            break;
        case 1:
            AjoutDeClient();
            AfficherLesClients();
            break;
        case 2:
            SupprimerClient();
            AfficherLesClients();
            break;
        case 3:
            ModifierInfoClient();
            AfficherLesClients();
            break;
        default:
            printf("Votre choix n'est pas valable!\n");
            break;
        }
    } while (choix != 0);
}

/*Les foctions Supplémentaires*/
/*Fonctoin qui trouve l'indice d'un element dans une list chaînée*/
int ChercherElement(int Element)
{
    int ind;
    for (ind = 1; ind < clients->Accounts + 1; ind++)
    {
        if (clients[ind].NumDuCompte == Element)
        {
            return ind;
        }
    }
    return 0;
}
/*Changer une valeur dans la list chaînée des clients*/
void change(int ch2, char Name[20], char Pre[20], int Num, int del)
{
    if (ch2 == 1)
    {
        strcpy(clients[ChercherElement(del)].NomDuClient, Name);
    }
    else if (ch2 == 2)
    {
        strcpy(clients[ChercherElement(del)].PrenomDuClient, Pre);
    }
    else if (ch2 == 3)
    {
        clients[ChercherElement(del)].NumDuCompte = Num;
    }
}
/*Fonction qui trie les clients ajoutée à la liste des clients*/
void TrierLesClients()
{
    int ind1;
    int ind2;
    struct client tmp;
    for (ind1 = 1; ind1 < clients->Accounts; ind1++)
    {
        for (ind2 = 1; ind2 < clients->Accounts; ind2++)
        {
            if (clients[ind2].NumDuCompte > clients[ind2 + 1].NumDuCompte)
            {
                tmp = clients[ind2];
                clients[ind2] = clients[ind2 + 1];
                clients[ind2 + 1] = tmp;
            }
        }
    }
}

/*Les fonctions Principales*/
/*Afficher la list des clients*/
void AfficherLesClients()
{
    TrierLesClients();
    int ind;
    printf("Les clients sont: (Nom du client|Prenom du client|Numero de compte)\n");
    for (ind = 1; ind < clients->Accounts + 1; ind++)
    {
        printf("\t%s | %s | %d\n", clients[ind].NomDuClient, clients[ind].PrenomDuClient, clients[ind].NumDuCompte);
    }
}
/*Ajouter un client à la list des clients*/
void AjoutDeClient()
{
    int Num;
    printf("Entrer le Numero de compte: ");
    scanf("%d", &Num);
    if (ChercherElement(Num) == 0)
    {
        clients[clients->Accounts + 1].NumDuCompte = Num;
        printf("Nom du client: ");
        scanf("%s", &clients[clients->Accounts + 1].NomDuClient);
        printf("Prenom du client:");
        scanf("%s", &clients[clients->Accounts + 1].PrenomDuClient);
        clients->Accounts++;
    }
    else
    {
        printf("Ce Numero de Compte est deja utilise!\n");
    }
}

/*Supprimer un client du list de client à partir de son numéro de compte*/
void SupprimerClient()
{
    int ind1, ind2;
    printf("Entrer le Numero de compte du client: ");
    scanf("%d", &ind1);
    fflush(stdin);
    if (ChercherElement(ind1) != 0)
    {
        for (ind2 = ChercherElement(ind1) + 1; ind2 < clients->Accounts + 1; ind2++)
        {
            clients[ind2 - 1] = clients[ind2];
        }
        clients->Accounts--;
    }
    else
    {
        printf("Ce Numero n'exist pas dans la base de donnees!\n");
    }
}

/*Modifier une inforamtion du client and son compte*/
void ModifierInfoClient()
{
    int del, ch2;
    int ind;
    char wrd[20];

    printf("Quel client voulez-vous modifier(Numero de compte): ");
    scanf("%d", &del);
    if (ChercherElement(del) != 0)
    {
        printf("Veuillez-vous modifier:\n");
        printf("\t1.Le Nom du client.\n");
        printf("\t2.Le Prenom du client.\n");
        printf("\t3.Le numero de compte.\n");
        printf("Votre choix est: ");
        scanf("%d", &ch2);
        switch (ch2)
        {
        case 1:
            printf("Entrer le nouveau Nom: ");
            scanf("%s", &wrd);
            change(ch2, wrd, "", ind, del);
            break;
        case 2:
            printf("Entrer le nouveau Prenom: ");
            scanf("%s", &wrd);
            change(ch2, "", wrd, 0, del);
            break;
        case 3:
            printf("Entrer le nouveau Numero du compte: ");
            scanf("%d", &ind);
            change(ch2, "", "", ind, del);
            break;
        default:
            printf("Ce choix n'est pas considere!\n");
            break;
        }
    }
    else
    {
        printf("Ce Numero n'exist pas dans la base de donnees!\n");
    }
}
