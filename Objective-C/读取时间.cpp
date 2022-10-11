//
//  main.m
//  dateTimeTest
//
//  Created by ZhangDezhi on 16/10/6.
//  Copyright (c) 2016年 ZhangDezhi. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {

//        NSString *time = @"2016-10-6 09:12:23 +0000";
//        NSDate *destDate = [NSDate dateWithNaturalLanguageString:time];
//        NSLog(@"%@",destDate);
//        NSLog(@"%@",[NSDate date]);
//        NSLog(@" ");
//        NSDateFormatter *timeformat =[[NSDateFormatter alloc]init];
//        [timeformat  setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
//        //------------------------------------------------------//转到当前时区时间
        NSTimeZone *zone1 = [NSTimeZone systemTimeZone];
        NSLog(@"%@",zone1);
        NSTimeZone *zone2 = [NSTimeZone defaultTimeZone];
        NSLog(@"%@",zone2);
        NSTimeZone *zone3 = [NSTimeZone localTimeZone];
        NSLog(@"%@",zone3);
        NSTimeZone *zone4 = [NSTimeZone timeZoneForSecondsFromGMT:-1*60*60];
        NSLog(@"%@",zone4);
        
//
////        NSInteger intervsl = [zone secondsFromGMTForDate:fileModDate];
////        NSDate *localeDate = [fileModDate dateByAddingTimeInterval:intervsl];
////        [timeformat setTimeZone:[NSTimeZone timeZoneWithName:@"Asia/Shanghai"]];
//        //------------------------------------------------------
//
//        NSString *uploadstartTime = [timeformat stringFromDate:destDate];//add by zdz
//        NSString *nowString = [timeformat stringFromDate:[NSDate date]];//add by zdz
//        NSLog(@"%@",uploadstartTime);
//        NSLog(@"%@",nowString);
//        NSLog(@" ");
        
        
        //date -> string
        NSDate *nowDate = [NSDate date];
        NSLog(@"date_now   :%@",nowDate);     //2016-10-06 02:31:15 +0000
        NSDateFormatter *timeformat =[[NSDateFormatter alloc]init];
        [timeformat  setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
        NSString *nowDateStr = [timeformat stringFromDate:nowDate];
        NSLog(@"date_string:%@",nowDateStr); //2016-10-06 10:36:21
        
        NSString *lastDateStr = [NSString stringWithFormat:@"%@ +0800",nowDateStr];
        NSLog(@"last_string:%@",lastDateStr);
        NSDate *lastDate = [NSDate dateWithNaturalLanguageString:lastDateStr];
        NSLog(@"last_date:  %@",lastDate);
        
//        NSString *time = @"2016-10-6 09:12:23 +0000";
//        NSDate *destDate = [NSDate dateWithNaturalLanguageString:time];
//        NSDate *zeroZoneDate = = [NSDate datewi]
        
//        NSDate *date = [destDate dateByAddingTimeInterval:-8*60*60];
//        NSString *dateStr = [timeformat stringFromDate:date];
//        NSLog(@"%@",dateStr);
    }
    return 0;
}
