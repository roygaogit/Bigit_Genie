#ifndef INNER_MACROS_H
#define INNER_MACROS_H
#define __IFACE2_HANDLER_CMD(__IFACE2_HANDLER_CMD_cmd,__IFACE2_HANDLER_CMD_para) ( (QGenieIface2ShareObject::sSingleInstance && QGenieIface2ShareObject::sSingleInstance->mHandler )?\
    (QGenieIface2ShareObject::sSingleInstance->mHandler->handler_command((__IFACE2_HANDLER_CMD_cmd),(QGenieIface2ShareObject::sUuidIdx),(__IFACE2_HANDLER_CMD_para))):QVariant())

#define __IFACE2_REGISTER_UI(__IFACE2_REGISTER_UI_p,__IFACE2_REGISTER_UI_t) do{\
if(QGenieIface2ShareObject::sSingleInstance && QGenieIface2ShareObject::sSingleInstance->mHandler )\
{\
    QVariant __IFACE2_REGISTER_UI_v;__IFACE2_REGISTER_UI_v.setValue((void *)(__IFACE2_REGISTER_UI_p));\
    QList<QVariant> __IFACE2_REGISTER_UI_lst;__IFACE2_REGISTER_UI_lst<<__IFACE2_REGISTER_UI_v<<QString(__IFACE2_REGISTER_UI_t)<<QGenieIface2ShareObject::sUuidIdx;\
    __IFACE2_HANDLER_CMD(HCMD_REGISTER_UI,__IFACE2_REGISTER_UI_lst);\
}\
}while(0)

#define __IFACE2_REGISTER_DBG_UI__(__IFACE2_REGISTER_DBG_UI__w) do{\
    QVariant __IFACE2_REGISTER_DBG_UI__v;\
    __IFACE2_REGISTER_DBG_UI__v.setValue((void *)__IFACE2_REGISTER_DBG_UI__w);\
    __IFACE2_HANDLER_CMD(HCMD_REGISTER_DBG_UI,__IFACE2_REGISTER_DBG_UI__v);\
}while(0)

#define __IFACE2_LOG_(__IFACE2_LOG__log) __IFACE2_HANDLER_CMD(HCMD_LOG,__IFACE2_LOG__log)


//#define __IFACE2_TELL_OTHER_PLUGIN(__IFACE2_TELL_OTHER_PLUGIN_uuid,__IFACE2_TELL_OTHER_PLUGIN_msg,__IFACE2_TELL_OTHER_PLUGIN_paras) do {\
//    QList<QVariant> __IFACE2_TELL_OTHER_PLUGIN_lst;__IFACE2_TELL_OTHER_PLUGIN_lst<<QVariant(__IFACE2_TELL_OTHER_PLUGIN_uuid)<<QVariant(__IFACE2_TELL_OTHER_PLUGIN_msg)<<QVariant(__IFACE2_TELL_OTHER_PLUGIN_paras);\
//    __IFACE2_HANDLER_CMD(HCMD_TELL_OTHERPLUGIN,__IFACE2_TELL_OTHER_PLUGIN_lst);\
//}while(0)

#define __IFACE2_TELL_OTHER_PLUGIN(__IFACE2_TELL_OTHER_PLUGIN_uuid,__IFACE2_TELL_OTHER_PLUGIN_msg,__IFACE2_TELL_OTHER_PLUGIN_paras) \
    __IFACE2_HANDLER_CMD(HCMD_TELL_OTHERPLUGIN,(QVariantList()<<QVariant(__IFACE2_TELL_OTHER_PLUGIN_uuid)\
    <<QVariant(__IFACE2_TELL_OTHER_PLUGIN_msg)<<QVariant(__IFACE2_TELL_OTHER_PLUGIN_paras)))


    //cmd,bbtidx,_para,uuid
#define __IFACE2_UI_COMMAND_MULTI_BBT(__IFACE2_UI_COMMAND_MULTI_BBT_uicmd,__IFACE2_UI_COMMAND_MULTI_BBT_bbtidx,__IFACE2_UI_COMMAND_MULTI_BBT_para) \
    (__IFACE2_TELL_OTHER_PLUGIN(PLUGIN_UUID_UI,I2CMD_UI_COMMAND,QVariantList()<<QVariant(__IFACE2_UI_COMMAND_MULTI_BBT_uicmd)<<QVariant(__IFACE2_UI_COMMAND_MULTI_BBT_bbtidx)<<QVariant(__IFACE2_UI_COMMAND_MULTI_BBT_para)<<QGenieIface2ShareObject::sUuidIdx))


#define __IFACE2_STATISTICS__(__IFACE2_STATISTICS___data,__IFACE2_STATISTICS___type,__IFACE2_STATISTICS___num) do{\
    QVariantList __IFACE2_STATISTICS___lst;__IFACE2_STATISTICS___lst<<QString(__IFACE2_STATISTICS___data)<<int(__IFACE2_STATISTICS___type)<<int(__IFACE2_STATISTICS___num);\
    __IFACE2_TELL_OTHER_PLUGIN(PLUGIN_UUID_STATISTIC,I2CMD_STATISTICS,__IFACE2_STATISTICS___lst);\
}while(0)

