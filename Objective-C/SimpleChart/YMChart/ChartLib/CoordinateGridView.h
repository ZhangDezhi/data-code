//坐标轴
#import <Cocoa/Cocoa.h>

@interface CoordinateGridView : NSControl
@property (nonatomic,retain) NSMutableArray *xAxleAry;//Y轴显示数组
//自定义
@property (nonatomic,retain) NSColor *bgColor;//背景色
@property (nonatomic,retain) NSColor *axisColor;//坐标轴色
@property (nonatomic,retain) NSColor *gridColor;//表格色
//Data
@property (nonatomic) float maxXVaule;//数据X轴最大值
@property (nonatomic) float minXValue;

@property (nonatomic) float maxYValue;
@property (nonatomic) float minYValue;
    //View
/*
+---------------------------------+
|    axisXend                     |
|  /|                             |
|   |                             |
|   |                             |
|   |__________________  axisXend |
|    axisYstart       /           |
|    axisXstart                   |
+---------------------------------+
 */
@property (nonatomic) float axisXstart;//绘制坐标轴_起始点
@property (nonatomic) float axisYstart;
@property (nonatomic) float axisXend;//绘制坐标轴_结束点(距离)
@property (nonatomic) float axisYend;

@property (nonatomic) float gridXstart;//绘制表格_起始点
@property (nonatomic) float gridYstart;
@property (nonatomic) float gridXend;
@property (nonatomic) float gridYend;

@property (nonatomic) int dpix;//表格X格数
@property (nonatomic) int dpiy;

@property (nonatomic) BOOL isShowGrid;

- (void)updateChartShowGrid:(BOOL)isShow;//更新表格
@end
