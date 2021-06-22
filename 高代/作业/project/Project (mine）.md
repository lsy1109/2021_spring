# Project

### Chenyang Zhao

------

## problem 1

> *More generally, with suitable assumptions on the smoothness of  f , the solution to the inhomogeneous system*
> $$
> \frac{d y}{d t}=A y+f(t, y), \quad y(0)=c, \quad y \in \mathbb{C}^{n}, A \in \mathbb{C}^{n \times n}
> $$
> *satisfies*
> $$
> y(t)=e^{A t} c+\int_{0}^{t} e^{A(t-s)} f(s, y) d s
> $$



*By the deriviation formula, we get this:*
$$
\frac{d}{d t}\left(e^{-A t} y\right)=-A  e^{-A t}y+e^{-A t} y^{\prime}(t)=e^{-A t}\left(y^{\prime}(t)-A y\right)
$$
And we let 
$$
\left(y^{\prime}(t)-A y\right)=f(t, y)
\\e^0y(0)=c
$$
*integrate it from 0 to t, thus we have:*
$$
\begin{array}{c}
e^{-A t} y-e^{0} y(0)=\int_{0}^{t} e^{-A s} f(s, y) d s \\
e^{-A t} y-c=\int_{0}^{t} e^{-A s} f(s, y) d s \\
y=e^{At}c+\int_{0}^{t} e^{A(t-s)} f(s, y) d s
\end{array}
$$

------

## Problem 2

> <img src="https://pic.imgdb.cn/item/60ce5efb844ef46bb271f74b.jpg" style="zoom:80%;" />



*First, any even function $f(x)$ only  have even power of $x$ as it’s expansion.*

*(If some power of $x$ are odd, then $f(x)$ could not be a even function)*

*And we know odd function time odd function would be an even function, even function plus an even function would still get an even function, hence $f(x)=cosx+x^{-1}sinx$ is a even function for $x$. So the expansion of $y(t)=cos(\sqrt {A}t)y_0+(\sqrt{A})^{-1}sin(\sqrt{A}t){y'_0}$ is even power of $\sqrt{A}$. Since $(\sqrt{A})^{2n}=A^n$, then the expansion of $y(t)$ is just the power series of A. Since the solution actually never depends on which $\sqrt{A}$ we choose, so $y(t)=cos(\sqrt {A}t)y_0+(\sqrt{A})^{-1}sin(\sqrt{A}t){y'_0}$ is a solution for any square root $\sqrt{A}$ of $A$.*

------

## Problem 3

> <img src="https://pic.imgdb.cn/item/60ce643f844ef46bb289d2b8.jpg" style="zoom:50%;" />



*For the  Jordan Canonical Form of $A $, we have  $A=Z J Z^{-1}, Z=\left[Z_{1}, Z_{2}\right], J=\left[\begin{array}{cc}J_{1} & \\ & J_{2}\end{array}\right]$ , where $p+q=n$, and $J_{1}$  is  $p \times p$  with all eigenvalues lying in the left complex plane, and  $J_{2}$  is  $q \times q$  with all eigenvalues lying in the right complex plane. Hence:*
$$
\begin{aligned}
\operatorname{sign}(A)=& Z\left[\begin{array}{ll}
\operatorname{sign}\left(J_{1}\right)  \\
& \operatorname{sign}\left(J_{2}\right)
\end{array}\right] Z^{-1} \\
&=Z\left[\begin{array}{cc}
-I_{p} & \\
& I_{q}
\end{array}\right] Z^{-1}
\end{aligned}
$$
*By definition, Since $W=(\operatorname{sign}(A)+I) / 2=Z\left[\begin{array}{ll}O & \\ & I_{q}\end{array}\right] Z^{-1} $, $rank(W)=q$, and we know $Range(W)$ is the invariant subspace for these eigenvalues of $A$ which are in the open right half-plane.*

*Let $Q=\left[Q_{1}, Q_{2}\right]$, where $Q_{1}$  is  $n \times q$  and  $Q_{2}$  is  $n \times p $. Hence*:
$$
\begin{array}{c}
W \Pi=\left[\begin{array}{cc}
\left.Q_{1} Q_{2}\right]
\end{array}\right]\left[\begin{array}{cc}
R_{11} & R_{12} \\
O & O
\end{array}\right]=Q_{1}\left[R_{11} R_{12}\right] \\\\
\end{array}
$$
*And since $\Pi$ is a permutation matrix. we have: $\Pi^{-1}=\Pi^T$, so:*
$$
W=Q_{1}\left[R_{11} R_{12}\right] \Pi^{T}
$$
*Because  $\operatorname{rank}(W)=q$, and $Q_{1}$ has full column rank, then the column of  $Q_{1} $ is a set of orthogonal basis of  $\operatorname{range}(W) $. Then  $A Q_{1}=Q_{1} X $, where  $X$  is a  $q \times q$  matrix whose eigenvalues are those of $A$ which are in the open right half-plane.*

