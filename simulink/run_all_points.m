%% ----- Set Environment -----
clc;
clear;
warning( 'off' );

%%  ----- Set Parameters -----
addr_td1 = [ 'ZSB_A1.csv' ];
sim_time = 2;
collect = 0.5;

%% ---- Run Models ----
u = csvread( addr_td1 );
n = size( u, 1 );
for  i = 1 : n
    [W_average,dPhi_average,W_pr,t_vec,y_vec] = simulinkrun( u(i,:), sim_time, collect );
    W_average1(i,:) = W_average;
    dPhi_average1(i,1:2) = dPhi_average;
    m(i,:)=dPhi_average1(i,1);
    dPhi_average1(i,3) = dPhi_average(1) / dPhi_average(2);
    W_pr1(i,:) = W_pr;
    %figure(i);
    %plot(t_vec,y_vec);
    %grid on;
    %hold on;
end
