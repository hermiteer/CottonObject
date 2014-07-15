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

#import "AppDelegate.h"
#import "SampleObject.h"

//------------------------------------------------------------------------------

@implementation AppDelegate

//------------------------------------------------------------------------------

- (BOOL) application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)options
{
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window.backgroundColor = [UIColor whiteColor];
    [self.window makeKeyAndVisible];
    [self runObjectTests];
    return YES;
}

//------------------------------------------------------------------------------

- (void) runObjectTests
{
    // create the object from a plist
    // this is an example of how to fake data while developing
    // the JSON blob from a web endpoint gets turned into an NSDictionary
    // so it's easy to see how a response block can return your
    // strongly typed CottonObject subclass
    NSURL* url = [[NSBundle mainBundle] URLForResource:@"SampleObject" withExtension:@"plist"];
    NSDictionary* dictionary = [NSDictionary dictionaryWithContentsOfURL:url];
    SampleObject* object = [[SampleObject alloc] initWithDictionary:dictionary];

    // accessing values using dot notation
    NSLog(@"sampleObject.name = %@", object.name);
    NSLog(@"sampleObject.type = %@", object.type.stringValue);

    // setting values using dot notation
    object.title = @"SOME TITLE";

    // dump the whole object
    NSLog(@"Sample Object %@", object.description);
    NSLog(@"Child Object %@", object.childObject.description);

    // set a nil value (which is ignored)
    // a message will be logged only for DEBUG builds
    object.title = nil;

    // validate the object
    // use this in unit tests to make sure the client and
    // the endpoint are in step
    BOOL matches = [object dictionaryMatchesDeclaredProperties];
    NSLog(@"Does this object's dictionary matches the declared properties %@", (matches ? @"YES" : @"NO"));
}

//------------------------------------------------------------------------------

@end
