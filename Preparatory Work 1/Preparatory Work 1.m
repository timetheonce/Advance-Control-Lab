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

