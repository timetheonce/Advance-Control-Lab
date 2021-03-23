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

%% Question 2
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


%% Question 3
SimPG1=sim('Q3G1block.slx');
SimPG2=sim('Q3G2block.slx');

% Step response for PG1
figure
plot(SimPG1.tout,SimPG1.ScopeData1.signals.values)
xlabel('time [seconds]')
ylabel('\theta [rad]')
title('step response for PG_1')
grid on

% Step response for PG2
figure
plot(SimPG2.tout,SimPG2.ScopeData1.signals.values)
xlabel('time [seconds]')
ylabel('\theta [rad]')
grid on
title('step response for PG_2')

%% Question 4
close all
% Step response for PG1
figure
step(Gvt*G1)
xlabel('time [seconds]')
ylabel('\theta [rad]')
title('step response for PG_1')
grid on
xlim([0 100])

% Step response for PG2
figure
step(Gvt*G2)
xlabel('time [seconds]')
ylabel('\theta [rad]')
title('step response for PG_2')
grid on
xlim([0 50])



%% Question 5




