#define __IFACE2_SETFRAMELESS_STYLE_(__IFACE2_SETFRAMELESS_STYLE__d) do{\
    QWidget *__IFACE2_SETFRAMELESS_STYLE__w=__IFACE2_SETFRAMELESS_STYLE__d;\
    QVariant __IFACE2_SETFRAMELESS_STYLE__v;__IFACE2_SETFRAMELESS_STYLE__v.setValue((void *)__IFACE2_SETFRAMELESS_STYLE__w);\
    __IFACE2_UI_COMMAND_MULTI_BBT(UICMD_SET_FRAMELESS_STYLE,0,__IFACE2_SETFRAMELESS_STYLE__v);\
}while(0)


//pointer,type,lan,mode
#define __IFACE2_TRANSLATE_(__IFACE2_TRANSLATE__p1,__IFACE2_TRANSLATE__p2,__IFACE2_TRANSLATE__p3,__IFACE2_TRANSLATE__p4 ) do{\
{\
    QVariant __IFACE2_TRANSLATE_v;__IFACE2_TRANSLATE_v.setValue((void *)__IFACE2_TRANSLATE__p1);\
    QList<QVariant> __IFACE2_TRANSLATE__lst;\
    __IFACE2_TRANSLATE__lst<<__IFACE2_TRANSLATE_v<<(int)__IFACE2_TRANSLATE__p3<<QString(__IFACE2_TRANSLATE__p4);\
    QGenieIface2ShareObject::sSingleInstance->mHandler->handler_command(__IFACE2_TRANSLATE__p2,(QGenieIface2ShareObject::sUuidIdx),__IFACE2_TRANSLATE__lst);\
}\
}while(0)

//pointer,objname,lan,mod
#define __IFACE2_TRANSLATE_CHILD_BUT_(__IFACE2_TRANSLATE_CHILD_BUT__p1,__IFACE2_TRANSLATE_CHILD_BUT__p2,__IFACE2_TRANSLATE_CHILD_BUT__p3,__IFACE2_TRANSLATE_CHILD_BUT__p4) do{\
    QPushButton *__IFACE2_TRANSLATE_CHILD_BUT__but=qFindChild<QPushButton *>(__IFACE2_TRANSLATE_CHILD_BUT__p1,QString(__IFACE2_TRANSLATE_CHILD_BUT__p2));\
    if(__IFACE2_TRANSLATE_CHILD_BUT__but){__IFACE2_TRANSLATE_(__IFACE2_TRANSLATE_CHILD_BUT__but,HCMD_TRANSLATE_BUTTON,__IFACE2_TRANSLATE_CHILD_BUT__p3,__IFACE2_TRANSLATE_CHILD_BUT__p4);}\
}while(0)

#define __IFACE2_TRANSLATE_CHILD_LAB_(__IFACE2_TRANSLATE_CHILD_LAB__p1,__IFACE2_TRANSLATE_CHILD_LAB__p2,__IFACE2_TRANSLATE_CHILD_LAB__p3,__IFACE2_TRANSLATE_CHILD_LAB__p4) do{\
    QLabel *__IFACE2_TRANSLATE_CHILD_LAB__lab=qFindChild<QLabel *>(__IFACE2_TRANSLATE_CHILD_LAB__p1,QString(__IFACE2_TRANSLATE_CHILD_LAB__p2));\
    if(__IFACE2_TRANSLATE_CHILD_LAB__lab){__IFACE2_TRANSLATE_(__IFACE2_TRANSLATE_CHILD_LAB__lab,HCMD_TRANSLATE_LABEL,__IFACE2_TRANSLATE_CHILD_LAB__p3,__IFACE2_TRANSLATE_CHILD_LAB__p4);}\
}while(0)

#define __IFACE2_TRANSLATE_CHILD_CHECKBOX_(__IFACE2_TRANSLATE_CHILD_CHECKBOX__p1,__IFACE2_TRANSLATE_CHILD_CHECKBOX__p2,__IFACE2_TRANSLATE_CHILD_CHECKBOX__p3,__IFACE2_TRANSLATE_CHILD_CHECKBOX__p4) do{\
    QCheckBox *__IFACE2_TRANSLATE_CHILD_CHECKBOX__chk=qFindChild<QCheckBox *>(__IFACE2_TRANSLATE_CHILD_CHECKBOX__p1,QString(__IFACE2_TRANSLATE_CHILD_CHECKBOX__p2));\
    if(__IFACE2_TRANSLATE_CHILD_CHECKBOX__chk){__IFACE2_TRANSLATE_(__IFACE2_TRANSLATE_CHILD_CHECKBOX__chk,HCMD_TRANSLATE_CHECKBOX,__IFACE2_TRANSLATE_CHILD_CHECKBOX__p3,__IFACE2_TRANSLATE_CHILD_CHECKBOX__p4);}\
}while(0)

