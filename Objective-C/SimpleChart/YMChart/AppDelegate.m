//
//  AppDelegate.m
//  YMChart
//

#import "AppDelegate.h"
#import "Default.h"
@interface AppDelegate ()
{
     ChartControl* ctller;
}
@property (weak) IBOutlet NSWindow *window;
@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {

    //监听窗口大小改变
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(windowDidResize:) name:NSWindowDidResizeNotification object:self.window];

    //初始化: 传入NSView
   ctller = [[ChartControl alloc]initWithView:_chartView];
     [ctller updateChartName :@"Chart1" ];//设置默认值
    [ctller addCurve:@"String1" color:[NSColor grayColor]];
    [ctller addCurve:@"String2" color:[NSColor blueColor]];

    //设置鼠标响应
    [ctller setMouseAction:YES];

//    //值变大自动扩大
//    ctller.isAutoCheckX = YES;
//    ctller.isAutoCheckY = YES;
    [ctller appendCurveName:@"String1" oneData:0 xLabel:nil isUpdateGraph:YES];
        [ctller appendCurveName:@"String1" oneData:26.8 xLabel:nil isUpdateGraph:YES];
    [ctller appendCurveName:@"String2" oneData:26 xLabel:nil isUpdateGraph:YES];
     [ctller appendCurveName:@"String2" oneData:26.5 xLabel:nil isUpdateGraph:YES];
    
//    for(int i=1; i<2048;i++){
//        int num1 = rand() % (DATA_Y_MAX - DATA_Y_MIN) + DATA_Y_MIN +10;  // “%”为模运算
//        int num2 = rand() % (DATA_Y_MAX - DATA_Y_MIN) + DATA_Y_MIN;  // “%”为模运算
//        [ctller appendCurveName:@"String1" Datas:@[@(0),@(num2)] xLabel:nil isUpdateGraph:YES];
//        [ctller appendCurveName:@"String2" oneData:num1 xLabel:nil isUpdateGraph:YES];
//    }
}


//调用窗口改变自动刷新
- (void)windowDidResize:(NSNotification *)notification
{
    [ctller updateChartView:_chartView.bounds];
}
- (IBAction)addValue:(id)sender {
    int num1 = rand() % (DATA_Y_MAX - DATA_Y_MIN) + DATA_Y_MIN +10;  // “%”为模运算
     int num2 = rand() % (DATA_Y_MAX - DATA_Y_MIN) + DATA_Y_MIN;  // “%”为模运算
    [ctller appendCurveName:@"String1" Datas:@[@(0),@(num2)] xLabel:nil isUpdateGraph:YES];
    [ctller appendCurveName:@"String2" oneData:num1 xLabel:nil isUpdateGraph:YES];

}
- (IBAction)eraseCurve:(id)sender {
    [ctller eraseCurveName:@"String1"];


}
- (IBAction)hidButton:(id)sender {
   [ctller showReadMe:NO];
}

@end
