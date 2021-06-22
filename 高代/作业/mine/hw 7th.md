$\Large\color{Black}\text{Chenyang Zhao ID:2020012363}$

$\Large\color{black}\text{collaborators: Hanwen Cao, Mingdao Liu}$

$\Large\color{black}\text{Pray for India.}$

------

$\Large\color{black}Problem\quad One$

$\large\color{black}1.1\quad $

*Let $ g=c$  for some constant real number c. Since we know that dual vector $v$ is a a linear map, hence, by product rule, for any  $p\in R^3$  :*
$$
\large\color{black} v(g^2)=v(g\cdot g)=g(p)\cdot v(g)+g(p)v(g)=2c\cdot v(g)
$$
*On the other hand, we have:*
$$
\large\color{black} v(g^2)=v(g\cdot g)=v(c\cdot g)=c\cdot v(g)\text{ (becuase v is linear)}
$$
So:
$$
\large\color{black}c\cdot v(g)=2c\cdot v(g)
$$
*On one hand*, *if $c=0$,* *then $v(g)=v(0)=v(g^2)=g(p)\cdot v(g)+g(p)v(g)=0$.*

*On the other hand, if $c\ne 0$, then from (4) we have $c\cdot v(g)=0$,* *hence $v(g)=0$*

*In conclusion, $v(g)=0$ for all constant function $g$.*

------

$\large\color{black}1.2\quad $

*By definition of x,y,z we have $x(p)=p_1$, $y(p)=p_2$, $z(p)=p_3$*.

*by product rule  and since $v$ is linear,hence:*
$$
\large\color{black}v((x − p_1)f)=(x-p_1)(p)\cdot v(f)+f(p)\cdot v(x-p_1)=x(p)\cdot v(f)\\
\large\color{black}=x(p)\cdot v(f)-p_1(p)\cdot v(f)+f(p)\cdot v(x)-f(p)\cdot v(p_1)
$$
*and from 1.1 and* $x(p)=p_1,p_1(p)=p_1$ *we know that:*
$$
\large\color{black}(4)=p_1\cdot v(f)-p_1\cdot v(f)+f(p)\cdot v(x)-f(p)\cdot 0=f(p)\cdot v(x)
$$
*Same thing with x, we have:*

*$y(p)=p_2,p_2(p)=p_2$, $v$ is linear:*
$$
\large\color{black}v((y − p_2)f)=(y-p_2)(p)\cdot v(f)+f(p)\cdot v(y-p_2)=y(p)\cdot v(f)\\
\large\color{black}=y(p)\cdot v(f)-p_2(p)\cdot v(f)+f(p)\cdot v(y)-f(p)\cdot v(p_2)\\\large\color{black}=p_2\cdot v(f)-p_2\cdot v(f)+f(p)\cdot v(y)-f(p)\cdot 0=f(p)\cdot v(y)
$$
*$z(p)=p_3,p_3(p)=p_3$, $v$ is linear:*
$$
\large\color{black}v((z − p_3)f)=(z-p_3)(p)\cdot v(f)+f(p)\cdot v(z-p_3)=z(p)\cdot v(f)\\

\large\color{black}=z(p)\cdot v(f)-p_3(p)\cdot v(f)+f(p)\cdot v(z)-f(p)\cdot v(p_3)\\\large\color{black}=p_3\cdot v(f)-p_3\cdot v(f)+f(p)\cdot v(z)-f(p)\cdot 0=f(p)\cdot v(z)
$$

------

$\large\color{black}1.3\quad $

*Suppose a < 1, b < 1, c < 1, then a = b = c = 0,  it is a contradiction.* *So at least one number in {a, b, c} ≥ 1. Without loss of generalization, assume a≥ 1. let d=a-1*

*let $f=(x-p_1)^{d}\cdot (y-p_2)^{b}\cdot (z-p_3)^{c}$, and for $d,b,c,$ if $d=b=c=0,$hence $a+b+c=d+1=1$, which is a contradiction to a + b + c > 1, so there must be at least one number in {d, b, c} ≥ 1. Without loss of generalization, assume d≥ 1.*

*Then we know:*
$$
\large\color{black}f(p)=[(x-p_1)^{d}\cdot (y-p_2)^{b}\cdot (z-p_3)^{c}](p)\\
\large\color{black}=(x-p_1)(p)\cdot [(x-p_1)^{(d-1)}\cdot (y-p_2)^{b}\cdot (z-p_3)^{c}](p)\\
\large\color{black}=(p_1-p_1)\cdot [(x-p_1)^{(d-1)}\cdot (y-p_2)^{b}\cdot (z-p_3)^{c}](p)=0
$$
*and we know that$(x-p_1)^{a}\cdot (y-p_2)^{b}\cdot (z-p_3)^{c}=(x-p_1)\cdot (x-p_1)^{d}\cdot (y-p_2)^{b}\cdot (z-p_3)^{c}=(x-p_1)\cdot  f$*

