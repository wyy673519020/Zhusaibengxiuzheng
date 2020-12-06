%% ----- Set Environment -----
clc;
clear;
warning( 'off' );
tic;

%%  ----- Set Parameters -----
addr_td1 = [ 'ZSB_A1.csv' ];

% model_name = [ 'modelZSB' ];
% sim_time = 0.2;

%   Result:
%       maxmium of error = 2.219578e-01
%       mean of error = 1.647800e-02
%       maxmium of pulsation rate= 3.590883e+00
%       mean of pulsation rate = 1.253463e+00
%       time consumption 25.279763 s

% model_name = [ 'modelZSB_chr1' ];
% sim_time = 0.6;

%       xp0 = 30
%   Result:
%       maxmium of error = 2.539913e-01
%       mean of error = 3.947843e-02
%       maxmium of pulsation rate= 3.590883e+00
%       mean of pulsation rate = 1.253463e+00
%       time consumption 262.986293 s

% model_name = [ 'modelZSB_chr2' ];
% sim_time = 0.6;

%       changing xp0 
%   Result:
%       maxmium of error = 4.052644e-02
%       mean of error = 1.582461e-03
%       maxmium of pulsation rate= 3.590883e+00
%       mean of pulsation rate = 1.253463e+00
%       time consumption 271.847918 s

model_name = [ 'modelZSB_lib' ];
sim_time = 0.2;

%       maxmium of error = 2.248118e-01
%       mean of error = 1.405494e-02
%       maxmium of pulsation rate= 3.590883e+00
%       mean of pulsation rate = 1.253463e+00
%       time consumption  136.292094 s

collect = 0.5;
sample_time = 0.01;

%% ---- Run Models ----
u = csvread( addr_td1 );
n = size( u, 1 );
for  i = 1 : n
    [W_average,dPhi_average,W_pr,t_vec,y_vec] = simulinkrun( model_name, u(i,:), sim_time, sample_time, collect );
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

save( 'comparisonplot\ZSB_res.mat', 'W_average1' );
run( 'comparisonplot\plot_compare_figures' );

toc;
