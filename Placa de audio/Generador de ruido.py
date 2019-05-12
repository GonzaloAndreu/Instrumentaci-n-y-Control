import numpy as np
import matplotlib.pyplot as plt
Periods=100
t=np.linspace(0,2*Periods*np.pi,50*Periods+1)
Noise=np.random.rand(50*Periods+1)*2-1
wave=10*np.sin(t) + Noise

plt.plot(t,wave)


Average = np.mean(wave)
Data0=abs(wave-Average)
Partial_Amplitude=[]
for i in range (11,len(Data0)-10):
    if Data0[i] == max(Data0[i-11:i+10]):
        Partial_Amplitude.append(Data0[i])
        
Amplitud=np.mean(Partial_Amplitude)
Desvio=np.std(Partial_Amplitude)
print(Amplitud,Desvio)
print(np.mean(Noise))
