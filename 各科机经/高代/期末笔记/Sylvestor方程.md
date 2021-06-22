#  xSylvestor方程

杨sir说了必考，考到就用wps的查找功能直接搜索

Sylvester’s equation :page 40 of lecture note && page 52 of lecture note

内容：对$m\times m$矩阵A和$n\times n$矩阵B，且A，B没有共同特征值，那么对于任意的$m\times n$矩阵C，方程AX-XB=C总**有且仅有**一个解，解即为一个$m\times n$的矩阵X。

## 前期工作

Sylvester’s equation 本身用于解决这样的问题：

$\begin{array}{l}
 A=\left[\begin{array}{llll}
1 & 2 & 1 & 2 \\
0 & 1 & 3 & 4 \\
0 & 0 & 3 & 5 \\
0 & 0 & 0 & 4
\end{array}\right] \text { . }\\
\text { 1. Find a matrix P such that PAP }^{-1}=\left[\begin{array}{llll}
1 & 2 & 0 & 0 \\
0 & 1 & 0 & 0 \\
0 & 0 & 3 & 5 \\
0 & 0 & 0 & 4
\end{array}\right] \text { . }
\end{array}$

看看题目需不需要我们证明解唯一，如果不需要证明，仍然需要说明

$\begin{bmatrix}
A  & C\\
 0 &B
\end{bmatrix}$的**A与B没有相同的特征值**。然后就可以设

$P=\begin{bmatrix}
I  & X\\
 0 &I
\end{bmatrix}
\quad P^{-1}=\begin{bmatrix}
I  & -X\\
 0 &I
\end{bmatrix}$

来解$AX-XB=C$，注意，说明了方程的解唯一后，**还是需要硬解这个方程。**

详见第四次作业第一题。

也就是说，解$A_1X-XA_2=B$等价于把矩阵$\begin{bmatrix}A_1
  &B \\
  &A_2
\end{bmatrix}$对角化为$\begin{bmatrix}A_1
  & \\
  &A_2
\end{bmatrix}$.

推论：当$A_1和A_2$没有common eigenvalue时，以上两个矩阵相似，具有相同的JNF。



## 解的唯一性

在第41(47/124)页，都很好理解，唯一需要注意的是：

**结合那一页的讲义。**

$p_A(A) = 0$，A的特征多项式作用在A上得到0矩阵，因为矩阵函数等价于作用在A的Jordan上，关键是A的特征值本身就是$p_A$的所有的根，且同一个$\lambda$对应的jordan块的大小就是$p_A$的根的次数。比如$p_A=(x-1)^4$，那么p_A作用在A的Jordan上，那么：

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

必然为0！所以说$p_A(A) = 0$

同样的，由于B和A没有相同的特征值，故而$f(J_B)$不为0，从能够推导出p_A(B)可逆。

