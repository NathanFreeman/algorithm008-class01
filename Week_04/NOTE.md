# **学习笔记-第四周**
#### **反思：**

最近要反思自己的时间管理，因为项目很急，算法训练这里是丢三落四的，质量也比以往的低了不少，这里一定要做个反思，不能这样发展下去，对于我个人来说很不利。

#### **感谢：**

最近的算法都是用C++写的，今年的任务是有学习C++这个任务的，算法训练相当于就是给我一个学习C++的机会，C++很难啃，希望自己能够完成年度任务。

#### **总结：**
首先是优化搜索的两种方式


1.广度优先搜索（Breadth-First-Search，简称BFS）

广度优先搜索（Breadth-First-Search），我们平常都把简称为 BFS。直观地讲，它其实就是一种“地毯式”层层推进的搜索策略，即先查找离起始顶点最近的，然后是次近的，依次往外搜索。BFS一般使用数据结构队列来解决搜索问题。

    def BFS(graph, start, end):
        visited = set()
	    queue = [] 
	    queue.append([start]) 

	    while queue: 
		    node = queue.pop() 
		    visited.add(node)

		    process(node) 
		    nodes = generate_related_nodes(node) 
		    queue.push(nodes)

	    # other processing work 

2.深度优先搜索（Depth-First-Search），简称 DFS

深度优先搜索主要用于查找树或者图，从根节点开始，沿着树的深度遍历节点，如果发现不能找不到目标，那就返回上一个节点，再从另外的路径开始搜索直到找到目标或者找不到目标才结束。这种尽量往深处搜索的思想就是深度优先搜索。
DFS一般采用栈数据结构解决问题。

    visited = set() 

    def dfs(node, visited):
        if node in visited: # terminator
    	    # already visited 
    	    return 

	    visited.add(node) 

	    # process current node here. 
	...
	    for next_node in node.children(): 
		    if next_node not in visited: 
			    dfs(next_node, visited)

贪心算法

贪心算法指的是在对问题求解时，总是做出在当前看来是最好的选择。也就是说，不从整体最优上加以考虑，他所做出的是在某种意义上的局部最优解。贪心算法不是对所有问题都能得到整体最优解，关键是贪心策略的选择，选择的贪心策略必须具备无后效性，即某个状态以前的过程不会影响以后的状态，只与当前状态有关。

贪心算法其实不算是一种算法，更多的是一种指导思想。

能用到贪心算法的题目基本有这洋的特征：我们定义了限制值和期望值，希望从中选出几个数据，在满足限制值的情况下，期望值最大。

#### **最后对自己说的话**

好好练习，刷一大堆题目还不如认认真真吃透一道题。