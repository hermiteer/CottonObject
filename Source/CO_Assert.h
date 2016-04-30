//******************************************************************************
//  Created by Christoph on 8/1/14.
//  Referenced from http://www.cimgf.com/2010/05/02/my-current-prefix-pch-file/
//******************************************************************************

#ifndef CO_Assert_h
#define CO_Assert_h

#ifdef DEBUG
    #define CO_ALog(...) [[NSAssertionHandler currentHandler] handleFailureInFunction:[NSString stringWithCString:__PRETTY_FUNCTION__ encoding:NSUTF8StringEncoding] file:[NSString stringWithCString:__FILE__ encoding:NSUTF8StringEncoding] lineNumber:__LINE__ description:__VA_ARGS__]
#else
    #ifndef NS_BLOCK_ASSERTIONS
        #define NS_BLOCK_ASSERTIONS
    #endif
    #define CO_ALog(...) NSLog(@"%s %@", __PRETTY_FUNCTION__, [NSString stringWithFormat:__VA_ARGS__])
#endif

#define CO_Assert(condition, ...) do { if (!(condition)) { CO_ALog(__VA_ARGS__); }} while(0)
#define CO_AssertReturn(condition, ...) do { if (!(condition)) { CO_ALog(__VA_ARGS__); return; }} while(0)
#define CO_AssertReturnNil(condition, ...) do { if (!(condition)) { CO_ALog(__VA_ARGS__); return nil; }} while(0)

#endif
