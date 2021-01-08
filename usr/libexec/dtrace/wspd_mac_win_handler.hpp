//
//  wspd_mac_win_handler.hpp
//  wspd
//
//  Created by Or Haimovich on 02/04/2019.
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#include "wspd_msg.hpp"
#include "wspd_row_msg_handler.hpp"

CFStringRef wspd_CreateItemTypeTextToWin(CFTypeRef MDvalue, MDItemRef MDrowRef);
CFStringRef wspd_CreateItemTypeTextFromWin(CFStringRef sWindowsItemTypeToSearch);
CFStringRef wspd_CreateItemTypeToWin(CFTypeRef MDvalue, MDItemRef MDrowRef);
CFStringRef wspd_CreateItemTypeFromWin(CFStringRef sWindowsItemTypeToSearch, uint32_t uMethod);
CFStringRef wspd_CreateFileExtention(CFStringRef sFileName);
CFStringRef wspd_CreateItemKindToWin(CFTypeRef MDvalue);
CFStringRef wspd_CreateItemKindQueryFromWin(CFStringRef sWindowsItemKindToSearch);
CFStringRef wspd_CreateLocalPathToNarrowDisply(CFTypeRef MDvalue, wspdConnectionInfo_s* wspConn);
CFStringRef wspd_CreateLocalPathToServerPath(CFTypeRef MDvalue, wspdConnectionInfo_s* wspConn);
CFStringRef wspd_CreateLocalPathToParent(CFTypeRef MDvalue, wspdConnectionInfo_s* wspConn);
uint64_t    wspd_TimeFrom2001To1601(uint64_t uNewTime);
uint32_t    wspd_TimeFrom1601To2001(uint64_t uOldTime, int64_t* puNewTime);
uint32_t    wspd_CreateSFGAOFlagsAccordingToAttr(wspd_FileAttributes_t* psFileAttr);
