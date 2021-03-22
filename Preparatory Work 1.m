%% Question 1
clear
clc
s=tf('s');
G1=15^2/(s^2+30*s+15^2);% Transfer function for system 1
G2=15*s/(s^2+30*s+15^2);% Transfer function for system 2
figure
step(G1) % Step response for G1
grid on
title('Step response for $G_1$','Interpreter','latex')
figure
step(G2) % Step response for G2
grid on
title('Step response for $G_2$','Interpreter','latex')

