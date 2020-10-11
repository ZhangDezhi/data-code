    //
    //  ChartControl.m
    //  YMChart
    //

#import "ChartControl.h"
#import "Default.h"
#import "ImageWindow.h"
@interface ChartControl ()
{
    NSMutableDictionary *lineDict;
    ImageWindow *controll;
}
@end
@implementation ChartControl
- (id)initWithView:(NSImageView *)cdView {
    if(self=[super init]){
        _superView = cdView;
        lineDict = [NSMutableDictionary dictionaryWithCapacity:10];
        _isAutoCheckY = NO;
        _isAutoCheckX = NO;
        _iMaxShowPoints = DATA_SHOW_NUM;

        _coordinateView = [[CoordinateGridView alloc]initWithFrame:cdView.bounds];
        [_superView addSubview:_coordinateView];

            //图示
        NSRect lineNameRect = NSMakeRect(cdView.bounds.size.width - 150, cdView.bounds.size.height - 150, 150, 150);
        _lineName = [[LineName alloc]initWithFrame:lineNameRect];
        [_superView addSubview:_lineName];

            //初始化后,读配置文件
        [self updateChartName:@""];
    }
    return self;
}

    //自定义参数
- (void)updateChartName:(NSString *)cName{
    self.chartName = cName;
    NSString* resourcePath = [[NSBundle mainBundle] resourcePath];
    NSMutableString* path = [NSMutableString stringWithString:resourcePath];
    [path appendString:@"/ChartConfig.plist" ];
    
    NSMutableDictionary* config  = [[NSMutableDictionary alloc] initWithContentsOfFile:path];
    NSDictionary *root = [config objectForKey:cName];
  
    if(root != nil){
        
        _iMaxShowPoints = [[root objectForKey:@"showDateBuffer"] intValue];
        _coordinateView.maxYValue = [[root objectForKey:@"showDataYMax"] intValue];
        _coordinateView.minYValue = [[root objectForKey:@"showDataYMin"] intValue];
        _isAutoCheckY = [[root objectForKey:@"isAutoCheckY"] boolValue];
        _isAutoCheckX = [[root objectForKey:@"isAutoCheckX"] boolValue];
        
    }else{
        _iMaxShowPoints = DATA_SHOW_NUM;
        _coordinateView.maxYValue = DATA_Y_MAX;
        _coordinateView.minYValue = DATA_Y_MIN;
        _isAutoCheckY = YES;
        _isAutoCheckX = YES;
    }
    
    
    _coordinateView.maxXVaule = _iMaxShowPoints;
    
    [_coordinateView updateChartShowGrid:YES];
}

- (void)setMouseAction:(BOOL)isActive
{
    if(isActive){
        [_coordinateView setTarget:self];
        [_coordinateView setAction:@selector(doubleClick:)];
    }
}

    //双击打开可放大的图片. 主要用于窗口大小不可修改的情况
- (IBAction)doubleClick:(id)sender{

    if(controll==nil){
        controll = [[ ImageWindow alloc] initWithWindowNibName:@"ImageWindow"];
    }

    [controll showWindow:self];
     [controll addChart:lineDict CoordinateGridView:_coordinateView];

        //2 打开显示
        //   [[NSWorkspace sharedWorkspace] openFile:sImgFilaPath withApplication:@"Preview"];

}


#pragma mark - ......:::::::: 数据接口 ::::::::......

- (void)addCure:(Line *)aLine{
    
    [lineDict setObject:aLine forKey:aLine.lineName];
    [_lineName addLine:aLine.lineName lineColor:aLine.lineColor];//添加图示
    [_superView addSubview:aLine];
    [_superView addSubview:_lineName positioned:NSWindowAbove relativeTo:aLine];//图示放最上面

}
//添加曲线
- (void)addCurve:(NSString *)name color:(NSColor *)lineColor isShowValue:(BOOL)sValue {
    Line *adLine = [[Line alloc] initWithFrame:_superView.bounds name:name];
    
    adLine.isShowSelectValue = sValue;
    adLine.maxXVaule = _coordinateView.maxXVaule;
    adLine.minXValue = _coordinateView.minXValue;
    adLine.maxYValue = _coordinateView.maxYValue;
    adLine.minYValue = _coordinateView.minYValue;
    
    adLine.lineColor = lineColor;
    [lineDict setObject:adLine forKey:name];
    [_lineName addLine:name lineColor:lineColor];//添加图示
    [_superView addSubview:adLine];
    [_superView addSubview:_lineName positioned:NSWindowAbove relativeTo:adLine];//图示放最上面
    [adLine updateLineName:_lineName];//添加readMe显示值
}
    //添加曲线
