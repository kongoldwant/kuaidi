#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "jsondata.h"
#include "getinfo.h"
//http://baidu.kuaidi100.com/query?type=ems&postid=1015898666405

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createMap();
    ui->comboBox->addItem("快递公司");
    foreach (const QString &str, m_companyMap.keys())
        ui->comboBox->addItem(str);
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_clicked()
{
    QString order=ui->lineEdit->text();
    QString company=ui->comboBox->currentText();
    company=m_companyMap[company];
    QString weburl="http://www.kuaidi100.com/query?type="+company+"&postid="+order;
    qDebug()<<weburl;
    getInfo *info=new getInfo(weburl);
    if(info->checkStatus())
    {
        QList<std::tuple<QString,QString>> infoList=info->insertIntoYuple();
        QList<std::tuple<QString,QString>>::iterator it;
        for(it=infoList.end();it != infoList.begin(); --it)
        {
            ui->listWidget->insertItem(0,std::get<0>(*(it-1))+"  "+std::get<1>(*(it-1)));
        }
    }
    else
    {
        ui->listWidget->insertItem(0,info->getMsg());
    }

    delete info;
}

void MainWindow::createMap()
{
    m_companyMap["EMS"]="ems";
    m_companyMap["顺丰"]="shunfeng";
    m_companyMap["宅急送"]="zhaijisong";
    m_companyMap["申通"]="shentong";
    m_companyMap["圆通"]="yuantong";
    m_companyMap["中通"]="zhongtong";
    m_companyMap["韵达"]="yunda";
    m_companyMap["天天"]="tiantian";
    m_companyMap["汇通"]="huitong";
    m_companyMap["全峰"]="quanfeng";
    m_companyMap["德邦"]="debang";
}
