#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif


#include "orb.h"

orb::orb(QString template0,QString template1,QString template2,QString template3,QString template4,QString template5)
{
    templateimg[0]=template0;
    templateimg[1]=template1;
    templateimg[2]=template2;
    templateimg[3]=template3;
    templateimg[4]=template4;
    templateimg[5]=template5;
}
void orb::reset()
{
    for(int i=0;i<6;i++)//0,1,2,3,4,5
    {
        flag[i]=0;
        result[i]=0;
    }
    target="";
    matched_type="";
}
//五个函数
void orb::orb_match_0()
{
    Mat src1=cv::imread(templateimg[0].toStdString());
    Mat src2=cv::imread(target.toStdString());

    Ptr<ORB> orb = ORB::create();
    std::vector<KeyPoint> kp1, kp2;
    Mat des1, des2;
    orb->detect(src1,kp1);
    orb->detect(src2,kp2);
    orb->compute(src1,kp1,des1);
    orb->compute(src2,kp2,des2);
    //创建一个匹配点数组
    vector<DMatch> matches;
    //创建一个BFMatcher匹配器
    BFMatcher matcher (NORM_HAMMING);
    //调用matcher的match方法进行匹配
    matcher.match(des1, des2, matches);
    double min_dist=0, max_dist=0;//定义距离
    for (int i = 0; i < des1.rows; ++i)//遍历
    {
        double dist = matches[i].distance;
        if(dist<min_dist) min_dist = dist;
        if(dist>max_dist) max_dist = dist;
    }
    std::vector<DMatch> good_matches;
    qint32 num=0;
    for (int j = 0; j < des1.rows; ++j)
    {
        if (matches[j].distance <= max(2*min_dist, 30.0))
        {
            good_matches.push_back(matches[j]);
            num=num+1;
        }
    }
    qint32 all_num;
    for (int j = 0; j < des1.rows; ++j)
    {
        all_num=all_num+1;
    }
    double a,b,r;
    a=num;
    b=100;
    r=a/b;
    result[0]= r;
    flag[0]=1;
}
void orb::orb_match_1()
{
    Mat src1=cv::imread(templateimg[1].toStdString());

    Mat src2=cv::imread(target.toStdString());


    Ptr<ORB> orb = ORB::create();
    std::vector<KeyPoint> kp1, kp2;
    Mat des1, des2;
    orb->detect(src1,kp1);
    orb->detect(src2,kp2);

    orb->compute(src1,kp1,des1);
    orb->compute(src2,kp2,des2);
    //创建一个匹配点数组
    vector<DMatch> matches;
    //创建一个BFMatcher匹配器
    BFMatcher matcher (NORM_HAMMING);
    //调用matcher的match方法进行匹配
    matcher.match(des1, des2, matches);
    //第四步：遍历matches[]数组，找出匹配点的最大距离和最小距离，用于后面的匹配点筛选。
    double min_dist=0, max_dist=0;//定义距离
    for (int i = 0; i < des1.rows; ++i)//遍历
    {
        double dist = matches[i].distance;
        if(dist<min_dist) min_dist = dist;
        if(dist>max_dist) max_dist = dist;
    }
    std::vector<DMatch> good_matches;
    qint32 num=0;
    for (int j = 0; j < des1.rows; ++j)
    {
        if (matches[j].distance <= max(2*min_dist, 30.0))
        {
            good_matches.push_back(matches[j]);
            num=num+1;
        }
    }
    qint32 all_num;
    for (int j = 0; j < des1.rows; ++j)
    {
        all_num=all_num+1;
    }
    double a,b,r;
    a=num;
    b=100;
    r=a/b;
    result[1]= r;
    flag[1]=1;
}
void orb::orb_match_2()
{
    Mat src1=cv::imread(templateimg[2].toStdString());
    Mat src2=cv::imread(target.toStdString());

    Ptr<ORB> orb = ORB::create();
    std::vector<KeyPoint> kp1, kp2;
    Mat des1, des2;
    orb->detect(src1,kp1);
    orb->detect(src2,kp2);
    orb->compute(src1,kp1,des1);
    orb->compute(src2,kp2,des2);
    //创建一个匹配点数组
    vector<DMatch> matches;
    //创建一个BFMatcher匹配器
    BFMatcher matcher (NORM_HAMMING);
    //调用matcher的match方法进行匹配
    matcher.match(des1, des2, matches);
    //第四步：遍历matches[]数组，找出匹配点的最大距离和最小距离，用于后面的匹配点筛选。
    double min_dist=0, max_dist=0;//定义距离
    for (int i = 0; i < des1.rows; ++i)//遍历
    {
        double dist = matches[i].distance;
        if(dist<min_dist) min_dist = dist;
        if(dist>max_dist) max_dist = dist;
    }
    //第五步：根据最小距离，对匹配点进行筛选，
    std::vector<DMatch> good_matches;
    qint32 num=0;
    for (int j = 0; j < des1.rows; ++j)
    {
        if (matches[j].distance <= max(2*min_dist, 30.0))
        {
            good_matches.push_back(matches[j]);
            num=num+1;
        }
    }
    qint32 all_num;
    for (int j = 0; j < des1.rows; ++j)
    {
        all_num=all_num+1;
    }
    double a,b,r;
    a=num;
    b=100;
    r=a/b;

    result[2]= r;
    flag[2]=1;
}
void orb::orb_match_3()
{
    Mat src1=cv::imread(templateimg[3].toStdString());
    Mat src2=cv::imread(target.toStdString());

    Ptr<ORB> orb = ORB::create();
    std::vector<KeyPoint> kp1, kp2;
    Mat des1, des2;
    orb->detect(src1,kp1);
    orb->detect(src2,kp2);
    orb->compute(src1,kp1,des1);
    orb->compute(src2,kp2,des2);
    //创建一个匹配点数组
    vector<DMatch> matches;
    //创建一个BFMatcher匹配器
    BFMatcher matcher (NORM_HAMMING);
    //调用matcher的match方法进行匹配
    matcher.match(des1, des2, matches);
    //第四步：遍历matches[]数组，找出匹配点的最大距离和最小距离，用于后面的匹配点筛选。
    double min_dist=0, max_dist=0;//定义距离
    for (int i = 0; i < des1.rows; ++i)//遍历
    {
        double dist = matches[i].distance;
        if(dist<min_dist) min_dist = dist;
        if(dist>max_dist) max_dist = dist;
    }
    //第五步：根据最小距离，对匹配点进行筛选，
    std::vector<DMatch> good_matches;
    qint32 num=0;
    for (int j = 0; j < des1.rows; ++j)
    {
        if (matches[j].distance <= max(2*min_dist, 30.0))
        {
            good_matches.push_back(matches[j]);
            num=num+1;
        }
    }
    qint32 all_num;
    for (int j = 0; j < des1.rows; ++j)
    {
        all_num=all_num+1;
    }
    double a,b,r;
    a=num;
    b=100;
    r=a/b;

    result[3]= r;
    flag[3]=1;
}
void orb::orb_match_4()
{
    Mat src1=cv::imread(templateimg[4].toStdString());
    Mat src2=cv::imread(target.toStdString());

    Ptr<ORB> orb = ORB::create();
    std::vector<KeyPoint> kp1, kp2;
    Mat des1, des2;
    orb->detect(src1,kp1);
    orb->detect(src2,kp2);
    orb->compute(src1,kp1,des1);
    orb->compute(src2,kp2,des2);
    //创建一个匹配点数组
    vector<DMatch> matches;
    //创建一个BFMatcher匹配器
    BFMatcher matcher (NORM_HAMMING);
    //调用matcher的match方法进行匹配
    matcher.match(des1, des2, matches);
    //第四步：遍历matches[]数组，找出匹配点的最大距离和最小距离，用于后面的匹配点筛选。
    double min_dist=0, max_dist=0;//定义距离
    for (int i = 0; i < des1.rows; ++i)//遍历
    {
        double dist = matches[i].distance;
        if(dist<min_dist) min_dist = dist;
        if(dist>max_dist) max_dist = dist;
    }
    //第五步：根据最小距离，对匹配点进行筛选，
    std::vector<DMatch> good_matches;
    qint32 num=0;
    for (int j = 0; j < des1.rows; ++j)
    {
        if (matches[j].distance <= max(2*min_dist, 30.0))
        {
            good_matches.push_back(matches[j]);
            num=num+1;
        }
    }
    qint32 all_num;
    for (int j = 0; j < des1.rows; ++j)
    {
        all_num=all_num+1;
    }
    double a,b,r;
    a=num;
    b=100;
    r=a/b;

    result[4]= r;
    flag[4]=1;
}
void orb::orb_match_5()
{
    Mat src1=cv::imread(templateimg[0].toStdString());
    Mat src2=cv::imread(target.toStdString());

    Ptr<ORB> orb = ORB::create();
    std::vector<KeyPoint> kp1, kp2;
    Mat des1, des2;
    orb->detect(src1,kp1);
    orb->detect(src2,kp2);
    orb->compute(src1,kp1,des1);
    orb->compute(src2,kp2,des2);
    //创建一个匹配点数组
    vector<DMatch> matches;
    //创建一个BFMatcher匹配器
    BFMatcher matcher (NORM_HAMMING);
    //调用matcher的match方法进行匹配
    matcher.match(des1, des2, matches);
    //第四步：遍历matches[]数组，找出匹配点的最大距离和最小距离，用于后面的匹配点筛选。
    double min_dist=0, max_dist=0;//定义距离
    for (int i = 0; i < des1.rows; ++i)//遍历
    {
        double dist = matches[i].distance;
        if(dist<min_dist) min_dist = dist;
        if(dist>max_dist) max_dist = dist;
    }
    //第五步：根据最小距离，对匹配点进行筛选，
    std::vector<DMatch> good_matches;
    qint32 num=0;
    for (int j = 0; j < des1.rows; ++j)
    {
        if (matches[j].distance <= max(2*min_dist, 30.0))
        {
            good_matches.push_back(matches[j]);
            num=num+1;
        }
    }
    qint32 all_num;
    for (int j = 0; j < des1.rows; ++j)
    {
        all_num=all_num+1;
    }
    double a,b,r;
    a=num;
    b=100;
    r=a/b;

    result[5]= r;
    flag[5]=1;
    qDebug()<<"5_of_match_finished";
}

