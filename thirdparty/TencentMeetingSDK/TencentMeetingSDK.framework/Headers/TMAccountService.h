//
//  TMAccountService.h
//  TencentWeMeetSDK
//
//  Created by zzjf on 2021/7/12.
//

#import <Foundation/Foundation.h>
#import "TencentMeetingSDKDefine.h"

typedef NS_ENUM(NSInteger, TMLogoutType) {
    TMLogoutType_Manual                     = 1,        // 手动登出
    TMLogoutType_Force                      = 2,        // 强制登出
};


typedef NS_ENUM(NSInteger, TMLoginType) {
  TMLoginTypePrivateWeWork                     = 1,
  TMLoginTypeSaasWeWork                 = 2,
};


NS_ASSUME_NONNULL_BEGIN

@protocol TMAuthenticationProtocol <NSObject>
- (void)onLogin:(TMSDKResult)code msg:(NSString *)msg;
- (void)onLogout:(TMLogoutType)type code:(TMSDKResult)code msg:(NSString *)msg;
- (void)onJumpUrlWithLoginStatus:(TMSDKResult)code msg:(NSString *)msg;
@end



@interface TMAccountService : NSObject

+ (instancetype)instance;

- (void)setDelegate:(id<TMAuthenticationProtocol>)delegate;

- (void)login:(NSString *)SSOUrl;
- (void)login:(NSString *)SSOUrl forceKickOtherDevice:(BOOL)forceKickOtherDevice;
- (void)loginByAccountPassword:(NSString *)SSOUrl userName:(NSString *)userName password:(NSString *)password;
- (void)loginByJSON:(NSString *)jsonString;

- (void)logout;

- (BOOL)isLoggedIn;

/**
 * 带登录态的网页跳转
 */
- (void)jumpUrlWithLoginStatus:(NSString *)targetUrl;

/**
 * 获取带登录态的Url
 */
- (NSString *)getUrlWithLoginStatus:(NSString *)targetUrl;

- (void)quickLoginWithUserId:(NSString *)userId loginType:(TMLoginType)loginType;

- (void)loginWithAuthCode:(NSString *)authCode userId:(NSString *)userId loginType:(TMLoginType)loginType;

@end

NS_ASSUME_NONNULL_END
