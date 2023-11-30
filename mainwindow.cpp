#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QDebug>
#include <iostream>
#include <QFileDialog>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_actionNew_triggered() {
    QMainWindow *newWindow = new QMainWindow(this);

    newWindow->show();
}

void MainWindow::on_actionSave_as_Image_triggered() {
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save Image"), "", tr("PNG Image (*.png);;All Files (*)"));
    if (!filePath.isEmpty()) {
        QSize imageSize = ui->widget->size();
        QPixmap widgetPixmap = ui->widget->renderPixmap();

        QPixmap backgroundPixmap(imageSize);
        backgroundPixmap.fill(Qt::black);

        QPainter painter(&backgroundPixmap);
        painter.drawPixmap(0, 0, widgetPixmap);

        backgroundPixmap.save(filePath);
        qDebug() << "Image saved to: " << filePath;
    } else {
        qDebug() << "Image save canceled.";
    }
}


void MainWindow::on_actionQuit_triggered() {
    QCoreApplication::quit();
}


void MainWindow::on_actionAbout_Me_triggered() {
    QMessageBox aboutMeBox;

    aboutMeBox.setWindowTitle("About Painty");

    aboutMeBox.setText("<h3>Painty</h3>"
                       "<p>Here's a little drawing tool.<br> This was a good exercise to learn more.</p><br>"
                       "GitHub: <a href=\"https://github.com/daninouai\">daninouai</a><br>"
                       "Website: <a href=\"https://danirahimi.ir\">danirahimi.ir</a>");

    aboutMeBox.setStandardButtons(QMessageBox::Ok);

    aboutMeBox.exec();
}

void MainWindow::on_colorWhite_clicked() {
    GLWidget glWidget;
    glWidget.changeColor(1.0, 1.0, 1.0);
}


void MainWindow::on_colorBlack_clicked() {
    GLWidget glWidget;
    glWidget.changeColor(0.0, 0.0, 0.0);
}


void MainWindow::on_colorRed_clicked() {
    GLWidget glWidget;
    glWidget.changeColor(1.0, 0.0, 0.0);
}


void MainWindow::on_colorGreen_clicked() {
    GLWidget glWidget;
    glWidget.changeColor(0.0, 1.0, 0.0);
}


void MainWindow::on_colorPurple_clicked() {
    GLWidget glWidget;
    glWidget.changeColor(1.0, 0.0, 1.0);
}


void MainWindow::on_colorBlue_clicked() {
    GLWidget glWidget;
    glWidget.changeColor(0.0, 0.0, 1.0);
}


void MainWindow::on_toolCircle_clicked() {
    GLWidget glWidget;
    glWidget.chanageMode(false, true, false, false, false, false, false, false);
}


void MainWindow::on_toolPen_clicked() {
    GLWidget glWidget;
    glWidget.chanageMode(true, false, false, false, false, false, false, false);
}


void MainWindow::on_fontSize_valueChanged(int arg1) {
    GLWidget glWidget;
    glWidget.changeFontSize(arg1);
}


void MainWindow::on_toolSquare_clicked() {
    GLWidget glWidget;
    glWidget.chanageMode(false, false, true, false, false, false, false, false);
}


void MainWindow::on_toolLine_clicked() {
    GLWidget glWidget;
    glWidget.chanageMode(false, false, false, true, false, false, false, false);
}


void MainWindow::on_toolEraser_clicked() {
    GLWidget glWidget;
    glWidget.chanageMode(false, false, false, false, true, false, false, false);
}


void MainWindow::on_toolSpray_clicked() {
    GLWidget glWidget;
    glWidget.chanageMode(false, false, false, false, false, true, false, false);
}


void MainWindow::on_toolText_clicked() {
    GLWidget glWidget;
    glWidget.chanageMode(false, false, false, false, false, false, true, false);
}


void MainWindow::on_toolSelection_clicked() {
    GLWidget glWidget;
    glWidget.chanageMode(false, false, false, false, false, false, false, true);
}


void MainWindow::on_actionExport_as_Json_triggered() {
    GLWidget glWidget;

    QString filePath = QFileDialog::getSaveFileName(this, tr("Export File"), "",
                                                    tr("Json Format (*.json);;All Files (*)"));
    if (!filePath.isEmpty()) {
        glWidget.SaveExportFile(filePath.toStdString());
    }

}


void MainWindow::on_actionImport_triggered() {
    GLWidget glWidget;

    QString filePath = QFileDialog::getOpenFileName(this, tr("Import File"), "", tr("Json Format (*.json);"));
    if (!filePath.isEmpty()) {
        glWidget.ImportFile(filePath.toStdString());
    }
}

