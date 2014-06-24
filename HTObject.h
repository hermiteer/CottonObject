//******************************************************************************
//  HTObject - a thin wrapper around NSDictionary to make life better with
//  JSON (and other) network objects.  For more details, checkout the github
//  for this project http://github.com/hermiteer/HTObject
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

//------------------------------------------------------------------------------

// TODO
// explain that this is provided as a convenience to help formalize objects
// and make the easier for clients to understand
#define NSArrayOfNSNumber NSArray
#define NSArrayOfNSString NSArray
#define NSArrayOfSelector NSArray
#define NSArrayOfNSURL NSArray

//------------------------------------------------------------------------------

@interface HTObject : NSObject <NSCoding>

//------------------------------------------------------------------------------

@property (nonatomic, readonly) NSDictionary* dictionary;

//------------------------------------------------------------------------------

- (id) initWithDictionary:(NSDictionary*)dictionary;

//------------------------------------------------------------------------------

// TODO
// clean up
// make note about how the converted value is updated in the dictionary
// so the next call will not do the same work again
- (NSArray*) arrayWithClass:(Class)objectClass forKey:(NSString*)key;
- (id) objectWithClass:(Class)objectClass forKey:(NSString*)key;

// TODO
// make a version of objectForKey that takes an SEL and does the
// selector to string conversion to save on typing for property implementations
- (void) setObject:(id)object withSetter:(SEL)setter;

//------------------------------------------------------------------------------

- (NSNumber*) numberForKey:(NSString*)key;
- (SEL) selectorForKey:(NSString*)key;
- (NSString*) stringForKey:(NSString*)key;
- (NSURL*) urlForKey:(NSString*)key;

//------------------------------------------------------------------------------

- (BOOL) boolForKey:(NSString*)key;
- (CGFloat) floatForKey:(NSString*)key;
- (NSInteger) integerForKey:(NSString*)key;
- (NSUInteger) unsignedIntegerForKey:(NSString*)key;

//------------------------------------------------------------------------------

- (BOOL) dictionaryMatchesDeclaredProperties;

//------------------------------------------------------------------------------

+ (NSArray*) arrayFromArray:(NSArray*)array withClass:(Class)aClass;

//------------------------------------------------------------------------------

@end
