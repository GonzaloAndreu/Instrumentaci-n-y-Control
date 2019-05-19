# -*- coding: utf-8 -*-
"""
Created on Wed May 15 15:32:55 2019

@author: Pato
"""

import sounddevice as sd
import numpy as np
import matplotlib.pyplot as plt
import pyaudio
from scipy import signal

'''Esto solo muestra los dispositivos conectados '''
p = pyaudio.PyAudio()  # Configura el sistema de PortAudio

for index in range(p.get_device_count()):   
    print(p.get_device_info_by_index(index)) 

#%%
''' Genero un seno de frecuencia 440Hz con un sample rate de 44100 y que dure 10 seg
y luego lo reproduzco mientras grabo'''    

fs = 44100
frequency = 400
duration = 20

t = np.linspace(0, duration, fs * duration)  #  Produce un vector tiempo de 5 seg
#y = np.sin(frequency * 2 * np.pi * t)  #  Genero un seno
y = signal.sawtooth(frequency * 2 * np.pi * t)  #  Genero un Rampa

'''Guardo la grabacion en myrecording, usar uno o dos canales lo que hace es devolver
1 o 2 curvas de grabaciones'''
myrecording = sd.playrec(y,fs,channels=1,blocking=True)




#%%
''' Ploteo la grabacion y el seno generado en funcion del tiempo'''

plt.plot(t,myrecording, label = 'Sonido grabado')
plt.plot(t,y, label = 'Sonido emitido')
plt.legend()
plt.show()




