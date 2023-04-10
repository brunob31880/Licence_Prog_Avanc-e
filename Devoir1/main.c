#include <stdio.h>
#include <stdlib.h>
#define rangees 6
#define colonnes 7
#define jeton1 'X'
#define jeton2 'O'



typedef enum
{
    Jeton1 = 48,
    Jeton2 = 49,
    Vide = 50
} jetons;
typedef enum
{
    Jouer = 48,
    Test = 49,
    Quitter = 50
} choix_possible;

typedef enum
{
    Joueur1 = 48,
    Joueur2 = 49,
} joueur_possible;

int plateau[rangees][colonnes];
void flush_stdin()
{
    while (getchar() != '\n')
        ;
}
int getChoice()
{

    int input;
    choix_possible choix;
    int quit = 0;
    while (!quit)
    {

        printf("Quelle option [0-2]? (JOUER=0/Test=1/Quitter=2)\n");
        input = getchar();
        choix = input;
        switch (choix)
        {
        case Jouer:
            quit = 1;
            break;
        case Test:
            quit = 1;
            break;
        case Quitter:
            exit(EXIT_SUCCESS);
        default:
            break;
        }
    }
    return choix;
}

void init_Plateau()
{
    for (int i = 0; i < rangees; i++)
    {
        for (int j = 0; j < colonnes; j++)
        {
            plateau[i][j] = Vide;
        }
    }
}
/**
 *
 */
char getShownJeton(int i, int j)
{
    if (plateau[i][j] == Vide)
    {
        return ' ';
    }
    else if (plateau[i][j] == Jeton1)
    {
        return 'X';
    }
    else if (plateau[i][j] == Jeton2)
        return 'O';
    // Valeur inconnue
    else
        return 'E';
}

char shownPourJeton(jetons jeton)
{
    return jeton == Jeton1 ? 'X' : 'O';
}

void afficher_Plateau()
{
    printf("--------------------\n");
    printf("Affichage du Plateau\n");
    printf("--------------------\n");
    printf(" ");
    for (int j = 0; j < colonnes; j++)
        printf("%d", (j + 1));
    printf("\n");
    for (int i = 0; i < rangees; i++)
    {
        printf("%d", (i + 1));
        for (int j = 0; j < colonnes; j++)
        {
            printf("%c", getShownJeton(i, j));
        }
        printf("\n");
    }
    printf("--------------------\n");
}
/**
 *
 */
char *getStringForJoueur(joueur_possible joueur)
{
    if (joueur == Joueur1)
        return "Joueur1";
    else
        return "Joueur2";
}

/**
 * Regarde si le choix de colonne est un choix correct
 */
int check_colonne(int col)
{
    // printf("Test avec %d",col);
    if ((col < 1) || (col > colonnes))
        return 0;
    else if (plateau[0][col] != Vide)
    {
        printf("Case non vide %d", plateau[0][col]);
        return 0;
    }
    else
        return 1;
}
/**
 * col valeur saisie
 */
void insere_en_colonne(int col, joueur_possible joueur)
{
    if (col < 1 || col > colonnes)
    {
        printf("Mauvais choix de colonne\n");
        return;
    }
    int cpt = 0;
    for (int i = 0; i < rangees; i++)
    {
        if (plateau[i][col - 1] != Vide)
        {
            printf("Case %d %d occupée\n", i + 1, col);
            break;
        }
        else
            cpt = i;
    }

    printf("%s insertion en ligne %d\n", getStringForJoueur(joueur), cpt + 1);
    plateau[cpt][col - 1] = joueur == Joueur1 ? Jeton1 : Jeton2;
}
/**
 *
 */
void coup_du_joueur(joueur_possible joueur)
{
    printf("--------------------\n");
    printf("Coup du joueur %s\n", getStringForJoueur(joueur));
    printf("--------------------\n");
    int ret = 0;
    int col;
    while (!ret)
    {
        // flush
        flush_stdin();
        char coup[1];
        printf("%s Entrez votre choix de colonne ? \n", getStringForJoueur(joueur));
        fgets(coup, 2, stdin);
        printf("Coup colonne %c\n", coup[0]);
        col = (int)coup[0] - 48;
        ret = check_colonne(col);
        // printf("Ret %d\n",ret);
    }
    insere_en_colonne(col, joueur);
}
/**
 *
 */
char getCharForJeton(jetons jeton)
{
    if (jeton == Jeton1)
        return jeton1;
    else if (jeton == Jeton2)
        return jeton2;
    else
        return ' ';
}
/**
 *
 */
int fin_avec_ligne(jetons jeton)
{
    int nb = 0;
    // ligne trouvée
    int lfind = -1;
    for (int i = 0; i < rangees; i++)
    {
        nb = 0;
        for (int j = 0; j < colonnes; j++)
        {
            if (getShownJeton(i, j) != shownPourJeton(jeton))
                nb = 0;
            else
            {
                nb++;
                // printf("Nb alignes=%d\n", nb);
                if (nb >= 4)
                {
                    lfind = i;
                }
            }
            if (lfind != -1)
                break;
        }
        if (lfind != -1)
            break;
    }
    if (nb >= 4)
        printf("Fin ligne %d remplie par %s \n", lfind + 1, (jeton == Jeton1 ? "Joueur1" : "Joueur2"));
    return (nb >= 4);
}

