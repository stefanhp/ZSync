/*
 *  ZSyncHandler.h
 *  ZSync
 *
 *  Created by Marcus S. Zarra on 11/8/09.
 *  Copyright 2009 Zarra Studios, LLC. All rights reserved.
 *
 *  Permission is hereby granted, free of charge, to any person
 *  obtaining a copy of this software and associated documentation
 *  files (the "Software"), to deal in the Software without
 *  restriction, including without limitation the rights to use,
 *  copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following
 *  conditions:
 *
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *  OTHER DEALINGS IN THE SOFTWARE.
 */

#import <SyncServices/SyncServices.h>
#import "ZSyncShared.h"
#import "ZSyncConnectionDelegate.h"

@interface ZSyncHandler : NSObject <TCPListenerDelegate>
{
  NSManagedObjectContext *managedObjectContext;
  NSMutableArray *_connections;
  NSString *_serverName;
  
  BLIPListener *_listener;
  
  id _delegate;
}

@property (readonly) NSMutableArray *connections;
@property (assign) id delegate;
@property (retain) NSString *serverName;
@property (retain) BLIPListener *listener;

+ (id)shared;

- (void)startBroadcasting;
- (void)stopBroadcasting;

- (void)connectionClosed:(ZSyncConnectionDelegate*)connection;

- (NSBundle*)pluginForSchema:(NSString*)schema;

- (void)unregisterApplication:(NSManagedObject*)applicationObject;
- (NSManagedObject*)registerDevice:(NSString*)deviceUUID withName:(NSString*)deviceName;
- (NSManagedObject*)registerApplication:(NSString*)schema withClient:(NSString*)clientUUID withDevice:(NSManagedObject*)device;

@end
