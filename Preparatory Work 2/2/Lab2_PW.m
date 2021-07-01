%% 2-1

clear; clc;
s = tf('s');
tau=0.04; kp=1.2; kc1=5; kc2=10; kc3=40; kc4=10.9362;

P = kp / (s*(tau*s+1));

sim('Lab2_PW');

figure(1)
step(kc4*P/(1+kc4*P));
grid on;
title('Step Reference Tracking - kc=10.9362');
xlabel('time - t'); ylabel('Amplitude - y');
set(findobj(gcf,'type','line'),'linewidth',2, 'color', [0.8,0.4,0.5])   ;
% legend('kc=5','kc=10','kc=40');

figure(2)
T1 = feedback(kc1*P,1); T2 = feedback(kc2*P,1); T3 = feedback(kc3*P,1); 
hold on;
nyquist(kc1*P);
nyquist(kc2*P);
nyquist(kc3*P);
set(findobj(gcf,'type','line'),'linewidth',2);
grid on;
% title('Step Reference Tracking');
% xlabel('time - t'); ylabel('Amplitude - y');
legend('kc=5','kc=10','kc=40');

figure(3)
hold on;
rlocus(P);
set(findobj(gcf,'type','line'),'linewidth',2);
grid on;


%% q2-5

clear; clc;
load('Data.mat');
syms z w;             % time ¦Æ ¦Øn
s = tf('s');
r = 1-exp(-80*t);
kc = 0.2;

% find rise time:
t90 = min(find(y>=0.9));    t10 = max(find(y<=0.1));
tr = t(t90)-t(t10);

% find setting time (1%)
t99 = min(find(abs(1-y)<=0.01));
ts = t(t99);

% solve for ¦Æ and ¦Øn
eqn = [tr==(1.6*z^3-0.17*z^2+0.92*z+1.02)/w, ts==4.6/(z*w)];
var = [z,w];
[zeta, wn] = solve(eqn, var);
z = double(vpa(zeta));  w = double(vpa(wn));
z = z(find(sqrt(z.^2)==real(z))); w = w(find(sqrt(w.^2)==real(w)));

G = w^2/(s^2+2*z*w*s+w^2);

% find ¦Óp and kp
tau_p = 1/(2*z*w);
kp = w^2*tau_p/kc;

figure() 
hold on;
lsim(G,r,t);
set(findobj(gcf,'type','line'),'linewidth',2);
plot(t,r, 'linewidth',1, 'color', [.5,.5,.5]);
plot(t,y, 'linewidth',1.5);
title('Linear simulation'); grid;
legend('Reference tracking of the theoretical system', ...
       'Experimental reference signal', ...
       'Reference tracking of the experimental system');
   

   
%% q2-6

clear; clc;
load('Data.mat');
r = 1-exp(-80*t);
ts = t(2)-t(1);
data = iddata(y,r,ts);
G = tfest(data,2,0);

figure() 
hold on;
lsim(G,r,t);
set(findobj(gcf,'type','line'),'linewidth',2);
plot(t,r, 'linewidth',1, 'color', [.5,.5,.5]);
plot(t,y, 'linewidth',1.5);
title('Linear simulation'); grid;
legend('Reference tracking of the theoretical system, by tfest', ...
       'Experimental reference signal', ...
       'Reference tracking of the experimental system');


