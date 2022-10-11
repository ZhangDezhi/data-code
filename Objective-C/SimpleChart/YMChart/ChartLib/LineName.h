//
//  LineName.h
//  YMChart
//

#import <Cocoa/Cocoa.h>

@interface LineName : NSView
@property (nonatomic ) BOOL   isShow;
@property (nonatomic ,retain) NSMutableDictionary  *LineDict;   //数据
@property (nonatomic ,retain) NSMutableDictionary  *ValueDict;   //当前值
- (void)updateRect:(NSRect)dirtyRect;
- (void)setIsShow:(BOOL)isShow;
- (void)addLine:(NSString *)lineName lineColor:(NSColor *)color;
- (void)deleteLine:(NSString *)lineName;
- (void)updateValue:(NSString *)value lineName:(NSString *)name;
@end
