# apt-get関連 自分用メモ


## apt-get updateが「Hash Sum mismatch」で失敗する
エラー内容例
```
W: Failed to fetch http://security.ubuntu.com/ubuntu/dists/trusty-security/main/binary-amd64/Packages  Hash Sum mismatch

E: Some index files failed to download. They have been ignored, or old ones used instead.
The command '/bin/sh -c apt-get update' returned a non-zero code: 100
```

解決方法1： 参照しているリポジトリをJPからUSに変更してみる
```
$ sudo sed -i.bak -e 's;http://jp.archive.ubuntu.com;http://us.archive.ubuntu.com;g' /etc/apt/sources.list
$ sudo apt-get update
```

解決方法2：/var/lib/apt/lists ディレクトリ配下のファイルを一旦削除する
```
$ sudo rm -rf /var/lib/apt/lists/*
$ sudo apt-get update
```

参考URL：https://qiita.com/TsutomuNakamura/items/93e4a4ea0e587160fcaf  



## Dockerfileに書いたapt-get installが、怒られるか止まってしまう。
エラー内容例
```
怒られた例のlogの在り処を忘れた。。。
```

解決方法：DEBIAN_FRONTEND=noninteractiveを付与し、プロンプト(インタラクティブ)をパスさせる様にする
```
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y curl apt-transport-https
```

参考URL：http://inokara.hateblo.jp/entry/2014/02/06/070834  
参考URL：http://d.hatena.ne.jp/mainyaa/20140203/p1  

