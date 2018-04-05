
# docker関連 自分用メモ

## よく使うコマンドメモ

### キャッシュなしで、Build
```
docker build --no-cache=true -t naotaru/study:1.2 .
```
dockerhubにアップする時には、naotaruの部分がdockerhubユーザ名と一致しないといけないので注意。

### キャッシュありで、Build
```
docker build -t naotaru/study:1.2 .
```


### DockerHubへログイン
```
docker login
```
DockerHubへのPUSH前に、ログインしておく必要がある事に注意。


### タグを貼る
```
docker tag naotaru/study:1.2 naotaru/study:latest
```

### DockerHubへプッシュ(コミット)
```
docker push naotaru/study:1.2 
docker push naotaru/study:latest
```
----


## DockerBuild時に生成されたゴミイメージの削除
DockerBuildを繰り返してトライしていると、無名のイメージレイヤーデータが溜まりますが、
それの削除方法に、docker rmi に docker images を実行した結果の Image ID(ハッシュ)を毎回
コピペするのが大変だったので、何か良い方法はないか、探したところ、良さそうな方法が
見つかったのでメモっておきます。
```
$ docker rmi -f $(docker images -f dangling=true -q)
```
どうやら、本家サイトにもこの方法が紹介されている様です。

参考URL(本家サイト)：https://docs.docker.com/engine/reference/commandline/images/#filtering


