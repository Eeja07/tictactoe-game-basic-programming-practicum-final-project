#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char kotak[3][3];
const char human = 'X';
const char computer = 'O';
int player = 1;

void reset_kotak();
void print_kotak();
int cek_kotak_kosong();
void jalan_manusia();
void jalan_manusia2();
void jalan_komputer();
char cek_pemenang();
void print_pemenang(char);
void print_pemenang2(char);

int main()
{
    int d;
    printf("\n=== Tic Tac Toe ===\n\n  [  Mode Game  ]\n\n1 = Mode PVP\n2 = Mode Computer");
    printf("\nPilih Modemu = ");
    scanf("%d", &d);
    if (d == 1)
    {
        do
        {
            char menang = ' ';
            reset_kotak();

            while (menang == ' ' && cek_kotak_kosong())
            {
                jalan_manusia2();
                menang = cek_pemenang();
                if (menang != ' ' || cek_kotak_kosong() == 0)
                {
                    break;
                }
            }
            print_kotak();
            print_pemenang2(menang);
            return 0;
        } while (d == 1);
    }

    else if (d == 2)
    {
        do
        {
            char menang = ' ';
            reset_kotak();

            while (menang == ' ' && cek_kotak_kosong())
            {
                print_kotak();

                jalan_manusia();
                menang = cek_pemenang();
                if (menang != ' ' || cek_kotak_kosong() == 0)
                {
                    break;
                }

                jalan_komputer();
                menang = cek_pemenang();
                if (menang != ' ' || cek_kotak_kosong() == 0)
                {
                    break;
                }
            }
            print_kotak();
            print_pemenang(menang);
            return 0;
        } while (d == 2);
    }
}

void reset_kotak()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            kotak[i][j] = ' ';
        }
    }
}

void print_kotak()
{
    printf("\n\tTic Tac Toe\n\n");
    printf("Player 1 (X) -- Player 2 (O)\n\n");
    printf("          |     |     \n");
    printf("      %c   | %c   | %c   \n", kotak[0][0], kotak[0][1], kotak[0][2]);
    printf("     _____|_____|_____\n");
    printf("          |     |      \n");
    printf("      %c   | %c   | %c   \n", kotak[1][0], kotak[1][1], kotak[1][2]);
    printf("     _____|_____|_____\n");
    printf("          |     |      \n");
    printf("      %c   | %c   | %c   \n", kotak[2][0], kotak[2][1], kotak[2][2]);
    printf("     _____|_____|_____\n");
    printf("          |     |      \n");
}
int cek_kotak_kosong()
{
    int kotak_kosong = 9;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (kotak[i][j] != ' ')
            {
                kotak_kosong--;
            }
        }
    }

    return kotak_kosong;
}
void jalan_manusia2()
{
    int a, b;
    do
    {
        print_kotak();
        player = (player % 2) ? 1 : 2;

        printf("Player %d, enter a number: ", player);
        scanf("%d %d", &a, &b);

        if (kotak[a][b] != ' ')
        {
            printf("Pilih Kotak Lain!\n");
            break;
        }
        else if (player == 1 && kotak[a][b] == ' ')
        {
            kotak[a][b] = human;
            break;
        }
        else if (player == 2 && kotak[a][b] == ' ')
        {
            kotak[a][b] = computer;
            break;
        }

    } while (kotak[a][b] != ' ');
    player++;
}

void jalan_manusia()
{
    int a, b;
    do
    {
        printf("Pemain 1, Masukkan Angka: ");
        scanf(" %d %d", &a, &b);

        if (kotak[a][b] != ' ')
        {
            printf("Pilih Kotak Lain!\n");
        }
        else
        {
            kotak[a][b] = human;
            break;
        }
    } while (kotak[a][b] != ' ');
}
void jalan_komputer()
{
    //
    srand(time(0));
    int a, b;

    do
    {
        a = rand() % 3;
        b = rand() % 3;
    } while (kotak[a][b] != ' ');

    kotak[a][b] = computer;
}
char cek_pemenang()
{
    //
    for (int i = 0; i < 3; i++)
    {
        if (kotak[i][0] == kotak[i][1] && kotak[i][0] == kotak[i][2] && kotak[i][0] != ' ')
        {
            return kotak[i][0];
        }
    }
    //
    for (int i = 0; i < 3; i++)
    {
        if (kotak[0][i] == kotak[1][i] && kotak[0][i] == kotak[2][i] && kotak[0][i] != ' ')
        {
            return kotak[0][i];
        }
    }
    //
    if (kotak[0][0] == kotak[1][1] && kotak[0][0] == kotak[2][2])
    {
        return kotak[0][0];
    }
    if (kotak[0][2] == kotak[1][1] && kotak[0][2] == kotak[2][0])
    {
        return kotak[0][2];
    }

    return ' ';
}
void print_pemenang(char menang)
{
    if (menang == human)
    {
        printf("Pemain 1, Anda Menang!");
    }
    else if (menang == computer)
    {
        printf("Pemain 1, Anda Kalah!");
    }
    else
    {
        printf("Pemain 1, Anda Seri!");
    }
}
void print_pemenang2(char menang)
{
    if (menang == human)
    {
        printf("Pemain 1, Anda Menang!");
    }
    else if (menang == computer)
    {
        printf("Pemain 2, Anda Menang!");
    }
    else
    {
        printf("Seri!");
    }
}