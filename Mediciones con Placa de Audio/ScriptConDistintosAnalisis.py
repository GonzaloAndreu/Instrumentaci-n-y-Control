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

#%%
'''
obtener frecuencia y amplitud si la señal es sinusoidal
'''
from scipy.fftpack import fft, ifft
import numpy as np
from scipy.optimize import curve_fit
import matplotlib.pyplot as plt

#cant_periodos=20
i=0
TiempoDeMedicion = max(0.3,cant_periodos/freqs[i])
#TiempoDeMedicion = 2
audio=RawData[i]

t=np.linspace(0,TiempoDeMedicion,len(RawData[i]))
#t=np.linspace(0,TiempoDeMedicion,len(audio))
def mysine(x,a,b,c,d):
    return a * np.sin(b * x * 2* np.pi + c) + d

Largo=len(audio)
Corte=int(Largo/20)
Lista=np.ndarray.tolist(abs(audio[Corte:Largo-Corte]))
t0_Index=Lista.index(min(Lista)) + Corte
OffSet=np.mean(audio[Corte:Largo-Corte])


sig_fft = np.fft.fft(audio)/Largo*2    # /N to scale due to python DFT equation, 
fft_freq = np.fft.fftfreq(Largo, TiempoDeMedicion/len(audio))
One_side=np.ndarray.tolist(20*np.log10(abs((sig_fft[:Largo//2]))))
freqaux=fft_freq[One_side.index(max(One_side))]


# Runs curve fitting with initial guess.
popt, pcov = curve_fit(mysine, t[Corte:Largo-Corte], audio[Corte:Largo-Corte], p0=[(max(audio)-min(audio))/2,freqaux,t[t0_Index]*2*np.pi*freqaux,OffSet])

# Calculates the fitted curve
yf = mysine(t, *popt)
perr = np.sqrt(np.diag(pcov))

plt.plot(t,audio)
plt.plot(t,yf)
plt.plot(yf*0.3/popt[0],audio)
#%%

param, pvar = np.polyfit(yf*0.3/popt[0], audio,1)
plt.plot(np.linspace(-0.3,0.3,1000),np.linspace(-0.3,0.3,1000)*param,'y')

#%%

sig_fft = np.fft.fft(audio)/Largo*2    # /N to scale due to python DFT equation, 
                                 
fft_freq = np.fft.fftfreq(Largo, TiempoDeMedicion/len(audio))
20*np.log10(abs((sig_fft[:Largo//2])))
#%%

'''
esta parte sirve para sacar las amplitudes y frecuencias de una tira de tiras de datos por medio de un ajuste
'''



import numpy as np
import matplotlib.pyplot as plt
import numpy as np
#import pylab as pl
from scipy.optimize import curve_fit




'''
en esta parte se van a poenr los parametro a utilizar
'''

#RawData = # estio es por si las tira de datos en realidad triene otro nombre, de esta forma no hay que cambiar todo el codigo

Amp_Sal_Control=[]
Amplitud_Salida=[]
Desvio_Amp_Salida=[]
Frecuencia_Salida=[]
Desvio_Frec_Salida=[]

cant_periodos=20
def mysine(x,a,b,c,d):
    return a * np.sin(b * x * 2* np.pi + c) + d


for i in range (0,len(RawData)):
    TiempoDeMedicion = max(0.3,cant_periodos/freqs[i])
    t=np.linspace(0,TiempoDeMedicion,len(RawData[i]))

    audio=RawData[i]
    t=np.linspace(0,TiempoDeMedicion,len(RawData[i]))

    Largo=len(audio)
    Corte=int(Largo/40)
    Lista=np.ndarray.tolist(abs(audio[Corte:Largo-Corte]))
    t0_Index=Lista.index(min(Lista)) + Corte
    del Lista
    OffSet=np.mean(audio[Corte:Largo-Corte])
#       
#    sig_fft = np.fft.fft(audio)/Largo*2    # /N to scale due to python DFT equation, 
#    fft_freq = np.fft.fftfreq(Largo, TiempoDeMedicion/len(audio))
#    One_side=np.ndarray.tolist(20*np.log10(abs((sig_fft[:Largo//2]))))
#    freqaux=fft_freq[One_side.index(max(One_side))]
#    del One_side
#    del sig_fft
#    del fft_freq
    freqaux=freqs[i]
    # Runs curve fitting with initial guess.
    popt, pcov = curve_fit(mysine, t[5*Corte:6*Corte], audio[5*Corte:6*Corte], p0=[(max(audio)-min(audio))/2,freqaux,t[t0_Index]*2*np.pi*freqaux,OffSet])
    
   
    # Calculates the fitted curve
    yf = mysine(t, *popt)
    perr = np.sqrt(np.diag(pcov))
    
    
    Amplitud_Salida.append(abs(popt[0]))
    Desvio_Amp_Salida.append(perr[0])
    Frecuencia_Salida.append(popt[1])
    Desvio_Frec_Salida.append(perr[1])
    Amp_Sal_Control.append((max(audio)-min(audio))/2)
    
#%%
    
    MedicionImputVolumen50=[Amplitud_Salida,Desvio_Amp_Salida,Frecuencia_Salida,Desvio_Frec_Salida]
    np.save('MedicionImputVolumen50',MedicionImputVolumen50) 
   