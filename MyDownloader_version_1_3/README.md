# MyDownloader
作者：重庆大学大数据与软件学院软件工程一班姚沛帆

## 中文版本

### 项目简介
MyDownloader是一款基于Qt框架开发的文件下载工具，支持HTTP/HTTPS协议，提供用户认证、断点续传、下载速度实时显示等功能。

### 功能特点
- 用户认证系统：支持用户注册和登录
- 断点续传：支持暂停和继续下载
- 下载速度显示：实时显示当前下载速度
- 系统托盘：支持最小化到系统托盘
- 历史记录：保存并查看下载历史
- 简洁界面：直观易用的用户界面

### 开发环境
- 开发工具：Qt Creator
- 编程语言：C++
- 数据库：SQLite
- Qt版本：Qt 5.15或更高

### 系统要求
- 操作系统：Windows 7/8/10/11
- 处理器：Intel Core i3或等效处理器
- 内存：至少2GB RAM
- 存储空间：至少100MB可用空间
- 网络连接：支持HTTP/HTTPS协议

### 安装方法
1. 下载MyDownloader安装包
2. 解压到任意文件夹
3. 运行MyDownloader.exe启动程序

### 使用说明
1. **登录/注册**：启动程序后，使用已有账号登录或注册新账号
2. **输入URL**：在主界面输入要下载的文件链接
3. **选择保存路径**：点击浏览按钮选择下载文件的保存位置
4. **开始下载**：点击下载按钮开始下载
5. **下载控制**：使用暂停/继续/取消按钮控制下载过程

### 项目结构
```
MyDownloader/
├── main.cpp              // 应用程序入口
├── mainwindow.h          // 主窗口头文件
├── mainwindow.cpp        // 主窗口实现
├── login.h               // 登录窗口头文件
├── login.cpp             // 登录窗口实现
├── signup.h              // 注册窗口头文件
├── signup.cpp            // 注册窗口实现
├── dialog.h              // 验证码对话框头文件
├── dialog.cpp            // 验证码对话框实现
├── database.h            // 数据库操作头文件
├── database.cpp          // 数据库操作实现
├── resource.qrc          // 资源文件
├── MyDownloader.pro      // 项目文件
└── README.md             // 项目说明文档
```

### 注意事项
1. 确保网络连接正常
2. 输入有效的URL链接
3. 确保有足够的存储空间
4. 程序需要Qt运行库支持

### 版权信息
© 2025 重庆大学大数据与软件学院软件工程一班姚沛帆. 保留所有权利.


## English Version

### Project Introduction
MyDownloader is a file download tool developed based on the Qt framework, supporting HTTP/HTTPS protocols, and providing user authentication, breakpoint resume, real-time download speed display, and other features.

### Features
- User Authentication System: Support user registration and login
- Breakpoint Resume: Support pause and resume downloads
- Download Speed Display: Real-time display of current download speed
- System Tray: Support minimizing to system tray
- History Record: Save and view download history
- Clean Interface: Intuitive and easy-to-use user interface

### Development Environment
- Development Tool: Qt Creator
- Programming Language: C++
- Database: SQLite
- Qt Version: Qt 5.15 or higher

### System Requirements
- Operating System: Windows 7/8/10/11
- Processor: Intel Core i3 or equivalent
- Memory: At least 2GB RAM
- Storage Space: At least 100MB available space
- Network Connection: Support for HTTP/HTTPS protocols

### Installation Method
1. Download the MyDownloader installation package
2. Extract it to any folder
3. Run MyDownloader.exe to start the program

### Usage Instructions
1. **Login/Register**: After starting the program, login with an existing account or register a new account
2. **Enter URL**: Enter the file link to download in the main interface
3. **Select Save Path**: Click the browse button to select the save location for the downloaded file
4. **Start Download**: Click the download button to start downloading
5. **Download Control**: Use the pause/resume/cancel buttons to control the download process