*Note that columns of  $Q$  span the who vector space, so $\operatorname{range}(Q_{2})$  is the invariant subspace for these eigenvalues of $A$ which are in the open left half-plane. So similarly,we have  $A Q_{2}=Q_{2} Y $ where  $Y$  is a  $p \times p$  matrix matrix whose eigenvalues are those of $A$ which are in the open left half-plane.*

*Since $Q$ is a matrix in $QR$ factorization, then $Q$ is orthogonal, hence $Q_1^{T}Q_1=I,$ $Q_2^{T}Q_2=I$, then $Q_{1}^{T} A Q_{1}=X,$ $Q_{2}^{T} AQ_{1}=Q_{2}^{T} Q_{1}X=0,Q_{2}^{T} A Q_{2}=Y$*

*All in all, we have:*
$$
\begin{aligned}
Q^{T} A Q=\left[\begin{array}{ll}
Q_{1}^{T} & Q_{2}^{T}
\end{array}\right] A\left[\begin{array}{l}
Q_{1} \\
Q_{2}
\end{array}\right]=\left[\begin{array}{cc}
Q_{1}^{T} A Q_{1} & Q_{1}^{T} A Q_{2} \\
Q_{2}^{T} A Q_{1} & Q_{2}^{T} A Q_{2}
\end{array}\right] \\
=\left[\begin{array}{cc}
X & Q_{1}^{T} A Q_{2} \\
Q_{2}^{T} Q_{1} X & Y
\end{array}\right] \\
=\left[\begin{array}{cc}
X & Q_{1}^{T} A Q_{2} \\
O & Y
\end{array}\right]:=\left[\begin{array}{cc}
A_{11} & A_{12} \\
0&A_{22}\\
\end{array}\right]
\end{aligned}
$$

------

## Problem 4

> <img src="https://pic.imgdb.cn/item/60ce72bc844ef46bb2d96fab.jpg" style="zoom:50%;" />

*If $A$ and $B$ commute，then **whatever** completely depend on $A$ would commute with **whatever** completely depend on $B$. Thus we have $A^{1 / 2}$ commute with $B^{1 / 2}$, $\log (A) $commute with $\log (B)$ and finally $\log(A^{1 / 2}) $ commute with $\log(B^{1 / 2})$*

*By the definition above, $A \# B$  is the unique Hermitian positive definite solution to  $X A^{-1} X=B $. Suppose the solution is$X=A^{1 / 2} B^{1 / 2}$ Then*
$$
X^{*}=\left(B^{*}\right)^{1 / 2}\left(A^{*}\right)^{1 / 2}=B^{1 / 2} A^{1 / 2}=A^{1 / 2} B^{1 / 2}=X.
$$
*Wow $X$ is Hermitian.*:smile:

*From our lecture note, at least, a Hermitian positive definite matrix is always diagonalizable. On the other hand A and B commute, then they are simultaneously diagonalizable.* 

*Hence  $\exists P$ , s.t.,  $A=P \Lambda_{a} P^{-1} . B=P \Lambda_{b} P^{-1}, \Lambda_{a}, \Lambda_{b}$  are both diagonal matrix with positive entry on the diagonal. So  $X=P \sqrt{\Lambda_{a}} P^{-1} P \sqrt{\Lambda_{b}} P^{-1}=P \sqrt{\Lambda_{a} \Lambda_{b}} P^{-1}$ ,which is still positive definite.*

