#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 The ARAPIKey is singleton based class which is used to keep track of the license key which is used to access KudanAR functonality.
 */
@interface ARAPIKey : NSObject

/**
   @return ARARPIkey singleton.
 **/
+ (instancetype)sharedInstance;

/**
 Sets the application's API key. You can find a list of our development licence keys here: <a href="https://wiki.kudan.eu/Development_License_Keys">Development Licence Keys</a>.
 If you require a unique API key for your application you can purchase one here: <a href="https://www.kudan.eu/sdk-pricing/">SDK Pricing</a>.
 
 @param key API License Key.
 **/
- (void)setAPIKey:(NSString *)key;

/**
 Returns whether the API License Key is valid or not.
 **/
- (BOOL)keyIsValid;

@end

NS_ASSUME_NONNULL_END
