clear; clc; close all;
load('data_1.mat')
figure()
plot(r_1.time,r_1.signals.values,'linewidth',2)
xlabel('time')
ylabel('amplitude')
grid on
figure()
plot(u_1.time,u_1.signals.values,'linewidth',2)
xlabel('time')
ylabel('amplitude')
grid on
figure()
plot(y_1.time,y_1.signals.values,'linewidth',2)
xlabel('time')
ylabel('arm degree[^o]')
grid on
ylim([-360 360])