#  Gauss公式和Stokes公式

------

==I love you==

## Review

$\Large\large-Green's formula$
$$
\Large{\begin{aligned}
\oint_{\partial D} P \mathrm{~d} x+Q \mathrm{~d} y &=\iint_{D}\left(Q_{x}^{\prime}-P_{y}^{\prime}\right) \mathrm{d} x \mathrm{~d} y \\
\oint_{\partial D} \vec{v} \cdot \vec{\tau} \mathrm{d} l &=\iint_{D} \nabla \times \vec{v} \mathrm{~d} x \mathrm{~d} y \\
\int_{\partial D}(P, Q) \cdot \vec{n} \mathrm{~d} l &=\iint_{D}\left(P_{x}^{\prime}+Q_{y}^{\prime}\right) \mathrm{d} x \mathrm{~d} y . \\
\int_{\partial D} \vec{v} \cdot \vec{n} \mathrm{~d} l &=\iint_{D} \nabla \cdot \vec{v} \mathrm{~d} x \mathrm{~d} y
\end{aligned}}
$$


$\Large-Green公式的条件$

$\Large变形处理，比如挖洞$

1)$\Large第二型曲线积分\large\longrightarrow\Large二重积分$

2) $\Large二重积分\large\longrightarrow\Large第二型曲线积分$

3)Green公式的应用： $\large df=Pdx+Qdy$

------



## 常见积分因子

$$
\huge\begin{array}{l}
y d x+x d y=d(x y) \quad \quad \frac{x d x+ydy}{x^{2}+y^{2}}=\frac{1}{2}d\ln{(x^2+y^2})\\\frac{y d x-x d y}{y^{2}}=d\left(\frac{x}{y}\right) \\
\frac{y d x-x d y}{x y}=d\left(\ln \left|\frac{x}{y}\right|\right) \quad \frac{y d x-x d y}{x^{2}+y^{2}}=d\left(\arctan \frac{x}{y}\right) \\
\frac{y d x-x d y}{x^{2}-y^{2}}=\frac{1}{2} d\left(\ln \left|\frac{x-y}{x+y}\right|\right) 
\end{array}
$$



------

## Gauss公式

$\Large设  \Omega \subset \mathbb{R}^{3}  为有界区域,向量场{\vec{v}=P \vec{i}+Q \vec{j}+R \vec{k} } 在  \Omega  内连续可微,在闭区域\bar{\Omega}= 
 \Omega \bigcup \partial \Omega 上 连 续 , 则$
$$
\Large\begin{array}{l}
\oiint_{\partial \Omega} P \mathrm{~d} y \wedge \mathrm{d} z+Q \mathrm{~d} z \wedge \mathrm{d} x+R \mathrm{~d} x \wedge \mathrm{d} y \\
=\iiint_{\Omega}\left(\frac{\partial P}{\partial x}+\frac{\partial Q}{\partial y}+\frac{\partial R}{\partial z}\right) \mathrm{d} x \mathrm{~d} y \mathrm{~d} z
\end{array}
$$
$\Large注意到对应关系 P \mathrm{~d} y \wedge \mathrm{d}z=\frac{\partial P}{\partial x}$

$\Large高斯公式是格林公式在三维空间的推广，和格林公式相同。物理意义:\\\Large向量在边界的积分等同于向量的散度在形内的积分。$

------

## 例子

$\Large1.确定是否符合连续可微的条件，以及检测曲面的方向是否为几何体的外表面，不是外边面需要取负号。$

$\Large2.曲面是否封闭，如果不封闭是无法围成几何体的，从而需要添加新的曲面来使其封闭。\\\Large这一点其实在格林公式里也有所体现，\\\Large比如把两个曲线连起来，证明区域内的积分为0，从而两曲线积分相等。$

------

## Stokes公式

*$\Large \color{green}{首先要说明的是，Stokes公式的作用非常有限，正如我们讨论的那样，\\\Large{既然大多的曲线都可以用三角函数形式的参数方程来表示，而三角函数由于积分时的周期性，非常好积分}\\\Large导致Stokes公式非常的鸡肋，但还是要掌握。}$*

------

