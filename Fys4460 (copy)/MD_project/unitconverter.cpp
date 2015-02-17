#include <unitconverter.h>
#include <cmath>

double atomicMassUnit = 1.661E-27;
double atomicLengthUnit = 1.0E-10;
double atomicEnergyUnit = 1.651E-21;
double atomicTemperatureUnit = 119.735;
double atomicTimeUnit = atomicLengthUnit*sqrt(atomicMassUnit/atomicEnergyUnit);
double atomicVelocityUnit = atomicLengthUnit/atomicTimeUnit;

double mDMassUnit = 39.948 ; //From amu
double mDLengthUnit = 3.405 ;
double mDEnergyUnit = 1.0;
double mDTemperatureUnit = 1.0;
double mDTimeUnit   = mDLengthUnit * sqrt( mDMassUnit/mDEnergyUnit );
double mDVelocityUnit = mDLengthUnit / mDTimeUnit;

double massAtomicToSI(double mass)
{    return mass*atomicMassUnit;    }

double massAtomicFromSI(double mass)
{    return mass/atomicMassUnit;    }

double lengthAtomicToSI(double length)
{    return length*atomicLengthUnit;    }

double lengthAtomicFromSI(double length)
{    return length/atomicLengthUnit;    }

double energyAtomicToSI(double energy)
{    return energy*atomicEnergyUnit;    }

double energyAtomicFromSI(double energy)
{    return energy/atomicEnergyUnit;    }

double tempAtomicToSI(double temperature)
{    return temperature*atomicTemperatureUnit;  }

double tempAtomicFromSI(double temperature)
{    return temperature/atomicTemperatureUnit;  }

double timeAtomicToSI(double time)
{    return time*atomicTimeUnit;    }

double timeAtomicFromSI(double time)
{    return time/atomicTimeUnit;    }

double velocityAtomicToSI(double velocity)
{    return velocity*atomicVelocityUnit;    }

double velocityAtomicFromSI(double velocity)
{    return velocity/atomicVelocityUnit;    }

//Between MD and SI units
//Converting to MD units where necessary
double massMDToSI(double mass)
{   return massAtomicToSI(mass)*mDMassUnit;     }

double massMDFromSI(double mass)
{   return massAtomicToSI(mass)/mDMassUnit;     }

double lengthMDToSI(double length)
{   return lengthAtomicToSI(length) * mDLengthUnit;  }
double lengthMDFromSI(double length)
{   return lengthAtomicFromSI(length)/ mDLengthUnit;  }

double energyMDToSI(double energy)
{   return energyAtomicToSI(energy);   }
double energyMDFromSI(double energy)
{   return energyAtomicFromSI(energy);    }

double tempMDToSI(double temperature)
{   return tempAtomicToSI(temperature);    }
double tempMDFromSI(double temperature)
{   return tempAtomicFromSI(temperature);   }

double timeMDToSI(double time)
{   return timeAtomicToSI(time) * mDTimeUnit;    }
double timeMDFromSI(double time)
{   return timeAtomicFromSI(time) / mDTimeUnit;  }

double velocityMDToSI(double velocity)
{   return velocityAtomicToSI(velocity) * mDVelocityUnit; }
double velocityMDFromSI(double velocity)
{   return velocityAtomicToSI(velocity) * mDVelocityUnit;    }