//总函数
void orb::orb_sametime_match()
{
    for(int i=0;i<6;i++)
    {
        orb::result[i]=-1;
    }
    QtConcurrent::run(this,&orb::orb_match_0);
    QtConcurrent::run(this,&orb::orb_match_1);
    QtConcurrent::run(this,&orb::orb_match_2);
    QtConcurrent::run(this,&orb::orb_match_3);
    QtConcurrent::run(this,&orb::orb_match_4);
    QtConcurrent::run(this,&orb::orb_match_5);
}
void orb::judge_finished_match()
{

    while(1)
    {
        int tmp=0;
        for(int i=0;i<6;i++)
        {
            tmp=tmp+orb::flag[i];
        }
        if(tmp==6)
            break;
    }
    qDebug()<<"match5 end,return 1";
    flag_end=1;
}
void orb::get_type()
{
    if(flag_end)
    {
        double tmp_score=-1;
        int tmp_type=0;
        for(int i=0;i<6;i++)
        {
            qDebug()<<"result"<<i<<result[i];
            if(tmp_score<result[i])
            {
                tmp_score=result[i];
                tmp_type=i;
            }
        }
        //double转qstring,保留1位小数
        orb::matched_type=QString::number(tmp_type, 'f', 0);
    }
    qDebug()<<"匹配的结果是："<<matched_type;
}
void orb::run_once(QString input_path)
{


    qDebug()<<"target"<<input_path;
    reset();
    target=input_path;
    qDebug()<<"reset";
    orb_sametime_match();
    qDebug()<<"orb_sametime_match_finished";
    judge_finished_match();
    qDebug()<<"judge_finished_match_finished";
    get_type();
    qDebug()<<"get_type";
}
