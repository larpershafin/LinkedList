#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void print_bits(uint16_t val) {
    for (int i = 15; i >= 0; i--) {
        int bit = (val >> i) & 1;
        printf("%d", bit);
        if (i == 8) {
            printf(" ");
        }
    }
}

int main() {
    uint16_t A = 0, B =  0;
    int auswahl;
    do {
        system("cls");
        printf("\nA  Hex: %04X\n", A);
        printf("   Bits: ");
        print_bits(A);
        printf("\n");
        printf("B  Hex: %04X\n", B);
        printf("   Bits: ");
        print_bits(B);
        printf("\n\n");
        printf("1      Neue Hexzahl für A einlesen\n");
        printf("2    	 Neue Hexzahl für B einlesen.\n");
        printf("3      Normale Addition. A = A + B\n");
        printf("4	     Bitweises Und. A = A & B\n");
        printf("5	     Bitweises Oder. A = A | B\n");
        printf("6	     XOR, exklusives Oder. A = A ^ B\n");
        printf("7	     Alle 16 Bits von A umdrehen. A = ~A\n");
        printf("8	     Bits von A um B Stellen nach links. A = A << B\n");
        printf("9	     Bits von A um B Stellen nach rechts. A = A >> B\n");
        printf("10	 Ein Bit auf 1 setzen. Die Bitnummer wird extra gefragt.\n");
        printf("11	 Ein Bit auf 0 löschen. Die Bitnummer wird extra gefragt.\n");
        printf("12	 Ein Bit umschalten: aus 0 wird 1, aus 1 wird 0.\n");
        printf("13	 Nur prüfen, ob ein Bit 1 oder 0 ist. A bleibt gleich.\n");
        printf("0	     Programm beenden.\n");
        if (scanf("%d", &auswahl) != 1) {
            printf("Ungueltige Eingabe. Bitte eine Zahl eingeben.\n");
            while(getchar() != '\n');
            continue;
        }
        switch (auswahl) {
            case 1:
                printf("Neuer Hexwert für A eingeben: \n");
                scanf("%hx", &A);
                break;
            case 2:
                printf("Neuer Hexwet für B eingeben: \n");
                scanf("%hx", &B);
                break;
            case 3:
                printf("Normale Addition. A = A + B\n");
                A=A+B;
                break;
            case 4:
                printf("Bitweises Und. A = A & B\n");
                A=A&B;
                break;
            case 5:
                printf("Bitweises Oder. A = A | B\n");
                A=A|B;
                break;
            case 6:
                printf("XOR, exklusives Oder. A = A ^ B\n");
                A=A^B;
                break;
            case 7:
                printf("Alle 16 Bits von A umdrehen.\n");
                A=~A;
                break;
            case 8:
                printf("Bits von A um B Stellen nach links. A = A << B\n");
                if(B<=15) {
                    A=A<<B;
                } else {
                    printf("B muss zwischen 0 und 15 liegen.\n");
                }
                break;
            case 9:
                printf("Bits von A um B Stellen nach rechts. A = A >> B\n");
                if (B<=15) {
                    A=A>>B;
                } else {
                    printf("B muss zwischen 0 und 15 liegen.\n");
                }
                break;
            case 10: {
                printf("Ein Bit auf 1 setzen. Die Bitnummer wird extra gefragt.\n");
                unsigned int n;
                printf("Bitnummer 0 bis 15: \n");
                if (scanf("%d", &n) == 1 && n<=15) {
                    A = A | (1u << n);
                } else {
                    printf("Ungultige Bitnummer. \n");
                    while (getchar() != '\n');
                }
                break;
            }
            case 11: {
                unsigned int n;
                printf("Bitnummer 0 bis 15: \n");
                if (scanf("%d", &n) == 1 && n<=15) {
                    A = A & ~(1u << n);
                } else {
                    printf("Ungultige Bitnummer. \n");
                    while (getchar() != '\n');
                }
                break;
            }

            case 12: {
                unsigned int n;
                printf("Bitnummer 0 bis 15: \n");
                if (scanf("%d", &n) == 1 && n<=15) {
                    A = A^(1u << n);
                } else {
                    printf("Ungultige Bitnummer. \n");
                    while (getchar() != '\n');
                }
                break;
            }
            case 13: {
                unsigned int n;
                printf("Bitnummer (0 bis 15): ");
                if (scanf("%u", &n) == 1 && n <= 15) {
                    int bit_val = (A >> n) & 1u;
                    printf("Bit %u ist %d\n", n, bit_val);
                } else {
                    printf("Ungueltige Bitnummer!\n");
                    while(getchar() != '\n');
                }
                break;
            }


            case 0:
                printf("Programm wird beendet\n");
                break;
            default:
                printf("Ungultige Auswahl. Bitte wähle von 0 bis 13. \n");
        }
    } while (auswahl != 0);
    return 0;
}
