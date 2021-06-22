# Project

Hanwen Cao  ID:2020010919

#### problem 1

Note that $\frac{d}{dt}(e^{-At}y)=-Aye^{-At}+e^{-At}y’(t)=e^{-At}(y’(t)-Ay)=e^{-At}f(t,y)$

Integrate both side,we get 
$$
e^{-At}y-e^0y(0)=\int_0^te^{-As}f(s,y)ds\\
e^{-At}y-c=\int_0^te^{-As}f(s,y)ds\\
y=ce^{At}+\int_0^te^{A(t-s)}f(s,y)ds.
$$


#### problem 2

For any even function f(x),it’s expansion has only even power of x.

Because $f=cos(x)+x^{-1}sin(x)$ is a even function of $x$,the expasion of $cos(\sqrt{A}t)y_0+(\sqrt{A})^{-1}sin(\sqrt{A}t)y’_0$also has only even power of $\sqrt{A}$,i.e,it’s just the power series of A.

So it has nothing to do with how we choose the square root$\sqrt{A}$ of A.



#### problem 3

Write A into its Jordan Canonical Form,i.e.,$A=ZJZ^{-1},Z=[Z_1,Z_2],J=\begin{bmatrix}J_1
  & \\
  &J_2
\end{bmatrix},$where $J_1$is $ p\times p $ with all eigenvalues lying in the left complex plane ,and$ J_2$ is $q\times q$ with all eigenvalues lying in the right complex plane.$(p+q=n.)$

Then
$$
sign(A)=Z\begin{bmatrix}sign(J_1)
  & \\
  &sign(J_2)
\end{bmatrix}Z^{-1}\\
=Z\begin{bmatrix}-I_p
  & \\
  &I_q
\end{bmatrix}Z^{-1}
$$
From section 2.5,we know that the columns of $W=(sign(A)+I)/2=Z\begin{bmatrix}O
  & \\
  &I_q
\end{bmatrix}Z^{-1}$ span the invariant subspace corresponding to the eigenvalues of $A$ in the open right half-plane(In fact,$W$ is a projection to this subspace),and $rank(W)=q.$

Partition $Q$ as $[Q_1,Q_2]$,$Q_1$ is $ n \times q$ and $Q_2$ is $n \times p$.then
$$
W\Pi =[Q_1\text{  }Q_2]\begin{bmatrix}R_{11}
  & R_{12}\\
  O&O
\end{bmatrix}=Q_1[R_{11} \text{ }R_{12}]\\
W=Q_1[R_{11}  \text{ }R_{12}]\Pi^T
$$
Because $rank(W)=q$,$Q_1$has full column rank, then the column of $Q_1$ is a set of orthogonal basis of $Ran(W).$

Then $AQ_1=Q_1Y $ , where $Y$ is a $q\times q$ matrix whose eigenvalues are those of $A$ that lies in the right half-plane.

Because columns of $Q$ span the who vector space, the p columns of $Q_2$ span the invariant subspace corresponding to the eigenvalues of $A$ in the open left half-plane.So similarly,we have $AQ_2=Q_2X,$ where $X$ is a $p\times p$ matrix whose eigenvalues are those of $A$ that lies in the left half-plane.

Then
$$
Q^TAQ=\begin{bmatrix}
Q_1^T  &Q_2^T
\end{bmatrix}A\begin{bmatrix}
 Q_1\\Q_2

\end{bmatrix}=\begin{bmatrix}Q_1^TAQ_1&Q_1^TAQ_2\\Q_2^TAQ_1&Q_2^TAQ_2\end{bmatrix}\\
=\begin{bmatrix}Y&Q_1^TAQ_2\\Q_2^TQ_1Y&Q_2^TAQ_2\end {bmatrix}\\=\begin{bmatrix}Y&Q_1^TAQ_2\\O&X\end {bmatrix}:=\begin{bmatrix}A_{11}&A_{12}\\&A_{22}\end {bmatrix}.
$$

#### problem 4

If $AB=BA$,and $A^{1/2}=f(A)$,$B^{1/2}=f(B)$,then $A^{1/2}B^{1/2}=B^{1/2}A^{1/2}.$Similarly, $log(A)$ and $log(B)$ also commute.

