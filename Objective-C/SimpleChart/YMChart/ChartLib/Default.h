//
//  Default.h
//  YMChart
//
#ifndef Default_h
#define Default_h
    //数据:坐标的起始/结束坐标
#define DATA_X_MIN 0    //X轴默认的最小坐标值
#define DATA_X_MAX 100  //X轴默认的最大坐标值
#define DATA_Y_MIN 22   //Y轴默认的最小坐标值
#define DATA_Y_MAX 50   //Y轴默认的最大坐标值

    //界面调整:
#define AXIS_X_START 40  //x 轴离左边框距离
#define AXIS_Y_START 20  //y 轴离下边框距离
#define AXIS_X_END 10    //x 轴离右边框距离
#define AXIS_Y_END 10    //y 轴离上边框距离

#define GRID_X_START 35  //横 网格线离左边框距离
#define GRID_Y_START 15  //竖 网格线离下边框距离
#define GRID_X_END 20
#define GRID_Y_END 20

#define GRID_DPI_X 10  //网格X轴划分为多少列
#define GRID_DPI_Y  6  //网格y轴划分为多少行

    //数据越界自动扩大比例
#define AUTO_X_EXPAND_SIZE 0.99
#define AUTO_Y_EXPAND_SIZE 0.95

    //曲线调整
#define LINE_Y_MAX_EDGE 1-AUTO_Y_EXPAND_SIZE     //上边距
#define LINE_Y_MIN_EDGE 0.33  //下边距


    //显示数据
#define DATA_SHOW_NUM 100

#endif /* Default_h */
