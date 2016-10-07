#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Mathis 2016 
#
# Et programt som plotter fildata. 
# Filen må ha en x kolonne og minimum en y kolonne.
# Data må separeres med et separeringstegn som kan velges under.
# Første rad er overskriftsrad,resten data med tilhørende x verdi i første kolonne.
#     format på eksempel fil under.
#
#  x verdi; y1(x) ; y2(x) ; y..(x)  
#   0     ; 31.2  ; 31    ; 13 
#   1     ; -31   ; 13    ; 31 
# 

import numpy as np
import matplotlib.pyplot as plt
import sys

#----------------------------------------------------------------------------------

filnavn='tabell.csv' #sett variablene for plotteprogrammet
separator=';'        #hvordan er verdiene pr linje separert normalt er , eller ;

#Om du vil at programet selv skal finne grensene for x og y aksene.
grenseFraData=1 #1 dersom programmet skal gjøre de, 0 dersom du vil sette under.

Xmin=-20
Xmax=360
Ymin=-1
Ymax=2

#----------------------------------------------------------------------------------

# Hvis et argumet er git til programmet, sett det som tabellnavn
if len(sys.argv) >= 2:
	filnavn = sys.argv[1]
if len(sys.argv) == 3:
	separator = sys.argv[2]
	
#Laster data fra filen
with open(filnavn) as f:
    linjer = f.readlines()

#initialiserer aksene og min og maksverdier
akse=[]
ymin=[]
ymax=[]

#Gjor om til en liste med linjer til akser med data.
for linjenr, linje in enumerate(linjer) :
	#behandler kolonne i rad
	for kolnr, kolonne in enumerate(linje.split(separator)) : 
		if linjenr == 0:
			akse.append([])
			ymin.append(99999)
			ymax.append(-1e300)
			akse[kolnr].append(kolonne)

		else:
			kolonne= float(kolonne)
			#Legger til min og maks verdier.
			if (kolonne < ymin[kolnr]):
				ymin[kolnr]=kolonne
			if (kolonne > ymax[kolnr]):
				ymax[kolnr]=kolonne

			akse[kolnr].append(kolonne)

if len(akse) < 2:

	print ("Du har ikke oppgitt en gyldig fil med 2 eller fler akser.. ")
	exit()


#Sette navnet på x aksen (første verdi i data)
plt.xlabel(akse[0][0])

# xmin, xmax ymin ymax
x=akse[0][1:]


# hvis grense skal beregnes fra data.
if grenseFraData == 1:

	grenser=[]
	grenser.append(min(x))
	grenser.append(max(x))
	grenser.append(min(ymin[1:]))
	grenser.append(max(ymax[1:]))

#hvis grenser for aksene ønskes å settes manuellt
else :
	grenser=[Xmin,Xmax,Ymin,Ymax]

# sett grensene
plt.axis(grenser)

#gir antall akser
antAkser=len(akse);
# Plot alle radene radene (y- veridene)
for i in range(antAkser)[1:]:
	plt.plot(x,akse[i][1:],label=akse[i][0])

#akser 
plt.legend()

#Regner ut skala for å kalkulere pilhodene
xmin, xmax = plt.xlim()
ymin, ymax = plt.ylim()
xscale = (xmax-xmin )/100
yscale = (ymax-ymin )/100

#viser en x og y akse.
plt.arrow(xmin, 0, (xmax-xmin)*0.98, 0,  head_width=yscale*2,head_length=xscale*2,fc='k', ec='k', lw=2)
plt.arrow(0, ymin, 0, (ymax-ymin)*0.96, head_width=xscale*1.5, head_length=yscale*3,fc='k', ec='k', lw=2)
#viser rutenett 
plt.grid()

#viser grafen
plt.show()
