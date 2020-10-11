# -*- coding:utf-8 -*-
###########################################################
# OpenCV example
#
# 轮廓检测
#
# 主要函数：cvFindContours, cvDrawContours
#
# By ChaiShushan 2008
###########################################################
 
import sys
 
# 导入OpenCV模块
 
from opencv.cv import *
from opencv.highgui import *
 
if __name__ == '__main__':
 
    # 声明IplImage指针
 
    pImg = None;
    pContourImg = None;
 
    storage = cvCreateMemStorage(0);
    contour = None;
    mode = CV_RETR_EXTERNAL;
 
    if len(sys.argv) == 3 and sys.argv[2] == "all":
        mode = CV_RETR_CCOMP
 
    # 创建窗口
 
    cvNamedWindow("src", 1)
    cvNamedWindow("contour",1)
 
    # 载入图像，强制转化为Gray
 
    if len(sys.argv) >= 2:
 
        pImg = cvLoadImage(sys.argv[1], 0)
        if not pImg: sys.exit(-1)
 
        cvShowImage( "src", pImg );
 
        # 为轮廓显示图像申请空间
        # 3通道图像，以便用彩色显示
 
        pContourImg = cvCreateImage(cvGetSize(pImg),IPL_DEPTH_8U,3);
 
        # copy source image and convert it to BGR image
 
        cvCvtColor(pImg, pContourImg, CV_GRAY2BGR);
 
        # 查找contour
 
        n, contour = cvFindContours( pImg, storage, sizeof_CvContour,
            mode, CV_CHAIN_APPROX_SIMPLE);
 
    else:
 
        # 销毁窗口
 
        cvDestroyWindow( "src" );
        cvDestroyWindow( "contour" );
        cvReleaseMemStorage(storage);
        sys.exit(-1)
 
    # 将轮廓画出
 
    cvDrawContours(pContourImg, contour, CV_RGB(255,0,0), CV_RGB(0, 0, 255),
        2, 2, 8);
 
    # 显示图像
 
    cvShowImage( "contour", pContourImg );
    cvWaitKey(0);
 
    # 销毁窗口
 
    cvDestroyWindow( "src" );
    cvDestroyWindow( "contour" );
 
    # 释放图像
 
    cvReleaseImage( pImg );
    cvReleaseImage( pContourImg );
 
    cvReleaseMemStorage(storage);
 
    sys.exit(0)