### Project Structure
```
MyDownloader/
├── main.cpp              // Application entry point
├── mainwindow.h          // Main window header file
├── mainwindow.cpp        // Main window implementation
├── login.h               // Login window header file
├── login.cpp             // Login window implementation
├── signup.h              // Registration window header file
├── signup.cpp            // Registration window implementation
├── dialog.h              // Verification code dialog header file
├── dialog.cpp            // Verification code dialog implementation
├── database.h            // Database operation header file
├── database.cpp          // Database operation implementation
├── resource.qrc          // Resource file
├── MyDownloader.pro      // Project file
└── README.md             // Project description document
```

### Notes
1. Ensure network connection is normal
2. Enter a valid URL link
3. Ensure sufficient storage space
4. The program requires Qt runtime libraries

### Copyright Information
© 2025 Yao Peifan, Software Engineering Class 1, School of Big Data and Software Engineering, Chongqing University. All rights reserved.


## 日本語バージョン

### プロジェクトの紹介
MyDownloaderはQtフレームワークに基づいて開発されたファイルダウンロードツールで、HTTP/HTTPSプロトコルをサポートし、ユーザー認証、ブレークポイント再開、リアルタイムダウンロード速度表示などの機能を提供します。

### 機能特徴
- ユーザー認証システム: ユーザー登録とログインをサポート
- ブレークポイント再開: ダウンロードの一時停止と再開をサポート
- ダウンロード速度表示: 現在のダウンロード速度をリアルタイムで表示
- システムトレイ: システムトレイに最小化することをサポート
- 履歴記録: ダウンロード履歴を保存および表示
- シンプルなインターフェース: 直感的で使いやすいユーザーインターフェース

### 開発環境
- 開発ツール: Qt Creator
- プログラミング言語: C++
- データベース: SQLite
- Qtバージョン: Qt 5.15以上

### システム要件
- オペレーティングシステム: Windows 7/8/10/11
- プロセッサ: Intel Core i3または同等のプロセッサ
- メモリ: 少なくとも2GB RAM
- ストレージスペース: 少なくとも100MBの空きスペース
- ネットワーク接続: HTTP/HTTPSプロトコルをサポート

### インストール方法
1. MyDownloaderインストールパッケージをダウンロードする
2. 任意のフォルダに解凍する
3. MyDownloader.exeを実行してプログラムを起動する

### 使用方法
1. **ログイン/登録**: プログラムを起動した後、既存のアカウントでログインするか、新しいアカウントを登録する
2. **URLを入力**: メインインターフェースでダウンロードするファイルのリンクを入力する
3. **保存パスを選択**: 参照ボタンをクリックして、ダウンロードしたファイルの保存場所を選択する
4. **ダウンロードを開始**: ダウンロードボタンをクリックしてダウンロードを開始する
5. **ダウンロード制御**: 一時停止/再開/キャンセルボタンを使用してダウンロードプロセスを制御する

### プロジェクト構造
```
MyDownloader/
├── main.cpp              // アプリケーションエントリポイント
├── mainwindow.h          // メインウィンドウヘッダーファイル
├── mainwindow.cpp        // メインウィンドウ実装
├── login.h               // ログインウィンドウヘッダーファイル
├── login.cpp             // ログインウィンドウ実装
├── signup.h              // 登録ウィンドウヘッダーファイル
├── signup.cpp            // 登録ウィンドウ実装
├── dialog.h              // 認証コードダイアログヘッダーファイル
├── dialog.cpp            // 認証コードダイアログ実装
├── database.h            // データベース操作ヘッダーファイル
├── database.cpp          // データベース操作実装
├── resource.qrc          // リソースファイル
├── MyDownloader.pro      // プロジェクトファイル
└── README.md             // プロジェクト説明ドキュメント
```

### 注意事項
1. ネットワーク接続が正常であることを確認する
2. 有効なURLリンクを入力する
3. 十分なストレージスペースがあることを確認する
4. プログラムはQtランタイムライブラリを必要とする

### 著作権情報
© 2025 重庆大学大数据与软件学院软件工程一班姚沛帆. 全著作権所有.