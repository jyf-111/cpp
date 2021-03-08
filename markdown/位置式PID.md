
#simple rocket 2  

##位置式PID
>PID（比例（proportion）、积分（integration）、微分（differentiation））控制器作为最早实用化的控制器已有近百年历史，现在仍然是应用最广泛的工业控制器。PID控制器简单易懂，使用中不需精确的系统模型等先决条件，因而成为应用最为广泛的控制器。  

![PID控制流程](https://pic2.zhimg.com/v2-2d7b09b5855a64155b630612a3a571e9_180x120.jpg "PID控制流程")


$$
u(k)=\underbrace{Kp{\,}*e(k)}_P{\,}+{\,}\underbrace{Ki{\,}*\sum\limits_{n=0}^ke(n)}_i{\,}+{\,}\underbrace{Kd{\,}*(e(k)-e(k-1))}_d
$$

-------
看到这一长串公式先不要怕，其实不难我们分开来看    

**实例是从地面悬停到50米高空**  


<iframe 
    src="//player.bilibili.com/player.html?aid=586512544&bvid=BV19z4y1m7uD&cid=295450379&page=1" 
    scrolling="no" 
    height=450 
    width=800 
    border="0" 
    frameborder="no" 
    framespacing="0" 
    allowfullscreen="true"> 
</iframe>  


******
current height = 0 m  
target height = 50 m  
e(k)=target height - current height  
## P 比例（proportion）  

先单纯考虑p比例控制  
$p=Kp{\,}*e(k)$

e(k)就是当前的误差:  
一开始就是  （50 - 火箭的高）  

随着火箭上升 e(k) = 0时，火箭推力为0，但速度不为0，势必冲过50米，引擎关机做加速度为g的均加速直线运动，待高度低于50米，引擎开机，逐渐增大推力，这时很大概率就装地炸了（才50米），就算没炸，重复上述过程，理想情况是形如正弦函数，但随着误差的积累，偏差会越大，  

Kp先放一放奥  

***纯P控制就是多退少补，势必会有很大误差，我们可以引入 D 控制***
******  

## D微分（differentiation）
$D=Kd{\,}*(e(k)-e(k-1))$  

detla = e(k)-e(k-1) 前一个时间点的误差减去后一个时间点的误差，采样时间点间隔大于游戏物理帧（小于的话会导致异常，大于的话会导致计算不精准，我设置的时0.1s）  

Kd放一放奥  

*D就是微分（差不多也就是速度）太大了就慢点，你别那么快，慢了就快点，你别那么慢*  

***P和 D 协调控制可以达到一个好的效果了，但这只是座舱里坐了一个up的情况，试想如果指令舱里坐了1000个up或者火箭载荷巨大，引擎推力要抗衡巨大的重力，会始终维持在目标高度下；试想up害怕了，没上飞船火箭很轻，引擎太大了始终维持在目标高度上方，这时候就要引入  i 控制***  

## I 积分（integration）
$I =Ki{\,}*\sum\limits_{n=0}^ke(n)$  

$\sum\limits_{n=0}^ke(n)$就是多次误差的和， 

假设火箭太重P和D让火箭稳定在40m上下， 
e（k）就是 50-40=10 m，多次积累，$\sum\limits_{n=0}^ke(n)$将会是一个很大的数，促使i项变大让火箭往上走， 
反之如果火箭太轻稳定在60m，火箭就会累计负的值使火箭下降  

*Ki先放一放*  

***值得注意的是最好不要让 I 项过早的起作用，这样一开始距离目标值很远也会起作用，不要翻很久之前的旧账***  

***P I D协同控制，可以把火箭控制的很好，PID这么简单但是好强大啊***

## 参数Kp,Ki,Kd  
也就是各个项占总控制量的权重，三个参数就是魔法调参了，多次尝试，每个火箭，每个任务都不一样，可以借助matlab，phyton多次实验找出最好的值
给个大概的意思
![PID参数](https://i0.hdslb.com/bfs/album/eb58c09ca36437b9881971c50c6d6613d72c1f87.gif "PID参数")

