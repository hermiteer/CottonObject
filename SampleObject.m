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

#import "SampleObject.h"

//------------------------------------------------------------------------------

@implementation SampleObject

//------------------------------------------------------------------------------
#pragma mark - Readonly properties
//------------------------------------------------------------------------------

- (NSString*) name
{
    return [self stringForGetter:_cmd];
}

//------------------------------------------------------------------------------

- (NSNumber*) type
{
    return [self numberForGetter:_cmd];
}

//------------------------------------------------------------------------------
#pragma mark - Mutable properties
//------------------------------------------------------------------------------

- (NSString*) title
{
    return [self stringForGetter:_cmd];
}

//------------------------------------------------------------------------------

- (void) setTitle:(NSString*)title
{
    [self setString:title forSetter:_cmd];
}

//------------------------------------------------------------------------------
#pragma mark - Child properties
//------------------------------------------------------------------------------

- (SampleObject*) childObject
{
    return [self objectWithClass:SampleObject.class
                          forKey:NSStringFromSelector(_cmd)];
}

//------------------------------------------------------------------------------

@end
