#include "pidregler.h"

double berechne_pid(double sollwert, double istwert, double *integral, double *letzter_fehler) {
    double kp = 2.0;
    double ki = 0.1;
    double kd = 0.5;

    double fehler = sollwert - istwert;
    *integral += fehler;
    double ableitung = fehler - *letzter_fehler;
    *letzter_fehler = fehler;


    double stellgroesse = (kp * fehler) + (ki * (*integral)) + (kd * ableitung);


    if (stellgroesse < 0.0) stellgroesse = 0.0;
    if (stellgroesse > 10.0) stellgroesse = 10.0;

    return stellgroesse;
}

double simuliere_strecke_pid(double istwert, double stellgroesse) {
    return istwert + (stellgroesse * 0.2) - 0.5;
}
