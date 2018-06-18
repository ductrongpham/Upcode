#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    myPlayer = new Player();
    QObject::connect(myPlayer, SIGNAL(processedImage(QImage)),
                              this, SLOT(updatePlayerUI(QImage)));
    QObject::connect(myPlayer, SIGNAL(processedBackground(QImage)),
                              this, SLOT(updateBackgroundUI(QImage)));
    QObject::connect(myPlayer, SIGNAL(processedArrow(QImage)),
                              this, SLOT(updateArrowUI(QImage)));
    QObject::connect(myPlayer, SIGNAL(processedMouse(QImage)),
                              this, SLOT(updateMouseUI(QImage)));
    QObject::connect(myPlayer, SIGNAL(processedPercent(int,double)),
                              this, SLOT(updatePercentUI(int,double)));
    QObject::connect(myPlayer, SIGNAL(processedHistogram(QImage)),
                              this, SLOT(updateHistogramUI(QImage)));
    ui->setupUi(this);
}

void MainWindow::updatePlayerUI(QImage img)
{
    if (!img.isNull())
    {
        ui->img_lbl->setAlignment(Qt::AlignCenter);
        ui->img_lbl->setPixmap(QPixmap::fromImage(img).scaled(ui->img_lbl->size(), Qt::KeepAspectRatio, Qt::FastTransformation));
    }
}

void MainWindow::updateBackgroundUI(QImage img)
{
    if (!img.isNull())
    {
        ui->img_bg_lbl->setAlignment(Qt::AlignCenter);
        ui->img_bg_lbl->setPixmap(QPixmap::fromImage(img).scaled(ui->img_bg_lbl->size(), Qt::KeepAspectRatio, Qt::FastTransformation));
    }
}

void MainWindow::updateHistogramUI(QImage img)
{
    if (!img.isNull())
    {
        ui->img_his_lbl->setAlignment(Qt::AlignCenter);
        ui->img_his_lbl->setPixmap(QPixmap::fromImage(img).scaled(ui->img_his_lbl->size(), Qt::KeepAspectRatio, Qt::FastTransformation));
    }
}

void MainWindow::updateMouseUI(QImage img)
{
    if (!img.isNull())
    {
        ui->ctrl_mouse_lbl->setAlignment(Qt::AlignCenter);
        ui->ctrl_mouse_lbl->setPixmap(QPixmap::fromImage(img).scaled(ui->ctrl_mouse_lbl->size(), Qt::KeepAspectRatio, Qt::FastTransformation));
    }
}

void MainWindow::updateArrowUI(QImage img)
{
    if (!img.isNull())
    {
        ui->ctrl_arrow_lbl->setAlignment(Qt::AlignCenter);
        ui->ctrl_arrow_lbl->setPixmap(QPixmap::fromImage(img).scaled(ui->ctrl_arrow_lbl->size(), Qt::KeepAspectRatio, Qt::FastTransformation));
    }
}
void MainWindow::updatePercentUI(int per,double fps)
{
        ui->print_percent_lbl->setAlignment(Qt::AlignCenter);
        QString number;
        number = QString::number(per);
        number.append(" %");
        number.append(QString::number(fps));
        number.append(" fps");
        ui->print_percent_lbl->setText(number);
}

void MainWindow::on_show_per_cb_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked){
        myPlayer->flag4 = true;
    }else{
        myPlayer->flag4 = false;
    }
}

void MainWindow::on_sub_bg_cb_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked){
        myPlayer->flag0 = true;
    }else{
        myPlayer->flag0 = false;
    }
}

void MainWindow::on_equal_his_cb_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked){
        myPlayer->flag2 = true;
    }else{
        myPlayer->flag2 = false;
    }
}

void MainWindow::on_draw_his_cb_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked){
        myPlayer->flag3 = true;
    }else{
        myPlayer->flag3 = false;
    }
}

void MainWindow::on_ctrl_mouse_cb_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked){
        myPlayer->flag5 = true;
    }else{
        myPlayer->flag5 = false;
    }
}

void MainWindow::on_ctrl_arrow_cb_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked){
        myPlayer->flag6 = true;
    }else{
        myPlayer->flag6 = false;
    }
}

void MainWindow::on_change_bg_btn_clicked()
{
    myPlayer->flag1 = !myPlayer->flag1;
}

void MainWindow::on_start_program_btn_clicked()
{
    if (myPlayer->isStopped())
    {
        myPlayer->Play();
        myPlayer->flagClose = false;
        ui->start_program_btn->setText(tr("Stop Program"));
    }else
    {
        myPlayer->Stop();
        myPlayer->flagClose = true;
        ui->start_program_btn->setText(tr("Play Program"));
    }
}

void MainWindow::on_start_process_btn_clicked()
{
    if(myPlayer->flagOn == 0)
        myPlayer->flagOn = 1;
    else
        myPlayer->flagOn = 0;
}

MainWindow::~MainWindow()
{
    delete myPlayer;
    delete ui;
}
