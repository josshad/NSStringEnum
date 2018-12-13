//
//  ViewController.h
//  NSStringEnum
//
//  Created by Danila Gusev on 13/12/2018.
//  Copyright © 2018 josshad. All rights reserved.
//

@import UIKit;
#import "jstrenum.h"

NSSRING_ENUM(JStrExampleEnum,
             (Loading,   @"JStrExampleEnumLoading"),
             (Error,     @"JStrExampleEnumError"),
             (Default,   @"JStrExampleEnumDefault")
             );


@interface ViewController : UIViewController


@end

