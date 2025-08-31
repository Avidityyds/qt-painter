#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QPainter>
#include <QFileDialog> //跳出用來讓user open、save file的對話框
#include <QColorDialog> //跳出用來讓user選顏色的對話框
#include <QInputDialog> //跳出用來獲取用戶輸入or選擇值的對話框

MainWindow::MainWindow(QWidget *parent)
    //初始化變數
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , drawing(false) //預設沒在畫畫
{
    ui->setupUi(this);

    setWindowTitle("小畫家");//設定視窗標題

    //signal and slots連接
    connect(ui->actionLoad, &QAction::triggered, this, &MainWindow::actionLoad_triggered);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::actionSave_triggered);
    connect(ui->actionClear, &QAction::triggered, this, &MainWindow::actionClear_triggered);
    connect(ui->actionSetPenColor, &QAction::triggered, this, &MainWindow::setPenColor);
    connect(ui->actionSetPenWidth, &QAction::triggered, this, &MainWindow::setPenWidth);

    //設定畫筆初始顏色和寬度
    pen.setColor(Qt::black);
    pen.setWidth(2);

    //創建一個空白圖片
    image = QImage(this->size(), QImage::Format_ARGB32);//創建一個跟視窗同尺寸的空白圖片，格式為ARGB32
    image.fill(Qt::white);//將圖片填充為白色
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)//每次update()會跳到paintEvent更新介面
{
    QPainter painter(this);//創建painter物件，繪製目標為當前視窗
    painter.drawImage(0, 0, image);//將圖片繪製在視窗的原點位置
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) { //是否左鍵按下//button()只回傳單個按鈕狀態所以用==即可
        lastPoint = event->pos(); //記錄按下時的滑鼠位置
        drawing = true; //按下左鍵代表開始繪畫
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (drawing && (event->buttons() & Qt::LeftButton)) { //是否正在繪畫且左鍵按住//buttons()回傳多個按鈕的狀態,用＆看代表左鍵的位元是否為1
        QPainter painter(&image); //創建painter物件，繪製目標為image
        painter.setPen(pen); //設置畫筆
        painter.drawLine(lastPoint, event->pos()); //繪製從上一次位置到當前滑鼠位置的線條
        lastPoint = event->pos(); //更新最後滑鼠位置
        update(); //更新視窗
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && drawing) { //是否左鍵放開且正在繪畫
        drawing = false; //放開左鍵代表結束繪畫
    }
}

void MainWindow::actionLoad_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Image", "", "Image Files (*.png *.jpg)");
    if (!fileName.isEmpty()) { //是否選擇了文件
        image.load(fileName); //加載選擇的圖片文件
        update(); //更新視窗
    }
}

void MainWindow::actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save Image", "", "PNG (*.png);;JPEG (*.jpg *.jpeg);;All Files (*)");
    if (!fileName.isEmpty()) { //是否選擇了文件路徑
        image.save(fileName); //保存當前圖片
    }
}

void MainWindow::actionClear_triggered()
{
    image.fill(Qt::white); //將圖片填充為白色(代表清除視窗)
    update(); //更新視窗
}

void MainWindow::setPenColor()
{
    QColor newColor = QColorDialog::getColor(pen.color(), this);
    if (newColor.isValid()) //判斷選擇的顏色是否可選
        pen.setColor(newColor); //設置畫筆顏色為選擇的顏色
}

void MainWindow::setPenWidth()
{
    bool ok; //用來接收user是否點擊ok按鈕
    int newWidth = QInputDialog::getInt(this, "Pen Width", "Select pen width:", pen.width(), 1, 50, 1, &ok); //打開輸入對話框，輸入畫筆寬度，範圍從 1 到 50
    if (ok)
        pen.setWidth(newWidth); //設置畫筆寬度為選擇的寬度
}
