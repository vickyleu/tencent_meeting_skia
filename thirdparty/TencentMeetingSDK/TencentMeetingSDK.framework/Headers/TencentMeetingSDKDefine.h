//
//  TencentMeetingSDKDefine.h
//  TencentMeetingSDK
//
//  Created by zzjf on 2021/7/27.
//

#ifndef TencentMeetingSDKDefine_h
#define TencentMeetingSDKDefine_h


typedef NS_ENUM(NSInteger, TMSDKResult) {
    kTMSDKErrorSuccess = 0,
    kTMSDKErrorServerConfigFail = -1001,
    kTMSDKErrorInvalidAuthCode = -1002,
    kTMSDKErrorLogoutInMeeting = -1003,
    kTMSDKErrorLoginAborted = -1004,
    kTMSDKErrorUnknown = -1005,
    kTMSDKErrorUserNotAuthorized = -1006,
    kTMSDKErrorUserInMeeting = -1007,
    kTMSDKErrorInvalidParam = -1008,
    kTMSDKErrorInvalidMeetingCode = -1009,
    kTMSDKErrorInvalidNickname = -1010,
    kTMSDKErrorDuplicateInitCall = -1011,
    kTMSDKErrorAccountAlreadyLogin = -1012,
    kTMSDKErrorSdkNotInitialized = -1013,
    kTMSDKErrorSyncCallTimeout = -1014,
    kTMSDKErrorNotInMeeting = -1015,
    kTMSDKErrorCancelJoin = -1016,
    kTMSDKErrorIsLogining = -1017,
    kTMSDKErrorLoginNetError = -1018,
    kTMSDKErrorTokenVerifyFailed = -1019,
    kTMSDKErrorChildProcessCrash = -1020,
    kTMSDKErrorMultiAccountLoginConflict = -1021,
    kTMSDKErrorJoinMeetingServiceFailed = -1022,
    kTMSDKErrorActionConflict = -1023,
    kTMSDKErrorInvalidJsonString = -1024,
    kTMSDKErrorProxySetFailed = -1025,
    kTMSDKErrorInvalidSchemaString = -1026,
    kTMSDKErrorNotSupportSwitchPip = -1027,
    kTMSDKErrorInMeetingBackgroundNotSupportSwitchPip = -1028,
    kTMSDKErrorEnterPipFail = -1029,
    kTMSDKErrorEnterPipPermissionReject = -1030,
    kTMSDKErrorInUninitializing = -1032,
    kTMSDKErrorUnableUnInit = -1033,
    kTMSDKErrorOpenQRCodeUrlNotInWhiteList = -1063,
    kTMSDKErrorOpenQRCodeUrlInMeeing = -1064,
    kTMSDKErrorOpenQRCodeUrlNotLogin = -1065,

    kTMSDKErrorServerResourceConstraint = -2001,
    kTMSDKErrorAddUsersSuccess = -2002,
    kTMSDKErrorAddHostMoreThen10 = -2003,
    kTMSDKErrorAddNormalMoreThen300 = -2004,
    kTMSDKErrorAddUsersUidIsEmpty = -2005,
    kTMSDKErrorAddUsersMembersModelError = -2006,

    kTMSDKErrorInnerCallError = -3001,
    kTMSDKErrorDuplicatedCall = -3002,
};

typedef NS_ENUM(NSInteger, TMSDKActionType) {
    kTMSDKActionTypeShowPreMeetingView = 0,
    kTMSDKActionTypeShowScreenCastView = 1,
    kTMSDKActionTypeShowHistoricalMeetingView = 2,
    kTMSDKActionTypeShowMeetingDetailView = 3,
    kTMSDKActionTypeShowJoinMeetingView = 4,
    kTMSDKActionTypeShowScheduleMeetingView = 5,
    kTMSDKActionTypeShowMeetingSettingView = 6,
    kTMSDKActionTypeClosePreMeetingView = 7,
    kTMSDKActionTypeQueryMeetingInfo = 8,
    kTMSDKActionTypeInviteUsers = 9,
    kTMSDKActionTypeOpenLogPageView = 14,
    kTMSDKActionTypeSetCustomOrgInfo = 1000,
    kTMSDKActionTypeScreenShareComplete = 1002,
    kTMSDKActionTypeBreakoutRoomStatusChange = 1003,
    kTMSDKActionTypekCloudRecordStateChange = 1005,
};

typedef NS_ENUM(NSInteger, TMSDKMeetingState) {
    kTMSDKMeetingStateUnknown = -1,  //begin_time-now > 1 hour
    kTMSDKMeetingStateNotStarted = 0,  // Before begin time
    kTMSDKMeetingStateCancel = 1,      // User canceled
    kTMSDKMeetingStateStarted = 2,     // Anyone in the meeting
    kTMSDKMeetingStateDeleted = 3,         // Meeting is deleted
    kTMSDKMeetingStateNone = 6, // // After end time and nobody in the meeting
    kTMSDKMeetingStateRecycled = 7, // Meeting expired
};

typedef NS_ENUM(NSInteger, TMSDKWemeetActionType) {
    kTMSDKWemeetActionTypeChooseInviteUser
};

typedef NS_ENUM (NSInteger, TMSDKMainUIStyle) {
  kTMSDKMainUIStyleClassic,
  kTMSDKMainUIStyleTabs
};

typedef NS_ENUM (NSInteger, TMSDKInviteType) {
    TMSDKInviteTypeUnkown = 0,
    TMSDKInviteTypeScheduleHost,
    TMSDKInviteTypeScheduleNormal,
    TMSDKInviteTypeInmeetingJoin,
    TMSDKInviteTypePSTNInvite,
};

typedef NS_ENUM (NSInteger, TMSDKOrgQueryType) {
    TMSDKOrgQueryTypeUser = 0,
    TMSDKOrgQueryTypeWaitingRoom
};

typedef NS_ENUM (NSInteger, TMSDKAudioStatus) {
    TMSDKAudioStatusNone = 0,
    TMSDKAudioStatusMuted = 1,
    TMSDKAudioStatusAudioMutedByHost = 2,
    TMSDKAudioStatusAudioMutedAllByHost = 3,
    TMSDKAudioStatusAudioUnMuted = 4,
    TMSDKAudioStatusAudioUnMutedByHost = 5,
    TMSDKAudioStatusAudioUnMutedAllByHost = 6,
};

typedef NS_ENUM (NSInteger, TMSDKVideoStatus) {
    TMSDKVideoStatusVideoNone = 0,
    TMSDKVideoStatusVideoMuted = 1,
    TMSDKVideoStatusVideoMutedByHost = 2,
    TMSDKVideoStatusVideoUnMuted = 3,
    TMSDKVideoStatusVideoUnMutedByHost = 4,
};

typedef NS_ENUM (NSInteger, TMSDKAudioOutputDevice) {
    TMSDKAudioOutputDeviceNone = 0,
    TMSDKAudioOutputDeviceEarPhone = 1,
    TMSDKAudioOutputDeviceSpeaker = 2,
    TMSDKAudioOutputDeviceWiredheadset = 3,
    TMSDKAudioOutputDeviceBluetooth = 4,
};

#endif /* TencentMeetingSDKDefine_h */
