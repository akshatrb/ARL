# ARL
 Room electricity automation using C8051F340 MC
 ARL stands for Automatic Room Lighting.
 
The aim of this project is to automatically turn on or off the lights/appliances in a room 
on detecting any human movement. This project is implemented using the 8051 Microcontroller, Infrared (IR) sensors
and other components.

When a person tries to enter the room, Sensor 1 detects the person first and then Sensor 2. 
This action will indicate the 8051 Microcontroller that the person is entering the room. 
Hence, the microcontroller will turn on the light and also increment the visitor counter to 1. 
If there are more visitors, the microcontroller will keep the light turned on and increment the visitor counter accordingly.

Detailed description of H/W involved is attachhed along with the Assembly code in C.
