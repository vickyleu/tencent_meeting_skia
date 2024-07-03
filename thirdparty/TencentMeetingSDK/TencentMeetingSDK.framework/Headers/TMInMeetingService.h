//
//  TWMInMeetingService.h
//  TencentWeMeetSDK
//
//  Created by zzjf on 2021/7/12.
//

#import <Foundation/Foundation.h>
#import "TencentMeetingSDKDefine.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TMLeaveType) {
   kLeaveTypeSelf = 1,
   kLeaveTypeKickOut = 2,
   kLeaveTypeDissolve = 3
};

@protocol TMInMeetingProtocol <NSObject>
- (void)onLeaveMeeting:(TMLeaveType)type code:(TMSDKResult)code msg:(NSString *)msg meetingCode:(NSString *)meetingCode;
- (void)onInviteMeeting:(NSString *)invite_info;
- (void)onShowMeetingInfo:(NSString *)meeting_info;
- (void)onSwitchPiPResult:(TMSDKResult)code msg:(NSString *)msg;
@optional
- (void)onQueryCustomOrgInfo:(NSString *)userIds;
- (void)onInviteUsers:(NSString *)json_param;
- (void)onActionResult:(TMSDKActionType)actionType code:(TMSDKResult)code msg:(NSString *)msg;
- (void)onPiPModeChanged:(NSString *)data;
- (void)onCaptionSwitchChanged:(BOOL)is_open;
- (void)onCaptionSettingChanged:(NSString *)json_info;
- (void)onAudioStatusChanged:(TMSDKAudioStatus)audio_status;
- (void)onVideoStatusChanged:(TMSDKVideoStatus)video_status;
- (void)onAudioOutputDeviceChanged:(TMSDKAudioOutputDevice)audio_output_device;
@end

@interface TMInMeetingService : NSObject
+ (instancetype)instance;
- (void)setDelegate:(id<TMInMeetingProtocol>)delegate;
- (void)leaveMeeting:(int)leaveMeetingType;
- (void)enableInviteCallback:(BOOL)enable show:(BOOL)show;
- (void)enableMeetingInfoCallback:(BOOL)enable show:(BOOL)show;
- (void)enableInviteUsersCallback:(BOOL)enable show:(BOOL)show;
- (void)enableCustomOrgInfo:(BOOL)enable;
- (void)switchPIPModel:(BOOL)isPIPModel;
- (void)bringInMeetingViewTop;
- (NSString *)getCurrentMeetingInfo;
- (void)setCustomOrgInfo:(NSString *)info;
- (void)switchCaption:(BOOL)open complete:(void(^ __nullable)(int32_t, NSString * __nullable))handler;
- (void)updateCaptionSettings:(NSString *)json_setting complete:(void(^ __nullable)(int32_t, NSString * __nullable))handler;
- (NSString *)getScreenShareInfo;
- (void)setLeaveCastRoomActionType:(NSString *)actionType;
@end

NS_ASSUME_NONNULL_END
