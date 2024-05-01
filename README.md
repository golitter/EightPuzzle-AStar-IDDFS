# EightPuzzle-AStar-IDDFS

人工智能大作业：基于迭代加深的A*算法求解八数码问题



基于迭代加深的A*算法（IA\*)本质是对dfs算法剪枝。

剪枝：

- 最优性剪枝：曼哈顿距离剪枝
- 记忆化剪枝：康托展开优化的哈希映射

评估函数：当前深度 + 到达目标状态所需的最小步骤

### 康托展开





[【数论系列】 康托展开-CSDN博客](https://blog.csdn.net/qq_40772692/article/details/80549303?ops_request_misc=&request_id=&biz_id=102&utm_term=康托展开&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-0-80549303.nonecase&spm=1018.2226.3001.4187)

[C++ 八数码问题理解 `IDA*` 算法原则：及时止损，缘尽即散-CSDN博客](https://blog.csdn.net/y6123236/article/details/136210573)

[康托展开 - OI Wiki (oi-wiki.org)](https://oi-wiki.org/math/combinatorics/cantor/)