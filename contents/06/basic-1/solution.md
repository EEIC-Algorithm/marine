## 解法
dp[i]:=足場iにたどり着くまでにかかるコストの総和の最小値 とします。
足場iにたどり着くには、足場i-1→i, i-2→i の2通りの場合があるので、
dp[i]=min(dp[i-1]+abs(h[i-1]-h[i]),dp[i-2]+abs(h[i-2]-h[i]))
という漸化式で書けます。
この式に従ってi=0(0-indexedとします)から順にdpテーブルを更新して行くことにより、O(N)で答えdp[N-1]が求められます。

上では遷移元(dp[i-1]とdp[i-2])の値からdp[i]を更新するいわゆる「貰うDP」を説明しましたが、
dp[i+1]=min(dp[i+1],dp[i]+abs(h[i]-h[i+1]))
dp[i+2]=min(dp[i+2],dp[i]+abs(h[i]-h[i+2]))
というように、現在の値から遷移先(dp[i+1]とdp[i+2])を更新する「配るDP」でも書けます。

## 計算量
各iに対してdp[i]の計算がO(1)なので全体でO(N)