//
//  line.m
//  YMChart

#import "Line.h"
#import "Default.h"
@interface Line()
{
    float toViewx;//实际数据转换图形数据
    float toViewy;

    NSMutableDictionary *viewPointDict;
    NSPoint nowPoint;
    LineName *readMe;
}
@end

@implementation Line
- (id)initWithFrame:(NSRect)frameRect name:(NSString *)lineName {
     self = [super initWithFrame:frameRect ];
    if(self){
        self.maxXVaule = DATA_X_MAX;
        self.maxYValue = DATA_Y_MAX;
        self.minXValue = DATA_X_MIN;
        self.minYValue = DATA_Y_MIN;

        self.axisXstart = AXIS_X_START;
        self.axisYstart = AXIS_Y_START;
        self.gridXstart = GRID_X_START;
        self.gridYstart = GRID_Y_START;

        self.axisXend = AXIS_X_END;
        self.axisYend = AXIS_Y_END;
        self.gridXend = GRID_X_END;
        self.gridYend = GRID_Y_END;

        self.lineName = lineName;
        self.lineWidth = 2.0;
        self.isLight = NO;
        self.isHightLightPoint = YES;
        self.isShowSelectValue = NO;
        self.lineColor = [NSColor blueColor];
   
        _pointAry = [NSMutableArray arrayWithCapacity:1024];
        _showValueAry = [NSMutableArray arrayWithCapacity:1024];
        viewPointDict = [NSMutableDictionary dictionaryWithCapacity:1024];
        
        //监听鼠标移动事件
        NSTrackingArea *trackingArea = [[NSTrackingArea alloc] initWithRect:self.bounds options:
                                        NSTrackingMouseMoved |
                                        NSTrackingMouseEnteredAndExited |
                                        NSTrackingActiveAlways owner:self userInfo:nil];
        
        // 添加到View中
        [self addTrackingArea:trackingArea];
    }
    return self;
}

- (void)clearLine{
    [self.pointAry removeAllObjects];
    [self.showValueAry removeAllObjects];
    [self setNeedsDisplay:YES];
}
- (void)updateLine{
     [self setNeedsDisplay:YES];
}


- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    if (self.pointAry == nil) {
        return;
    }
    //计算换算比例
    // NSLog(@"4     (%f,%f) h:%f w:%f",screen.origin.x,screen.origin.y, screen.size.height, screen.size.width);
    int SW = fabs([self frame].size.width);
    int SH = fabs([self frame].size.height);

    toViewx = (SW-self.gridXstart-self.gridXend)/(self.maxXVaule - self.minXValue);//乘以该值, 实际数据-> 显示数据//x
    toViewy = (SH-self.gridYstart-self.gridYend)/(self.maxYValue - self.minYValue);//乘以该值, 实际数据-> 显示数据//y

//   NSLog(@"%f   %f  %f   %f",self.gridXstart,self.gridXend,self.maxXVaule,self.minXValue);
//     NSLog(@"%f   %f  %f   %f",self.gridYstart,self.gridYend,self.maxYValue,self.minYValue);
//    NSLog(@"%f   %f",toViewx,toViewy);
    //NSLog(@"Line SH:%d ",SH);
    //绘制图形
    [self drawLine:self.pointAry  lineColor:self.lineColor];


    if(_isHightLightPoint){
        NSNumber *selectPoint = [viewPointDict objectForKey:[NSNumber numberWithInteger:nowPoint.x]];
        if(selectPoint != nil){
            NSPoint hpoint = NSMakePoint(nowPoint.x, [selectPoint floatValue]);
            [self hightLightPoint:hpoint];
        }
    }
}


#pragma mark - ......:::::::: 绘制函数 ::::::::......

/** 通过点数组绘制图形

 @param lineAry 点数字
 @param color 线颜色
 */
