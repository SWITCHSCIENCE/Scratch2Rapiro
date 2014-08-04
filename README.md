# Scratch2Rapiro
RapiroをScratch 2.0 Offline Editorから制御するためのソフトウェアです。

## 使い方
- [ここ](http://ssci.to/)からScratch2Rapiroをダウンロードし、解凍します。
- Scratch2RapiroとScratch2.0 Offline Editorを起動します。
- Shiftキーを押しながら左上の「ファイル」をクリックし、「Import Experimental Extension」を選択します。
- 同梱されていたRapiro.jsonを選択します。
- 「その他」のカテゴリにブロックが追加されているはずです！

## 開発に参加する
```
$ cd $(OF_ROOT)/apps/myapps
$ git clone https://github.com/SWITCHSCIENCE/Scratch2Rapiro.git
```

Scratch2Rapiroは、[openFrameworks](http://openframeworks.jp/)というツールキットを用いて開発されており、現在はv0.8.1を用いています。
Windows, Mac, Linux共に動作するはずですが、動作確認ははMac OSX上でのみ行っています。

addonとして、以下のaddonを利用しているので、開発の際は適宜cloneしてください。

- [mactkg/ofxScratch](https://github.com/mactkg/ofxScratch)
- [armadillu/ofxHttpServer](https://github.com/armadillu/ofxHttpServer)

## ライセンス
MIT ライセンスで公開します。LICENSE.txtをご覧ください。

This software is released under the MIT License, see LICENSE.txt