/**
 *
 */
int fin_avec_colonne(jetons jeton)
{
    int nb;
    // colonne trouvée
    int cfind = -1;
    for (int j = 0; j < colonnes; j++)
    {

        nb = 0;
        for (int i = 0; i < rangees; i++)
        {

            if (getShownJeton(i, j) != shownPourJeton(jeton))
            {
                nb = 0;
            }
            else
            {
                nb++;
                // printf("Nb alignes=%d\n", nb);
                if (nb >= 4)
                {
                    cfind = j;
                }
            }
            if (cfind != -1)
                break;
        }
        if (cfind != -1)
            break;
    }
    // printf("On trouve nb=%d\n", nb);
    if (nb >= 4)
        printf("Fin colonne %d remplie par %s \n", cfind + 1, (jeton == Jeton1 ? "Joueur1" : "Joueur2"));
    return (nb >= 4);
}

/**
 * On va partir du bas du plateau et on va remonter
 * les diagonales qui nous interessent sont celles qui contiennent
 * plus de 4 éléments
 */
int fin_avec_diagonale_premier_sens(jetons jeton)
{
    int nb;
    // diagonale trouvée
    int dfind = -1;

    for (int i = rangees - 3; i >= 0; i--)
    {
        nb = 0;
        for (int j = i; j < rangees; j++)
        {
            if (getShownJeton(j, j - i) != shownPourJeton(jeton))
                nb = 0;
            else
                nb++;
            if (nb >= 4)
            {
                dfind = j;
            }
            if (dfind != -1)
                break;
        }
        if (dfind != -1)
            break;
    }
    if (nb < 4)
    {
        for (int j = colonnes - 3; j >= 0; j--)
        {
            nb = 0;
            for (int i = j; i < colonnes; i++)
            {
                if (getShownJeton(i - j, i) != shownPourJeton(jeton))
                    nb = 0;
                else
                    nb++;
                if (nb >= 4)
                {
                    dfind = j;
                }
                if (dfind != -1)
                    break;
            }
            if (dfind != -1)
                break;
        }
        if (nb >= 4)
        {
            printf("Fin diagonale %d remplie par %s \n", dfind, (jeton == Jeton1 ? "Joueur1" : "Joueur2"));
            return 1;
        }
        else
            return 0;
    }
    else
    {
        printf("Fin diagonale %d remplie par %s \n", dfind, (jeton == Jeton1 ? "Joueur1" : "Joueur2"));
        return 1;
    }

    return 0;
}

/**
 * On va partir du bas du plateau et on va remonter
 * les diagonales qui nous interessent sont celles qui contiennent
 * plus de 4 éléments
 */
int fin_avec_diagonale_second_sens(jetons jeton)
{
    int nb;
    // diagonale trouvée
    int dfind = -1;

    for (int i = 3; i < rangees; i++)
    {
        nb = 0;
        for (int j = i; j >= 0; j--)
        {

            if (getShownJeton(j, i - j) != shownPourJeton(jeton))
                nb = 0;
            else
                nb++;
            if (nb >= 4)
            {
                dfind = j;
            }
            // printf("case testée (%d,%d) nb= %d\n",j,(i-j),nb);
            if (dfind != -1)
                break;
        }
        if (dfind != -1)
            break;
    }
    if (nb < 4)
    {
        for (int j = colonnes - 3; j >= 0; j--)
        {
            nb = 0;
            for (int i = j; i < colonnes; i++)
            {
                if (getShownJeton(rangees - (i - j), i) != shownPourJeton(jeton))
                    nb = 0;
                else
                    nb++;
                if (nb >= 4)
                {
                    dfind = j;
                }
                // printf("case testée (%d,%d) nb= %d\n",j,(i-j),nb);
                if (dfind != -1)
                    break;
            }
            if (dfind != -1)
                break;
        }
        if (nb >= 4)
        {
            printf("Fin diagonale %d remplie par %s \n", dfind, (jeton == Jeton1 ? "Joueur1" : "Joueur2"));
            return 1;
        }
        else
            return 0;
    }
    else
    {
        printf("Fin diagonale %d remplie par %s \n", dfind, (jeton == Jeton1 ? "Joueur1" : "Joueur2"));
        return 1;
    }

    return 0;
}
/**
 * Retourne 0 si personne n'a gagné
 * 1 si c'est le joueur 1
 * 2 si c'est le joueur 2
 */
