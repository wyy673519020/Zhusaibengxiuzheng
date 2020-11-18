function W_average= simrun( u,sim_time,collect)
t = [ 0; sim_time];
u1 = [ u; u ];
[~,~,y] = sim( 'modelZSB5', sim_time, [], [t, u1] );
% average output values of the considered points (at i-th test point)
W_average=mean(y( end-end*collect:end,1));
% dPhi_average(:,1) = mean( y( end-end*collect:end, 2 ) );
% dPhi_average(:,2) = mean( y( end-end*collect*0.5:end, 2 ) ); 
% % pulsation rate of the output, which reflects the severity of signal oscillation
% W_pr = ( max( y( end-end*collect:end, 1 ) ) - min( y( end-end*collect:end, 1 ) ) ) * 100;
% y_vec = y;
% t_vec=[0:0.0001:sim_time];
end