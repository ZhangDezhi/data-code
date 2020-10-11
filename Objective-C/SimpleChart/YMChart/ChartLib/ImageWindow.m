//
//  ImageWindow.m
//  YMChart
//

#import "ImageWindow.h"
#import "ChartControl.h"
#import "CoordinateGridView.h"
@interface ImageWindow ()

@end

@implementation ImageWindow

- (void)windowDidLoad {
    [super windowDidLoad];

    //监听窗口大小改变
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(windowDidResize:) name:NSWindowDidResizeNotification object:self.window];
    //初始化: 传入NSView
    self.ctller = [[ChartControl alloc]initWithView:_cView];
    [self.ctller setMouseAction:NO];
        //
    self.ctller.isAutoCheckX = YES;
    self.ctller.isAutoCheckY = YES;
}
- (void)addChart:(NSDictionary *)lineDict CoordinateGridView:(CoordinateGridView *)coor{
        //曲线
    self.ctller.coordinateView.maxYValue = coor.maxYValue;
    self.ctller.coordinateView.minYValue = coor.minYValue;
      [ self.ctller.coordinateView updateChartShowGrid:YES];
    NSArray *lineAry = [lineDict allValues];
    for(Line *tLine in lineAry){
        [self.ctller eraseCurveName:tLine.lineName];
        
        Line *iLine = [[Line alloc] initWithFrame:_cView.bounds name:tLine.lineName];
        iLine.lineColor = tLine.lineColor;
        iLine.pointAry = tLine.pointAry;
        iLine.maxXVaule = coor.maxXVaule;
        iLine.minXValue = coor.minXValue;
        iLine.maxYValue = coor.maxYValue;
        iLine.minYValue = coor.minYValue;
        iLine.isShowSelectValue = YES;
   
        //[self.ctller addCure:iLine];
        [self.ctller addCurve:iLine.lineName color:iLine.lineColor isShowValue:YES];
        [self.ctller appendCurveName:iLine.lineName Datas:iLine.pointAry xLabel:coor.xAxleAry isUpdateGraph:YES];

    }
}
- (void)windowDidResize:(NSNotification *)notification
{
    [_ctller updateChartView:_cView.bounds];
}
@end
