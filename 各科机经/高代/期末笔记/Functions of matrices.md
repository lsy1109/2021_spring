# Functions of matrices

## 一、矩阵极限

1. If $lim A_n = A $ and $ lim B_n = B$, then$ lim(A_nB_n)$ exists and it is$ AB.$

2. $lim(BA_nB^{−1}) = B(lim A_n)B^{−1}$，**极限与换基无关。**

3. 可对角矩阵是连续的，所有矩阵都是可对角矩阵的极限。

     -  Diagonalizable matrices are dense in n × n matrices. 
     -  Any matrix is a limit of diagonalizable matrices.

4. $A^{-1}=\frac{1}{\operatorname{det}(A)} \operatorname{Adj}(A)$，$Adj(AB) = Adj(B)Adj(A).$

<img src="https://vkceyugu.cdn.bspapp.com/VKCEYUGU-3f5ac434-77f3-4bf1-a1c6-ad1deeb5100a/9f321694-a9c5-4187-b381-e78e1b2d1b54.png" style="zoom:67%;" />



## 二、矩阵函数

1. $e^A$的定义和泰勒展开完全一样。
2. **矩阵函数与基的选取无关**，$f(BAB^{-1})=Bf(A)B^{-1}$
3.  对角分块阵经过f作用等于f对每个分块作用，$f\left(\left[\begin{array}{ll}
   A & \\
   & B
   \end{array}\right]\right)=\left[\begin{array}{ll}
   f(A) & \\
   & f(B)
   \end{array}\right]$
4.  F(x)**连续**，则F(A)连续。



## 三、核心计算方法

注意这里说的是**一般的计算方法**，而不是理解方法。

如果一个函数在$\lambda$处可分析，也就是可以泰勒展开，那么对于一个$jordan$ $block$

$\begin{array}{l}
 J=\left[\begin{array}{llll}
\lambda & 1 & & \\
& \ddots & \ddots & \\
& & \ddots & \\
& & & \lambda
\end{array}\right]\\
f(J)=\left[\begin{array}{cccc}
f(\lambda) & \frac{1}{1 !} f^{\prime}(\lambda) & \ldots & \frac{1}{(n-1) !} f^{(n-1)}(\lambda) \\
& \ddots & \ddots & \vdots \\
& & \ddots & \frac{1}{1 !} f^{\prime}(\lambda) \\
& & & f(\lambda)
\end{array}\right]
\end{array}$

就是泰勒展开！

故而先对一个矩阵分解为$jordan$矩阵，然后再利用计算方法即可。

$f(A)=B\left[\begin{array}{lll}
f\left(J_{1}\right) & & \\
& \ddots & \\
& & f\left(J_{t}\right)
\end{array}\right] B^{-1}$

$A=B\left[\begin{array}{lll}J_{1} & & \\ & \ddots . & \\ & & J_{t}\end{array}\right] B^{-1}$



## 四、理解方法

矩阵函数都理解为泰勒展开成多项式，然后验证矩阵的多项式是否满足这些性质即可。



## 五、矩阵函数的性质

1.  f(A)g(A) = h(A) if f(x)g(x) = h(x), and f(A) + g(A) = h(A) if f(x) + g(x) = h(x).
2.  if f(x) = x, then f(A) = A, and if f = 1 is a constant function, then f(A) = I.
3.  If f is a polynomial, then f(A) is exactly as we have always defined it to be.所以对于多项式直接带入即可。
4.  If f = g **at all eigenvalues of A** and they also equal at enough derivatives that are used in
    f(A) and g(A), then f(A) = g(A).（对同一个矩阵的矩阵函数，只关心函数在特征值附近的性质）
5.  Fix a matrix A, then for any well-defined f(A), there is a polynomial p(x) such that f(A) = p(A)，注意这个是**固定了A**，然后对于f有了定义多项式，虽然这个定义多项式可以完全用泰勒公式来理解。但是，对于不同的矩阵，同一个函数虽然都对应着多项式，但对应的多项式可能不同。
6.  $f(A^T)=[f(A)]^T$
7.  If $f(x) = x^{−1}$, and A is invertible, then f(A) = A^{−1}.
8.  $f: \mathbb{C} \rightarrow \mathbb{C}$  is complex differentiable and  $f(\mathbb{R}) \subseteq \mathbb{R}$ , then $ f(\bar{A})=\overline{f(A)} $ and $ f\left(A^{*}\right)=f(A)^{*}$  for any complex matrix  A ，注意复可导的条件非常强，以及A*的定义：共轭转置。



## 六、矩阵函数的应用

1. If $AB = BA$, then $e^{A+B }= e^Ae^B = e^Be^A.$满足交换律的前提非常强，但是用泰勒展开很好理解。
2. $\frac{d}{dt}e^{At}=Ae^{At}$，泰勒展开，一步理解到位。
3. 向量函数$v(t)$也就是每个坐标都是t的函数的向量。$v’(t)=Av(t)$的唯一解为$c\cdot e^{At}$，其中c就是常微分方程里的初始条件，$c=v(0)$，同时$e^{At}$的列构成了解空间。
4. 关于旋转矩阵的讨论考到了就去看机经里的《高代——讲义与答疑》的第8页，**Traits of exponential of A**。
5. $det({e^A})=e^{traceA}$
6. 存在R上的反对称矩阵 B，使得$A=e^B$，当且仅当A是real orthogonal matrix，and|A|=1.（即A是一个rotation matrix）
7. skew-Hermitian：$A^*=-A$，类似于实矩阵的反对称，那么$e^A$是unitary的，unitary并不是单位矩阵的意思，而是指$A^{*}A=I$
8. If A is a real orthogonal matrix with determinant 1 ($i.e.$, a rotation matrix), then$ A = e^B$ for some real skew-symmetric B.
9. 可导性要求，f(A)如果想在$\lambda$处有定义，必须在$\lambda$处复可导，仅仅实数可导是不行的，具体可以看《高代——讲义与答疑》的第13页。
10. If AB=BA and A,B are both diagnoalizeable,then they can be simultaneously diagonalized.
11. If AB=BA,then A,B can be simultaneously triangularized.However,they may not be able to put into Jordan Normal Form simultaneously.



## 七、$Commuting$  $matrics$

**完全由A决定的B可以与A交换。**

1. $f(A), g(A)$ are both defined, then $f(A)g(A) = g(A)f(A)$.
2. 当A的特征值的几何重数都是1时，$AB = BA$ 则 $B = p(A)$ for some polynomial $p$.
3. 中国剩余定理，讲义《final class》的56页，[56(62/124)]。
4. A和B都是C的函数，那么A与B可以交换。

**完全和A无关的B也可以和A交换。**

在中间的部分**大多没法**交换，但是平行的事情能够交换。具体的参见讲义《final class》的58页，[58(64/124)]。注意到，平行的事情没法表达为共同的矩阵函数。也就是：

$E_{13}$与$E_{23}$平行，可以交换，但是没法找到共同的C，使得$E_{13}=f(C)$$E_{23}=g(C)$。

