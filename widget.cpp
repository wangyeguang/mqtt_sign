#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include "sign.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString ds = ui->lineEdit_deviceSecret->text();
    QString pk = ui->lineEdit_productKey->text();
    QString dn = ui->lineEdit_deviceName->text();
    QString ts = ui->lineEdit_timestamp->text();
    QString ci = ui->lineEdit_clientID->text();
    QString sm = ui->comboBox_method->currentText();

    if (pk == nullptr || pk == "" || dn == nullptr || dn == "" || ds == nullptr || ds == "" || ci == nullptr || ci == "")
    {
        QMessageBox::warning(this, tr("参数缺失"),
                                         tr("productKey,deviceName,deviceSecret,clientId can not be empty\n"));
        return ;
    }

    QString contentStr = "";
    if(ts == nullptr || ts == "")
    {
        contentStr = "clientId"+ci+"deviceName"+dn+"productKey"+pk;
    }
    else {
        contentStr = "clientId"+ci+"deviceName"+dn+"productKey"+pk+"timestamp"+ts;
    }
    QString sign="";
    if (sm == "hmacmd5") {
        //                sign = hex_hmac_md5(ds, contentStr);
    } else if (sm == "hmacsha1") {
        sign = hmacSha1(ds.toLatin1(), contentStr.toLatin1());
    } else {
        QMessageBox::warning(this,tr("参数错误"),tr("method is invalid"));
    }
    ui->lineEdit_password->setText(sign.toUpper());
}
