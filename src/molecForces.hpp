//#include <math.h>

#define K_E 1 //9.897551788e9

// Lennard Jones radius cut-off squared
#define LJ_CUTTOFF_SQ 4

double LennardJonesForce(double distSq, double epsilon, double sigma) {

    if (distSq == 0) return 0.0;
    if (distSq > LJ_CUTTOFF_SQ) return 0.0;
    if (distSq < 0.001) distSq = 0.001;

    double sigmaDistSq = sigma * sigma / distSq;
    double sigmaDistPower6 = sigmaDistSq * sigmaDistSq * sigmaDistSq;
    return -24 * epsilon * (2*sigmaDistPower6 - 1) * sigmaDistPower6 / distSq;
}

double CoulombForce(double distSq, double chargeProd) {
    if (chargeProd == 0.0) return 0.0;
    return chargeProd / distSq / K_E;
}

double harmonicForce(double dist, double bondLength, double stiffness) {
    return 0.0;
}

double angleBendingForce() {
    return 0.0;
}

double dihedralForce() {
    return 0.0;
}