#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4

void manji(int, int);
void veci(int, int);

struct Tim
{
    char ime[20];
    int bodovi;
    int datiG;
    int primG;
    int igrano;
} Tim;

char poredak[] = "Poredak";
char ime[] = "TIM";
char odigrano[] = "OS";
char datiPrim[] = "G";
char bodovi[] = "B";
FILE *stream;
struct Tim tabela[MAX];

void trazi(int i)
{
    int x;
    char op;

    printf("\nUnesi broj bodova i zavisnost (x,<    ili     x,>)\n");
    scanf("%d,%s", &x, &op);
    if (op == '<')
    {
        printf("Timovi sa bodovima manjim od %d: \n", x);
        printf("\n%s   %s   %s   %s    %s\n", poredak, ime, odigrano, datiPrim, bodovi);
        manji(x, i);
    }
    else if (op == '>')
    {
        printf("Timovi sa bodovima vecim od %d: \n", x);
        printf("\n%s   %s   %s   %s    %s\n", poredak, ime, odigrano, datiPrim, bodovi);
        veci(x, i);
    }
    else
    {
        printf("Netacno unet parametar (<,>)!\n");
    }
}

void manji(int x, int k)
{
    stream = fopen("tabela", "r");
    if (stream == NULL)
    {
        fprintf(stderr, "\nGreska pri citanju fajla\n");
        exit(1);
    }
    else
    {
        fread(&tabela, sizeof(Tim), MAX, stream);
        for (int i = 0; i < k; i++)
        {
            if (tabela[i].bodovi <= x)
            {
                printf("%d.  %s  %d  %d:%d   %d\n", i + 1, tabela[i].ime, tabela[i].bodovi, tabela[i].datiG, tabela[i].primG, tabela[i].igrano);
            }
        }
    }
}
void veci(int x, int k)
{
    stream = fopen("tabela", "r");
    if (stream == NULL)
    {
        fprintf(stderr, "\nGreska pri citanju fajla\n");
        exit(1);
    }
    else
    {
        fread(&tabela, sizeof(Tim), MAX, stream);
        for (int i = 0; i < k; i++)
        {
            if (tabela[i].bodovi >= x)
            {
                printf("%d.  %s  %d  %d:%d   %d\n", i + 1, tabela[i].ime, tabela[i].bodovi, tabela[i].datiG, tabela[i].primG, tabela[i].igrano);
            }
        }
    }
}

void sorting(int a) //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
}

void noviTim(int i)
{
    char tmp[20];
    stream = fopen("tabela", "w");
    if (stream == NULL)
    {
        fprintf(stderr, "\nGreska pri citanju fajla\n");
        exit(1);
    }
    else
    {
        printf("Upisi ime Tima: ");
        scanf("%s", tmp);

        strcpy(tabela[i].ime, tmp);
        tabela[i].bodovi = 0;
        tabela[i].datiG = 0;
        tabela[i].primG = 0;
        tabela[i].igrano = 0;

        fwrite(&tabela, sizeof(Tim), MAX, stream);
    }
    fclose(stream);
}

void print(int k) //TREBA UBACITI SORTING! ~~~~~~~~~~~~~~~~~~~~~~~
{
    stream = fopen("tabela", "r");
    if (stream == NULL)
    {
        fprintf(stderr, "\nGreska pri citanju fajla\n");
        exit(1);
    }
    else
    {
        fread(&tabela, sizeof(Tim), MAX, stream);
        printf("\n%s   %s   %s   %s    %s\n", poredak, ime, odigrano, datiPrim, bodovi);
        for (int i = 0; i < k; i++)
        {
                printf("%d.  %s  %d  %d:%d   %d\n", i + 1, tabela[i].ime, tabela[i].bodovi, tabela[i].datiG, tabela[i].primG, tabela[i].igrano);
        }
    }
}