- (void)addCurve:(NSString *)name color:(NSColor *)lineColor {
    Line *adLine = [[Line alloc] initWithFrame:_superView.bounds name:name];
    [adLine updateLineName:_lineName];//添加readme显示值

    adLine.maxXVaule = _coordinateView.maxXVaule;
    adLine.minXValue = _coordinateView.minXValue;
    adLine.maxYValue = _coordinateView.maxYValue;
    adLine.minYValue = _coordinateView.minYValue;

    adLine.lineColor = lineColor;
    [lineDict setObject:adLine forKey:name];
    [_lineName addLine:name lineColor:lineColor];//添加图示
    [_superView addSubview:adLine];
    [_superView addSubview:_lineName positioned:NSWindowAbove relativeTo:adLine];//图示放最上面
}

    //添加一笔数据
- (void)appendCurveName:(NSString *)cName oneData:(double )data xLabel:(NSString *)xLable isUpdateGraph:(BOOL)isUpdate{

    Line *iLine = lineDict[cName];
    if(iLine==nil){
        return;
    }

    [iLine.pointAry addObject:@(data)];
    [iLine.showValueAry addObject:@(data)];
    if(xLable!=nil){
        [_coordinateView.xAxleAry addObject:xLable];
    }

        //只显示部分数据,删除最开始的数据
    if ([iLine.pointAry count] > _iMaxShowPoints){
        [iLine.pointAry removeObjectAtIndex:0];
        [iLine.showValueAry removeObjectAtIndex:0];
        if(xLable!=nil){
            [_coordinateView.xAxleAry removeObjectAtIndex:0];
        }
    }

    if(isUpdate){
        [self updateCurve: iLine];
    }
}

    //添加一组数据
- (void)appendCurveName:(NSString *)cName Datas:(NSArray *)dataAry xLabel:(NSArray *)xLable isUpdateGraph:(BOOL)isUpdate{

    Line *iLine = lineDict[cName];
    if(iLine==nil){
        NSLog(@"error: pleas add Curve first!!!");
        return;
    }

    [iLine.pointAry addObjectsFromArray:dataAry];
    [iLine.showValueAry addObjectsFromArray:dataAry];

    if(xLable!=nil){
        [_coordinateView.xAxleAry addObjectsFromArray:xLable];
    }
    if ([iLine.pointAry count] > _iMaxShowPoints){
        
        unsigned long iRemoveLen = [iLine.pointAry count] - _iMaxShowPoints -1;
        [iLine.pointAry removeObjectsInRange:NSMakeRange(0, iRemoveLen)];
        [iLine.showValueAry removeObjectsInRange:NSMakeRange(0, iRemoveLen)];

//        if(xLable!=nil){
//            [_coordinateView.xAxleAry removeObjectsInRange:NSMakeRange(0, iRemoveLen)];
//        }
    }

    if(isUpdate){
        [self updateCurve: iLine];
    }
}
- (void)updateCurveName:(NSString *)cName{
    Line *iLine = lineDict[cName];
    if(iLine==nil){
        return;
    }
    [self updateCurve: iLine];
}
#pragma mark - ......:::::::: 刷新接口 ::::::::......
    //窗口变化重绘图标
- (void)updateChartView:(NSRect)rBounds{

        //更新图示位置
    NSRect lineNameRect = NSMakeRect(_superView.bounds.size.width - 100, _superView.bounds.size.height - 100, 100, 100);
    _lineName.frame = lineNameRect;

        //坐标
    _coordinateView.frame = rBounds;
    [_coordinateView updateChartShowGrid:YES];

        //曲线
    NSArray *lineAry = [lineDict allValues];
    for(Line *iLine in lineAry){
        iLine.frame = rBounds;
        [self updateCurve: iLine];
    }
}
    //更新所有曲线
- (void)updateClass{
        //坐标
    [_coordinateView updateChartShowGrid:YES];
        //曲线
    NSArray *lineAry = [lineDict allValues];
    for(Line *iLine in lineAry){
        [self updateCurve: iLine];
    }
}
    //更新单条曲线