By definition of **2.26**$,A$#$B$ is the unique Hermitian positive definite solution to $XA^{-1}X=B$.

Let $X=A^{1/2}B^{1/2}$,$X^*=(B^*)^{1/2}(A^*)^{1/2}=B^{1/2}A^{1/2}=A^{1/2}B^{1/2}=X.$$X$ is Hermitian.

Although a random positive definite matrix is not necessarily diagonalizeable,a Hermitian positive definite matrix can surely be diagonalized.And because A and B commute,they can be simultaneously diagonalized.So $\exist P$ , s.t., $A=P\Lambda_aP^{-1}$.$B=P\Lambda_bP^{-1}$,$\Lambda_a,\Lambda_b$ are both diagonal matrix with positive entry on the diagonal.So $X=P\sqrt{\Lambda_a}P^{-1}P\sqrt{\Lambda_b}P^{-1}=P\sqrt{\Lambda_a\Lambda_b}P^{-1}$,which is still positive definite.

Also,by calculation we know:


$$
XA^{-1}X=A^{1/2}B^{1/2}A^{-1}A^{1/2}B^{1/2}=A^{1/2}B^{1/2}A^{-1/2}B^{1/2}\\=A^{1/2}A^{-1/2}B^{1/2}B^{1/2}=B.
$$
So $X$ satisfies the definition,and is the geometric mean.

As for the log-Euclidean geometric mean $E$, we know that if $AB=BA$, then $e^{A+B}=e^Ae^B=e^Be^A$.
$$
E(A,B)=e^{\frac{1}{2}log(A)+\frac{1}{2}log(B)}=e^{\frac{1}{2}log(A)}e^{\frac{1}{2}log(B)}\\=e^{log(\sqrt{A})}e^{log(\sqrt{B})}\\
=A^{\frac{1}{2}}B^{\frac{1}{2}}
$$

#### problem 5

###### 2.27a

$AA^{-1}A=A$,and A is a Hermitian positive definite matrix.By definition of 2.26,$A$ # $A=A.$

###### 2.27b

$A$#$B=(AB^{-1})^{1/2}B$

We know that the inverse of a Hermitian positive definite matrix is still a Hermitian positive definite matrix.So $A^{-1}$#$B^{-1}=(A^{-1}B)^{1/2}B^{-1}$.

