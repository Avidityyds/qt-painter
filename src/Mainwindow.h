#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPen>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected: //事件處理函數習慣用protected，比public更安全封裝且子類別也可以訪問
    void paintEvent(QPaintEvent *event); //處理繪圖事件
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:  //同樣是private但可以與signal連結 //建議不要以on_命名，會跳錯誤ex:on_actionLoad_triggered
    void actionLoad_triggered();
    void actionSave_triggered();
    void actionClear_triggered();
    void setPenColor();
    void setPenWidth();

private: //需要用到的變數設在這
    Ui::MainWindow *ui;
    QImage image; //存放當前的畫布圖像
    QPoint lastPoint; //記錄上一次滑鼠位置
    QPen pen; //設定畫筆的顏色和寬度
    bool drawing; //記錄是否正在繪圖
};
#endif // MAINWINDOW_H
