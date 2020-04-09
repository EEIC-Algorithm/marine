# 基本課題#3-a

*以下の課題においては，入出力や問題文で指示がある場合を除き，実装すべき処理において標準ライブラリや問題で指定されていない外部の関数やライブラリ等を使用しないでください．また，課題によってはコードの一部分（コーディング画面の初期コードとは別のコード）があらかじめ与えられている場合があります． その場合，問題文に明記してありますので，指示に従ってください．*

### 問題文
オープンアドレス法でハッシュを実装し、以下の\\(Q\\)個のクエリに答えてください。
- タイプ0: ハッシュ表に要素\\(x\\)を追加する。 
- タイプ1: ハッシュ表に要素\\(x\\)が存在すれば`'found'`を、存在しなければ`'not found'`を出力する。 



### 制約
- 入力は全て整数
- \\(1 \leq Q \leq 10^5\\)
- クエリ番号は\\(0\\)または\\(1\\)
- \\(0 \leq x \leq 10^9\\)


### 入力
以下の形式で標準入力から与えられる。

---

\\(Q\\)
\\(query_1\\)
\\(query_2\\)
:
\\(query_Q\\)

---

各クエリは以下のうちいずれかの形式で与えられる。

---
\\(0 \quad x\\)

---

または

---
\\(1 \quad x\\)

---

0のときはタイプ0、1のときはタイプ1のクエリであることを示している。


### 出力
\\(Q\\)個のクエリに答えなさい。  

### 入力例1
```
5
0 6
0 9
1 6
1 4
0 10
```
### 出力例1
```
found
not found
```

### 入力例2
```
5
0 7
0 13
1 7
0 7
1 7
```
### 出力例2
```
found
found
```