$\Large设向量场  \vec{v}=P \vec{i}+Q \vec{j}+R \vec{k}  在空 间区域\Omega内连续可微,  S  是  \Omega  内逐片光滑的有向曲 面,  \partial  S逐段光滑,则$
$$
\large\oint_{\partial S} P \mathrm{~d} x+Q \mathrm{~d} y+R \mathrm{~d} z 
 =\iint_{S}\left(R_{y}^{\prime}-Q_{z}^{\prime}\right) \mathrm{d} y \wedge \mathrm{d} z+\left(P_{z}^{\prime}-R_{x}^{\prime}\right) \mathrm{d} z \wedge \mathrm{d} x+\left(Q_{x}^{\prime}-P_{y}^{\prime}\right) \mathrm{d} x \wedge \mathrm{d} y \\
\Large =\iint_{S} \operatorname{det}\left(\begin{array}{ccc}\cos \alpha & \cos \beta & \cos \gamma \\ \frac{\partial}{\partial x} & \frac{\partial}{\partial y} & \frac{\partial}{\partial z} \\ P & Q & R\end{array}\right) \mathrm{d} S
$$

$$
\Large Remark:  \vec{v}=P \vec{i}+Q \vec{j}+R \vec{k} , 定义旋度算子  \nabla \times  为

\nabla \times \vec{v}=\operatorname{det}\left(\begin{array}{ccc}
\vec{i} & \vec{j} & \vec{k} \\
\frac{\partial}{\partial x} & \frac{\partial}{\partial y} & \frac{\partial}{\partial z} \\
P & Q & R
\end{array}\right)\\
\Large=(\left(R_{y}^{\prime}-Q_{z}^{\prime}\right),\left(P_{z}^{\prime}-R_{x}^{\prime}\right),\left(Q_{x}^{\prime}-P_{y}^{\prime}\right))\\
\Large则Stokes公式可记为  \oint_{\partial S} \vec{v} \cdot \vec{\tau} \mathrm{d} l=\iint_{S}(\nabla \times \vec{v}) \cdot \vec{n} \mathrm{~d} S
$$

$\Large另外，Stokes公式有两个方向问题，第一是曲线方向。第二是曲面方向。$

$\Large Stokes 公式中站在你构造的曲面的正面，沿着曲线的正向走，曲面应该一直在左手侧。\\\Large如果不在左手侧，那么给曲面换个方向就好了。$

$\Large注意到，旋度算子\nabla \times \vec{v}是个向量，这个向量是由det计算而出的。$

$$
\Large记忆方法：记住叉乘的下半部分就可以了（这当然只有咱俩看得懂啦！）\\
\Large\frac{\partial}{\partial x} \quad \frac{\partial}{\partial y}\quad  \frac{\partial}{\partial z}\quad \frac{\partial}{\partial x} \quad \frac{\partial}{\partial y}\quad  \frac{\partial}{\partial z}\\\Large P\quad \quad Q \quad\quad R\quad \quad P\quad\quad  Q \quad\quad R
\\\Large不过，一定小心原来的对应关系，Pdx+Qdy+Rdz，小心调换顺序来整人。
$$
$\Large适当选择曲面，或者更换曲面，可以极大地简化运算。$

------

## 步骤

**重要的是，清晰地意识到每一步在做什么**

$\Large\color{red}{\text{0. 想清楚是否该用Stokes？大多数的曲线都能用较为简单的参数方程表示，用参数方程求二型积分往往会优化许多。}}\\\Large\color{black}{如果遇见难以写出参数方程的曲线，或者参数方程还要分段讨论的曲线（比如一个三角形），\\\Large那么就应该使用Stokes，并如下操作：}$

$\Large1.理清楚曲线，选定最优的曲面，一般为平面或者球面（见下），并且理清楚曲面的方向。$

$\Large 2.由于我们选的曲面一般是平面或者球面，完全可以用显函数z=f(x,y),很快可以得出\vec{n}。$
$$
\Large\overrightarrow{n }=\frac{({f'_x},{f'_y},-1)}{\sqrt{1+{f'_x}^{2}+{f'_y}^{2}}}
$$
$\Large注意到，这个向量的分子算出来是必须的，因为接下来的公式会用到，分母完全可以不管，\\\Large因为ds向dx\cdot dy转换时会消去分母。\\\Large 另一方面，这里使用了显函数z=f(x,y)的形式，是因为我们希望把S^+投影到xoy面上。\\\Large如果不投影到xoy上，那么将有奇妙的算法，不过大多数时候都会投影到xoy面上，例子:习题4.7.5.3，\\\Large\color{red}{以及，无论投不投影，都必须将\vec{n}与选择的曲面的方向进行对比,因为可能需要对\vec{n}换号。}$

