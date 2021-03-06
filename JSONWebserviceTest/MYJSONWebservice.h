//
//  MYJSONWebservice.h
//  JSONWebserviceTest
//
//  Copyright (C) 2013, Matt York
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy of
//  this software and associated documentation files (the "Software"), to deal in
//  the Software without restriction, including without limitation the rights to
//  use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
//  of the Software, and to permit persons to whom the Software is furnished to do
//  so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.
//

#import <Foundation/Foundation.h>

#define HTTP_METHOD_POST @"POST"
#define HTTP_METHOD_GET @"GET"
#define HTTP_METHOD_PUT @"PUT"
#define HTTP_METHOD_DELETE @"DELETE"

#define kMaxConcurrentConnections 5

#pragma mark - MySampleClass Interface
/*  This is a class created purely for the sake of demoing webservice interaction with a custom object.
 Its use is restricted to viewDidLoad: in MYViewController.m (construction) and the "sampleComplexWebserviceMethod"
 in MYJSONWebservice.m (consumption). You may delete its interface and implementation at your discretion.
 */
@interface MYSampleClass : NSObject
@property (nonatomic, retain) NSString* FirstName;
@property (nonatomic, retain) NSString* LastName;
@property (nonatomic, assign) int Age;

//On a better day, one might consider building the dictionary via reflection
+(NSDictionary *)dictionaryForMYSampleClass:(MYSampleClass *)sample;
@end
/***************************************************************/



#pragma mark - Webservice

@protocol WebserviceDelegate
@optional
-(void)sampleMethodDidReturnWithDictionary:(NSDictionary *)responseDictionary;
@end


// Typedef Blocks
typedef void (^SampleWebserviceBlock) (NSDictionary *responseDictionary);
typedef void (^SampleComplexWebserviceBlock) (NSDictionary *responseDictionary);

@interface MYJSONWebservice : NSObject

// Properties
@property (weak) id <WebserviceDelegate> delegate;
@property (nonatomic, retain) NSOperationQueue *MYJSONOperationQueue;

// Init
-(id)initWithDelegate:(id <WebserviceDelegate>)delegate;

// Request Builder
+(NSMutableURLRequest *)RequestForMethod:(NSString *)method withBodyData:(NSData *)data forHttpMethod:(NSString *)httpMethod;

// Delegated Webservice Methods
-(void)sampleWebserviceMethod:(NSString *)sampleString;
-(void)sampleComplexWebserviceMethod:(MYSampleClass *)sampleClass;

// Block Based Webservice Methods
-(void)sampleWebserviceMethod:(NSString *)sampleString completion:(SampleWebserviceBlock)completion;
-(void)sampleComplexWebserviceMethod:(MYSampleClass *)sampleClass completion:(SampleComplexWebserviceBlock)completion;

@end







