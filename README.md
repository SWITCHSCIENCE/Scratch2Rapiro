# Scratch2Rapiro
RapiroをScratch 2.0 Offline Editorから制御するためのソフトウェアです。現在、バイナリでの配布は***Macのみ***で行っています。申し訳ありません。同じソースコードを使ってビルドして実行することは可能かと思います。

## 使い方
![hogehoge](https://cloud.githubusercontent.com/assets/178418/3809127/2d909494-1c80-11e4-9568-671570a47641.gif)

- [ここ](https://github.com/SWITCHSCIENCE/Scratch2Rapiro/releases)からScratch2Rapiroをダウンロードし、解凍します。
- Scratch2RapiroとScratch2.0 Offline Editorを起動します。
- Shiftキーを押しながら左上の「ファイル」をクリックして、「Import Experimental Extension」を選択します。
- 同梱されていたRapiro.jsonを選択します。
- 「その他」のカテゴリにブロックが追加されているはずです！
- Scratch2Rapiroの"Select Rapiro Port"から、Rapiroを接続しているUSBポートを選んでください。
  - Macの場合は"/dev/tty.usbserial-..."といった風になっているはずです。
  - (Windowsの場合は"COM3"など?)
- Rapiroの目が一度消えて、しばらくしてまた光れば接続成功です。
- 試しにScratchから「前に歩く」ブロックを実行してみましょう。Rapiroが前に歩き始めるはずです。
- もちろん、「すべてを止める」ボタンを押せば初期ポーズに戻ります。

## ブロックの解説
分かりづらくて申し訳ないのですが、ブロックには二種類あります。プリセットで入っているモーションで動かすためのブロックと、カスタムで自分で決めたポーズをさせるためのブロックです。

### 基本モーション
基本モーションは、プリセットで元から入っているモーションです。いくつかのポーズを順番に動かすことで実現しているようです。基本モーションにあたるブロックは以下のブロックです。

- 停止する
-  (前/後ろ)に歩く
- (左/右)に曲がる
- (左/右/両)手を振る
- 両手を握る
- 右手を伸ばす

### カスタムポーズ
カスタムポーズをRapiroにさせるには、2つのステップを踏む必要があります。

1. ```ポーズNのXのサーボをR度にする```ブロックなどを使ってポーズを登録する
2. ```T秒かけてポーズNにする```ブロックを使ってそのポーズを呼び出す

の二段階です。一度ポーズを登録してしまえば、何度も登録する必要はありません。また、登録してあるポーズを上書きすることもできます。ポーズの番号はコンピュータの限界が来るまで増やすことが出来るはずですが、あまり大きな数字は入れないほうが良いでしょう。***マイナスの数字は入れてはいけません。***

カスタムポーズに関するブロックは以下のブロックです。

- ポーズNのXのサーボをR度にする
- ポーズNのX色のLEDの明るさをRにする
- ポーズNをリセットする
- S秒かけてポーズNにする
- ポーズNの時のXのサーボの角度
- ポーズNの時のX色LEDの明るさ

## 開発に参加する
```
$ cd $(OF_ROOT)/apps/myapps
$ git clone https://github.com/SWITCHSCIENCE/Scratch2Rapiro.git
```

Scratch2Rapiroは、[openFrameworks](http://openframeworks.jp/)というツールキットを用いて開発されており、現在は開発にv0.8.1を用いています。
Windows, Mac, Linux共に動作するはずですが、動作確認はMac OSX上でのみ行っています。

addonとして、以下のaddonを利用しているので、開発の際は適宜cloneしてください。

- [mactkg/ofxScratch](https://github.com/mactkg/ofxScratch)
- [armadillu/ofxHttpServer](https://github.com/armadillu/ofxHttpServer)
- [bakercp/ofxUnicode](https://github.com/bakercp/ofxUnicode)
- [rezaali/ofxUI](https://github.com/rezaali/ofxUI)

## ライセンス
MIT ライセンスで公開します。このソフトウェアを使ったことによるRapiroの故障などに対して、開発チームは一切責任を負いませんので注意してください。詳しくはLICENSE.txtをご覧ください。

This software is released under the MIT License, see LICENSE.txt
