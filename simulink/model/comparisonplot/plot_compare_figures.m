%% ----- Set Environment -----
clc;
clear;
warning( 'off' );
%%  ----- Set Parameters -----
addr_td1 = [ 'ZSB_A2.csv' ];
load ZSB_res.mat;

%% ---- Run Models ----
m = csvread( addr_td1 );
% calculate maxmium of error and mean of error
m(:,2) = W_average1;
m(:,4)=m(:,1)-m(:,2);
m(:,4)=abs(m(:,4));
[max_m,index]=max(m(:,4));
mean_m=mean(m(:,4));
X = fprintf('maxmium of error = %d\n',max_m);
X = fprintf('mean of error = %d\n',mean_m);
%calculate maxmium of pulsation rate and mean of pulsation rate
max_p=max(m(:,3));
mean_p=mean(m(:,3));
X = fprintf('maxmium of pulsation rate= %d\n',max_p);
X = fprintf('mean of pulsation rate = %d\n',mean_p);
% plot 7 pictures
addr_td2 = [ 'ZSB_A3.csv' ];
n = csvread( addr_td2 );
n(:,5)=m(:,2);
n1=n(1:42,2:5);
n2=n(43:108,2:5);
n3=n(109:163,2:5);
n4=n(164:276,2:5);
n5=n(277:396,2:5);
n6=n(397:509,2:5);
n7=n(510:605,2:5);
m1=size(n1,1);
m2=size(n2,1);
m3=size(n3,1);
m4=size(n4,1);
m5=size(n5,1);
m6=size(n6,1);
m7=size(n7,1);
figure(1)
for i=1 : m1
x1_1=n1(i,1);
y1_1=n1(i,2);
z1_1=n1(i,3);
x1_2=n1(i,1);
y1_2=n1(i,2);
z1_2=n1(i,4);
plot3(x1_1,y1_1,z1_1,'o',x1_2,y1_2,z1_2,'p');
hold on;
line([x1_1,x1_2],[y1_1,y1_2],[z1_1,z1_2])
title('Pout=0.242954762');
xlabel('Np');ylabel('deltaP');zlabel('W');
grid on;
end
figure(2)
for i=1 : m2
x2_1=n2(i,1);
y2_1=n2(i,2);
z2_1=n2(i,3);
x2_2=n2(i,1);
y2_2=n2(i,2);
z2_2=n2(i,4);
plot3(x2_1,y2_1,z2_1,'o',x2_2,y2_2,z2_2,'p');
hold on;
line([x2_1,x2_2],[y2_1,y2_2],[z2_1,z2_2])
title('Pout=0.364431487');
xlabel('Np');ylabel('deltaP');zlabel('W');
grid on;
end
figure(3)
for i=1 : m3
x3_1=n3(i,1);
y3_1=n3(i,2);
z3_1=n3(i,3);
x3_2=n3(i,1);
y3_2=n3(i,2);
z3_2=n3(i,4);
plot3(x3_1,y3_1,z3_1,'o',x3_2,y3_2,z3_2,'p');
hold on;
line([x3_1,x3_2],[y3_1,y3_2],[z3_1,z3_2])
title('Pout=0.485908649');
xlabel('Np');ylabel('deltaP');zlabel('W');
grid on;
end
figure(4)
for i=1 : m4
x4_1=n4(i,1);
y4_1=n4(i,2);
z4_1=n4(i,3);
x4_2=n4(i,1);
y4_2=n4(i,2);
z4_2=n4(i,4);
plot3(x4_1,y4_1,z4_1,'o',x4_2,y4_2,z4_2,'p');
hold on;
line([x4_1,x4_2],[y4_1,y4_2],[z4_1,z4_2])
title('Pout=0.535714286');
xlabel('Np');ylabel('deltaP');zlabel('W');
grid on;
end
figure(5)
for i=1 : m5
x5_1=n5(i,1);
y5_1=n5(i,2);
z5_1=n5(i,3);
x5_2=n5(i,1);
y5_2=n5(i,2);
z5_2=n5(i,4);
plot3(x5_1,y5_1,z5_1,'o',x5_2,y5_2,z5_2,'p');
hold on;
line([x5_1,x5_2],[y5_1,y5_2],[z5_1,z5_2])
title('Pout=0.666666667');
xlabel('Np');ylabel('deltaP');zlabel('W');
grid on;
end
figure(6)
for i=1 : m6
x6_1=n6(i,1);
y6_1=n6(i,2);
z6_1=n6(i,3);
x6_2=n6(i,1);
y6_2=n6(i,2);
z6_2=n6(i,4);
plot3(x6_1,y6_1,z6_1,'o',x6_2,y6_2,z6_2,'p');
hold on;
line([x6_1,x6_2],[y6_1,y6_2],[z6_1,z6_2])
title('Pout=0.833333333');
xlabel('Np');ylabel('deltaP');zlabel('W');
grid on;
end
figure(7)
for i=1 : m7
x7_1=n7(i,1);
y7_1=n7(i,2);
z7_1=n7(i,3);
x7_2=n7(i,1);
y7_2=n7(i,2);
z7_2=n7(i,4);
plot3(x7_1,y7_1,z7_1,'o',x7_2,y7_2,z7_2,'p');
hold on;
line([x7_1,x7_2],[y7_1,y7_2],[z7_1,z7_2])
title('Pout=1');
xlabel('Np');ylabel('deltaP');zlabel('W');
grid on;
end