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
  return self.dictionary[NSStringFromSelector(_cmd)];
}
```

Checkout SampleObject.h and SampleObject.m to see how to declare a read-only object.  Checkout MutableSampleObject if you want to see how to declare an object that allows readwrite properties.

How to install it
========

Simply download CottonObject.h and CottonObject.c, then add to your project.  CottonObject uses ARC, so if your project does not, follow these instructions http://www.codeography.com/2011/10/10/making-arc-and-non-arc-play-nice.html.

Or, if you want to be fancy, you can install from Cocoapods by adding the line:

```
pod 'CottonObject' 
```

How does it work?
========

The trick is to use the _cmd variable, which is a hidden instance variable inside every Objective-C method's context.  When a property is synthesized, the compiler creates a method of the same name as the property.  You can override that method with your own version, and so CottonObject adds some convenience methods to use the _cmd variable as the key to the object's internal dictionary.

```
IMPORTANT: Note that if you specify the getter in the property declaration, that will be
the name of the getter method.  So, custom getters may not work with CottonObject.
```

