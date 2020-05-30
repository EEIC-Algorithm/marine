## 解法
左や右から貪欲に決定していくことはできないので動的計画法を考えます。  
状態を考えるにあたって、ある区間が同じ色の時その色は左端の色か右端の色しかありえないという特性に注目します。  
dp[i][j][k]: i番目からj番目のブロックが同じ色に塗られている時の操作回数の最小値、ただしk = 0の時左端の色で塗られていて、k = 1の時右端の色で塗られている  
このような状態の持ち方は「区間dp」などと呼ばれることがあります。
求めるべき答えはmin(dp[0][N][0], dp[0][N][1])となります。
このdpの値は区間長の小さい値からボトムアップに決定していくことができるため、再帰関数などを用いて実装すると理解しやすいでしょう。  


## 計算量
適切にメモ化などを行うことでO(N^2)で求めることができます。