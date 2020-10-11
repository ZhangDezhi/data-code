//
//  AppDelegate.m
//  RestartAppDemo
//
//  Created by 张德志 on 16/9/22.
//  Copyright © 2016年 张德志. All rights reserved.
//

#import "AppDelegate.h"

@interface AppDelegate ()

@property (weak) IBOutlet NSWindow *window;
@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    // Insert code here to initialize your application
}

- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}

- (IBAction)restart:(id)sender {
    [self restartApp];

}
- (void)restartApp{

    NSTask *task = [[NSTask alloc] init];
    NSMutableArray *args = [NSMutableArray array];
    [args addObject:@"-c"];
    [args addObject:[NSString stringWithFormat:@"sleep %d; open \"%@\"", 3, [[NSBundle mainBundle] bundlePath]]];
    NSLog(@"%@",[[NSBundle mainBundle] bundlePath]);//显示程序当前路径
    [task setLaunchPath:@"/bin/sh"];
    [task setArguments:args];
    [task launch];
    [NSApp terminate:nil];

}
@end
