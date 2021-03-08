#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include <QApplication>
#include <QCoreApplication>
#include<QDebug>
#include<QDir>
#include<QFileDialog>
#include<QMainWindow>
#include<QObject>
#include<orb.h>
#include<iostream>
#include<time.h>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString t0="./template/A0.png";
    QString t1="./template/A1.png";
    QString t2="./template/A2.png";
    QString t3="./template/A3.png";
    QString t4="./template/A4.png";
    QString t5="./template/A5.png";
    orb b(t0,t1,t2,t3,t4,t5);
    for(int k=0;k<6;k++)
    {
        QString filename = QFileDialog::getOpenFileName(0,QObject::tr("Open Image"),".",QObject::tr("Image File (*.jpg *.png *.bmp)"));
        if(!(filename.isEmpty()))
        {
            qDebug()<<"选的文件是"<<filename;
            b.run_once(filename);
            clock_t start_time=clock();
            b.run_once(filename);
            clock_t end_time=clock();
            cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;//输出运行时间
            qDebug()<<"\n"<<"\n"<<"\n"<<"\n";
        }
    }
    a.quit();
    return 0;
}
