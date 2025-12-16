# Utiliser anciecréatures
Utiliser_anciecréatures_project  
-> ゲームプロジェクト  
Utiliser_Resources  
-> Obsidianでの仕様書、タスク管理  

# プロジェクトセットアップ
## DXLibのセットアップ
1. DXLib [Windows版 VisualStudio( C++ )用(Ver3.24d)](https://dxlib.xsrv.jp/dxolddload.html)をダウンロードし、`DxLib_VC3_24f.zip`を解凍してください。
2. 解凍したフォルダの中にある`DxLib_VC/プロジェクトに追加すべきファイル_VC用`をこのプロジェクトのルートディレクトリへ移動してください。
3. `プロジェクトに追加すべきファイル_VC用`の名前を`DxLib_VC3_24f`に変更してください。

## nlohmann/jsonのセットアップ
1. プロジェクトのルートディレクトリに`nlohmann_3.12.0`という名前のフォルダを作成してください。
2. [nlohmann_3.12.0](https://github.com/nlohmann/json/releases/tag/v3.12.0)から`include.zip`をダウンロードし、解凍してください。
3. 解凍したフォルダの中の`include`に入っている`nlohmann`をプロジェクトのルートディレクトリに作成した`nlohmann_3.12.0`フォルダの中に移動してください。

## 最終的なフォルダ構造
```
Utiliser-anciecreatures
├DxLib_VC3_24f  <-----HERE!
│├celt.lib
│⌊...
├nlohmann_3.12.0  <-----HERE!
│⌊nlohmann
│ ├detail
│ ⌊...
├Utiliser_anciecréatures_project
│⌊...
├Utiliser_Resources
│⌊...
├.gitignore
⌊README.md
```

