
Swift like implementation of enums with NSString associated values for objective-c using macros

## Installation
Include "jstrenum.h" and "metamacros.h" into your project.

## Example
### Declaring an string enum
```
NSSRING_ENUM(JStrExampleEnum,
             (Loading,   @"JStrExampleEnumLoading"),
             (Error,     @"JStrExampleEnumError"),
             (Default,   @"JStrExampleEnumDefault")
             );
```

* `JStrExampleEnum` -- type of the enum. All strings that declared in this enum will be of this type.
* `Loading`, `Error`, `Default` -- Swift style cases of enum
* `@"JStrExampleEnumLoading"`, `@"JStrExampleEnumError"`, `@"JStrExampleEnumDefault"` -- NSString associated values for enum


### Using the enum
---
To access to a member of enum you should use similar to swift syntax:
```
 NSLog(@"%@", JStrExampleEnum_.Loading);
```

```
- (void)handleLoadingState:(JStrExampleEnum)state {
	if ([state isEqualToString:JStrExampleEnum_.Loading]) {
		...
	}
}
```
---
To switch between members of enum you should use macros:
```
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
```


## Author
Danila Gusev

<a href="mailto:jos.shad@gmail.com">jos.shad@gmail.com</a>

## License

Usage is provided under the <a href="http://opensource.org/licenses/MIT" target="_blank">MIT</a>
