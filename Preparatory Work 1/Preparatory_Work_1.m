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
Km=39.6/1000; %[Nm/A]
Kb=6.46/1000/pi*60; %[V/rad]
Ra=6.8; %[Ohm]
La=620e-6; %[H]
J=0.06; %[kg m2]
f=0.01; %[Nm sec / rad]

% with La
G3=1/(Ra+La*s);
G4=Km;
G5=1/(J*s+f);
G6=Kb;
Gvt=feedback(G3*G4*G5,G6)/s;

% without La
La=0;
G3s=1/(Ra+La*s);
G4s=Km;
G5s=1/(J*s+f);
G6s=Kb;
Gvts=feedback(G3s*G4s*G5s,G6s)/s;

% plot the bode with and without La
figure
bode(Gvt,'r')
hold on
bode(Gvts,'g')
hold off
legend('with La','without La')

