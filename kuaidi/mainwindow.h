#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void createMap();
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QMap<QString,QString> m_companyMap;
};

#endif // MAINWINDOW_H