*All in all, we get:*
$$
\begin{array}{c}
X A^{-1} X=A^{1 / 2} B^{1 / 2} A^{-1} A^{1 / 2} B^{1 / 2}=A^{1 / 2} B^{1 / 2} A^{-1 / 2} B^{1 / 2} \\
=A^{1 / 2} A^{-1 / 2} B^{1 / 2} B^{1 / 2}=B
\end{array}
$$
*Surely $X=A^{1 / 2} B^{1 / 2}$ is the geometric mean $A \# B$ we are searching for.*

*We have seen that $\log(A^{1 / 2}) $ commute with $\log(B^{1 / 2})$, and From our lecture note , we know that if  $A B=B A$ , then  $e^{A+B}=e^{A} e^{B}=e^{B} e^{A} $.*

*So in the end:*
$$
\begin{array}{c}
E(A, B)=e^{\frac{1}{2} \log (A)+\frac{1}{2} \log (B)}=e^{\frac{1}{2} \log (A)} e^{\frac{1}{2} \log (B)} \\
=e^{\log (\sqrt{A})} e^{\log (\sqrt{B})} \\
=A^{\frac{1}{2}} B^{\frac{1}{2}}
\end{array}
$$

------

## Problem 5

<img src="https://pic.imgdb.cn/item/60ce7ca3844ef46bb2169019.jpg" style="zoom:67%;" />

***2.27 a :***
*By the definition above, $A \# B$  is the unique Hermitian positive definite solution to  $X A^{-1} X=B.$ Since the solution is unique, and we know $A A^{-1} A=A$ , and  $A$  itself is a Hermitian positive definite matrix. So A is the solution, i.e. $A \# A=A $*



***2.27 b :***

By definition, we have: $ A\#B=\left(A B^{-1}\right)^{1 / 2} B .$ On the other hand, the inverse of a Hermitian positive definite matrix is still a Hermitian positive definite matrix. So  $A^{-1} \# B^{-1}=\left(A^{-1} B\right)^{1 / 2} B^{-1} .$ All in all  $(A \# B)^{-1}=\left(A B^{-1}\right)^{-1 / 2} B^{-1}=B^{1 / 2} A^{-1 / 2} B^{-1}=\left(A^{-1} B\right)^{1 / 2} B^{-1}=A^{-1} \# B^{-1} .$



***2.27 c :***

*Let $X_1=A\#B$, which is the unique Hermitian positive definite matrix that satisfies  $X_1 A^{-1} X_1=B $.  And Let $X_2=B\#A$ , which is the unique Hermitian positive definite matrix that satisfies  $X_2 B^{-1} X_2=A$. Apply  $X_1^{-1}$  on  both side of $X_1 A^{-1} X_1=B $, then we have$ A^{-1}=X_1^{-1} B X_1^{-1}$ .Take inverse of both side,  $X _1B^{-1} X_1=A$ . This is the same as $X_2=B\#A$ which satisfies $X_2 B^{-1} X_2=A$. Since the solution is unique, so we have $X_1=A\#B=X_2=B\#A$*



***2.27 d :***

*From page 46, we know Here,X ≥ 0 denotes that the Hermitian matrix X is positive semidefinite. And by the original definition, we have:$A\#B=\left(B^{-1 / 2} A B^{-1 / 2}\right)^{1 / 2}$*

*We want to prove that $X:=\frac{A+B}{2}-A\#B$ is positive semidefinite. Here we go.*

*Since we know that if B is semipositive then $B^{1/2}$ is also semipositive, and the result of   two semipositive matrix’s product is still semipositive.*

