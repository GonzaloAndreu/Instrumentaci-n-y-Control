# -*- coding: utf-8 -*-
"""
Created on Tue Apr 23 16:24:15 2019

@author: macabre
"""

import pyaudio
import numpy as np
import matplotlib.pyplot as plt
 
CHUNK = 1024 # CAntidad de frames por buffer
FORMAT = pyaudio.paInt32  # SI CAMBIO EL TIPO DE DATO CAMBIAR EL VARIABLE AUDIO
CHANNELS = 1
RATE = 98000
RECORD_SECONDS = 1
WAVE_OUTPUT_FILENAME = "output.wav"
 
p = pyaudio.PyAudio()  # Configura el sistema de PortAudio
'''


print("Input Device Info")
print(p.get_default_input_device_info())
print("Output Device Info")
print(p.get_default_output_device_info())
 
for i in range(p.get_host_api_count()):
    print(p.get_host_api_info_by_index(i))
'''
for index in range(p.get_device_count()):   
    print(p.get_device_info_by_index(index)) 
    
# El for anterior, busca cuantos aparatos hay conectados y luego los lista
# especificando cual es cada uno

'''
Esto abre un flujo en determinado aparato, con  ciertos parametros de 
audio, para poder grabar o reproducir audio. Es decir, Configura
 p.Stream para reproducir o grabar audio
'''
volume = 0.5     # range [0.0, 1.0]
fs = 44100       # sampling rate, Hz, must be integer
duration = 1   # in seconds, may be float
f = 261.626        # sine frequency, Hz, may be float
#F = np.linspace(110,4400,4291)
#for i in F:
    # generate samples, note conversion to float32 array
#    f=i


# for paFloat32 sample values must be in range [-1.0, 1.0]
stream = p.open(format=pyaudio.paFloat32,
                channels=1,
                rate=fs,
                output=True)

record = p.open(format=FORMAT,     # Tipos de formato paFloat32, paInt32, paInt24, paInt16, paInt8, paUInt8, paCustomFormat   
                channels=CHANNELS,  #  Numero de canales
                rate=RATE,          #  frecuencia de muestreo
                input=True,   #   Especifica si es un input stream. Defecto = False
                frames_per_buffer=CHUNK, # Cantidad de frames por buffer
                input_device_index=1)  # Indice del dispositivo a usar. Si no especifico usa el por defecto y lo ignora si el input es 'False'
 
# play. May repeat with different volume values (if done interactively) 
samples = (np.sin(2*np.pi*np.arange(fs*duration)*f/fs)).astype(np.float32).tobytes()
stream.write(samples)


print("* recording")
 
frames = []
 
 
for i in range(0, int( (RATE / CHUNK) * RECORD_SECONDS)):  # Si el numero es chico como usa la funcion int redondea a cero y no da nada.
    data = record.read(CHUNK)  # Lee la data del audio del stream CHUNK
    frames.append(data)
  
    
print("* done recording")
 
record.stop_stream()   # Pausa la grabacion
record.close()     # termina el stream


stream.stop_stream()
stream.close()





p.terminate()    # termina la sesion de portaudio
 
time = []
 
 
wave = np.fromstring(b''.join(frames),dtype=np.int16)

Average = np.mean(wave)
Data0=abs(wave-Average)
Partial_Amplitude=[]
for i in range (11,len(Data0)-10):
    if Data0[i] == max(Data0[i-11:i+10]):
        Partial_Amplitude.append(Data0[i])
        
Amplitud=np.mean(Partial_Amplitude)
Desvio=np.std(Partial_Amplitude)
    
# 
#t = np.linspace(0,RECORD_SECONDS,num=wave.size)
#plt.plot(t,wave)
#plt.show()