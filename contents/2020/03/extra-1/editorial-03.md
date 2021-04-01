# コードチャレンジ#3 extra課題

### 解法
まず，不可能なケースを除きます．P/Q = 1で現在の正答率が1に満たない場合は今後どれだけ正解してもP/Qに届くことはあり得ないので答えは-1です．
また，現在1問以上正解しているがP=0の場合も達成不可能なので-1となります．

それ以外の場合を考えます．追加で何問か解いた後のX,YをそれぞれX',Y'とします．
X'/Y' = P/Qが成り立つ時，PとQは互いに素であることからY'はQの倍数である必要があります．したがってこのような分母の値を決めうち，分子の値が条件を満たすかを考えれば良いです．
分母がQの倍数であるという条件下では解の存在に単調性があるのでこれは二分探索を用いて求めることができます．

なお，この問題は二分探索を用いずO(1)で解くことも可能です．是非考えてみてください．

### 実装例
```python
T = int(input())

for t in range(T):
  x, y, p, q = map(int, input().split())
  if p == q and x != y:
      print(-1)
      continue

  INF = 10000000000
  lb = -1
  ub = INF
  mod_y = (q - y % q) % q

  while ub - lb > 1:
    mid = (ub + lb) // 2
    diff = mod_y + q * mid
    bunbo = y + diff
    bunshi = p * bunbo // q
    if bunshi >= x and bunshi - x <= diff:
      ub = mid
    else:
      lb = mid
  if ub == INF:
    print(-1)
  else:
    print(mod_y + q * ub)
  
```