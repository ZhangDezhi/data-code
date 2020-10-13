//
//  LineName.m
//  YMChart
//
#import "LineName.h"

@implementation LineName

- (id)initWithFrame:(NSRect)frameRect {
    self = [super initWithFrame:frameRect ];
    if(self){
        _LineDict = [NSMutableDictionary dictionaryWithCapacity:1024];
        _ValueDict = [NSMutableDictionary dictionaryWithCapacity:1024];
        _isShow = YES;
    }
    return self;
}

#pragma mark - ......:::::::: 对外接口 ::::::::......
//是否显示
- (void)setIsShow:(BOOL)isShow{
    _isShow = isShow;
    [self setNeedsDisplay:YES];
}
//添加图示
- (void)addLine:(NSString *)lineName lineColor:(NSColor *)color{
    [_LineDict setObject:color forKey:lineName];
    [self setNeedsDisplay:YES];
}
//删除图示
- (void)deleteLine:(NSString *)lineName{
    NSArray *lineAry = [_LineDict allKeys];
    if([lineAry containsObject:lineName]){
        [_LineDict removeObjectForKey:lineName];
    }
    [self setNeedsDisplay:YES];
}
//重新绘制,例如图像大小变化
- (void)updateRect:(NSRect)dirtyRect{
    [self drawRect:dirtyRect];
}
//用于鼠标事件,更新值
- (void)updateValue:(NSString *)value lineName:(NSString *)name{

    [_ValueDict setObject:value forKey:name];
    NSLog(@"_%@",_ValueDict);
    [self setNeedsDisplay:YES];
}
#pragma mark - ......:::::::: 绘制函数 ::::::::......
- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    if (self.LineDict == nil || _isShow == NO) {
        return;
    }
    NSArray *lineAry = [_LineDict allKeys];
    int icont = (int)lineAry.count;
    float HW = dirtyRect.size.height;
   // float SW = dirtyRect.size.width;
    float iHight = HW/(icont +1);
    
    
    for(int i=0; i<lineAry.count ;i++){
        int pintX = 50;
        int pintY = (i+1)*iHight ;
        NSString *lineName = [lineAry objectAtIndex:i];
        NSPoint start = NSMakePoint(pintX, pintY);
        NSPoint end = NSMakePoint(pintX + 15, pintY);
        
        [self drawLineP1:start P2:end color:_LineDict[lineName] lineWidth:5];
        
        NSPoint fontPoint = NSMakePoint(end.x+3, end.y-10);
      
        NSMutableDictionary *md = [NSMutableDictionary dictionary];
        [md setObject:[NSFont fontWithName:@"Times" size:15 ]forKey:NSFontAttributeName];
        [md setValue:[NSColor blackColor] forKey:NSForegroundColorAttributeName];//设置字体颜色
        [lineName drawAtPoint:fontPoint withAttributes:md];


        NSArray *ary = [_ValueDict allKeys];
        if([ary containsObject:lineName]){

            NSString *value = _ValueDict[lineName];
            NSPoint valuePoint = NSMakePoint(0, end.y-10);
            [value drawAtPoint:valuePoint withAttributes:md];
        }

    }
    
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


@end