*hence:*
$$
\large\color{black}v((x-p_1)^{a}\cdot (y-p_2)^{b}\cdot (z-p_3)^{c})=v((x-p_1)\cdot  f)\\
\large\color{black}=f(p)\cdot v(x)=0\cdot v(x)=0
$$



------

$\large\color{black}1.4\quad $

 *Using Taylor Expansion at  $\boldsymbol{p}$  for $ f$ , we have:*
$$
\large\color{}f(x,y,z)=f\left(p_{1}, p_{2}, p_{3}\right)+\frac{\partial f}{\partial x}(\boldsymbol{p})\left(x-p_{1}\right)+\frac{\partial f}{\partial y}(\boldsymbol{p})\left(y-p_{2}\right)+\frac{\partial f}{\partial z}(\boldsymbol{p})(z- \left.p_{3}\right)+\bigtriangleup (x, y, z)
$$
 *where  $\bigtriangleup (x, y, z)$  is the remainder term.*

*By the definition of Taylor Expansion, we know that $\bigtriangleup (x, y, z)$ is a linear combination of terms with form $(x-p_1)^{a}\cdot (y-p_2)^{b}\cdot (z-p_3)^{c}$  where $a+b+c≥2$, since terms  with  form $(x-p_1)^{a}\cdot (y-p_2)^{b}\cdot (z-p_3)^{c}$ with $0\le a+b+c\le 1$ have all be included in $f\left(p_{1}, p_{2}, p_{3}\right)+\frac{\partial f}{\partial x}(\boldsymbol{p})\left(x-p_{1}\right)+\frac{\partial f}{\partial y}(\boldsymbol{p})\left(y-p_{2}\right)+\frac{\partial f}{\partial z}(\boldsymbol{p})(z- \left.p_{3}\right)$.*