int fin_du_jeu(jetons jeton)
{
    // printf("Test Fin du jeu avec joueur %s\n",jeton==Jeton1?"Joueur1":"Joueur2");
    return fin_avec_colonne(jeton) || fin_avec_ligne(jeton) || fin_avec_diagonale_premier_sens(jeton1) || fin_avec_diagonale_second_sens(jeton);
}
void Choix_Jeu()
{
    // printf("Jouer \n");
    init_Plateau();
    joueur_possible joueur_en_cours;
    joueur_en_cours = Joueur1;
    int arret = 0;
    while (arret == 0)
    {
        afficher_Plateau();
        coup_du_joueur(joueur_en_cours);
        arret = fin_du_jeu(joueur_en_cours == Joueur1 ? Jeton1 : Jeton2);
        joueur_en_cours = (joueur_en_cours == Joueur1) ? Joueur2 : Joueur1;
    }
    afficher_Plateau();
    getChoice();
}
void Test_Remplissage_colonne(int ncol, jetons jeton)
{
    plateau[0][ncol] = jeton;
    plateau[1][ncol] = jeton;
    plateau[2][ncol] = jeton;
    plateau[3][ncol] = jeton;
}
void attente_clavie_test()
{
    flush_stdin();
    char coup[1];
    printf("Passer au test suivant\n");
    fgets(coup, 2, stdin);
}
void Test_Remplissage_ligne(int nligne, jetons jeton)
{
    plateau[nligne][0] = jeton;
    plateau[nligne][1] = jeton;
    plateau[nligne][2] = jeton;
    plateau[nligne][3] = jeton;
}
void Test_Remplissage_diagonale(jetons jeton)
{
    plateau[0][0] = jeton;
    plateau[1][1] = jeton;
    plateau[2][2] = jeton;
    plateau[3][3] = jeton;
}
void Test_Remplissage_diagonale_1(jetons jeton)
{
    plateau[1][0] = jeton;
    plateau[2][1] = jeton;
    plateau[3][2] = jeton;
    plateau[4][3] = jeton;
}
void Test_Remplissage_diagonale_2(jetons jeton)
{
    plateau[3][0] = jeton;
    plateau[2][1] = jeton;
    plateau[1][2] = jeton;
    plateau[0][3] = jeton;
}
void Test_Remplissage_diagonale_3(jetons jeton)
{
    plateau[5][3] = jeton;
    plateau[4][4] = jeton;
    plateau[3][5] = jeton;
    plateau[2][6] = jeton;
}
void Test_Init_Plateau()
{
    init_Plateau();
    afficher_Plateau();
}
void Test_Fin_Jeu()
{
    // Test fin du jeu

    init_Plateau();
    // colonne rentrée en valeur du tableau plateau
    Test_Remplissage_colonne(1, Jeton1);
    afficher_Plateau();
    
    printf("test fin colonne=%d\n", fin_avec_colonne(Jeton1));
    attente_clavie_test();
    init_Plateau();
    // ligne rentrée en valeur du tableau plateau
    Test_Remplissage_ligne(rangees - 1, Jeton2);
    afficher_Plateau();
   
    printf("test fin ligne=%d\n", fin_avec_ligne(Jeton2));
    init_Plateau();
    attente_clavie_test();
    Test_Remplissage_diagonale_1(Jeton2);
    afficher_Plateau();
    
    printf("test fin diagonale=%d\n", fin_avec_diagonale_premier_sens(Jeton2));
    init_Plateau();
    attente_clavie_test();
    Test_Remplissage_diagonale_2(Jeton1);
    afficher_Plateau();
   ;
    printf("test fin diagonale=%d\n", fin_avec_diagonale_second_sens(Jeton1));
    init_Plateau();
    attente_clavie_test();
    Test_Remplissage_diagonale_3(Jeton2);
    afficher_Plateau();
    printf("test fin diagonale=%d\n", fin_avec_diagonale_second_sens(Jeton2));
}
void Test_Coup_Joueur()
{
    init_Plateau();
    coup_du_joueur(Joueur1);
    afficher_Plateau();
    coup_du_joueur(Joueur1);
    afficher_Plateau();
}
void Choix_Test()
{
    printf("---------- Debut du Test ----------\n");
    Test_Init_Plateau();
    // printf("%s\n", getStringForJoueur(Joueur1));
    // printf("%c\n", getCharForJeton(Jeton1));
    // Test mauvais choix de colonne
    // insere_en_colonne(0, Joueur1);
    // afficher_Plateau();
    // insere_en_colonne(1, Joueur1);
    // afficher_Plateau();
    // Test empilage
    // insere_en_colonne(1, Joueur1);
    // afficher_Plateau();
    attente_clavie_test();
    Test_Fin_Jeu();
    attente_clavie_test();
    Test_Coup_Joueur();
    printf("---------- Fin du Test ----------\n");

    getChoice();
}
int main()
{
    int choice = getChoice();
    if (choice == Jouer)
    {
        Choix_Jeu();
    }
    else if (choice == Test)
    {
        Choix_Test();
    }
    exit(EXIT_SUCCESS);

    return 0;
}