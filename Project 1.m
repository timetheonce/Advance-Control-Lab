clear; clc;
s=tf('s');
G1=15^2/(s^2+30*s+15^2);
G2=15*s/(s^2+30*s+15^2);
step(G1)
step(G2)

%%
Km=39.6/1000;
Kb=6.46/1000/pi*60;
Ra=6.8;
La=620e-6;
J=0.06;
f=0.01;
G3=1/(Ra+La*s);
G4=Km;
G5=1/(J*s^2+f*s);
G6=Kb*s;
