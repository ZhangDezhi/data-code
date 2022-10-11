//
//  CoordinateGridView.m
//  YMChart
//

#import "CoordinateGridView.h"
#import "Default.h"


@implementation CoordinateGridView

- (id)initWithFrame:(NSRect)frameRect{
    self = [super initWithFrame:frameRect];
    if(self){
         [self reset2DefaultParam];

        self.bgColor = [NSColor clearColor];
        self.gridColor = [NSColor redColor];
        self.axisColor = [NSColor blackColor];



        self.xAxleAry = [NSMutableArray arrayWithCapacity:self.maxYValue];
    }
    return self;
}
-(void)reset2DefaultParam
{
    self.dpix = GRID_DPI_X;
    self.dpiy = GRID_DPI_Y;
    self.axisXstart = AXIS_X_START;
    self.axisYstart = AXIS_Y_START;
    self.gridXstart = GRID_X_START;
    self.gridYstart = GRID_Y_START;
//    self.maxXVaule = DATA_X_MAX;

    self.minXValue = DATA_X_MIN;
//    self.maxYValue = DATA_Y_MAX;//Y轴最大最小值外部修改,重置时候不管
//    self.minYValue = DATA_Y_MIN;

    self.axisXend = AXIS_X_END;
    self.axisYend = AXIS_Y_END;
    self.gridXend = GRID_X_END;
    self.gridYend = GRID_Y_END;
    self.isShowGrid = YES;//默认显示表格
    [self.xAxleAry removeAllObjects];
}
- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    //NSRect screen = [self bounds];
   // NSLog(@"5     (%f,%f) h:%f w:%f",screen.origin.x,screen.origin.y, screen.size.height, screen.size.width);
    // Drawing code here.
    [self drawChartGrid];
}

/**
 更新坐标轴

 @param isShow 是否显示表格
 */
- (void)updateChartShowGrid:(BOOL)isShow {

     self.isShowGrid = isShow;
    [self setNeedsDisplay:YES];
}

#pragma mark - ......:::::::: 更   新 ::::::::......


- (void)updateGrid{
      [self setNeedsDisplay:YES];
}


#pragma mark - ......:::::::: 绘制表格 ::::::::......

