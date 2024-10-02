Decision - do you want to take this item, yes or no.

# Graph

Graph - decisions are moves. Graph of states.

State
How much weight is left == how much weight is accumulated
Edge - adding items
weight - value of the item with 0

Node - item, weight of taken item

3 items, backpack can hold 5 lb

```
1 $10 4
2 $4  2
3 $7  3

s    1      2     3     Done  items
0   1,0  -> 2,0   3,0
1   1,1    2,1   3,1
2   2,2    2,2   3,2
3
4
5
```

Lb

if we don't take next item, edge goes from 1,0 to 2.0 (Edge weight of 0)
If we take, then from 1,0 to 2,4 (edge weight of -10)

# DP

```
    0  1  2
 0  0  0  0
 1  0  0  0
 2  4  4  0
 3  7  7  0
 4 10  7  7
 5 11  11 7

 or
   0  1  2  3  4   5
 0 0  0  0  0  7   7
 1 0  0  4  7  7   11
 2 0  0  4  7  10  11
```

Decisions = do I take item i or do not take item i

```
dp[i][j] = max  dp[i+1][j]   [do not take this item, take next]
                 vi + dp[i + 1][j - sj] if j >= si  [take this item]
```

Input matters because we go sequentially from 0 to s

