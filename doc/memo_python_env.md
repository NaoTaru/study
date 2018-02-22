# python環境 自分用メモ


## python環境構築
  * python2系と3系で互換性がない部分があるので、どちらの環境にも切替られる様に、「miniconda」を使う。  
    

## minicondaインストール
  * bashインストーラを公式サイトから入手する。  
    https://conda.io/miniconda.html
```
$ wget https://repo.continuum.io/miniconda/Miniconda3-latest-Linux-x86_64.sh
```

  * .bashrcに色んなパスが追加されるので、適用させる。  
```
$ source ~/.bashrc
```


## python環境セットの作成と切替

  * condaで、python3系列の環境を作成  
```
$ conda create -n python3kei python=3.6
```
  * condaで、python2系列の環境を作成  
```
$ conda create -n python2kei python=2.7
```
  * 作成した環境の有効化  
```
$ source activate python3kei
```


