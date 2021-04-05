# Extra課題#11

### 問題文
英小文字からなる\\(N\\)個の文字列\\(s_1, s_2, ..., s_N\\)が与えられます．また，\\(t\\)を空文字列とします．ここから次の操作を繰り返します．

- \\(s_1, s_2,...,s_N\\)のうち空文字列でないものを一つ選ぶ．
- 選んだ\\(s_i\\)に含まれる好きな英小文字を1つ選び，その文字を1つだけ\\(s_i\\)から削除する．
- \\(t\\)の末尾に選んだ英小文字を追加する

各文字列\\(s_i\\)には削除できる最大の文字数\\(a_i\\)が設定されており，\\(s_i\\)からは最大でも\\(a_i\\)文字までしか削除することができません．

また，文字列の選択にはコストが発生し，\\(s_i\\)を選択した時には毎回\\(i\\)だけコストがかかります．  
つまり\\(s_1\\)を選択した時にはコスト1が，\\(s_N\\)を選択した時にはコスト\\(N\\)が発生します．

あなたの目標は文字列\\(t\\)を与えられた文字列\\(T\\)に一致させることです．この時に必要となるコストの最小値を求めてください．\\(T\\)を作ることができない場合は``-1``を出力してください．


### 制約
- \\(1 \leq |T| \leq 100 \\)
- \\(1 \leq N \leq 100 \\)
- \\(1 \leq |s_i| \leq 100 \\)
- \\(0 \leq a_i \leq 100\\)
- \\(s_i, T\\)は英小文字のみからなる．
- \\(N,a_i\\)は整数


### 入力
以下の形式で標準入力から与えられる。

---
\\(T\\)
\\(N\\)
\\(s_1 \quad a_1\\)
:
\\(s_N \quad a_N\\)

---


### 出力
文字列\\(T\\)を作るために必要なコストの最小値を一行に出力してください．  
文字列\\(T\\)を作ることができない場合は``-1``を出力してください．

### 入力例1
```
aabcd
3
aca 2
bda 3
ab 10

```

### 出力例1
```
8

```
\\(s_1\\)を\\(2\\)回，\\(s_2\\)を\\(3\\)回選択することでコスト\\(8\\)で目標を達成でき，これが最小です．

### 入力例2
```
abacaba
4
aba 2
bcc 1
caa 2
bbb 5

```
### 出力例2
```
18

```

### 入力例3
```
xyz
4
bxj 8
zz 1
xxz 4
ttt 1

```
### 出力例3
```
-1

```