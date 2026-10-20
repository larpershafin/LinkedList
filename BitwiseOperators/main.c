#include <stdio.h>
#include <stdint.h>

int main() {
    uint16_t A = 0, B =  0;
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

}