*We denote* $T$ *as* $B^{-1 / 2} A B^{-1 / 2}$*, and* $T^{*}=\left(B^{*}\right)^{-1 / 2} A^{*}\left(B^{*}\right)^{-1 / 2}=B^{-1 / 2} A B^{-1 / 2}=T$ . *From problems above, it's positive-definite, so it can be diagonalized into*  $T=B \Lambda B^{-1} $ *for some positive diagonal matrix * $\Lambda$ . *Thus we have *$T^{1/2}=B \Lambda^{1/2} B^{-1} $, *let*  $\Lambda'=I-\Lambda^{1/2}$, *okay:*
$$
\frac{1}{2}\left(B^{-1 / 2} A B^{-1 / 2}+I\right)-\left(B^{-1 / 2} A B^{-1 / 2}\right)^{1 / 2} \\
=\frac{1}{2}(T+I)-T^{1 / 2} \\
=\frac{1}{2}\left(I-T^{1 / 2}\right)^{2} \\
=\frac{1}{2}\left(B \Lambda^{\prime} B^{-1}\right)^{2} \\
=\frac{1}{2} B\left(\Lambda^{\prime}\right)^{2} B^{-1}
$$
*And we see$ (\Lambda^{\prime})^{2}$ is semipositive. So $\frac{1}{2}\left(B^{-1 / 2} A B^{-1 / 2}+I\right)-\left(B^{-1 / 2} A B^{-1 / 2}\right)^{1 / 2}$ is semipositive. Apply $B^{1/2}$ on both side.$​
$$
X:=\frac{A+B}{2}-A\#B
\\=\frac{1}{2}(A+B)-B^{1 / 2}\left(B^{-1 / 2} A B^{-1 / 2}\right)^{1 / 2}  
\\=B^{1/2}(\frac{1}{2}\left(B^{-1 / 2} A B^{-1 / 2}+I\right)-\left(B^{-1 / 2} A B^{-1 / 2}\right)^{1 / 2})B^{1 / 2}
$$
*So $X$ is semipositive definite in the end.*

------

## Problem 6

<img src="https://pic.imgdb.cn/item/60ce9529844ef46bb2c2ca10.jpg" style="zoom:67%;" />

*Because  $A$, $B$  are both hermitian positive definite, they have real positive determinant.
**WLOG**, assume $\alpha, \beta>0 .$*  Let  $T=\left(A^{-1} B\right)^{1 / 2}$  with two eigenvalue  $\lambda_{1}, \lambda_{2} \in \mathbb{C}$ .

*Thus we have  $\operatorname{trace}(T)=\lambda_{1}+\lambda_{2}$, $\operatorname{det}(T)=\lambda_{1} \lambda_{2}=\operatorname{det}\left(A^{-1 / 2}\right) \operatorname{det}\left(B^{1 / 2}\right)=\frac{\beta}{\alpha}$ .*

*Furthermore, we see that the eigenvalue of  $(\alpha^{-1} I+\beta^{-1} T^{2})$ are $(\beta^{-1}\lambda_{1}^2+\alpha^{-1})$ and $(\beta^{-1}\lambda_{2}^2+\alpha^{-1})$. Hence:
$$
\operatorname{det}\left(\alpha^{-1} I+\beta^{-1} X^{2}\right)=(\beta^{-1}\lambda_{1}^2+\alpha^{-1})(\beta^{-1}\lambda_{2}^2+\alpha^{-1})
\\=1+\frac{\alpha}{\beta}\lambda_1^2+\frac{\alpha}{\beta}\lambda_2^2+\frac{\alpha^2}{\beta^2}\lambda_1^2\lambda_2^2
=\frac{\alpha}{\beta}\times\frac{\beta}{\alpha}+\frac{\alpha}{\beta}\lambda_1^2+\frac{\alpha}{\beta}\lambda_2^2+\frac{\alpha}{\beta}\lambda_1\lambda_2
\\=\frac{\alpha}{\beta}\lambda_1^2+\frac{\alpha}{\beta}\lambda_2^2+2\frac{\alpha}{\beta}\lambda_1\lambda_2=\frac{\alpha}{\beta}\left(\lambda_{1}+\lambda_{2}\right)^{2}
$$
*All in all:*
$$
\begin{array}{c}
\operatorname{det}\left(\alpha^{-1} A+\beta^{-1} B\right)=\operatorname{det}(A) \operatorname{det}\left(\alpha^{-1} I+\beta^{-1} X^{2}\right) \\
=\alpha^2(\beta^{-1}\lambda_{1}^2+\alpha^{-1})(\beta^{-1}\lambda_{2}^2+\alpha^{-1}) \\
=\frac{\alpha}{\beta}\left(\lambda_{1}+\lambda_{2}\right)^{2} \\
=\frac{\alpha}{\beta} \operatorname{trace}(T)^{2}
\end{array}
$$
*The product of two hermitian positive definite matrix is still hermitian positive definite, so  $T$  is still hermitian positive definite,  $\operatorname{trace}(T)>0$ ;So* $\operatorname{trace}(T)=\sqrt{\frac{\beta}{\alpha} \operatorname{det}\left(\alpha^{-1} A+\beta^{-1} B\right)}$