void koriguj(int a)
{
    char domacin[20];
    char gost[20];
    char rez[2];
    int rezDomacin = 0;
    int rezGost = 0;

    printf("Unesi domaci tim: ");
    scanf("%s", domacin);
    printf("Unesi gostujuci tim: ");
    scanf("%s", gost);
    printf("\nUnesi rezultat utakmice: ");
    scanf("%s", rez);

    char s = rez[0];
    char b = rez[2];
    rezDomacin = s - '0';
    rezGost = b - '0';

    int c = 0;
    //p1 win
    if (s < b)
    {
        c = 3;
    }
    //p2 win
    else if (b < s)
    {
        c = 1;
    }
    //tie
    else if (b == s)
    {
        c = 2;
    }

    struct Tim tabela[MAX];
    int primG;
    int datiG;
    int bodovi;
    int igrano = 0;
    stream = fopen("tabela", "r");

    fread(&tabela, sizeof(Tim), MAX, stream);
    for (int i = 0; i < a; i++)
    {
        int t = strcmp(domacin, tabela[i].ime);
        if (t == 0)
        {
            igrano = tabela[i].igrano;
            bodovi = tabela[i].bodovi;
            datiG = tabela[i].datiG;
            primG = tabela[i].primG;
        }
    }
    fclose(stream);

    stream = fopen("tabela", "w");

    for (int i = 0; i < a; i++)
    {
        int t = strcmp(domacin, tabela[i].ime);

        if (t == 0)
        {
            if (c == 1)
            {
                tabela[i].bodovi = bodovi + 3;
            }
            else if (c == 2)
            {
                tabela[i].bodovi = bodovi + 1;
            }
            tabela[i].igrano = igrano + 1;
            tabela[i].datiG = datiG + rezDomacin;
            tabela[i].primG = primG + rezGost;
        }
    }
    fwrite(&tabela, sizeof(Tim), MAX, stream);
    fclose(stream);

    // --GOST--
    int bodovi1;
    int datiG1;
    int primG1;
    int igrano1 = 0;
    stream = fopen("tabela", "r");
    fread(&tabela, sizeof(Tim), MAX, stream);
    for (int i = 0; i < a; i++)
    {
        int t = strcmp(gost, tabela[i].ime);

        if (t == 0)
        {
            igrano1 = tabela[i].igrano;
            bodovi1 = tabela[i].bodovi;
            datiG1 = tabela[i].datiG;
            primG1 = tabela[i].primG;
        }
    }
    fclose(stream);

    stream = fopen("tabela", "w");

    for (int i = 0; i < a; i++)
    {
        int t = strcmp(gost, tabela[i].ime);
        if (t == 0)
        {
            if (c == 3)
            {
                tabela[i].bodovi = bodovi1 + 3;
            }
            else if (c == 2)
            {
                tabela[i].bodovi = bodovi1 + 1;
            }
            tabela[i].igrano = igrano1 + 1;
            tabela[i].datiG = datiG1 + rezGost;
            tabela[i].primG = primG1 + rezDomacin;
        }
    }
    fwrite(&tabela, sizeof(Tim), 4, stream);
    fclose(stream);
}

void main()
{
    int opcija, n = 0, k = 0;
    if (stream = fopen("br.txt", "r"))
    {
        fclose(stream);
    }
    else
    {
        stream = fopen("br.txt", "w");
        fprintf(stream, "%d", n);
        fclose(stream);
    }
    stream = fopen("br.txt", "r");
    fscanf(stream, "%d", &k);
    fclose(stream);

    do
    {
        printf("\n1. Unesi novi tim.\n");
        printf("2. Pretrazi tabelu.\n");
        printf("3. Ispis tabele. (U IZRADI)\n");
        printf("4. Koriguj parametre tima.\n");
        printf("5. Napusti program i sacuvaj promene.\n");
        printf("Molimo Vas izaberite opciju od 1 do 5: ");
        scanf("%d", &opcija);

        switch (opcija)
        {
        case 1:
            noviTim(k);
            k++;
            break;
        case 2:
            trazi(k);
            break;
        case 3:
            print(k);
            break;
        case 4:
            koriguj(k);
            break;
        case 5:
            stream = fopen("br.txt", "w");
            fprintf(stream, "%d", k);
            fclose(stream);
            printf("Kraj programa!\n");
            exit(1);
            break;
        default:
            printf("\nNiste uneli broj od 1 do 5~!?");
            break;
        }
    } while (opcija > 0 && opcija < 6);
}
