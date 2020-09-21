# DijkstraAlgorithm

求图中一个顶点到另外一个顶点的最短路径  
算法时间复杂度O(n3)，其中n为顶点个数  

STEP1: 选择一个顶点，建立一个表格，记录从该顶点出发，到达其他顶点的最短路径，无法到达的顶点距离记录为无穷大  
STEP2: 从该顶点（假设A点）出发，依次到达第一批可以到达的点，选取距离最近的点（假设为B），遍历B点能到达的除了A点以为的其他点，根据所得起始点距离，更新表格  
STEP3: 按照更新后的表格，再取除了A点所能到达的点中除了B点之外距离最短的点（假设为C），再依次遍历C点能到达的除了A,B之外的点，更新表格  
STEP4: 更新完所有内容后，获得一个A点到达所有其他点的最短路径和最短距离表格  

![](https://github.com/ShowTimeWalker/DijkstraAlgorithm/blob/master/images/001.png)

![](https://github.com/ShowTimeWalker/DijkstraAlgorithm/blob/master/images/002.png)
->  
![](https://github.com/ShowTimeWalker/DijkstraAlgorithm/blob/master/images/003.png)
->  
![](https://github.com/ShowTimeWalker/DijkstraAlgorithm/blob/master/images/004.png)
->  
![](https://github.com/ShowTimeWalker/DijkstraAlgorithm/blob/master/images/005.png)
->  
![](https://github.com/ShowTimeWalker/DijkstraAlgorithm/blob/master/images/006.png)
->  
![](https://github.com/ShowTimeWalker/DijkstraAlgorithm/blob/master/images/007.png)

