//
//  ViewController.m
//  NSStringEnum
//
//  Created by Danila Gusev on 13/12/2018.
//  Copyright © 2018 josshad. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self handleState:@"JStrWrongState"];
    NSLog(@"---");
    [self handleState:@"JStrExampleEnumLoading"];
    NSLog(@"---");
    [self handleState:JStrExampleEnum_.Default];
}

- (void)handleState:(NSString *)state {
    SWITCH(JStrExampleEnum, state) {
        CASE(Loading) {
            NSLog(@"Handle loading state: <%@>", state);
            break;
        }
        
        CASE(Error) {
            NSLog(@"Handle error state: <%@>", state);
            break;
        }
        
        CASE(Default) {
            NSLog(@"Handle default state: <%@>", state);
            break;
        }
        
        DEFAULT {
            NSLog(@"Can't handle state: <%@>", state);
        }
    }
}



@end
