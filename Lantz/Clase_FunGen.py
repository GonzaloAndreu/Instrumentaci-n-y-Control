# -*- coding: utf-8 -*-
"""
Prueba del Instrumento virtual
"""



#
#from lantz import MessageBasedDriver
##from lantz.core import mfeats
#
#
## Definimos una clase osciloscopio con algunos metodos y que herede os de MBD
#class FunGen(MessageBasedDriver): 
#    
#    def idnn(self):
#        return self.query('idn')
#    
#    def get_frequency(self):
#        return float(self.query('freq'))
#    
##    def set_timebase(self, value):
##        return self.write('HOR:MAIN:SCA {}' . format(value))
#        
#    
#        
#with FunGen('5678') as osci:
#    print(osci.idnn)
#        
#        
#
#    print(osci.idn())
#    osci.set_frequency(10)   # setea el timebase
#    print(osci.get_frequency()) # devuelve el valor del timebase


#%%

from lantz.drivers.examples import LantzSignalGenerator

class FunGen(LantzSignalGenerator):
    
    def __init__(self):
       self = LantzSignalGenerator('TCPIP::localhost::5678::SOCKET')
        
    def GetFrequency(self):
        return self.FunGen.frequency


#with FunGen('TCPIP::localhost::5678::SOCKET') as osci:
#    print(osci.GetFrequency)
#
Prueba=FunGen()
Prueba.GetFrequency