-(void)drawChartGrid
{

    NSArray *sViews = [self subviews];

        //The below code is for cleaning up the view for drawing

    for (int j=0; j<[sViews count];)
        {
        [[sViews objectAtIndex:0] removeFromSuperview];
        }

    float axisXStart = self.axisXstart;
    float axisYStart = self.axisYstart;
    float gridXStart = self.gridXstart;
    float gridYStart = self.gridYstart;

        //Drawing the X-Axis and Y-Axis
    NSBezierPath *path = [NSBezierPath bezierPath];
    [path setLineWidth: 1.8];
    [self.axisColor set];

    [path moveToPoint:[self originPoint]];//(100,100)
    [path lineToPoint:NSMakePoint(axisXStart, [self axisMaxHeight])];//(95,frame.hight-40)

    [path moveToPoint:[self originPoint]];//(100,100)
    [path lineToPoint:NSMakePoint([self axisMaxWidth], axisYStart)];//(fram.width-20,100)
    [path stroke];

        //Horizontal Arrow
    [path moveToPoint:NSMakePoint([self axisMaxWidth]-20, axisYStart-10)];
    [path lineToPoint:NSMakePoint([self axisMaxWidth], axisYStart)];
    [path lineToPoint:NSMakePoint([self axisMaxWidth]-20, axisYStart+10)];
    [path stroke];

        //Vertical Arrow
    [path moveToPoint:NSMakePoint(axisXStart-10, [self axisMaxHeight]-20)];
    [path lineToPoint:NSMakePoint(axisXStart, [self axisMaxHeight])];
    [path lineToPoint:NSMakePoint(axisXStart+10, [self axisMaxHeight]-20)];
    [path stroke];


    NSFont *font = [NSFont userFontOfSize:10];
    CGFloat lineDash[2];
    lineDash[0] = 10.0;
    lineDash[1] = 5.0;


        //Drawing the Horizontal Grid With Labels
    int numOfSegments = self.dpix;//
    float valueXdpi = (self.maxXVaule - self.minXValue)/numOfSegments;
    float segmentWidth = ([self gridMaxWidth] - gridXStart)/numOfSegments;
    NSBezierPath *hPath = [NSBezierPath bezierPath];
    [[NSColor redColor] set];
    [hPath setLineWidth: 0.15];

    for (int i=1; i<=numOfSegments; i++)
        {
        //表格
        if(self.isShowGrid){
            [hPath moveToPoint:NSMakePoint(gridXStart + (i*segmentWidth), gridYStart)];
            [hPath lineToPoint:NSMakePoint(gridXStart + (i*segmentWidth), [self gridMaxHeight])];
                //[hPath setLineWidth: 1.2];
            [hPath setLineDash:lineDash count:2 phase:1.0];
            [hPath stroke];
        }

        //数据
        NSTextField *tField = [[NSTextField alloc] initWithFrame:NSMakeRect(gridXStart + (i*segmentWidth)-8, gridYStart-20, 50, 18)];
        [tField setFont:font];
        [tField setEditable:NO];
        [tField setBordered:NO];
        [tField setDrawsBackground:NO];

        //根据是否有x轴坐标数组,进行显示
        int index = i*valueXdpi + self.minYValue;
        if(self.xAxleAry.count < self.maxXVaule || self.xAxleAry.count < index){
            [tField setStringValue:[NSString stringWithFormat:@" %.f",i*valueXdpi + self.minXValue]];
        }else{
            [tField setStringValue:[NSString stringWithFormat:@" %.fs",[self.xAxleAry[index] floatValue]]];
        }
        [tField setTextColor:[NSColor darkGrayColor]];
        //[tField setFrameRotation:90]; //竖向显示
        [self addSubview:tField];
        }

        //Drawing the Horizontal Grid With Labels
    //坐标转换
    int numOfVerSegments = self.dpiy;
    float valueYdpi = (self.maxYValue - self.minYValue)/numOfVerSegments;
    float segmentHeight = ([self gridMaxHeight] - gridYStart)/numOfVerSegments;

    NSBezierPath *vPath = [NSBezierPath bezierPath];
    [vPath setLineWidth: 0.2];

    for (int i=1; i<=numOfVerSegments; i++)
        {
        //表格显示
        if(self.isShowGrid){
            [vPath moveToPoint:NSMakePoint(gridXStart , gridYStart+ (i*segmentHeight))];
            [vPath lineToPoint:NSMakePoint([self gridMaxWidth], gridYStart + (i*segmentHeight))];
            [vPath setLineDash:lineDash count:2 phase:1.0];
            [vPath stroke];
        }

        //数据显示
        NSTextField *tField = [[NSTextField alloc] initWithFrame:NSMakeRect(gridXStart - 40, gridYStart -10 + (i*segmentHeight), 80, 18)];
        [tField setEditable:NO];
        [tField setBordered:NO];
        [tField setDrawsBackground:NO];
        [tField setStringValue:[NSString stringWithFormat:@" %.2f",i*valueYdpi+self.minYValue]];

        [tField setFont:font];
        [tField setTextColor:[NSColor blackColor]];
        [self addSubview:tField];

        }

}
#pragma mark - ......:::::::: 表格位置 ::::::::......

//原点坐标(视图)
-(NSPoint) originPoint
{

    NSPoint origin = NSMakePoint(self.axisXstart, self.axisYstart);
    return origin;

}
//表格最高点(视图)
-(float)gridMaxHeight
{

    float mHeight = [self frame].size.height - self.gridYend;
    return mHeight;

}
//坐标轴最高点(视图)
-(float)axisMaxHeight
{

    float mHeight = [self frame].size.height - self.axisYend;
    return mHeight;

}
//表格最长(视图)
-(float)gridMaxWidth
{

    float mWidth = [self frame].size.width - self.gridXend;
    return mWidth;

}
//坐标轴最长(视图)
-(float)axisMaxWidth
{

    float mWidth = [self frame].size.width - self.axisXend;
    return mWidth;

}
#pragma mark - ......:::::::: 鼠标事件 ::::::::......
- (void)mouseDown:(NSEvent *)event
{
    if (event.clickCount == 2)
        {
        [NSApp sendAction:[self action] to:[self target] from:self];
        }
}

@end
