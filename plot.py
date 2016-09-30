#!/usr/bin/env python
# -*- coding: utf-8 -*-
## Dette programmet plotter en fil med data der første linje er ovrskriftene

import numpy as np
import matplotlib.pyplot as plt



#-----------------------------------------------------------------------
#sett variablene for plotteprogrammet
##----------------------------------------------------------------------
filnavn='tabell.csv'
#hvordan er verdiene pr linje separert normalt er , eller ;
separator=';'
#Om du vil forsøke å se igjennom data for å finne grense.
grenseFraData=0;
Xmin=-20;
Xmax=360;
Ymin=-1;
Ymax=2

#Laster data fra filen
with open(filnavn) as f:
    linjer = f.readlines()

#initialiserer aksene (y data settene)
akse=[]

#fyller aksene med data
#behandler linje for linje
for linjenr, linje in enumerate(linjer) :
	#behandler kolonne i linjen
	for kolnr, kolonne in enumerate(linje.split(separator)) : 
		if linjenr == 0:
			#lager aksene
			akse.append([])
		#Setter inn i aksene.
		akse[kolnr].append(kolonne)


#Sette navnet på x aksen (første verdi i data)
plt.xlabel(akse[0][0])


# xmin, xmax ymin ymax
x=map(float, akse[0][1:])
y=map(float, akse[1][1:])#sinus 

grenser=[]
if grenseFraData == 1:
	grenser.append(min(x))
	grenser.append(max(x))
	grenser.append(min(y))
	grenser.append(max(y))
else :
	grenser=[Xmin,Xmax,Ymin,Ymax]

plt.axis(grenser)
plt.axis

antAkser=len(akse);

#looper alle utenom overskriftene
for i in range(antAkser)[1:]:
	#plotter data.
	plt.plot(x,akse[i][1:],label=akse[i][0])

#akser 
plt.plot([0,0],[10,0])
plt.legend()

#Regner ut skala for å kalkulere pilhodene
xmin, xmax = plt.xlim()
ymin, ymax = plt.ylim()
xscale = (xmax-xmin )/100
yscale = (ymax-ymin )/100

#setter en x og y akse.
plt.arrow(xmin, 0, xmax, 0,  head_width=yscale*2,head_length=xscale*2,fc='k', ec='k', lw=2)
plt.arrow(0, ymin, 0, ymax, head_width=xscale*1.5, head_length=yscale*3,fc='k', ec='k', lw=2)
#setter rutenett 
plt.grid()

#Vis grafen
plt.show()
