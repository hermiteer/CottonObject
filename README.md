HTObject
========

A thin wrapper around NSDictionary to make life better with JSON (and other) network responses.


There are lots of web endpoints that returns blobs of text that frameworks like RestKit or JSONKit turns into Cocoa's NSDictionary and NSArray.  Unfortunately, the app code that needs to use the NSDictionary needs to use NSString keys to pull values out.  This is error prone and time-consuming, not to mention Xcode won't auto-complete the keys unless you declare them as constants.  Multiply this by the number of values in a response and you'll quickly see how messy it gets. 

Another complication is that NSDictionary will happily return whatever value it has for the key, regardless of the type your code might be expecting.  There are lots of times where endpoints will switch between strings and numbers for a property, and your app will simply just start crashing.

```
[networkRequestManager GET:(NSString*)URLString
                parameters:(NSDictionary*)parameters
                   success:^(NetworkRequestOperation* operation,
                             id responseObject)
  {
    NSDictionary* dictionary = responseObject;
    NSString* name = dictionary[@"name"];
    ...
    NSString* 
  }];
```

HTObject allows a developer to take the NSDictionary response and quickly wrap it in a formal Objective-C class.  This has a number of benefits:

1.  Because the object uses NSDictionary as the data store, it can be easily de/serialized using the NSCoding protocol.
2.  Objects can be "faked" with dictionaries instanced from plists if your network or API is not up yet.
3.  The objects can enforce types.  So as long as your code can handle properties with nil values, the web endpoint can switch types and the worst is that a value may no longer be shown.
4.  The property names are used a keys, eliminating the need for declaring string constants.

The key to this is using the _cmd variable, which is a hidden instance variable inside every Objective-C method's context.  In the case of properties, _cmd will be the name of the property, which is then used as a key into the object's dictionary.

How to use it
========



```
// declare a subclass of HTObject
@interface SampleObject : HTObject

// declare the property in the .h
@property (nonatomic, readonly) NSString* name;

// implement the getter in the .m
- (NSString*) name
{
  return self.dictionary[NSStringFromSelector(_cmd)];
}
```