#define __IFACE2_TRANSLATE_CHILD_RADIOBUT_(__IFACE2_TRANSLATE_CHILD_RADIOBUT__p1,__IFACE2_TRANSLATE_CHILD_RADIOBUT__p2,__IFACE2_TRANSLATE_CHILD_RADIOBUT__p3,__IFACE2_TRANSLATE_CHILD_RADIOBUT__p4) do{\
    QRadioButton *__IFACE2_TRANSLATE_CHILD_RADIOBUT__rdt=qFindChild<QRadioButton *>(__IFACE2_TRANSLATE_CHILD_RADIOBUT__p1,QString(__IFACE2_TRANSLATE_CHILD_RADIOBUT__p2));\
    if(__IFACE2_TRANSLATE_CHILD_RADIOBUT__rdt){__IFACE2_TRANSLATE_(___IFACE2_TRANSLATE_CHILD_RADIOBUT_rdt,HCMD_TRANSLATE_RADIOBUT,__IFACE2_TRANSLATE_CHILD_RADIOBUT__p3,__IFACE2_TRANSLATE_CHILD_RADIOBUT__p4);}\
}while(0)

#define _IFACE2_GET_TEXT_USINGUUID(_IFACE2_GET_TEXT_USINGUUID_lan,_IFACE2_GET_TEXT_USINGUUID_uuid) ( (QGenieIface2ShareObject::sSingleInstance &&QGenieIface2ShareObject::sSingleInstance->mHandler )?\
    (QGenieIface2ShareObject::sSingleInstance->mHandler->handler_command(HCMD_GET_TEXT,(_IFACE2_GET_TEXT_USINGUUID_uuid),int(_IFACE2_GET_TEXT_USINGUUID_lan)).toString()):QString())

#define __IFACE2_GET_SETTINGS(__IFACE2_GET_SETTINGS_x) ( (QGenieIface2ShareObject::sSingleInstance &&QGenieIface2ShareObject::sSingleInstance->mHandler )?\
(QGenieIface2ShareObject::sSingleInstance->mHandler->handler_command(HCMD_GET_SETTINGS,(QGenieIface2ShareObject::sUuidIdx),QString(__IFACE2_GET_SETTINGS_x))):QVariant())

#define __IFACE2_SET_SETTINGS(__IFACE2_SET_SETTINGS_key,__IFACE2_SET_SETTINGS_value) do {\
QList<QVariant> _lst;_lst<<QString(__IFACE2_SET_SETTINGS_key)<<QVariant(__IFACE2_SET_SETTINGS_value);\
__IFACE2_HANDLER_CMD(HCMD_SET_SETTINGS,_lst);\
}while(0)

#define __IFACE2_VARIANT_TO_STRING_OF_UUID(__IFACE2_VARIANT_TO_STRING_OF_UUID_v,__IFACE2_VARIANT_TO_STRING_OF_UUID_uuid) (((__IFACE2_VARIANT_TO_STRING_OF_UUID_v).type()==QVariant::Int)?\
    ( ((__IFACE2_VARIANT_TO_STRING_OF_UUID_v).toInt()<0)?_IFACE2_GET_TEXT_USINGUUID(-(__IFACE2_VARIANT_TO_STRING_OF_UUID_v).toInt(),QGenieIface2ShareObject::sUuidIdx)\
        :_IFACE2_GET_TEXT_USINGUUID(((__IFACE2_VARIANT_TO_STRING_OF_UUID_v).toInt()),int(__IFACE2_VARIANT_TO_STRING_OF_UUID_uuid)) ):\
    (__IFACE2_VARIANT_TO_STRING_OF_UUID_v).toString())

#define __IFACE2_NOTIFY_MESSAGE(__IFACE2_NOTIFY_MESSAGE_msg,__IFACE2_NOTIFY_MESSAGE_paras) do{if(QGenieIface2ShareObject::sSingleInstance &&QGenieIface2ShareObject::sSingleInstance->mHandler )\
{QList<QVariant> _lst;_lst<<int(__IFACE2_NOTIFY_MESSAGE_msg)<<QVariant(__IFACE2_NOTIFY_MESSAGE_paras);__IFACE2_HANDLER_CMD(HCMD_NOTIFY_MESSAGE,_lst);}}while(0)


#define __IFACE2_RESOURCE__(__IFACE2_RESOURCE___res) (QGenieIface2ShareObject::sSingleInstance->getDbgResource(__IFACE2_RESOURCE___res))

#define __IFACE2_SET_FOCUS__(__IFACE2_SET_FOCUS__w) do{if((__IFACE2_SET_FOCUS__w)->isVisible()){__IFACE2_SET_FOCUS__w->setFocus();}}while(0)
#endif // INNER_MACROS_H
