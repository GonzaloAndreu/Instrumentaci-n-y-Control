# -*- coding: utf-8 -*-
"""
Created on Sun Apr 21 16:53:50 2019

@author: Gonzalo

"""
"""
import pyvisa

rm=pyvisa.ResourceManager()
rm.list_resources()

"""


from lantz.drivers.examples import LantzSignalGenerator

inst = LantzSignalGenerator('TCPIP::localhost::5678::SOCKET')
inst.initialize()
inst.amplitude= 10
inst.frequency=30

print(inst.idn)
print(inst.frequency)
print(inst.amplitude)
inst.finalize()