$\Large3.用咱俩的行列式方法算出\nabla \times \vec{v}。$
$$
\Large\frac{\partial}{\partial x} \quad \frac{\partial}{\partial y}\quad  \frac{\partial}{\partial z}\quad \frac{\partial}{\partial x} \quad \frac{\partial}{\partial y}\quad  \frac{\partial}{\partial z}\\\Large P\quad \quad Q \quad\quad R\quad \quad P\quad\quad  Q \quad\quad R
$$
$\Large4.先寻求是否能用质心法，如果不能，则套用显函数的二型曲面积分公式,记得\vec{n}方向与S不同可能导致取负号。$
$$
\Large\iint_{s^{+}}  \overrightarrow{v}\mathrm{d}\overrightarrow{s}{ } =\iint_{s^{+}}\overrightarrow{ v }\cdot \overrightarrow{n}\mathrm{d}s=\iint_{s_{x,y}^{+}}({p_{x,y}}\cdot f'_x+q_{x,y}\cdot f'_y-r_{x,y})\mathrm{d}x \cdot dy
$$
$\Large5.利用对称性优化二重积分的计算。$

------



## 例子

*$\Large Stokes公式对于平面的选择纯粹是自己来，这个选择性会出现在计算\vec{n}和ds上。$*

*$\Large前文已经叙述过，stokes公式非常鸡肋，就算要用他，选择的曲面应该尽量是球面，平面。$*

*$\Large 像PPT上那样选择一个锥面实在是非常少见。$*

$\large I=\oint_{L}(y-z) \mathrm{d} x+(z-x) \mathrm{d} y+(x-y) \mathrm{d} z , \large其中  L  是
 x^{2}+y^{2}=R^{2}与x / a+z / b=1(a>0, b>0)的交线, \\\large其
正向从oz轴往下看为逆时针方向. \\\large解 : 记  \vec{v}=(y-z) \vec{i}+(z-x) \vec{j}+(x-y) \vec{k} , 则
 \nabla \times v=\operatorname{det}\left(\begin{array}{ccc}\vec{i} & \vec{j} & \vec{k} \\ \partial / \partial x & \partial / \partial y & \partial / \partial z \\ y-z & z-x & x-y\end{array}\right)=-2(1,1,1) 
\\\large记S为平面  x / a+z / b=1  包含在柱面  x^{2}+y^{2}=R^{2}  以 内的部分, 上侧为正,则其正单位法向量为
 \vec{n}=\frac{(1 / a, 0,1 / b)}{\sqrt{(1 / a)^{2}+(1 / b)^{2}}}=\frac{(b, 0, a)}{\sqrt{a^{2}+b^{2}}} 
\\\large面积微元  d S=\sqrt{1+z_{x}^{\prime 2}+z_{y}^{\prime 2}} d x d y=\frac{\sqrt{a^{2}+b^{2}}}{a} \mathrm{~d} x \mathrm{~d} y .
\\\large由Stokes公式  \begin{aligned} I &=\oint_{L} \vec{v} \cdot \vec{\tau} \mathrm{d} l=\iint_{S} \nabla \times \vec{v} \cdot \vec{n} \mathrm{~d} S=\frac{-2(a+b)}{\sqrt{a^{2}+b^{2}}} \iint \mathrm{d} S \\ &=\frac{-2(a+b)}{\sqrt{a^{2}+b^{2}}} \iint_{\mathrm{x}^{2}+y^{2} \leq R^{2}} \frac{\sqrt{a^{2}+b^{2}}}{a} \mathrm{~d} x \mathrm{~d} y \\ &=\frac{-2(a+b)}{a} \pi R^{2} . \end{aligned}$

