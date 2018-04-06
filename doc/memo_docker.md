
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


### ローカルのイメージを走らせる(特権、MQ、共有フォルダマウント付き)
```
sudo docker run --name my_study --privileged --ulimit msgqueue=12582912:12582912 -v /home/vagrant/share:/root/share -i -t test/dotnet:1.0
```
test/dotnet:1.0は、ローカルBuildしたイメージで、dockerhubにアップ(PUSH)していないもの。


### startとexec
```
docker start my_study
docker exec -it my_study /bin/bash
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
----


## Docker RUN時に実行されたゴミの削除

パラメータ指定の不備などで、  
$ docker run xxxxxx  
の実行に失敗した場合にも、  
$ docker ps -a  
をすると、docker側が自動で名前をつけた状態で走ってしまっています。

```
vagrant@ubuntu-xenial:~$ docker ps -a
CONTAINER ID        IMAGE               COMMAND                  CREATED             STATUS                      PORTS               NAMES
d7302ef448d1        test/dotnet:1.0     "--name my_dotnet --…"   3 hours ago         Created                                         infallible_beaver
3edc5cb041ae        test/dotnet:1.0     "--name dotnet --pri…"   3 hours ago         Created                                         blissful_bardeen
df12dcc51050        test/dotnet:1.0     "--name dotnet --pri…"   3 hours ago         Created                                         quizzical_keller
7250fd59e811        b1bba73d9ce0        "/bin/sh -c 'apt-get…"   22 hours ago        Exited (100) 22 hours ago                       lucid_agnesi
dbc17ba40404        7a23933336a9        "/bin/sh -c 'apt-get…"   23 hours ago        Exited (100) 23 hours ago                       zen_albattani
40b2ad379dab        b96d7c64667a        "/bin/sh -c 'apt-get…"   23 hours ago        Exited (100) 23 hours ago                       goofy_leakey
852f48e83b12        e1cb46b3a7ce        "/bin/sh -c 'apt-get…"   24 hours ago        Exited (100) 23 hours ago                       adoring_nobel
2556d840111a        naotaru/study       "/bin/bash"              2 weeks ago         Up 4 hours                                      study

```
dockerが勝手にNAMEをつけてくれているので、やっちまったイメージを docker rm で削除すればOKです。  
```
$ docker rm infallible_beaver
$ docker rm blissful_bardeen
：
$ docker rm adoring_nobel
```

