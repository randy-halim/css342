Randy Halim <br/>
UWB CSS 342

# Analysis for $2^n$

Prove that the amount of moves (executions) from `hanoiMoves(n, "A", "C", "B")` is equal to $2^n$ when completed recursively.

Suppose we have a equation, representing three rods of the Tower of Hanoi problem and moves, defined as so:
$$ \text{moves} = f(n, rod*{from}, rod*{to}, rod*{extra}) $$ (1)
Where $n$ is how many disks are in $rod*{from}$.

The objective of this problem is to move all disks from `disk A` to `disk C`. Therefore, we can assume that the base case of this function is defined by the following equation:
$$ f(1, \text{A}, \text{C}, \text{B}) = 1 $$ (2)
A case where $ n = 0 $ is not considered, as there would be no disks to move. In a programmatic implementation,
you could implement a base (break) case with $ n = 0 $, as shown in the `hanoiMoved.cpp` file.

Let us also define $ g(n) $, which is the equation we are attempting to prove:
$$ g(n) = 2^n $$ (3)

Therefore, we are attempting to prove that $ f(n) = g(n) $.
By executing our C++ implementation, a table can be constructed for all real integers $ [1, 15] $ below:

| $ n $ | $ f(n, \text{A}, \text{C}, \text{B}) $ | $ g(n) $ |
| ----- | -------------------------------------- | -------- |
| 1     | 1                                      | 2        |
| 2     | 3                                      | 4        |
| 3     | 7                                      | 8        |
| 4     | 15                                     | 16       |
| 5     | 31                                     | 32       |
| 6     | 63                                     | 64       |
| ...   | ...                                    | ...      |
| 14    | 16383                                  | 16384    |
| 15    | 32767                                  | 32768    |

Notice how $ f(n, ...) \neq g(n) $. Therefore, the number of moves from our recursive implementation **does not equal** $ 2^n $. However, notice how $ g(n) $ is one more than $ f(n ...) $. Mathematically,

$$ g(n) = f(n ...) + 1 $$ (4)

By algebraically solving for $ f(n ...) $ and substituting back $ 2^n $ for $ g(n) $, we come up with the following equation:

$$ f(n ...) = 2^n - 1 $$ (5)

Therefore, using the same table above, we can prove that $ 2^n - 1 = f(n ...) $ by comparing
the answers for each real integer $ n $ for $ [1, 15] $.

**Since the numbers do match, we prove that $ 2^n - 1 = f(n ...) $.**
