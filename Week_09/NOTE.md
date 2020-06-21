##### **高级动态规划**

**1.递归 函数自己调用自己**

**2.分而治之** 

**3.人肉递归低效，很累**

**4.找到最近最简单方法，将其拆解成可重复解决的问题**

**5.数学归纳法思维**

**6.本质：寻找重复性**

动态规划的本质就是递归和分治

动态规划 Dynamic Programming

    1.“Simplifying a complicated problem by breaking it down into simpler sub-problems”(in a recursive manner)
    2.Divide & Conquer + Optimal substructure 分治 + 最优子结构
    3.顺推形式: 动态递推
    
高阶的 DP 问题
复杂度来源

    状态拥有更多维度(二维、三维、或者更多、甚至需要压缩)
    状态方程更加复杂

字符串匹配算法

    暴力法(brute force) - O(mn)
    暴力字符串匹配（brute force string matching）是子串匹配算法中最基本的一种，它确实有自己的优点，比如它并不需要对文本（text）或模式串（pattern）进行预处理。然而它最大的问题就是运行速度太慢，所以在很多场合下暴力字符串匹配算法并不是那么有用。
    
    Rabin-Karp 算法
    由Michael O. Rabin和Richard M. Karp在1987年提出一个想法，即可以对模式串进行哈希运算并将其哈希值与文本中子串的哈希值进行比对。总的来说这一想法非常浅显，唯一的问题在于我们需要找到一个哈希函数 ，它需要能够对不同的字符串返回不同的哈希值。例如，该哈希函数可能会对每个字符的ASCII码进行算，但同时我们也需要仔细考虑对多语种文本的支持。
    
    KMP 算法
    “KMP算法是由D.E. Knuth、J.H.Morris和V.R. Pratt提出的,可在一个主文本字符串S内查找一个词W的出现位置。此算法通过运用对这个词在不匹配时本身就包含足够的信息来确定下一个匹配将在哪里开始的发现,从而避免重新检查先前匹配的字符。
    
