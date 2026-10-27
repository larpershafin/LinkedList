#include "2punktregler.h"

int berechne_2punkt(double sollwert, double istwert) {
    if (istwert < sollwert) {
        return 1;
    }
    return 0;
}

double simuliere_strecke(double istwert, int heizung) {
    if (heizung) {
        return istwert + 1.2;
    } else {
        return istwert - 0.6;
    }
}
