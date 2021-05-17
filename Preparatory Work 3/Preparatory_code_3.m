clear
clc
close all
cd 'E:\OneDrive\学习\大四下spring 2021\Advance Control Lab\Advance-Control-Lab\Preparatory Work 3';
load('SIMULINK Q1.mat');
s=tf('s');
format short
set(groot,'defaultLineLineWidth',2);

P=(10)/(s*(s+10));
C=4;
TF=feedback(C*P,1);
ST=0.01; % threshold of setting time error
S=stepinfo(TF,'SettlingTimeThreshold',ST);

while S.SettlingTime >= 1 || S.Overshoot>=20
    C=C+0.001;
    TF=feedback(C*P,1);
    S=stepinfo(TF,'SettlingTimeThreshold',ST);
end
Kp_min=C;

while S.SettlingTime < 1 && S.Overshoot<20
    C=C+0.01;
    TF=feedback(C*P,1);
    S=stepinfo(TF,'SettlingTimeThreshold',ST);
end
Kp_max=C-0.01;
y1=out.ScopeData.signals(1).values;   % system response y(t) of r(t)=1
y2=out.ScopeData.signals(2).values;    % system response y(t) of d(t)=1
time=out.ScopeData.time;

TF_ru=C/(1+C*P); % Transfer function from r to u
TF_du=-C*P/(1+C*P); % Transfer function from d to u

plot(time,y1,time,y2,'--'); xlabel('time [sec]'); ylabel('response y')
grid on; legend('r(t)=1, d(t)=0','r(t)=0, d(t)=1')

%% Q1 Part 2
s=tf('s');
Kp=20;Ki=14;Kd=4;N=100;
C=Kp*(1+Ki/s+Kd*N/(1+N*1/s));
P=(10)/(s*(s+10));

TF_ru=C/(1+C*P); % Transfer function from r to u
TF_du=-C*P/(1+C*P); % Transfer function from d to u




