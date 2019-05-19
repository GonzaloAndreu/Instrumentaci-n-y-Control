'''
script para analizar los datos medidos con la placa de videop, en principio va a buscar las amplitudes de las oscilaciones para graficar la salida en funcion de la entrada y ver si existe una relacion lineal.

'''

import numpy as np
import matplotlib.pyplot as plt


'''
en esta parte se van a poenr los parametro a utilizar
'''


Frec = 440 # Hertz
TiempoDeMedicion = 10 # segundos
#RawData =
Cantidad_Oscilaciones=Frec*TiempoDeMedicion
Largo_Oscilaciones=int(len(RawData[0])/Cantidad_Oscilaciones)

Amplitud_Salida=[]
Desvio_Salida=[]
for i in range (0,len(RawData)):
    M=np.mean(RawData[i])
    Data0=np.abs(RawData[i]-M)
    Amplitud_Parcial=[]
    for j in range (0,int(Cantidad_Oscilaciones)):
        Inicio=int(j*Largo_Oscilaciones/2+Largo_Oscilaciones/4)
        Fin=int(min((j+1)*Largo_Oscilaciones/2+Largo_Oscilaciones/4,len(Data0)))
        Amplitud_Parcial.append(max(Data0[Inicio:Fin]))
    Amplitud_Salida.append(np.mean(Amplitud_Parcial))
    Desvio_Salida.append(np.std(Amplitud_Parcial))
Amplitud_Entrada=(np.linspace(0.01,1,20))

plt.plot(Amplitud_Entrada,Amplitud_Salida)
plt.show()

