学习笔记

第1周知识点小结：

一维数据结构：数组、链表、队列、栈
	数组：插入O(1),删除O(n),查找O(1);
	链表：插入O(1),删除O(1),查找O(n);
	队列：入队O(1),出队O(1),查找O(n),先进先出;
	栈  ：入栈O(1),出栈O(1),查找O(n),先进后出;

高级数据结构：跳表、优先队列、循环队列
	跳表：空间换时间，建立多级索引，对标平衡树和二分查找，插入、删除、查找都是O(log n);
	优先队列：入队O(1),出队O(log n)；
	循环队列：两端都可以进出。

其他：
	只用栈实现队列或者只用队列实现栈，一般都是用两个栈/两个队列来实现。