Also $(A$#$B)^{-1}=(AB^{-1})^{-1/2}B^{-1}=B^{1/2}A^{-1/2}B^{-1}=(A^{-1}B)^{1/2}B^{-1}=A^{-1}$#$B^{-1}$.

###### 2.27c

For any Hermitian positive definite matrix $X$ that satisfies $XA^{-1}X=B$,

Apply $X^{-1}$at both side,$A^{-1}=X^{-1}BX^{-1}$.

Take inverse of both side,$XB^{-1}X=A.$ So the unique solution to $A$#$B$ is also the unique solution to $B$#$A$.

###### 2.27d

First,we define a Hermitian matrix $A>0$ if and only if it is positive definite. And $A\ge 0$ if and only if A is semipositive definite.And also,from **problem 5** we conclude that the product of two hermitian semipositive definite matrix is still hermitian semipositive definite,so we can apply hermitian semipositive definite matrix on both side of the equation below,and it won’t change the result.

Let $T:=$$B^{-1/2}AB^{-1/2}$，$T^*=(B^*)^{-1/2}A^*(B^*)^{-1/2}=B^{-1/2}AB^{-1/2}=T$.And by problem 5,it’s positive-definite,so it can be diagonalized into $T=B\Lambda B^{-1}$ for some positive diagonal matrix $\Lambda$.
$$
\frac{1}{2}(A+B)-B^{1/2}(B^{-1/2}AB^{-1/2})^{1/2}B^{1/2}\\=
\frac{1}{2}(B^{-1/2}AB^{-1/2}+I)-(B^{-1/2}AB^{-1/2})^{1/2}\\=
\frac{1}{2}(T+I)-T^{1/2}\\=\frac{1}{2}
(I-T^{1/2})^2\\=
\frac{1}{2}(B\Lambda'B^{-1} )^2\\=
\frac{1}{2}B(\Lambda')^2B^{-1}
$$
which is hermitian semipositive definite.

#### problem 6

Because $A,B$ are both hermitian positive definite,they have real positive determinant.

WLOG,assume $\alpha,\beta>0$.

Let $T=(A^{-1}B)^{1/2}$ and its two eigenvalue be $\lambda_1,\lambda_2\in \mathbb{C}$.

Then $trace(T)=\lambda_1+\lambda_2,det(T)=\lambda_1\lambda_2=det(A^{-1/2})det(B^{1/2})=\frac{\beta}{\alpha}$.

Then 
$$
det(\alpha^{-1}A+\beta^{-1}B)=det(A)det(\alpha^{-1}I+\beta^{-1}X^2)\\=
\alpha (\alpha^{-1}+\beta^{-1}\lambda_1^2)(\alpha^{-1}+\beta^{-1}\lambda_2^2)\\=
\frac{\alpha}{\beta}{(\lambda_1+\lambda_2)^2}\\=
\frac{\alpha}{\beta}trace(T)^2.
$$
The product of two hermitian positive definite matrix is still hermitian positive definite, so T is still hermitian positive definite,$trace(T)>0;$So
$$
trace(T)=\sqrt{\frac{\beta}{\alpha}det(\alpha^{-1}A+\beta^{-1}B)}\\
$$
By Cayley-Hamiltion theorem,which states that
$$
A^{-1}=-\frac{1}{c_{n}}\left(A^{n-1}+\sum_{i=1}^{n-1} c_{i} A^{n-i-1}\right)
$$
When A has characteristic polynomial $det(A-\lambda I)=x^n+c_1x^{n-1}+…+c_n$.

We know that $T^2-trace(T)+det(T)I=O$

(This is true only when $T$ is a $2\times 2$ matrix.This result can also be obtained simply by the characteristic polynomial,which is $(x-\lambda_1) (x-\lambda_2)=x^2-(\lambda_1+\lambda_2)+\lambda_1\lambda_2.$ )

Then $trace(T)(A^{-1}B)^{1/2}=T^2+det(T)I$.

Multiply A from the left,we have
$$
trace(T)A(A^{-1}B)^{1/2}=B+det(T)A.\\
trace(T)(B\text{#}A)=B+det(T)A.\\
trace(T)(A\text{#}B)=B+det(T)A.\\
A\text{#}B=\frac{B+det(T)A}{trace(T)}\\
=\frac{B+\frac{\beta}{\alpha}A}{\sqrt{\frac{\beta}{\alpha}det(\alpha^{-1}A+\beta^{-1}B)}}\\
=\frac{\sqrt{\alpha\beta}}{\sqrt{det(\alpha^{-1}A+\beta^{-1}B)}}(a^{-1}A+\beta^{-1}B).
$$

#### problem 7

Cholesky factorization of $A: A=R^*R$ for some upper triangular $R$.

From **problem 5**,we know that we can write $A>0 $ if $A$ is hermitian positive definite.

Because$ B>0$,for $\forall x\in \mathbb{C^n},x^*RBR^*x=(R^*x)^*B(R^*x)>0$.

So $RBR^*$>0,$\sqrt{RBR^*}>0$.

Similarly,for $\forall x\in \mathbb{C^n},x^*R^{-1}(RBR^*)^{\frac{1}{2}}R^{-*}x=(R^{-*}x)^*(RBR^*)^{\frac{1}{2}}(R^{-*}x)>0$.So $R^{-1}(RBR^*)^\frac{1}{2}R^{-*}>0$ as well.

From 2.26,we know that the solution to $X>0,XAX=B$ is unique.So we only have to verify that$R^{-1}(RBR^*)^{\frac{1}{2}}R^{-*}AR^{-1}(RBR^*)^{\frac{1}{2}}R^{-*}=B.$
$$
R^{-1}(RBR^*)^{\frac{1}{2}}R^{-*}AR^{-1}(RBR^*)^{\frac{1}{2}}R^{-*}\\=
R^{-1}(RBR^*)^{\frac{1}{2}}R^{-*}R^*RR^{-1}(RBR^*)^{\frac{1}{2}}R^{-*}\\=
R^{-1}(RBR^*)R^{-*}\\=
(R^{-1}R)B(R^*R^{-*})=B.
$$
So $X=R^{-1}(RBR^*)^\frac{1}{2}R^{-*}$ is the hermitian positive definite solution to $XAX=B$.
