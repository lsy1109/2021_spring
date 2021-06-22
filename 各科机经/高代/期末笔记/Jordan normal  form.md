# Jordan normal  form

如何对一个线性映射$L:V\to V$找到你需要的基，使得这个映射在这组基下为*Jordan normal form*

也就是对于映射的初始表示矩阵$A$，计算使得出$P^{-1}AP=J$

其中$P$矩阵的每一列代表一个基向量，每个基向量都可以由自然基的线性组合表示。而$V$空间的自然基就选择最自然的即可，比如$V=C^2$则选择$\begin{bmatrix}1\\0\end{bmatrix}$、$\begin{bmatrix}i\\0\end{bmatrix}$、$\begin{bmatrix}0\\1\end{bmatrix}$、$\begin{bmatrix}0\\i\end{bmatrix}$

$V = P_4$*, the real vector space space of all real polynomials of degree at most 4.*注意到次数不大于4的多项式空间的维度为5，选择的基为$0，x，x^2，x^3，x^4$



**按照如下步骤进行计算，考试的时候只需要按照标题走就可以了，具体的细节不清楚了再回顾。**

## 一、选出自然基并且计算出映射$L$的初始表示矩阵$A$

$\large \mathbf{ L([e_1,e_2,…..e_n])=[e_1,e_2,…..e_n]A}$



## 二、对A计算特征多项式

$\large \mathbf{A=(x-\lambda_1)^{t_1}...(x-\lambda_n)^{t_n}}$

$t_1$是$\lambda_1$对应的广义特征空间的维度，也就是$\lambda_1$对应的所有*Jordan block*的大小之和。

求得大小之后后，需要计算$\lambda_1$对应几块*Jordan block*。



## 三、对每个特征值$\lambda_i$计算几何重数，并记录对应特征向量

解方程$\large \mathbf{(A-\lambda I)=0}$，记录解出的特征向量，且解出的向量个数即是几何重数，即是$\lambda_1$对应的所有*Jordan block*的个数，同时也是$dim(ker(A-\lambda I))=n-rank(A-\lambda I)$。

马上就能得知$A-\lambda I$的$rank$。

接下来注意一件事，我们在二中，根据代数重数，算出了$\lambda_1$对应的所有*Jordan block*的大小之和，接下来根据几何重数算出了$\lambda_1$对应的所有*Jordan block*的个数。问题在于，知道这些信息后，倘若没有巧合，不足以我们推导出每个*Jordan block*的大小。

所谓的巧合，比如代数重数是3，几何重数是2，那么显然是$1+2$型。但如果代数重数是4，几何重数是2，没法直接确定是$2+2$还是$1+3$。

这个确定方法放在最后，我们不要偏离主线，因为**大多时候都是巧合的**。



## 四、对$\lambda_i$的某个具体大小的$jordan$块，计算出广义特征向量

比如已知$\lambda_i$的某个$jordan$块的大小是$m$，任意选择$\lambda_i$的某个特征向量$x_1$，开始辗转计算：

$\large \mathbf{((A-\lambda_i I)x_k=x_{k-1}}$，直到计算出m个广义特征向量，并且写成特征向量链的形式，也就是$x_1、x_2...x_n$。那么对应的$jordan$块就是

$\begin{bmatrix}
 \lambda_i & 1 &  &  & \\
  &  \lambda_i&  1&  & \\
  &  &  \lambda_i& 1 & \\
  &  &  &  .& .\\
  &  &  &  &.
\end{bmatrix}$，大小为$m$。



## 五、计算出$\lambda_i$的其他$jordan$块，同上计算，顺次排列



## 六、对于其他的特征值，不断重复直到完全写出所有$jordan$块

注意到之前我们已经按照顺序排列出了特征向量链$x_1、x_2...x_n,y_1,y_2...y_m$，顺次写出即为矩阵$P$。用这些列向量去组合自然基，即是我们为映射$L$找的基。



## 附录.关于不是巧合的情况

记特征值$\lambda$具体大小为$k$的jordan块的个数为$n_k$，使用如下公式：

$\large \mathbf{(d_k=rank(A-\lambda I)^{k+1}+rank(A-\lambda I)^{k-1}-2rank(A-\lambda I)^{k}}$

注意，虽然公式在这里，**但是大多时候都是巧合，如果出现了不是巧合的情况，一定检查下是否是算错了！**

