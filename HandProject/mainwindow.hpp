#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <player.hpp>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void updatePlayerUI(QImage img);
    void updateBackgroundUI(QImage img);
    void updateHistogramUI(QImage img);
    void updateMouseUI(QImage img);
    void updateArrowUI(QImage img);
    void updatePercentUI(int per,double fps);
    void updateHandUI(int lr);
    void updateNumUI(int num);
    void updateVideoStop(bool flagVideoStop);
    void updateMouseCtrl(int ctrl);

    void on_show_per_cb_stateChanged(int arg1);

    void on_sub_bg_cb_stateChanged(int arg1);

    void on_equal_his_cb_stateChanged(int arg1);

    void on_draw_his_cb_stateChanged(int arg1);

    void on_ctrl_mouse_cb_stateChanged(int arg1);

    void on_ctrl_arrow_cb_stateChanged(int arg1);

    void on_change_bg_btn_clicked();

    void on_start_program_btn_clicked();

    void on_start_process_btn_clicked();

    void on_browser_btn_clicked();

    void on_waitkey_sl_valueChanged(int value);

    void on_waitkey_sl_sliderMoved(int position);

    void clearWindows();

private:
    Ui::MainWindow *ui;
    Player* myPlayer;
};

#endif // MAINWINDOW_H