*$\Large\text{仔细观察上例，我们会发现，在计算}\vec n和ds \text{的时候，选择的封闭曲面全是}x / a+z / b=1(a>0, b>0)\\\Large这个选择看似平凡，实际上极大简化了ds和\vec{n}是一个非常优秀的选择。$*

------

$\large \int \frac{y}{(x+z)^2+y^2}dx=arctan(\frac{x+z}{y})+f(x,y)$

------

$\Large \begin{array}{l}
\text { 2. 设 } \mathrm{L} \text { 是平面 } x+y+z=0 \text { 与球面 } x^{2}+y^{2}+z^{2}=1 \text { 的交线, 从 } \mathrm{z} \text { 轴正向看去为逆时针方向, }\\
\text { 求第二类曲线积分 } \int_{L^{+}} \frac{(y+1) d x+(z+2) d y+(x+3) d z}{x^{2}+y^{2}+z^{2}}
\end{array}$

$\Large 首先，由于积分区域都在曲线上，也在球面上，那么分母必然形同虚设。因为我们不论是直接利用参数方程求\vec\tau，$

$\Large 还是投影到三个轴上来分别积分，我们都必然会带入曲线在球面上这个限制。$

$\Large其次，注意到积分的对称性。我认为，我们应该从区域的对称性和函数的对称性两方面入手来看待积分对称性这件事。$



$\Large例如：\iiint_vxy\cdot dxdydz，v为x^2+y^2\le 1，1\le z\le 2 这个柱体的内部，考虑到柱体是关于xoz面对称的。$

$\Large 对于函数f(x,y,z)=xy，其关于xoz面的对称点为f(x,-y,z)=-xy。而在xoz面两侧的积分微元dxdydz$

$\Large 都为正，那么左右对称的两部分积分必为0。我们先根据积分区域的对称性，验证了函数的相应对称性。$



$\Large 回到这个题，对于\int_{L^{+}} {1d x+2d y+3dz}而言，首先观察到了积分区域的轮转对称性，那么这个积分=6\int_{L^{+}} {dx}$

**不要考虑二型积分的对称性，转化为一型积分或者用Stokes，Gauss，Green后再考虑对称性。**



$\Large 最后，回到这个题上，唯一需要解决的部分就是余下的\int_{L^{+}} {yd x+zd y+xdz}，回顾下，我们讨论过，\\\Large大多曲线都能写出不复杂的参数方程，且参数方程算二型积分一般会比Stokes快。一般而言，\\\Large有圆柱x^2+y^2=R^2时，曲线往往能写出很简单的参数方程，但是没有圆柱，则参数方程会比较\\\Large麻烦。$

$\Large 那么老老实实Stokes，选择平面为截面，且上侧为正，则\nabla \times v=(-1,-1,-1)。给出显函数z=-x-y。$

$\Large 则\oint_{\partial S} \vec{v} \cdot \vec{\tau} \mathrm{d} l=\iint_{S}(\nabla \times \vec{v}) \cdot \vec{n} \mathrm{~d} S=\iint_{S_{xy}}-3\cdot dxdy=-3\sigma(S_{xy}) =-3\pi$

$\Large 等等，有问题，S投影到xoy面上真的是圆吗?这就是个很大的问题，这个斜着的圆投下来是个椭圆，\\\Large 而且这个椭圆有交叉项，不是标准型。故而不要投影了，直接算到\Large\vec{n}=\frac{(1,1,1)}{\sqrt{3}},注意我是用隐函数求导\\\Large算出的\vec{n}，还要确保方向是对的。\\\Large接下来\iint_{S}(\nabla \times \vec{v}) \cdot \vec{n}ds=\iint_{S}-\sqrt{3} ds=-\sqrt{3}\pi,这个面积就是圆的面积。$



------



## 空间向量场

### 1.连通性

#### （1）面（二维）连通：

区域内任一**封闭**曲面的内部都包含在该区域内。

#### （2）线（一维）连通：

区域内任一简单闭曲线，都存在区域内的一个曲面以该曲线为边界。

#### （3）线连通、面连通的关系

两者不相互蕴含。

i.e.一个开球：面连通、线连通

一个甜甜圈：面连通，非线连通

一个去除了原点的开球：线连通、非面连通。

## 2.





















































































































































































































































































































































































































































































































































































































































































































































































































































































































