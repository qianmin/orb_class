#ifndef ORB_H
#define ORB_H
#include <QMainWindow>
#include<QImage>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include<QTextCodec>
#include<QMessageBox>
#include<QTimer>
#include<QDebug>
#include<QFileDialog>
#include<QtConcurrent> //要记得添加该头文件
using namespace cv;
using namespace std;

class orb
{
public:
    orb(QString template0,QString template1,QString template2,QString template3,QString template4,QString template5);
    //图片路径数据
    QString templateimg[6];
    QString target;
    //匹配结果数据
    int flag[6];
    int flag_end=0;
    //匹配结果数据
    double result[6];
    Mat matched_img;
    QString matched_type;
    //函数
    void orb_match_0();
    void orb_match_1();
    void orb_match_2();
    void orb_match_3();
    void orb_match_4();
    void orb_match_5();
    //分步函数
    void reset();
    void orb_sametime_match();
    void judge_finished_match();//结束了返回1
    void get_type();
    void orb_img();
    //总函数
    void run_once(QString input_path);
};

#endif // ORB_H
