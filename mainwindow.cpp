#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(1200, 800));
    ui->listWidget->addItem("2");
    ui->listWidget->addItem("3");
    ui->listWidget->addItem("4");
    ui->listWidget->addItem("5");
    ui->listWidget->addItem("6");
    ui->listWidget->addItem("7");
    ui->listWidget->addItem("8");
    ui->listWidget->addItem("9");
    ui->listWidget->addItem("10");
    ui->listWidget->addItem("11");
    ui->listWidget->addItem("12");

    ui->listWidget->item(0)->setForeground(Qt::white);
    ui->listWidget->item(1)->setForeground(Qt::white);
    ui->listWidget->item(2)->setForeground(Qt::white);
    ui->listWidget->item(3)->setForeground(Qt::white);
    ui->listWidget->item(4)->setForeground(Qt::white);
    ui->listWidget->item(5)->setForeground(Qt::white);
    ui->listWidget->item(6)->setForeground(Qt::white);
    ui->listWidget->item(7)->setForeground(Qt::white);
    ui->listWidget->item(8)->setForeground(Qt::white);
    ui->listWidget->item(1)->setForeground(Qt::white);
    ui->listWidget->item(9)->setForeground(Qt::white);
    ui->listWidget->item(10)->setForeground(Qt::white);

    ui->listWidget_2->addItem("2");
    ui->listWidget_2->addItem("3");
    ui->listWidget_2->addItem("4");
    ui->listWidget_2->addItem("5");
    ui->listWidget_2->addItem("6");
    ui->listWidget_2->addItem("7");
    ui->listWidget_2->addItem("8");
    ui->listWidget_2->addItem("9");
    ui->listWidget_2->addItem("10");
    ui->listWidget_2->addItem("11");
    ui->listWidget_2->addItem("12");

    ui->listWidget_2->item(0)->setForeground(Qt::white);
    ui->listWidget_2->item(1)->setForeground(Qt::white);
    ui->listWidget_2->item(2)->setForeground(Qt::white);
    ui->listWidget_2->item(3)->setForeground(Qt::white);
    ui->listWidget_2->item(4)->setForeground(Qt::white);
    ui->listWidget_2->item(5)->setForeground(Qt::white);
    ui->listWidget_2->item(6)->setForeground(Qt::white);
    ui->listWidget_2->item(7)->setForeground(Qt::white);
    ui->listWidget_2->item(8)->setForeground(Qt::white);
    ui->listWidget_2->item(1)->setForeground(Qt::white);
    ui->listWidget_2->item(9)->setForeground(Qt::white);
    ui->listWidget_2->item(10)->setForeground(Qt::white);

    ui->listWidget_3->addItem("2");
    ui->listWidget_3->addItem("3");
    ui->listWidget_3->addItem("4");
    ui->listWidget_3->addItem("5");

    ui->listWidget_3->item(0)->setForeground(Qt::white);
    ui->listWidget_3->item(1)->setForeground(Qt::white);
    ui->listWidget_3->item(2)->setForeground(Qt::white);
    ui->listWidget_3->item(3)->setForeground(Qt::white);


}

MainWindow::~MainWindow()
{
    delete ui;
    delete gameWindow;
}

void MainWindow::on_pushButton_clicked()
{
    hide();
    unsigned row=ui->listWidget->currentItem()->text().toInt();
    unsigned column=ui->listWidget_2->currentItem()->text().toInt();
    unsigned nbColor=ui->listWidget_3->currentItem()->text().toInt();

    this->gameWindow=new class gameWindow(this,row,column,nbColor);
    gameWindow->show();
    int result = gameWindow->exec();
    if(result==QDialog::Rejected){
        show();
    }
}
