#!/bin/sh
########################################################################
#
#  build.sh
#
#  Created by wuyj on 14/9/18.
#  Copyright (c) 2018 asiainfo. All rights reserved.
#
########################################################################

# 应用targetName，一般应用的根目录的名称
targetName="WMShell"

#当前证书的ID标识
code_sign_identity="iPhone Distribution: Beijing WeiMeiTianCheng Technology Co., Ltd."

#证书签名文件名
code_sign_profile="WeiMeiShellDis_profile.mobileprovision"



########################
#执行打包脚本
. ./core.sh

