//******************************************************************************
//  CottonObject - a thin wrapper around NSDictionary to make life better with
//  JSON (and other) network objects.  For more details, checkout the github
//  for this project http://github.com/hermiteer/CottonObject
//
//  Created by Christoph on 6/22/14.
//
//  The MIT License (MIT)
//
//  Copyright (c) 2014 Hermiteer, LLC.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//******************************************************************************

#import <Foundation/Foundation.h>
#import "ZAssert.h"

//------------------------------------------------------------------------------

// subclasses are encouraged define their own NSArray of
// types to add clarity to their APIs
#define NSArrayOfNSNumber NSArray
#define NSArrayOfNSString NSArray
#define NSArrayOfSelector NSArray
#define NSArrayOfNSURL NSArray

//------------------------------------------------------------------------------

@interface CottonObject : NSObject <NSCoding>

//------------------------------------------------------------------------------

@property (nonatomic, readonly) NSDictionary* dictionary;

//------------------------------------------------------------------------------

- (instancetype) init;
- (instancetype) initWithDictionary:(NSDictionary*)dictionary;
- (BOOL) dictionaryMatchesDeclaredProperties;

//------------------------------------------------------------------------------
#pragma mark Getters by NSString key
//------------------------------------------------------------------------------

- (BOOL) boolForKey:(NSString*)key;
- (CGFloat) floatForKey:(NSString*)key;
- (NSInteger) integerForKey:(NSString*)key;
- (NSNumber*) numberForKey:(NSString*)key;
- (SEL) selectorForKey:(NSString*)key;
- (NSString*) stringForKey:(NSString*)key;
- (NSURL*) urlForKey:(NSString*)key;
- (NSUInteger) unsignedIntegerForKey:(NSString*)key;

//------------------------------------------------------------------------------
#pragma mark Getters by SEL
//------------------------------------------------------------------------------

- (BOOL) boolForGetter:(SEL)getter;
- (CGFloat) floatForGetter:(SEL)getter;
- (NSInteger) integerForGetter:(SEL)getter;
- (NSNumber*) numberForGetter:(SEL)getter;
- (SEL) selectorForGetter:(SEL)getter;
- (NSString*) stringForGetter:(SEL)getter;
- (NSURL*) urlForGetter:(SEL)getter;
- (NSUInteger) unsignedIntegerForGetter:(SEL)getter;

//------------------------------------------------------------------------------
#pragma mark Setters by NSString key
//------------------------------------------------------------------------------

- (void) setBool:(BOOL)value forKey:(NSString*)key;
- (void) setFloat:(CGFloat)value forKey:(NSString*)key;
- (void) setInteger:(NSInteger)value forKey:(NSString*)key;
- (void) setNumber:(NSNumber*)value forKey:(NSString*)key;
- (void) setSelector:(SEL)selector forKey:(NSString*)key;
- (void) setString:(NSString*)value forKey:(NSString*)key;
- (void) setUrl:(NSURL*)url forKey:(NSString*)key;
- (void) setUnsignedInteger:(NSUInteger)value forKey:(NSString*)key;

//------------------------------------------------------------------------------
#pragma mark Setters by SEL
//------------------------------------------------------------------------------

- (void) setBool:(BOOL)value forSetter:(SEL)setter;
- (void) setFloat:(CGFloat)value forSetter:(SEL)setter;
- (void) setInteger:(NSInteger)value forSetter:(SEL)setter;
- (void) setNumber:(NSNumber*)value forSetter:(SEL)setter;
- (void) setSelector:(SEL)selector forSetter:(SEL)setter;
- (void) setString:(NSString*)value forSetter:(SEL)setter;
- (void) setUrl:(NSURL*)url forSetter:(SEL)setter;
- (void) setUnsignedInteger:(NSUInteger)value forSetter:(SEL)setter;

//------------------------------------------------------------------------------
#pragma mark - Readwrite property support
//------------------------------------------------------------------------------

- (void) setObject:(id)object forSetter:(SEL)setter;

//------------------------------------------------------------------------------
#pragma mark - Factory methods for child CottonObjects
//------------------------------------------------------------------------------

+ (NSArray*) arrayFromArray:(NSArray*)array withClass:(Class)aClass;
- (NSArray*) arrayWithClass:(Class)objectClass forKey:(NSString*)key;
- (id) objectWithClass:(Class)objectClass forKey:(NSString*)key;

//------------------------------------------------------------------------------

@end
