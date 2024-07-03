//
//  TencentWeMeetSDK.m
//  TencentWeMeetSDK
//
//  Created by zzjf on 2021/7/12.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TMAccountService.h"
#import "TMPreMeetingService.h"
#import "TMInMeetingService.h"
#import "TencentMeetingSDKDefine.h"
NS_ASSUME_NONNULL_BEGIN

@interface TMInitParam : NSObject
@property (nonatomic, copy) NSString *sdkId;
@property (nonatomic, copy) NSString *sdkToken;
/// 私有化服务器地址，格式为：{protocol}://{domain}:{port}，protocol默认为http；port默认为29666
@property (nonatomic, copy) NSString *serverAddress;
/// 组织机构域，如填写，SDK则会通过org_domain从公有云服务上获取私有化服务器地址，并覆盖server_host的值
@property (nonatomic, copy) NSString *orgDomain;
@property (nonatomic, copy) NSString *appName;
@property (nonatomic, copy) NSString *proxyInfo;
@property (nonatomic, weak) UIWindow *keyWindow;
@property (nonatomic, strong) NSDictionary *ext;
@property (nonatomic, copy) NSString *preferLanguage;
@property (nonatomic, copy) NSString *extensionBundleId;
@property (nonatomic, strong) UIImage *pipIconImage;
@end

@protocol TMSDKProtocol <NSObject>
- (void)onSDKInitializeResult:(TMSDKResult)code msg:(NSString *)msg;
- (void)onSDKError:(TMSDKResult)code msg:(NSString *)msg;
- (void)onResetSDKState:(TMSDKResult)code msg:(NSString *)msg;
- (void)onShowLogsResult:(TMSDKResult)code msg:(NSString *)msg;
- (void)onHandleWemeetAction:(TMSDKWemeetActionType)actionType param:(NSString *)param;
- (void)onHandleSchemaResult:(TMSDKResult)code msg:(NSString *)msg;
- (void)onSetProxyInfoResult:(TMSDKResult)code msg:(NSString *)msg;
- (void)onAddUsersResult:(TMSDKInviteType)userType code:(TMSDKResult)code msg:(NSString *)msg;
- (void)onParseMeetingInfoUrlCode:(NSInteger)code param:(NSString *)param;
- (void)onActiveUploadLogsResult:(TMSDKResult)code msg:(NSString *)msg;
@optional
- (void)onSDKUninitializeResult:(TMSDKResult)code msg:(NSString *)msg;
@end

@interface TencentMeetingSDK : NSObject
+ (instancetype)instance;

- (void)initialize:(TMInitParam *)params
          delegate:(id<TMSDKProtocol>)delegate;

//- (void)uninitialize:(NSString *)param;

- (BOOL)isInitialized;

- (void)updateDelegate:(id<TMSDKProtocol>)delegate;

- (TMSDKResult)refreshSDKToken:(NSString *)newSDKToken;

- (NSString *)getCurrentSDKToken;

- (NSString *)getSDKVersion;

- (void)showLogs;

/**
 * 带登陆态链接入会
 */
- (void)handleSchema:(NSString *)schemaUrl;

- (void)addUsersWithParam:(NSString *)params;


/// 设置代理信息
/// - Parameter proxyInfo: 代理信息
- (void)setProxyInfo:(NSString *)proxyInfo;
- (NSString *)getProxyInfo;
- (void)parseMeetingInfoUrl:(NSString *)schemaUrl;

- (void)appMultiWindowLayoutTypeChangedFromSize:(CGSize)fromSize toSize:(CGSize)toSize;
- (void)discardSceneSession:(UISceneSession *)session API_AVAILABLE(ios(13.0));
- (void)discardSceneSessionsExcept:(nonnull UISceneSession *)session API_AVAILABLE(ios(13.0));

- (NSArray <NSString *>*)collectLogFiles:(uint64_t)beginTime
                             endTime:(uint64_t)endTime;
- (void)activeUploadLogs:(uint64_t)beginTime endTime:(uint64_t)endTime description:(NSString *)description;
- (TMAccountService *)getAccountService;
- (TMPreMeetingService *)getPreMeetingService;
- (TMInMeetingService *)getInMeetingService;
@end

NS_ASSUME_NONNULL_END
