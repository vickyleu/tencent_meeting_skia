//
//  TWMPreMeetingService.h
//  TencentWeMeetSDK
//
//  Created by zzjf on 2021/7/12.
//

#import <Foundation/Foundation.h>
#import "TencentMeetingSDKDefine.h"


NS_ASSUME_NONNULL_BEGIN
@protocol TMPreMeetingProtocol <NSObject>
- (void)onJoinMeeting:(TMSDKResult)code msg:(NSString *)msg meetingCode:(NSString *)meetingCode;
- (void)onShowScreenCastViewResult:(TMSDKResult)code msg:(NSString *)msg;
- (void)onActionResult:(TMSDKActionType)actionType code:(TMSDKResult)code msg:(NSString *)msg;
- (void)onShowAddressBook:(TMSDKInviteType)userType users:(NSString *)users;
@optional
- (void)onRingInvitationEvent:(int32_t)ring_state ringInfo:(NSString *)ring_info;
- (void)onOpenQRCodeUrlResult:(TMSDKResult)code url:(NSString *)url msg:(NSString *)msg;
@end

@interface TMJoinParam : NSObject
/// 会议号
@property (nonatomic, copy) NSString *meetingCode;
/// 用户名
@property (nonatomic, copy) NSString *userDisplayName;
/// 会议密码
@property (nonatomic, copy) NSString *password;
/// 邀请链接
@property (nonatomic, copy) NSString *inviteUrl;
/// 是否开启麦克风
@property (nonatomic, assign) BOOL micOn;
/// 是否开启摄像头
@property (nonatomic, assign) BOOL cameraOn;
/// 是否开启扬声器
@property (nonatomic, assign) BOOL speakerOn;
/// 是否开启美颜
@property (nonatomic, assign) BOOL faceBeautyOn;
/// 会中窗口的标题
@property (nonatomic, copy) NSString *meetingWindowTitle;
@end

@interface TMPreMeetingService : NSObject
+ (instancetype)instance;
- (void)setDelegate:(id<TMPreMeetingProtocol>)delegate;

/**
 * 进入主页面
 */
- (void)showPreMeetingView;

/**
 * 进入主页面
 * style 主页UI样式
 */
- (void)showPreMeetingView:(TMSDKMainUIStyle)style;
/**
 * 无线投屏
 */
- (void)showScreenCastView;

/**
 * 加入会议，传入的JoinParam对象
 */
- (void)joinMeeting:(TMJoinParam *)param;

/**
 * 加入会议，传入的Json字符串
 */
- (void)joinMeetingByJSON:(NSString *)param;

/**
 * 进入历史会议列表页面
 */
- (void)showHistoricalMeetingView;

/**
 * 进入会议详情页面，默认历史会议，会议详情
 */
- (void)showMeetingDetailView:(NSString *)meetingId currentSubMeetingId:(NSString *)currentSubMeetingId;

- (void)showMeetingDetailView:(NSString *)meetingId 
          currentSubMeetingId:(NSString *)currentSubMeetingId 
                    beginTime:(NSString *)beginTime 
                    isHistory:(BOOL)isHistory;

/**
 * 展示加入会议界面
 */
- (void)showJoinMeetingView;

/**
 * 展示预定会议界面
 */
- (void)showScheduleMeetingView:(int)meetingType;

/**
 * 展示设置管理界面
 */
- (void)showMeetingSettingView;

/**
 * 查询会议信息，结果通过onActionResult获取
 */
- (void)queryMeetingInfo:(NSString *)param;

/**
 * 快速会议
 */
- (void)quickMeeting;

/**
 * 快速会议，传入的Json字符串
 */
- (void)quickMeetingByJSON:(NSString *)quickMeetingJSON;

- (void)enableAddressBookCallback:(BOOL)enable show:(BOOL)show;

/**
 * 开始投屏
 */
- (void)startScreenCast:(NSString *)screenCastJSON;
/**
 * 唤起日志上传页面
 */
- (void)openLogPageView;

/**
 * 启用响铃邀请回调，配置是否同时展示默认响铃接听页面
 */
- (void)enableRingInvitationView:(BOOL)enable;

/**
 * 处理指定invite id的响铃邀请
 */
- (void)handleRingInvitation:(BOOL)accept inviteId:(NSString *)invite_id complete:(void(^ __nullable)(int32_t, NSString * __nullable))handler;

/**
 * 二维码扫码后入口
 */
- (void)openQRCodeUrl:(NSString * __nonnull)urlString;
/**
 * 打开隐私安全页面
 */
- (void)openPrivacyPage;

@end

NS_ASSUME_NONNULL_END