- (void)updateCurve:(Line *)aLine{

        //X轴越界检测, 重新设置maxXValue
    if(_isAutoCheckX){
        long xMax = 0;
        NSArray *lineAry = [lineDict allValues];
        for(Line *iLine in lineAry){
            long iCount = iLine.pointAry.count;
            xMax= iCount>xMax ? iCount : xMax;
        }

        if(xMax >= _coordinateView.maxXVaule*AUTO_X_EXPAND_SIZE){
            long newMaxXvalue = xMax ;//_coordinateView.maxXVaule*(1.1); //2.0 - AUTO_X_EXPAND_SIZE
            _coordinateView.maxXVaule = newMaxXvalue;

            for(Line *iLine in lineAry){
                iLine.maxXVaule = newMaxXvalue;
            }
            [_coordinateView updateChartShowGrid:YES];
        }
    }

        //Y轴越界检测
    if(_isAutoCheckY){
            //找最大值
        float yMax = 0;
        float yMin = _coordinateView.minYValue;
        NSArray *lineAry = [lineDict allValues];
        for(Line *iLine in lineAry){
            for(NSNumber *value in iLine.pointAry){
                float valueFloat = [value floatValue];
                yMax= valueFloat>yMax ? valueFloat : yMax;
                yMin = valueFloat<yMin ? valueFloat : yMin;
            }
        }



        //Y轴上限更新
        if(yMax >= _coordinateView.maxYValue )//- (_coordinateView.maxYValue - _coordinateView.minYValue)*(1-AUTO_Y_EXPAND_SIZE)) //加大Y坐标最大值,上移
            {

            long newMaxYvalue = _coordinateView.maxYValue + (_coordinateView.maxYValue - _coordinateView.minYValue)*(LINE_Y_MAX_EDGE); //2.0 - AUTO_Y_EXPAND_SIZE

            if (yMax >= newMaxYvalue && yMax < 200) {
                newMaxYvalue = yMax + (_coordinateView.maxYValue-_coordinateView.minYValue)*(LINE_Y_MAX_EDGE);
            }
            _coordinateView.maxYValue = newMaxYvalue;

            for(Line *iLine in lineAry){
                iLine.maxYValue = newMaxYvalue;
            }
            [_coordinateView updateChartShowGrid:YES];

            }
        else if(yMax < _coordinateView.maxYValue - (_coordinateView.maxYValue-_coordinateView.minYValue)*(0.33))   //减小Y坐标最大值
            {

            if (yMax >= _coordinateView.minYValue ) {
                _coordinateView.maxYValue = yMax + (_coordinateView.maxYValue-_coordinateView.minYValue)*(LINE_Y_MAX_EDGE);// _coordinateView.maxYValue - (_coordinateView.maxYValue-_coordinateView.minYValue)*0.33;
            }

            for(Line *iLine in lineAry){
                iLine.maxYValue = _coordinateView.maxYValue;
            }
            [_coordinateView updateChartShowGrid:YES];
            }

        //Y轴下限更新
        if(yMin < _coordinateView.minYValue){  //减小Y坐标最小值，Y轴原点下移

            if (yMin >= 0 && yMin <= _coordinateView.maxYValue) {
                _coordinateView.minYValue = yMin - (_coordinateView.maxYValue-_coordinateView.minYValue)*(1-AUTO_Y_EXPAND_SIZE);

                for(Line *iLine in lineAry){
                    iLine.minYValue = _coordinateView.minYValue;
                }
                [_coordinateView updateChartShowGrid:YES];

            }

        }
        else if(yMin > _coordinateView.minYValue + (_coordinateView.maxYValue-_coordinateView.minYValue)*(0.33)) {  //加大Y坐标最大值，Y轴原点上移

            if (yMin <= _coordinateView.maxYValue) {
                _coordinateView.minYValue = yMin - (_coordinateView.maxYValue-_coordinateView.minYValue)*(1-AUTO_Y_EXPAND_SIZE);//_coordinateView.minYValue + (_coordinateView.maxYValue-_coordinateView.minYValue)*(0.33);

                for(Line *iLine in lineAry){
                    iLine.minYValue = _coordinateView.minYValue;
                }
                [_coordinateView updateChartShowGrid:YES];
            }
        }
    }

    [aLine updateLine];

}


#pragma mark - ......:::::::: 清除接口 ::::::::......
- (void)eraseCurveName:(NSString *)cName{
        //清空
    NSArray *sViews = [_superView subviews];
    for (int j=0; j<[sViews count];)
        {
        [[sViews objectAtIndex:0] removeFromSuperview];
        }


    [lineDict removeObjectForKey:cName]; //曲线
    [_lineName deleteLine:cName];//删除图示
    
        //重新绘制
    [_superView addSubview:_coordinateView];
    [_superView addSubview:_lineName];
    NSArray *lineAry = [lineDict allValues];
    for(Line *iLine in lineAry){
        [_superView addSubview:iLine];
    }
}

#pragma mark - ......:::::::: 附加功能 ::::::::......
- (void)showReadMe:(BOOL)isShow{
    _lineName.isShow = isShow;
}

- (BOOL)saveImage:(NSString *)path{

    NSImageView *_imgShowTemp = (NSImageView *)_superView;

    [_imgShowTemp lockFocus];//zwView为继承NSView类的一个对象
    NSImage *image = [[NSImage alloc] initWithData:[_imgShowTemp dataWithPDFInsideRect:[_imgShowTemp bounds]]];
    [_imgShowTemp unlockFocus];

    NSData *imageData = [image TIFFRepresentation];
    NSBitmapImageRep *imageRep = [NSBitmapImageRep imageRepWithData:imageData];

    [imageRep setSize:[[_imgShowTemp image] size]];

    NSDictionary *imageProps = nil;
    NSNumber *quality = [NSNumber numberWithFloat:.85];
    imageProps = [NSDictionary dictionaryWithObject:quality forKey:NSImageCompressionFactor];
    NSData* imageData1 = [imageRep representationUsingType:NSJPEGFileType properties:imageProps];

    NSString* sImgFilaPath =  [path stringByExpandingTildeInPath];

    return  [imageData1 writeToFile:sImgFilaPath atomically:YES];

}


@end
