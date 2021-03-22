%% Question 1

clear; clc;
s=tf('s');
G1=15^2/(s^2+30*s+15^2);
G2=15*s/(s^2+30*s+15^2);
figure
step(G1)
grid on
title('Step response for $G_1$','Interpreter','latex')
figure
step(G2)
grid on
title('Step response for $G_2$','Interpreter','latex')

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