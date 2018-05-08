## Question

If $X_1,X_2.X_3, \dots $ are independant random variables,

(1) $Y_i = X_iX_{i+1}X_{i+2}$, are the random variables, are they independant?

(2) $S_1,S_2$ are any subsets of $\bold{N^{*}}$, $Y_S = \prod_{i \in S} X_i$. When are $S_1$ and $S_2$ independant?

## Solution

(1) No.

As $X_1,X_2.X_3, \dots $ are independant random variables, 
$$
E[Y_1] = E[X_1X_2X_3] = E[X_1]E[X_2]E[X_3]
$$
Similarly, we have
$$
E[Y_2] = E[X_2X_3X_4] = E[X_2]E[X_3]E[X_4]
$$
So 
$$
E[Y_1]E[Y_2] = E[X_1]E[X_2]^2E[X_3]^2E[X_4]
$$
But 
$$
E[Y_1Y_2] =E[X_1X_2^2X_3^2X_4] = E[X_1]E[X_2^2]E[X_3^2]E[X_4]
$$
Since we could not derive $E[X_2^2] = E[X_2]^2$, so
$$
E[Y_1Y_2] = E[Y_1]E[Y2]
$$
So they are not independant.

(2) With the condition 
$$
E[X_i^2] = E[X_i]^2, \quad \forall i \in \bold{N^*}
$$
We can show that $S_1$ and $S_2$ are independant. It is also easy to show that the condition is also necessary.







