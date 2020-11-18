%% 清空环境
clear
clc
warning( 'off' );
tic;
%% 参数设置
w = 0.6;      % 惯性因子 
c1 = 2;       % 加速常数
c2 = 2;       % 加速常数
Dim = 5;            % 维数
SwarmSize = 10;    % 粒子群规模
ObjFun = @PSO_cha;  % 待优化函数句柄
MaxIter = 2;      % 最大迭代次数  
MinFit = 0;       % 最小适应值 
Vmax=0.5;
Vmin=-0.5;
Ub = [43 70 41 315.3773 167];
Lb = [43 70 41 315.3773 167];
%% 粒子群初始化
Range = ones(SwarmSize,1)*(Ub-Lb);
Swarm = rand(SwarmSize,Dim).*Range + ones(SwarmSize,1)*Lb;   % 初始化粒子群
VStep = rand(SwarmSize,Dim)*(Vmax-Vmin)+Vmin;                 % 初始化速度
fSwarm = zeros(SwarmSize,1);
for i=1:SwarmSize
    fSwarm(i,:) = feval(ObjFun,Swarm(i,:));                         % 粒子群的适应值
end
%% 个体极值和群体极值
[bestf bestindex]=min(fSwarm);
zbest=Swarm(bestindex,:);   % 全局最佳
gbest=Swarm;                % 个体最佳
fgbest=fSwarm;              % 个体最佳适应值
fzbest=bestf;               % 全局最佳适应值
%% 迭代寻优
iter = 0;
y_fitness = zeros(1,MaxIter);   % 预先产生4个空矩阵
l1 = zeros(1,MaxIter);         
l2 = zeros(1,MaxIter);
l3 = zeros(1,MaxIter);
l4 = zeros(1,MaxIter);
l5 = zeros(1,MaxIter);
while( (iter < MaxIter) && (fzbest > MinFit) )
for j=1:SwarmSize
% 速度更新
VStep(j,:) = w*VStep(j,:) + c1*rand*(gbest(j,:) - Swarm(j,:)) + c2*rand*(zbest - Swarm(j,:));
if VStep(j,:)>Vmax, VStep(j,:)=Vmax; end
if VStep(j,:)<Vmin, VStep(j,:)=Vmin; end
% 位置更新
Swarm(j,:)=Swarm(j,:)+VStep(j,:);
for k=1:Dim
if Swarm(j,k)>Ub(k), Swarm(j,k)=Ub(k); end
if Swarm(j,k)<Lb(k), Swarm(j,k)=Lb(k); end
end
% 适应值
fSwarm(j,:) = feval(ObjFun,Swarm(j,:));
% 个体最优更新     
if fSwarm(j) < fgbest(j)
gbest(j,:) = Swarm(j,:);
fgbest(j) = fSwarm(j);
end
% 群体最优更新
if fSwarm(j) < fzbest
zbest = Swarm(j,:);
fzbest = fSwarm(j);
end
end 
iter = iter+1;                      % 迭代次数更新
y_fitness(1,iter) = fzbest;         % 为绘图做准备
l1(1,iter)=zbest(1);
l2(1,iter)=zbest(2);
l3(1,iter)=zbest(3);
l4(1,iter)=zbest(4);
l5(1,iter)=zbest(5);
end

toc;
