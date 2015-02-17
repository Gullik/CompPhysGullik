#ifndef UNITCONVERTER
#define UNITCONVERTER

double massAtomicToSI(double mass);
double massAtomicFromSI(double mass);

double lengthAtomicToSI(double length);
double lengthAtomicFromSI(double length);

double energyAtomicToSI(double energy);
double energyAtomicFromSI(double energy);

double tempAtomicToSI(double temperature);
double tempAtomicFromSI(double temperature);

double timeAtomicToSI(double time);
double timeAtomicFromSI(double time);

double velocityAtomicToSI(double velocity);
double velocityAtomicFromSI(double velocity);

//Converting to MD units where necessary
double massMDToSI(double mass);
double massMDFromSI(double mass);

double lengthMDToSI(double length);
double lengthMDFromSI(double length);

double energyMDToSI(double energy);
double energyMDFromSI(double energy);

double tempMDToSI(double temperature);
double tempMDFromSI(double temperature);

double timeMDToSI(double time);
double timeMDFromSI(double time);

double velocityMDToSI(double velocity);
double velocityMDFromSI(double velocity);

#endif // UNITCONVERTER