-(void)drawLine:(NSArray *)lineAry lineColor:(NSColor *)color{


    //绘制点
    NSMutableArray *drawPointAry = [NSMutableArray arrayWithCapacity:10];

    for (int pointNum = 0;pointNum < [lineAry count] ;pointNum++) {

        NSNumber *linePointValue = [lineAry objectAtIndex:pointNum];
        float linePointX = (float)pointNum;
        float linePointY = [linePointValue floatValue];

        NSPoint linePoint = NSMakePoint(linePointX, linePointY);
        NSPoint showLinePoint = [self toView:linePoint];
        //显示当前值
//        if([self.showValueAry containsObject:linePointValue]){
//
//            NSString *strH = [NSString stringWithFormat:@"%.2f",linePointY];
//            NSMutableDictionary *md = [NSMutableDictionary dictionary];
//            [md setObject:[NSFont fontWithName:@"Times" size:10 ]forKey:NSFontAttributeName];
//            [md setValue:self.lineColor forKey:NSForegroundColorAttributeName];//设置字体颜色
//            [strH drawAtPoint:showLinePoint withAttributes:md];
//
//        }
       
        //NSPoint showSelectPoint = [self toView:self.mSelectPoint];
        //NSLog(@"%@",self.isShowSelectValue?@"YES":@"NO");
        if(self.isShowSelectValue
           &&((int)showLinePoint.x > (int)self.mSelectPoint.x -2)
           && ((int)showLinePoint.x < (int)self.mSelectPoint.x +2 ) ){
         
           
            NSString *strH = [NSString stringWithFormat:@"%.2f",linePointY];
            NSMutableDictionary *md = [NSMutableDictionary dictionary];
            [md setObject:[NSFont fontWithName:@"Times" size:40 ]forKey:NSFontAttributeName];
            [md setValue:[NSColor blackColor] forKey:NSForegroundColorAttributeName];//设置字体颜色

            //[strH drawAtPoint:showLinePoint withAttributes:md];

             [readMe updateValue:strH lineName:self.lineName];
            //绘制X轴*Y轴
            NSPoint X_Point_1 = NSMakePoint(showLinePoint.x, 0);
            NSPoint X_Point_2 = NSMakePoint(showLinePoint.x, self.bounds.size.height);

              [self drawLineP1:X_Point_1 P2:X_Point_2 color:self.lineColor lineWidth:self.lineWidth];
            NSPoint Y_Point_1 = NSMakePoint(0, showLinePoint.y);
            NSPoint Y_Point_2 = NSMakePoint( self.bounds.size.width, showLinePoint.y);
             [self drawLineP1:Y_Point_1 P2:Y_Point_2 color:self.lineColor lineWidth:self.lineWidth];

        }
        
        
        NSValue *showLinePointValue = [NSValue valueWithPoint:showLinePoint];
        [drawPointAry addObject:showLinePointValue];
        //NSLog(@"%d,   x:%f   y:%f",pointNum,showLinePoint.x,showLinePoint.y);

        //for show HightLight
       [ viewPointDict setObject:[NSNumber numberWithInteger:showLinePoint.y] forKey:[NSNumber numberWithInteger:showLinePoint.x]];
    }


    //连线
    for (int i = 0; i< [drawPointAry count]; i ++) {
        if (i>=1) {
            NSPoint point1 = [[drawPointAry objectAtIndex:i-1] pointValue];
            NSPoint point2 = [[drawPointAry objectAtIndex:i] pointValue];
            [self drawLineP1:point1 P2:point2 color:self.lineColor lineWidth:self.lineWidth];
        }
    }
}

- (void)hightLightPoint:(NSPoint )point{

    NSBezierPath *bezierPath = [NSBezierPath bezierPath];
    bezierPath.lineWidth = 100;
    NSRect pointRect = NSMakeRect(point.x, point.y, 20, 20);
    [[NSColor redColor]set];
    [[NSBezierPath bezierPathWithOvalInRect:pointRect]stroke];
}

#pragma mark - ......:::::::: 基础函数 ::::::::......
/** 绘制直线基本函数

 @param p1 起始点
 @param p2 结束点
 @param lineColor 线颜色
 @param width 线宽带
 */
-(void)drawLineP1:(NSPoint)p1 P2:(NSPoint)p2 color:(NSColor *)lineColor lineWidth:(float)width{
    [lineColor set];

    NSBezierPath *bezierPath = [NSBezierPath bezierPath];
    bezierPath.lineWidth = width;

    [bezierPath moveToPoint:p1];
    [bezierPath lineToPoint:p2];
    [bezierPath stroke];

}
#pragma mark - ......:::::::: 转换函数 ::::::::......

-(NSPoint)toView:(NSPoint)realPoint{

    NSPoint viewPoint = NSMakePoint((realPoint.x-self.minXValue)*toViewx + self.gridXstart, (realPoint.y-self.minYValue)*toViewy + self.gridYstart);

    return viewPoint;
}

#pragma mark - ......:::::::: 鼠标事件 ::::::::......


- (void)mouseMoved:(NSEvent *)theEvent{

    NSPoint mp = [self convertPoint:[theEvent locationInWindow] fromView:nil];//鼠標新座標
   
    self.mSelectPoint = mp;
    //NSLog(@"%@",[NSValue valueWithPoint:mp]);
    [self updateLine];
    //temp

}
- (void)updateLineName:(LineName *)name{
    
    readMe = name;
}

@end
