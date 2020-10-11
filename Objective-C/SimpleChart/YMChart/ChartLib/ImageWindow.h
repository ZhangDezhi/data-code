//
//  ImageWindow.h
//  YMChart
//

#import <Cocoa/Cocoa.h>
//
@class ChartControl;
@class CoordinateGridView;
@interface ImageWindow : NSWindowController

@property (weak) IBOutlet NSImageView *cView;
@property (strong) ChartControl *ctller;
- (void)addChart:(NSDictionary *)lineDict CoordinateGridView:(CoordinateGridView *)coor;
@end
