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
    QObject::connect(myPlayer, SIGNAL(processedHand(int)),
                              this, SLOT(updateHandUI(int)));
    QObject::connect(myPlayer, SIGNAL(processedMouseCtrl(int)),
                              this, SLOT(updateMouseCtrl(int)));
    QObject::connect(myPlayer, SIGNAL(processedNum(int)),
                              this, SLOT(updateNumUI(int)));
    QObject::connect(myPlayer, SIGNAL(processVideoStop(bool)),
                              this, SLOT(updateVideoStop(bool)));
    ui->setupUi(this);
}
// check update UI______________________________
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
        number.append(" % ");
        number.append(QString::number(fps));
        number.append(" fps");
        ui->print_percent_lbl->setText(number);
}
void MainWindow::updateNumUI(int num)
{
        ui->print_num_finger_lbl->setAlignment(Qt::AlignCenter);
        QString number;
        number = QString::number(num);
        ui->print_num_finger_lbl->setText(number);
}

void MainWindow::updateHandUI(int lr)
{
    switch(lr){
        case 1:ui->hand_lbl->setText("------>");break;
        case 0: ui->hand_lbl->setText("---0---");break;
        case -1:ui->hand_lbl->setText("<------");break;
    }
}

void MainWindow::updateMouseCtrl(int ctrl)
{
    switch(ctrl){
        case 3:ui->mouse_ctrl_lbl->setText("Click Left");break;
        case 1:ui->mouse_ctrl_lbl->setText("---MOVE---");break;
        case 4:ui->mouse_ctrl_lbl->setText("Click Right");break;
        case 5:ui->mouse_ctrl_lbl->setText("Long Click");break;
        case 0:ui->mouse_ctrl_lbl->setText("---0---");break;
    }
}

void MainWindow::updateVideoStop(bool flagVideoStop){
    ui->start_process_btn->setText(tr("Play Process"));
}

//_________________________________________________
//check event component____________________________

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
    if( myPlayer->resetProcess !=0){
        myPlayer->flag1 = !myPlayer->flag1;
    }
}

void MainWindow::on_start_program_btn_clicked()
{
    if (myPlayer->isStopped())
    {

        myPlayer->ipComputer = ui->text_ip->toPlainText().toStdString();
        myPlayer->Play();
        myPlayer->flagClose = false;
        ui->start_program_btn->setText(tr("Stop Program"));
    }
    else
    {
        if(myPlayer->flagPause){
            ui->pause_btn->setText(tr("Pause"));
            myPlayer->flagPause = false;
        }
        myPlayer->Stop();
        myPlayer->flagClose = true;
        myPlayer->resetProcess = 0;
        myPlayer->flagOn = 0;
        myPlayer->flagReset = true;
        clearWindows();
        ui->start_process_btn->setText(tr("Play process"));
        ui->start_program_btn->setText(tr("Play Program"));
    }
}

void MainWindow::on_start_process_btn_clicked()
{
    if(myPlayer->isReseted() == (-1)){
        if(myPlayer->flagPause){
            ui->pause_btn->setText(tr("Pause"));
            myPlayer->flagPause = false;
        }
        clearWindows();
        myPlayer->flagOn = 0;
        myPlayer->flagReset = true;
        myPlayer->resetProcess = 0;
        ui->start_process_btn->setText(tr("Play Process"));
    }
    if(myPlayer->isReseted() == (1)){
        myPlayer->flagOn = 1;
        myPlayer->flagReset = false;
        myPlayer->resetProcess = 0;
        ui->start_process_btn->setText(tr("Reset Process"));
    }
}

MainWindow::~MainWindow()
{
    delete myPlayer;
    delete ui;
}

void MainWindow::on_browser_btn_clicked()
{
    if(myPlayer->flagPause){
        ui->pause_btn->setText(tr("Pause"));
        myPlayer->flagPause = false;
    }
    myPlayer->Stop();
    myPlayer->flagClose = true;
    myPlayer->resetProcess = 0;
    myPlayer->flagOn = 0;
    myPlayer->WaitKeyOS(2000);
    QString filename = QFileDialog::getOpenFileName(this,
                                          tr("Open Video"), ".",
                                          tr("Video Files (*.avi *.mpg *.mp4)"));
    if (!filename.isEmpty()){
            myPlayer->fileName = filename.toStdString();
            myPlayer->flagVideo = true;
            ui->start_process_btn->setText(tr("Play process"));
            ui->start_program_btn->setText(tr("Play Program"));
    }
}
//_____________________________________________________________

void MainWindow::on_waitkey_sl_valueChanged(int value)
{
    myPlayer->time_wait = value;
}

void MainWindow::on_waitkey_sl_sliderMoved(int position)
{
    ui->value_slider_lbl->setText(QString::number(position));
}

void MainWindow::clearWindows(){
    QPixmap pm_black;
    pm_black.fill(QColor(0, 0, 0));
    ui->img_bg_lbl->setPixmap(pm_black);
    ui->img_his_lbl->setPixmap(pm_black);
    ui->ctrl_mouse_lbl->setPixmap(pm_black);
    ui->ctrl_arrow_lbl->setPixmap(pm_black);
    ui->img_lbl->setPixmap(pm_black);
}


void MainWindow::on_pause_btn_clicked()
{
    if(myPlayer->isReseted() == (-1)){
        if(myPlayer->flagPause == false){
            ui->pause_btn->setText(tr("Replay"));
            myPlayer->flagPause = true;
        }else{
            ui->pause_btn->setText(tr("Pause"));
            myPlayer->flagPause = false;
        }
    }
}

