# Qt 小畫家 (Mini Painter)

一個使用 **Qt Widgets** 開發的輕量小畫家專案。支援滑鼠自由繪圖、載入/儲存圖片、清除畫布、調整畫筆顏色與粗細。

▶️ Demo 影片：[YouTube](https://youtu.be/7vUoPLrOI60)

---

## 軟體環境
- 直接安裝 **Qt Creator**（內含 Qt SDK）  
  下載頁：<https://www.qt.io/download>
- 建議版本：Qt 6.x（Windows / macOS / Linux 皆可）
- 本專案採 **qmake** 專案格式，開啟 `painter.pro` 即可建置與執行

**使用方式：**
1. 開啟 Qt Creator → **File → Open File or Project…**  
2. 選擇專案根目錄下的 `painter.pro`  
3. 選擇一組 Kit（例如 Qt 6.x + MinGW）  
4. 點 **Run** 即可執行

---

## 📂 專案結構
```text
MiniPainter/
├── painter.pro              # qmake 專案檔   
├── src/                     # 程式碼
│   ├── main.cpp             # 進入點 (建立 QApplication / 主視窗)
│   ├── MainWindow.h         # 主視窗類別宣告
│   └── MainWindow.cpp       # 主視窗邏輯 (繪圖/事件/功能)
├── ui/                      # 介面設計 (Qt Designer)
│   └── MainWindow.ui
├── README.md                # 專案說明
└── LICENSE                  # 授權條款
