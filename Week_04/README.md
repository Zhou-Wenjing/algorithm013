学习笔记

第4周学习笔记

1. DFS模板-递归写法

        visited = set()

        def dfs(node):
    
            visited.add(node)

            # process current node here
            ...

            for next_node in node.children():
                if not next_node in visited:
                    dfs(next_node, visited)
    
2. DFS模板-非递归写法

        def DFS(self, tree):

            if tree.root is None:
                return []

            visited, stack = [], [tree.root]

            while stack:
                node = stack.pop()
                visited.add(node)

                process (node)
                nodes = generate_related_nodes(node)
                stack.push(nodes)

            # other processing work
            ...

3. BFS模板

        def BFS(graph, start, end):

            queue = []
            queue.append([start])
            visited.add(start)

            while queue:
                node = queue.pop()
                visited.add(node)

                process(node)
                nodes = generate_related_nodes(node)
                queue.push(nodes)

            # other processing work
            ...

4. 二分法模板

   使用前提：
   1) 目标函数单调
   2) 存在上下界
   3) 能够通过索引访问

            def BinarySearch():

                left, right = 0, len(array) - 1
                while left <= right:
                    mid = (left + right) / 2
                    if (array[mid] == target):
                        break or return result
                    elif array[mid] < target:
                        left = mid + 1
                    else:
                        right = mid - 1
