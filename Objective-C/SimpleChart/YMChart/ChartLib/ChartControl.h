/*****************************************************************************
 * Description
 *
 * 绘图模块.提供基础的折线图绘制.并可以进行简单的自定义.
 * 只需要导图NSView或者NSImageView到ChartControl. 可以使用该模块

 - (id)initWithView:(NSView *)cdView; //初始化.需要导入控件
 - (void)updateChartView:(NSRect)rBounds; //窗口改变时候重绘
 - (void)addCurve:(NSString *)name color:(NSColor *)lineColor;//添加曲线
 - (void)appendCurveName:(NSString *)cName oneData:(double )data isUpdateGraph:(BOOL)isUpdate;//追加数据
 - (void)appendCurveName:(NSString *)cName Datas:(NSArray *)dataAry isUpdateGraph:(BOOL)isUpdate;//追加数组
 - (void)updateCurveName:(NSString *)cName;//刷新曲线
 - (void)updateClass;//刷新所有图像
 - (void)eraseCurveName:(NSString *)cName;//清除曲线
 - (void)showReadMe:(BOOL)isShow;
 *****************************************************************************/

/*****************************************************************************
 * Version:1.0.0 Date:2018/6/28.
 *
 * UpdateContent:
 * 1.基础模块创建
 ****************************************************************************/
/*****************************************************************************
 * Version:1.0.1 Date:2018-08-13 23:23:08
 *
 * UpdateContent:
 * 1.基础模块创建
 ****************************************************************************/
/*****************************************************************************
 * Version:1.0.2 Date:2018-08-13 23:23:08
 *
 * UpdateContent:
 * 1.增加显示曲线值接口. 将值显示在图示处.
 ****************************************************************************/

#import <Foundation/Foundation.h>
#import "Line.h"
#import "CoordinateGridView.h"
#import "LineName.h"

@interface ChartControl : NSObject
@property (nonatomic,copy) NSString *chartName;;
@property (strong) CoordinateGridView *coordinateView;
@property (strong) LineName *lineName;
@property (strong) NSView *superView;

@property (nonatomic) int  iMaxShowPoints;//绘制点的个数
//越界检测(自动扩大坐标轴)
@property (nonatomic) BOOL isAutoCheckY;
@property (nonatomic) BOOL isAutoCheckX;

- (id)initWithView:(NSImageView *)cdView; //初始化,导入NSView或者NSImageView

- (void)addCure:(Line *)aLine;//增加曲线
- (void)addCurve:(NSString *)name color:(NSColor *)lineColor isShowValue:(BOOL)sValue;
- (void)addCurve:(NSString *)name color:(NSColor *)lineColor;//添加曲线
- (void)appendCurveName:(NSString *)cName oneData:(double )data xLabel:(NSString *)xLable isUpdateGraph:(BOOL)isUpdate;//追加数据
- (void)appendCurveName:(NSString *)cName Datas:(NSArray *)dataAry  xLabel:(NSArray *)xLable isUpdateGraph:(BOOL)isUpdate;//追加一组数数据

//刷新曲线
- (void)updateChartView:(NSRect)rBounds; //窗口改变时候重绘
- (void)updateCurveName:(NSString *)cName;//刷新单条曲线
- (void)updateClass;//刷新所有图像

//清除曲线
- (void)eraseCurveName:(NSString *)cName;//清除曲线

//附加功能
- (void)updateChartName:(NSString *)cName;//更新坐标初始值
- (void)setMouseAction:(BOOL)isActive;//设置鼠标响应
- (void)showReadMe:(BOOL)isShow;//设置图示显示
- (BOOL)saveImage:(NSString *)path;//保存图片


@end