*From **Cayley-Hamiltion theorem**, we have:*

*When $A$ has characteristic polynomial* $p(x)=\operatorname{det}(A-\lambda I)=x^{n}+c_{1} x^{n-1}+\ldots+c_{n} $

*then* $p(A)=0$ 

*And the characteristic polynomial for A is* $\left(x-\lambda_{1}\right)\left(x-\lambda_{2}\right)=x^{2}-\left(\lambda_{1}+\lambda_{2}\right)x+\lambda_{1} \lambda_{2} $

*Hence We know that*  $T^{2}-\operatorname{trace}(T)T+\operatorname{det}(T) I=0$

Then  $\operatorname{trace}(T)\left(A^{-1} B\right)^{1 / 2}=T^{2}+\operatorname{det}(T) I $ *Multiply $A$ from the left,we have*
$$
trace(T)A(A^{-1}B)^{1/2}=B+det(T)A.\\
trace(T)(B\text{#}A)=B+det(T)A.\\
trace(T)(A\text{#}B)=B+det(T)A.\\
A\text{#}B=\frac{B+det(T)A}{trace(T)}\\
=\frac{B+\frac{\beta}{\alpha}A}{\sqrt{\frac{\beta}{\alpha}det(\alpha^{-1}A+\beta^{-1}B)}}\\
=\frac{\sqrt{\alpha\beta}}{\sqrt{det(\alpha^{-1}A+\beta^{-1}B)}}(a^{-1}A+\beta^{-1}B).
$$

------

## Problem 7

<img src="https://pic.imgdb.cn/item/60cea59e844ef46bb2400c46.jpg" style="zoom:67%;" />

> P161 the Cholesky factor of A:  $A = R^*R$  (Cholesky factorization: R upper triangular)

*From **problem 5**, we define $A>0 $ if $A$ is hermitian positive definite.*

*Since* $ B>0$, *thus for* $\forall x\in \mathbb{C^n},x^*RBR^*x=(R^*x)^*B(R^*x)>0$. *thus* $RBR^*>0$,$\sqrt{RBR^*}>0$.

*Similarly,for* $\forall x\in \mathbb{C^n},x^*R^{-1}(RBR^*)^{\frac{1}{2}}R^{-*}x=(R^{-*}x)^*(RBR^*)^{\frac{1}{2}}(R^{-*}x)>0$. *So* $R^{-1}(RBR^*)^\frac{1}{2}R^{-*}>0$ *as well.*

*From the definition of $A\#B$, we know that the solution to* $X>0,XAX=B$ *is unique.*  *Thus we only need to prove:* $R^{-1}(RBR^*)^{\frac{1}{2}}R^{-*}AR^{-1}(RBR^*)^{\frac{1}{2}}R^{-*}=B.$
$$
R^{-1}(RBR^*)^{\frac{1}{2}}R^{-*}AR^{-1}(RBR^*)^{\frac{1}{2}}R^{-*}\\=
R^{-1}(RBR^*)^{\frac{1}{2}}R^{-*}R^*RR^{-1}(RBR^*)^{\frac{1}{2}}R^{-*}\\=
R^{-1}(RBR^*)R^{-*}\\=
(R^{-1}R)B(R^*R^{-*})=B.
$$
*So* $X=R^{-1}(RBR^*)^\frac{1}{2}R^{-*}$ *is the solution to* $XAX=B$ *that we are searching for.*

------

**完结撒花，好耶！**:smile:

