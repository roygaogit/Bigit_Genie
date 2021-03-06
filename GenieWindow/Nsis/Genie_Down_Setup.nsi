﻿; Script generated by the HM NIS Edit Script Wizard.
;-----------------------------------------
; NETGEAR Genie Install/Unistall Program
; author:peter.zhang
; time:2010.7.23 	update:
;-----------------------------------------

; Define your application name
!define APPNAME "NETGEAR Genie Download"

!include "define_download.nsh"

!define APPNAMEANDVERSION "${APPNAME}"

XPstyle on
;Main Install settings
Name "${APPNAMEANDVERSION}"

;InstallDir "C:\NETGEAR Genie Downloads"


BrandingText "${APPNAMEANDVERSION}"
; Use compression
SetCompressor LZMA

; Modern interface settings
!include "Sections.nsh"
!include "MUI.nsh"

;Interface Settings
!define MUI_ABORTWARNING
!define MUI_HEADERIMAGE
!define MUI_HEADERIMAGE_BITMAP "Graphics\bmps\Genie_Down_title.bmp"

# MUI defines
!define MUI_ICON "Graphics\icons\Genie_Down_install.ico"
!define MUI_FINISHPAGE_NOAUTOCLOSE
;!define MUI_LICENSEPAGE_RADIOBUTTONS
;!define MUI_COMPONENTSPAGE_SMALLDESC

; Language Selection Dialog Settings

;!define MUI_LANGDLL_REGISTRY_VALUENAME "NSIS:Language"
!define MUI_LANGDLL_REGISTRY_VALUENAME InstallerLanguage

; Defines the installer /uninstall logo of Genie
;!insertmacro MUI_DEFAULT MUI_WELCOMEFINISHPAGE_BITMAP "Graphics\bmps\Genie_install.bmp"

; Set languages (first is default language)

!insertmacro MUI_RESERVEFILE_LANGDLL
ReserveFile "${NSISDIR}\Plugins\AdvSplash.dll"

;--------------------------------
;Configuration

# Installer pages
;!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_INSTFILES
;!insertmacro MUI_PAGE_FINISH

# Installer languages
!define MUI_LANGDLL_ALLLANGUAGES

	!insertmacro MUI_LANGUAGE "English"
	!insertmacro MUI_LANGUAGE "German"
	!insertmacro MUI_LANGUAGE "Swedish"
	!insertmacro MUI_LANGUAGE "French"
	!insertmacro MUI_LANGUAGE "Dutch"
	!insertmacro MUI_LANGUAGE "Italian"
	!insertmacro MUI_LANGUAGE "Spanish"
	!insertmacro MUI_LANGUAGE "Danish"
	!insertmacro MUI_LANGUAGE "Finnish"
	!insertmacro MUI_LANGUAGE "Norwegian"
	!insertmacro MUI_LANGUAGE "Greek"
	!insertmacro MUI_LANGUAGE "Portuguese"
	!insertmacro MUI_LANGUAGE "Russian"
	!insertmacro MUI_LANGUAGE "Polish"
	!insertmacro MUI_LANGUAGE "Hungarian"
	!insertmacro MUI_LANGUAGE "Czech"
	!insertmacro MUI_LANGUAGE "Slovenian"
	!insertmacro MUI_LANGUAGE "Slovak"
	!insertmacro MUI_LANGUAGE "Romanian"
	;!insertmacro MUI_LANGUAGE "Bulgarian"
	;!insertmacro MUI_LANGUAGE "Croatian"
	!insertmacro MUI_LANGUAGE "SimpChinese"
	!insertmacro MUI_LANGUAGE "Korean"
	;!insertmacro MUI_LANGUAGE "Japanese"
	!insertmacro MUI_LANGUAGE "Arabic"

	!include "language_down.nsh"



