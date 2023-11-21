#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:

    void on_actionQuit_triggered();

    void on_actionAbout_Me_triggered();

    void on_colorWhite_clicked();

    void on_colorBlack_clicked();

    void on_colorRed_clicked();

    void on_colorGreen_clicked();

    void on_colorPurple_clicked();

    void on_colorBlue_clicked();

    void on_toolCircle_clicked();

    void on_toolPen_clicked();

    void on_fontSize_valueChanged(int arg1);

    void on_toolSquare_clicked();

    void on_toolLine_clicked();

    void on_toolEraser_clicked();

    void on_toolSpray_clicked();

    void on_toolText_clicked();

    void on_actionNew_triggered();

    void on_actionSave_as_Image_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
