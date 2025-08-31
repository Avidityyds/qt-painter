# Qt 小畫家 (Mini Painter)

一個使用 **Qt Widgets** 開發的輕量小畫家專案。支援滑鼠自由繪圖、載入/儲存圖片、清除畫布、調整畫筆顏色與粗細。

🎥 Demo 影片：[YouTube](https://youtu.be/7vUoPLrOI60)

---

## ✨ 功能
- 以滑鼠在視窗上自由繪圖  
  （左鍵按住拖曳：畫線；放開：結束筆畫）
- 載入現有圖片檔（PNG、JPG）
- 儲存目前畫布為圖片（PNG、JPG、JPEG）
- 一鍵清除畫布
- 選擇畫筆顏色與畫筆寬度

---

## 📂 專案結構
painter.pro # qmake 專案檔   
src/main.cpp # 進入點  
src/MainWindow.h # 主視窗類別宣告  
src/MainWindow.cpp # 主視窗邏輯 (繪圖/事件/功能)  
ui/MainWindow.ui # 視覺化介面 (Qt Designer)  
README.md # 說明文件  

---