Section "MainSection" SEC01
SetOutPath $TEMP
;File "InetLoad.dll"
File "NSISdl.dll"
;NSISdl::download http://192.168.9.3/netgeargenie/update/NETGEARGenie-install.exe NETGEARGenie-install.exe
;NSISdl::download http://192.168.9.3/test/update2/NETGEARGenie-install.exe NETGEARGenie-install.exe
;NSISdl::download http://eccdemo.siteview.com:8088/test/update2/NETGEARGenie-install.exe NETGEARGenie-install.exe
NSISdl::download http://updates1.netgear.com/netgeargenie/update/NETGEARGenie-install.exe NETGEARGenie-install.exe
;NSISdl::download http://ftp-dg.pconline.com.cn/pub/download/201007/haozip_v2.0.exe
Pop $R0 ; 获取返回值
  StrCmp $R0 "success" +3
   MessageBox MB_OK "$(install_info)：$R0"
   Quit


ExecWait '$TEMP\NETGEARGenie-install.exe'
;Exec '$TEMP\NETGEARGenie-install.exe'

SectionEnd
Function .onInit
	SetShellVarContext all
;!insertmacro MUI_RESERVEFILE_INSTALLOPTIONS
  ;!insertmacro MUI_LANGDLL_DISPLAY
  ;Language selection dialog
	;-----------------------------
/*	Push ""
	Push ${LANG_ENGLISH}
	Push English
	;Push ${LANG_FRENCH}
	;Push French
	Push ${LANG_GERMAN}
	Push German
	Push ${LANG_SPANISH}
	Push Spanish
	Push ${LANG_PORTUGUESE}
	Push Portuguese
	;Push ${LANG_TRADCHINESE}
	;Push "Traditional Chinese"
	Push ${LANG_SIMPCHINESE}
	Push "Simplified Chinese"
	;Push Simplified Chinese
	Push A ; A means auto count languages
	       ; for the auto count to work the first empty push (Push "") must remain
	LangDLL::LangDialog "$(multilan_title)" "$(multilan_info)"

	Pop $LANGUAGE
	StrCmp $LANGUAGE "cancel" 0 +2
		Abort*/

	; 仅当系统语言未支持时才让用户选择
	IntCmp $LANGUAGE 1033 lang_sel_end
	IntCmp $LANGUAGE 1031 lang_sel_end
	IntCmp $LANGUAGE 1053 lang_sel_end
	IntCmp $LANGUAGE 1036 lang_sel_end
	IntCmp $LANGUAGE 1043 lang_sel_end
	IntCmp $LANGUAGE 1040 lang_sel_end
	IntCmp $LANGUAGE 1034 lang_sel_end
	IntCmp $LANGUAGE 1030 lang_sel_end
	IntCmp $LANGUAGE 1035 lang_sel_end
	IntCmp $LANGUAGE 1044 lang_sel_end
	IntCmp $LANGUAGE 1032 lang_sel_end
	IntCmp $LANGUAGE 2070 lang_sel_end ; Portuguese
	IntCmp $LANGUAGE 1049 lang_sel_end
	IntCmp $LANGUAGE 1045 lang_sel_end
	IntCmp $LANGUAGE 1038 lang_sel_end
	IntCmp $LANGUAGE 1029 lang_sel_end
	IntCmp $LANGUAGE 1060 lang_sel_end
	IntCmp $LANGUAGE 1051 lang_sel_end
	IntCmp $LANGUAGE 1048 lang_sel_end
	;IntCmp $LANGUAGE 1026 lang_sel_end
	;IntCmp $LANGUAGE 1050 lang_sel_end
	IntCmp $LANGUAGE 2052 lang_sel_end
	IntCmp $LANGUAGE 1042 lang_sel_end
	IntCmp $LANGUAGE 1041 lang_sel_end
	;IntCmp $LANGUAGE 1025 lang_sel_end
	!insertmacro MUI_LANGDLL_DISPLAY

lang_sel_end:

FunctionEnd

