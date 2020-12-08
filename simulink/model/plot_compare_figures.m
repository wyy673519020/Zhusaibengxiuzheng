num_list = [ 42, 66, 55, 113, 120, 113, 96 ];

%%  ----- Set Parameters -----
addr_td1 = [ 'ZSB_A1.csv' ];
load ZSB_res.mat;

%% ---- Run Models ----
m = csvread( addr_td1 );
% calculate maxmium of error and mean of error
m(:,6) = W_average1;
m(:,7)=abs(m(:,5)-m(:,6)) * 100;
[max_m,index]=max(m(:,7));
mean_m=mean(m(:,7));
X = fprintf('maxmium of error = %f %% \n',max_m);
X = fprintf('mean of error = %f %% \n',mean_m);
%calculate maxmium of pulsation rate and mean of pulsation rate
max_p=max(W_pr1(:));
mean_p=mean(W_pr1(:));
X = fprintf('maxmium of pulsation rate= %f %%\n',max_p);
X = fprintf('mean of pulsation rate = %f %%\n',mean_p);

%% ---- Plot 7 Pictures ----

Pout_list = [ 0.242954762, 0.364431487, 0.485908649, 0.535714286, 0.666666667, 0.833333333, 1 ];
cnt = 0;
for i = 1 : 7
    
    figure( i )
    
    for j = 1 : num_list( i )
    
         plot3( m( cnt + j, 1 ), m( cnt + j, 4 ), m( cnt + j, 5 ), 'o', m( cnt + j, 1 ), m( cnt + j, 4 ), m( cnt + j, 6 ), 'p' );
         hold on;
         line( [m( cnt + j, 1 ),m( cnt + j, 1 )], [ m( cnt + j, 4 ),  m( cnt + j, 4 ) ], [m( cnt + j, 5 ), m( cnt + j, 6 )] );
         title( [ 'Pout=' num2str( Pout_list(i) ) ] );
         xlabel('Np');
         ylabel('deltaP');
         zlabel('W');
         grid on;
    end
    cnt = cnt + num_list( i );
end