//
//  line.h
//  YMChart
//

#import <Cocoa/Cocoa.h>
#import "LineName.h"
@interface Line : NSView
//Data
@property (nonatomic ) NSMutableArray  *pointAry;   //数据
@property (nonatomic ) NSMutableArray  *showValueAry;//显示值

@property (nonatomic ) NSPoint mSelectPoint;

//[START]用于与坐标轴同步
@property (nonatomic) float maxXVaule;//数据X轴最大值
@property (nonatomic) float minXValue;
@property (nonatomic) float maxYValue;
@property (nonatomic) float minYValue;

@property (nonatomic) float axisXstart;//绘制坐标轴_起始点
@property (nonatomic) float axisYstart;
@property (nonatomic) float axisXend;//绘制坐标轴_结束点(距离)
@property (nonatomic) float axisYend;

@property (nonatomic) float gridXstart;//绘制表格_起始点
@property (nonatomic) float gridYstart;
@property (nonatomic) float gridXend;
@property (nonatomic) float gridYend;
//[END]

//自定义
@property (nonatomic ) float lineWidth;
@property (nonatomic ,retain) NSString  *lineName;
@property (nonatomic ,retain) NSColor   *lineColor;


//操作
@property (nonatomic ) BOOL   isLight;
@property (nonatomic ) int   selectNum;
@property (nonatomic ) BOOL isShowSelectValue;
//高亮点
@property (nonatomic ) BOOL  isHightLightPoint;




- (id)initWithFrame:(NSRect)frameRect name:(NSString *)lineName ;
- (void)clearLine;
- (void)updateLine;
- (void)updateLineName:(LineName *)name;//readMe显示值
@end