*So from 1.3 we know $v(\bigtriangleup (x, y, z))=0$.* *and $f(p_1,p_2,p_3)$ is a constant number, so $v(f(p_1,p_2,p_3))=0$,  and we know $v$ is linear, hence*
$$
\large\color{}v(f)=v(f\left(p_{1}, p_{2}, p_{3}\right)+\frac{\partial f}{\partial x}(\boldsymbol{p})\left(x-p_{1}\right)+\frac{\partial f}{\partial y}(\boldsymbol{p})\left(y-p_{2}\right)+\frac{\partial f}{\partial z}(\boldsymbol{p})(z- \left.p_{3}\right)+\bigtriangleup (x, y, z)\\
\large\color{}=v(f\left(p_{1}, p_{2}, p_{3}\right))+v(\frac{\partial f}{\partial x}(\boldsymbol{p})\left(x-p_{1}\right))+v(\frac{\partial f}{\partial y}(\boldsymbol{p})\left(y-p_{2}\right))+v(\frac{\partial f}{\partial z}(\boldsymbol{p})(z- \left.p_{3}\right))+v(\bigtriangleup (x, y, z))\\
\large\color{}=v(\left(x-p_{1}\right)\cdot \frac{\partial f}{\partial x}(\boldsymbol{p}))+v(\left(y-p_{2}\right)\cdot \frac{\partial f}{\partial y}(\boldsymbol{p}))+v((z- \left.p_{3}\right)\cdot \frac{\partial f}{\partial z}(\boldsymbol{p}))
\\\large\color{}=\frac{\partial f}{\partial x}(\boldsymbol{p}) v(x)+\frac{\partial f}{\partial y}(\boldsymbol{p}) v(y)+\frac{\partial f}{\partial z}(\boldsymbol{p}) v(z)-v(p_1)\cdot \frac{\partial f}{\partial x}(\boldsymbol{p})-v(p_2)\cdot \frac{\partial f}{\partial y}(\boldsymbol{p})-v(p_3)\cdot \frac{\partial f}{\partial z}(\boldsymbol{p})
\\\large\color{}=\frac{\partial f}{\partial x}(\boldsymbol{p}) v(x)+\frac{\partial f}{\partial y}(\boldsymbol{p}) v(y)+\frac{\partial f}{\partial z}(\boldsymbol{p}) v(z)
$$

------

$\large\color{black}1.5\quad $
*By definition of direction derivative, we know that for $\forall f$ and given point  $\boldsymbol{p} \in \mathbb{R}^{3}$*
$$
\large\begin{aligned}
\large\nabla_{v} f &=\lim _{t \rightarrow 0^{+}} \frac{f(\boldsymbol{p}+t \boldsymbol{v})-f(\boldsymbol{p})}{t} \\
\large&=\lim _{t \rightarrow 0^{+}} \frac{f(\boldsymbol{p})+\frac{\partial f}{\partial x}(\boldsymbol{p}) v(x) t+\frac{\partial f}{\partial y}(\boldsymbol{p}) v(y) t+\frac{\partial f}{\partial z}(\boldsymbol{p}) v(z) t+o(\|\boldsymbol{v}\| t)-f(\boldsymbol{p})}{t} \\
\large&=\frac{\partial f}{\partial x}(\boldsymbol{p}) v(x)+\frac{\partial f}{\partial y}(\boldsymbol{p}) v(y)+\frac{\partial f}{\partial z}(\boldsymbol{p}) v(z) \\
\large&=v(f)
\end{aligned}
$$

------

$\Large\color{black}Problem\quad two$

$\large\color{black}2.1\quad $*Target——to show that $Xp(fg) = f(p)Xp(g) + g(p)Xp(f)$*

$$
\large Xp(f\cdot g)=(X(f\cdot g))(p)= (fX(g) + gX(f))(p)=f(X(g))(p)+g(X(f))(p)\\
\large=f(p)(X(g))(p)+g(p)(X(f))(p)=f(p)Xp(g)+g(p)Xp(f)
$$

------

$\large\color{black}2.2\quad $

*If we input any $p\in \mathbb{R}^{3}$, hence $df(X)(p)=df_p(X_p)$, $df_p$ is a covector. From 1.5 we know that deriviation at p is canonical isomoprphism to tangent vector at p, and from 2.1 we see that $X_p$ is a deriviation at p, it is exactly a tangent vector, let the corresponding tangent vector be $\boldsymbol{w}$ , hence.*
$$
\large\boldsymbol{w}=\left[\begin{array}{c}
X_{\boldsymbol{p}}(X) \\
X_{\boldsymbol{p}}(Y) \\
X_{\boldsymbol{p}}(Z)
\end{array}\right]\text{,where X,Y,Z are the coordinate functions.}
$$

$$
\large \text { so }\left.d f(X)\right|_{p}=df_p(\boldsymbol{w})=\left[\begin{array}{lll}
\frac{\partial f}{\partial x}(\boldsymbol{p}) & \frac{\partial f}{\partial y}(\boldsymbol{p}) & \frac{\partial f}{\partial z}(\boldsymbol{p})
\end{array}\right]\left[\begin{array}{c}
X_{\boldsymbol{p}}(X) \\
X_{\boldsymbol{p}}(Y) \\
X_{\boldsymbol{p}}(Z)
\end{array}\right]\\\large=\frac{\partial f}{\partial x}(\boldsymbol{p}) X_{\boldsymbol{p}}(X)+\frac{\partial f}{\partial y}(\boldsymbol{p}) X_{\boldsymbol{p}}(Y)+\frac{\partial f}{\partial z}(\boldsymbol{p}) X_{\boldsymbol{p}}(Z)\\
$$

*Also from 1.4, we have:*
$$
\large (X(f))(\boldsymbol{p})=X_p(f)=\frac{\partial f}{\partial x}(\boldsymbol{p}) X_{\boldsymbol{p}}(X)+\frac{\partial f}{\partial y}(\boldsymbol{p}) X_{\boldsymbol{p}}(Y)+\frac{\partial f}{\partial z}(\boldsymbol{p}) X_{\boldsymbol{p}}(Z)\\
$$
*So $df(X)|_{\boldsymbol{p}}$=$X(f)(\boldsymbol{p})$, ie. $df(X)=X(f).$*


------

$\large\color{black}2.3\quad $
$$
\large (X\circ Y-Y\circ X)(f\cdot g)=X(Y(f\cdot g))-Y(X(f\cdot g))\\
\large=X(f\cdot Y(g)+g\cdot Y(f))-Y(f\cdot X(g)+g\cdot X(f))
\\\large=f\cdot X(Y(g))+Y(g)\cdot X(f)+g\cdot X(Y(f))+Y(f)\cdot X(g)\\\large-(X(g)\cdot Y(f)+f\cdot Y(X(g))+g\cdot Y(X(f))+X(f)\cdot Y(g))\\\large=f\cdot X(Y(g))-f\cdot Y(X(g))+g\cdot X(Y(f))-g\cdot Y(X(f))\\\large=
f\cdot (X\circ Y-Y\circ X)(g)+g\cdot (X\circ Y-Y\circ X)(f)\\\large
$$
*Hence by definition, $ X◦Y−Y◦X$ is always a vector field.*

------

$\large\color{black}2.4\quad $

*Since A and B are skew-symmetric，then $A^T=-A$, $B^T=-B$. Hence*
$$
\large\begin{aligned}
(A B-B A)^{T} &=(A B)^{T}-(B A)^{T} \\
&=\left(B^{T} A^{T}\right)-\left(A^{T} B^{T}\right) \\
&=(-B)(-A)-(-A)(-B) 
\\&=BA-AB
\\&=-(A B-B A)
\end{aligned}
$$
*So we know $(AB-BA)$ is skew-symmetric.*

------

