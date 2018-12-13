//
//  jstrenum.h
//  MacroTest
//
//  Created by Danila Gusev on 06/12/2018.
//  Copyright © 2018 Danila Gusev. All rights reserved.
//

#import "metamacros.h"

#ifndef jstrenum_h
#define jstrenum_h

#define jstr_enum_list_(name, val) name
#define jstr_enum_list(INDEX, CONTEXT, VAR) CONTEXT jstr_enum_list_ VAR;

#define jstr_enum_var_(name, val) .name = val
#define jstr_enum_var(INDEX, CONTEXT, VAR) jstr_enum_var_ VAR ,

#define NSSRING_ENUM(Enum_Name, ...) \
    typedef NSString* Enum_Name; \
    static const struct { \
        metamacro_foreach_concat(,,metamacro_foreach_cxt(jstr_enum_list,,Enum_Name,__VA_ARGS__))\
    } Enum_Name##_ = { \
        metamacro_foreach_cxt(jstr_enum_var,,Enum_Name,__VA_ARGS__)\
    }\

#define SWITCH(type, a) for (int __jstr_i = 0; __jstr_i < 1; __jstr_i++) \
                            for (__auto_type const __jstr_switch_var = a; __jstr_i < 1; __jstr_i++) \
                                for (__auto_type const __jstr_enum = type##_; __jstr_i < 1; __jstr_i++)

#define DEFAULT 
#define CASE(s) if ([__jstr_enum.s isEqual:__jstr_switch_var])

#endif /* jstrenum_h */
