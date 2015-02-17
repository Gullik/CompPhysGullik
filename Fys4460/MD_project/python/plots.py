import numpy as np
import pylab as pl
import scipy.stats as stats



# Plotting of the solutions to the first 
atoms = np.genfromtxt('../states/state_20_300.xyz',skip_header = 2, usecols = (0,1,2,3,4,5,6))

nAtoms = atoms.shape[0]

velocityx = sorted(atoms[:,4])
velocityy = sorted(atoms[:,4])
velocityz = sorted(atoms[:,5])

fitx = stats.norm.pdf(velocityx, np.mean(velocityx), np.std(velocityx))  #this is a fitting indeed
fity = stats.norm.pdf(velocityy, np.mean(velocityy), np.std(velocityy))  #this is a fitting indeed
fitz = stats.norm.pdf(velocityz, np.mean(velocityz), np.std(velocityz))  #this is a fitting indeed

# h = sorted(velocityz)  #sorted
velocityDistributions = pl.figure()


x = pl.subplot(311)
pl.title('Starting velocity distributions')

pl.plot(velocityx,fitx,'-')
pl.hist(velocityx,normed=True, bins=100)      #use this to draw histogram of your data

y = pl.subplot(312)

pl.plot(velocityy,fity,'-')
pl.hist(velocityy,normed=True, bins=100)      #use this to draw histogram of your data

z = pl.subplot(313)

pl.plot(velocityz,fitz,'-')
pl.hist(velocityz,normed=True, bins=100)      #use this to draw histogram of your data


pl.savefig('velocityDistributions.png')





pl.show()                   #use may also need add this 



# totalEnergy = kineticEnergy + potentialEnergy

# relativeVariation = np.abs(( np.max(totalEnergy) - np.min(totalEnergy) ) /np.average(totalEnergy))

# print "The total energy has a relative maxvariation of = " , relativeVariation

# tempFigs = pl.figure()
# pl.plot(time, temperature)
# pl.ylabel('Temperature in Kelvin')
# pl.xlabel('Time in picoseconds')
# pl.title('Temperature of argon gas')
# pl.savefig('./Plots/temperature.png')



## Plotting the force so we can estiamte when it approaches zero.

sigma = 1.0
epsilon = 1.0

def lennardJonesForce(x):
	return 24/sigma*epsilon*(2*(sigma/x)**13 - (sigma/x)**7)

xx = np.linspace(0.01,3,1000)


forceFig = pl.figure()
pl.plot( xx, lennardJonesForce(xx))
pl.ylim( [-3,10] )
pl.grid(True)
pl.title('The force between to particles. sigma = 1, epsilon = 1')
pl.xlabel('Distance')
pl.ylabel('Force')

pl.savefig('forcePlot.png')



