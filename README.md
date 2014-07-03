CottonObject
========

A cushy, comfy, oh-so-soft wrapper around NSDictionary to make life easier with JSON (and other) network objects.


There are lots of web endpoints that returns blobs of text that frameworks like RestKit or JSONKit turns into Cocoa's NSDictionary and NSArray.  Unfortunately, the app code that needs to use the NSDictionary needs to use NSString keys to pull values out.  This is error prone and time-consuming, not to mention Xcode won't auto-complete the keys unless you declare them as constants.  Multiply this by the number of values in a response and you'll quickly see how messy it gets. 

```
[someNetworkFramework GET:@"blahblahblah"
                parameters:parameters
                   success:^(NetworkOperation* operation,
                             id responseObject)
  {
    NSDictionary* dictionary = responseObject;
    NSString* name = dictionary[@"name"];
    ...
    NSString* type = dictionary[@"type"];
  }];
```

Another complication is that NSDictionary will happily return whatever value it has for the key, regardless of the type your code might be expecting.  There are lots of times where endpoints will switch between strings and numbers for a property, and your app will simply just start crashing.

CottonObject allows a developer to take the NSDictionary response and quickly wrap it in a formal Objective-C class.  This has a number of benefits:

1.  Because the object uses NSDictionary as the data store, it can be easily de/serialized using the NSCoding protocol.
2.  Objects can be "faked" with dictionaries instanced from plists if your network or API is not up yet.
3.  The objects can enforce types.  So as long as your code can handle properties with nil values, the web endpoint can switch types and the worst is that a value may no longer be shown.
4.  The property names are used a keys, eliminating the need for declaring string constants.

How to use it
========

```
// declare a subclass of CottonObject
@interface SampleObject : CottonObject

// declare the property in the .h
@property (nonatomic, readonly) NSString* name;

// implement the getter in the .m
- (NSString*) name
{
  return [self stringForGetter:_cmd];
}
```

If the internal dictionary has, for some reason, a different name for the value than the property name, you can use a string as the key.  This is helpful to correct inconsistencies between the client and server API.

```
// declare the property in the .h
@property (nonatomic, readonly) NSString* myName;

// implement the getter in the .m
- (NSString*) name
{
  return [self stringForKey:@"my_name"];
}
```

If a property is an NSDictionary (i.e. a dictionary with dictionary values), you can establish parent-child CottonObject hierarchies.

```
// declare the child object
@interface Child : CottonObject
...
@end

// declare the parent object with the Child property
@interface Parent : CottonObject

@property (nonatomic, readonly) Child* child;

@end

// implement a getter for the Child
- (Child*) child
{
  return [self objectWithClass:Child.class forKey:NSStringFromSelector(_cmd)];
}
```

But what about read-write properties?  Well, CottonObject can help you there too.

```
// declare a read-write property
@property (nonatomic, copy) NSString* name;

// implement getter
- (NSString*) name
{
  return [self stringForGetter:_cmd];
}

// implement setter
- (void) setName:(NSString*)name
{
  [self setObject:name withSetter:_cmd];
}
```

Remember that the internal NSDictionary only supports NSObject instances, so if your property is a primitive, you'll need to transform it in the setter.

```
// declare a primitive read-write property
@property (nonatomic) NSUInteger count;

// implementer getter
- (NSUInteger) count
{
  return [self unsignedIntegerForGetter:_cmd];
}

// implement setter
- (void) setCount:(NSUInteger)count
{
  NSNumber* countNumber = @(count);
  [self setObject:countNumber withSetter:_cmd];
}
```

Checkout the CottonObject sample Xcode project.  It has a SampleObject that is created from a plist dictionary and shows how to declare, implement and use the SampleObject.

How to install it
========

Simply download CottonObject.h and CottonObject.c, then add to your project.  CottonObject uses ARC, so if your project does not, follow these instructions http://www.codeography.com/2011/10/10/making-arc-and-non-arc-play-nice.html.

Support for Cocoapods is coming soon!

How does it work?
========

The trick is to use the _cmd variable, which is a hidden instance variable inside every Objective-C method's context.  When a property is synthesized, the compiler creates a method of the same name as the property.  You can override that method with your own version, and so CottonObject adds some convenience methods to use the _cmd variable as the key to the object's internal dictionary.

```
IMPORTANT: Note that if you specify the getter in the property declaration, that will be
the name of the getter method.  In this case, you can use the xxxForKey flavor methods and
re-map the value in the dictionary.
```

