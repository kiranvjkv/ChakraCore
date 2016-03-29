//-------------------------------------------------------------------------------------------------------
// Copyright (C) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.txt file in the project root for full license information.
//-------------------------------------------------------------------------------------------------------
// Default all macro to nothing
#ifndef DEF2
#define DEF2(process, op, func)
#endif
#ifndef DEF3
#define DEF3(process, op, func, y)
#endif
#ifndef DEF2_WMS
#define DEF2_WMS(process, op, func)
#endif
#ifndef DEF3_WMS
#define DEF3_WMS(process, op, func, y)
#endif
#ifndef DEF4_WMS
#define DEF4_WMS(process, op, func, y, t)
#endif
#ifndef EXDEF2
#define EXDEF2(process, op, func)
#endif
#ifndef EXDEF3
#define EXDEF3(process, op, func, y)
#endif
#ifndef EXDEF2_WMS
#define EXDEF2_WMS(process, op, func)
#endif
#ifndef EXDEF3_WMS
#define EXDEF3_WMS(process, op, func, y)
#endif
#ifndef EXDEF4_WMS
#define EXDEF4_WMS(process, op, func, y, t)
#endif

#if defined(INTERPRETER_ASMJS) && !defined(TEMP_DISABLE_ASMJS)
#include "InterpreterHandlerAsmJs.inl"
#else

  DEF2    (FALLTHROUGH,             EndSwitch,                  /* Common case with Br */)
  DEF2    (BR,                      Br,                         OP_Br)
#ifdef BYTECODE_BRANCH_ISLAND
EXDEF2    (BRLONG,                  BrLong,                     OP_Br)
#endif
  DEF3    (CUSTOM,                  StartCall,                  OP_StartCall, StartCall)
  DEF2    (NOP,                     Nop,                        Empty)
  DEF2_WMS(NOP,                     Unused,                     Reg1)
  DEF2_WMS(IP_TARG,                 ProfiledLoopStart,          OP_ProfiledLoopStart)
  DEF2_WMS(FALLTHROUGH,             LoopBodyStart,              /* Common case with ProfiledLoopBodyStart */)
  DEF2_WMS(IP_TARG,                 ProfiledLoopBodyStart,      OP_ProfiledLoopBodyStart)
  DEF2_WMS(IP_TARG,                 ProfiledLoopEnd,            OP_ProfiledLoopEnd)
  DEF2_WMS(BRCMem,                  BrEq_A,                     JavascriptOperators::Equal)
  DEF2_WMS(BRCMem,                  BrGt_A,                     JavascriptOperators::Greater)
  DEF2_WMS(BRCMem,                  BrGe_A,                     JavascriptOperators::GreaterEqual)
  DEF2_WMS(BRCMem,                  BrLt_A,                     JavascriptOperators::Less)
  DEF2_WMS(BRCMem,                  BrLe_A,                     JavascriptOperators::LessEqual)
  DEF2_WMS(BRCMem,                  BrNeq_A,                    JavascriptOperators::NotEqual)
  DEF2_WMS(BRBMem_ALLOW_STACK,      BrFalse_A,                  OP_BrFalse_A)
  DEF2_WMS(BRBMem_ALLOW_STACK,      BrTrue_A,                   OP_BrTrue_A)
  DEF2_WMS(BRB_ALLOW_STACK,         BrOnObject_A,               JavascriptOperators::IsObject)
  DEF2_WMS(BRB,                     BrNotNull_A,                OP_BrNotNull_A)
//Not emitted for byte code, keep it here for completeness
//EXDEF2_WMS(BRB,                   BrUndecl_A,                 OP_BrUndecl_A)
EXDEF2_WMS(BRB,                     BrNotUndecl_A,              OP_BrNotUndecl_A)
  DEF2_WMS(FALLTHROUGH,             Case,                       /* Common case with BrSrEq_A */)
  DEF2_WMS(BRCMem,                  BrSrEq_A,                   JavascriptOperators::StrictEqual)
  DEF2_WMS(BRCMem,                  BrSrNeq_A,                  JavascriptOperators::NotStrictEqual)
//Not emitted for byte code, keep it here for completeness
//DEF2    (BRS,                     BrHasSideEffects,           JavascriptOperators::OP_BrHasSideEffects)
  DEF2    (BRS,                     BrNotHasSideEffects,        JavascriptOperators::OP_BrNotHasSideEffects)
EXDEF2    (BRPROP,                  BrOnHasProperty,            OP_BrOnHasProperty)
  DEF2    (BRPROP,                  BrOnNoProperty,             OP_BrOnNoProperty)
  DEF2    (BRLOCALPROP,             BrOnNoLocalProperty,        OP_BrOnNoProperty)
  DEF2    (BRENVPROP,               BrOnNoEnvProperty,          OP_BrOnNoEnvProperty)
  DEF2_WMS(BRBS,                    BrFncNeqApply,              JavascriptOperators::OP_BrFncNeqApply)
//Not emitted for byte code, keep it here for completeness
//DEF2_WMS(BRBS,                    BrFncEqApply,               JavascriptOperators::OP_BrFncEqApply)
  DEF3_WMS(CALL_FLAGS_None,         CallI,                      OP_CallI,         CallI)
  DEF3_WMS(CALL_FLAGS_None,         CallIExtended,              OP_CallIExtended, CallIExtended)
  DEF3_WMS(CALL_FLAGS_None,         CallIExtendedFlags,         OP_CallIExtendedFlags, CallIExtendedFlags)
  DEF3_WMS(CALL_FLAGS_None,         CallIFlags,                 OP_CallIFlags,      CallIFlags)
  DEF3_WMS(CALL_FLAGS_None,         ProfiledCallI,                           PROFILEDOP(OP_ProfiledCallI, OP_CallI), ProfiledCallI)
  DEF3_WMS(CALL_FLAGS_None,         ProfiledCallIExtended,                   PROFILEDOP(OP_ProfiledCallIExtended, OP_CallIExtended), ProfiledCallIExtended)
  DEF3_WMS(CALL_FLAGS_None,         ProfiledCallIExtendedFlags,              PROFILEDOP(OP_ProfiledCallIExtendedFlags, OP_CallIExtendedFlags), ProfiledCallIExtendedFlags)
  DEF3_WMS(CALL_FLAGS_None,         ProfiledCallIWithICIndex,                PROFILEDOP(OP_ProfiledCallIWithICIndex, OP_CallI), ProfiledCallIWithICIndex)
  DEF3_WMS(CALL_FLAGS_Value,        ProfiledCallIExtendedWithICIndex,        PROFILEDOP(OP_ProfiledCallIExtendedWithICIndex, OP_CallIExtended), ProfiledCallIExtendedWithICIndex)
  DEF3_WMS(CALL_FLAGS_None,         ProfiledCallIExtendedFlagsWithICIndex,   PROFILEDOP(OP_ProfiledCallIExtendedFlagsWithICIndex, OP_CallIExtendedFlags), ProfiledCallIExtendedFlagsWithICIndex)
  DEF3_WMS(CALL_FLAGS_None,         ProfiledCallIFlagsWithICIndex,           PROFILEDOP(OP_ProfiledCallIFlags, OP_CallIFlags), ProfiledCallIFlagsWithICIndex)
  DEF3_WMS(CALL_FLAGS_None,         ProfiledCallIFlags,                      PROFILEDOP(OP_ProfiledCallIFlags, OP_CallIFlags), ProfiledCallIFlags)
  DEF3_WMS(CALL_FLAGS_None,         ProfiledReturnTypeCallI,                 PROFILEDOP(OP_ProfiledReturnTypeCallI, OP_CallI), ProfiledCallI)
  DEF3_WMS(CALL_FLAGS_None,         ProfiledReturnTypeCallIExtended,         PROFILEDOP(OP_ProfiledReturnTypeCallIExtended, OP_CallIExtended), ProfiledCallIExtended)
  DEF3_WMS(CALL_FLAGS_None,         ProfiledReturnTypeCallIExtendedFlags,    PROFILEDOP(OP_ProfiledReturnTypeCallIExtendedFlags, OP_CallIExtendedFlags), ProfiledCallIExtendedFlags)

  DEF3_WMS(CALL_FLAGS_None,         ProfiledReturnTypeCallIFlags,            PROFILEDOP(OP_ProfiledReturnTypeCallIFlags, OP_CallIFlags), ProfiledCallIFlags)
EXDEF2_WMS(A1toA1Mem,               Conv_Str,                   JavascriptConversion::ToString)
  DEF2_WMS(A1toA1Mem,               Conv_Obj,                   JavascriptOperators::ToObject)
EXDEF2_WMS(A1toA1Mem,               NewWithObject,              JavascriptOperators::ToWithObject)
  DEF2_WMS(A1toA1Mem,               Conv_Num,                   JavascriptOperators::ToNumber)
  DEF2_WMS(A1toA1Mem,               Incr_A,                     JavascriptMath::Increment)
  DEF2_WMS(A1toA1Mem,               Decr_A,                     JavascriptMath::Decrement)
  DEF2_WMS(A1toA1Mem,               Neg_A,                      JavascriptMath::Negate)
  DEF2_WMS(A1toA1Mem,               Not_A,                      JavascriptMath::Not)
  DEF2_WMS(A1toA1Mem,               Typeof,                     JavascriptOperators::Typeof)
  DEF2_WMS(A1toA1Mem,               Delete_A,                   JavascriptOperators::Delete)
  DEF2_WMS(GET_ELEM_IMem,           TypeofElem,                 JavascriptOperators::TypeofElem)
  DEF2_WMS(A3toA1Mem,               Concat3,                    JavascriptOperators::Concat3)
  DEF2_WMS(A2I1toA1Mem,             NewConcatStrMulti,          JavascriptOperators::NewConcatStrMulti)
  EXDEF2_WMS(A2I1toXXMem,             SetConcatStrMultiItem,      JavascriptOperators::SetConcatStrMultiItem)
  EXDEF2_WMS(A3I1toXXMem,             SetConcatStrMultiItem2,     JavascriptOperators::SetConcatStrMultiItem2)
  DEF2_WMS(A2toA1Mem,               Add_A,                      JavascriptMath::Add)
  DEF2_WMS(A2toA1Mem,               Div_A,                      JavascriptMath::Divide)
  DEF2_WMS(A2toA1MemProfiled,       ProfiledDiv_A,              PROFILEDOP(ProfiledDivide<true>, ProfiledDivide<false>))
  DEF2_WMS(A2toA1Mem,               Mul_A,                      JavascriptMath::Multiply)
  DEF2_WMS(A2toA1Mem,               Expo_A,                     JavascriptMath::Exponentiation)
  DEF2_WMS(A2toA1Mem,               Rem_A,                      JavascriptMath::Modulus)
  DEF2_WMS(A2toA1MemProfiled,       ProfiledRem_A,              PROFILEDOP(ProfileModulus<true>, ProfileModulus<false>))
  DEF2_WMS(A2toA1Mem,               Sub_A,                      JavascriptMath::Subtract)
  DEF2_WMS(A2toA1Mem,               And_A,                      JavascriptMath::And)
  DEF2_WMS(A2toA1Mem,               Or_A,                       JavascriptMath::Or)
  DEF2_WMS(A2toA1Mem,               Xor_A,                      JavascriptMath::Xor)
  DEF2_WMS(A2toA1Mem,               Shl_A,                      JavascriptMath::ShiftLeft)
  DEF2_WMS(A2toA1Mem,               Shr_A,                      JavascriptMath::ShiftRight)
  DEF2_WMS(A2toA1Mem,               ShrU_A,                     JavascriptMath::ShiftRightU)
  DEF2_WMS(CMMem,                   CmEq_A,                     JavascriptOperators::Equal)
  DEF2_WMS(CMMem,                   CmGt_A,                     JavascriptOperators::Greater)
  DEF2_WMS(CMMem,                   CmGe_A,                     JavascriptOperators::GreaterEqual)
  DEF2_WMS(CMMem,                   CmLt_A,                     JavascriptOperators::Less)
  DEF2_WMS(CMMem,                   CmLe_A,                     JavascriptOperators::LessEqual)
  DEF2_WMS(CMMem,                   CmNeq_A,                    JavascriptOperators::NotEqual)
  DEF2_WMS(CMMem,                   CmSrEq_A,                   JavascriptOperators::StrictEqual)
  DEF2_WMS(CMMem,                   CmSrNeq_A,                  JavascriptOperators::NotStrictEqual)
  DEF2_WMS(FALLTHROUGH,             BeginSwitch,                /* Common case with Ld_A */)
  DEF2_WMS(FALLTHROUGH,             InitConst,                  /* Common case with Ld_A */)
  DEF2_WMS(A1toA1_ALLOW_STACK,      Ld_A,                       OP_Ld_A)
  DEF2_WMS(INNERtoA1,               LdInnerScope,               OP_Ld_A)
  DEF2_WMS(XXtoA1,                  LdLocalObj,                 OP_LdLocalObj)
EXDEF2_WMS(A1toA1_ALLOW_STACK,      UnwrapWithObj,              JavascriptOperators::OP_UnwrapWithObj)
EXDEF2_WMS(A2toXX,                  SetComputedNameVar,         JavascriptOperators::OP_SetComputedNameVar)
  DEF2_WMS(A1toXX_ALLOW_STACK,      ChkUndecl,                  OP_ChkUndecl)
  DEF2_WMS(XXtoA1,                  InitUndecl,                 OP_InitUndecl)
  DEF2_WMS(ELEM_RtU_to_XX,          EnsureNoRootFld,            OP_EnsureNoRootProperty)
  DEF2_WMS(ELEM_RtU_to_XX,          EnsureNoRootRedeclFld,      OP_EnsureNoRootRedeclProperty)
  DEF2_WMS(ELEM_C2_to_XX,           ScopedEnsureNoRedeclFld,    OP_ScopedEnsureNoRedeclProperty)
  DEF2_WMS(A1toA1Profiled,          ProfiledBeginSwitch,        PROFILEDOP(ProfiledSwitch<true>, ProfiledSwitch<false>))
  DEF2_WMS(XXtoA1Mem,               LdC_A_Null,                 JavascriptOperators::OP_LdNull)
  DEF2_WMS(XXtoA1,                  ArgIn0,                     OP_ArgIn0)
  DEF2_WMS(CUSTOM_ArgNoSrc,         ArgOut_Env,                 OP_ArgOut_Env)
#if DBG
  DEF2_WMS(CUSTOM_L_Arg,            ArgOut_ANonVar,             OP_ArgOut_ANonVar)
#else
  DEF2_WMS(FALLTHROUGH,             ArgOut_ANonVar,             /* Common case with ArgOUt_A in fre build */)
#endif
  DEF2_WMS(CUSTOM_L_Arg,            ArgOut_A,                   OP_ArgOut_A)
  DEF3_WMS(CUSTOM_L_Arg2,           ProfiledArgOut_A,           PROFILEDOP(OP_ProfiledArgOut_A, OP_ArgOut_A), ProfiledArg)

  DEF3_WMS(CUSTOM_L_Value,          LdFld,                      OP_GetProperty, ElementCP)
  DEF3_WMS(CUSTOM_L_Value,          LdLocalFld,                 OP_GetLocalProperty, ElementP)
EXDEF3_WMS(CUSTOM_L_Value,          LdSuperFld,                 OP_GetSuperProperty, ElementC2)
  DEF3_WMS(CUSTOM_L_Value,          LdFldForTypeOf,             OP_GetPropertyForTypeOf, ElementCP)
EXDEF3_WMS(CUSTOM_L_Value,          LdRootFldForTypeOf,         OP_GetRootPropertyForTypeOf, ElementRootCP)
  DEF3_WMS(CUSTOM_L_Value,          LdFldForCallApplyTarget,    OP_GetProperty, ElementCP)
  DEF3_WMS(CUSTOM_L_Value,          ProfiledLdFld,              PROFILEDOP(OP_ProfiledGetProperty, OP_GetProperty), ElementCP)
  DEF3_WMS(CUSTOM_L_Value,          ProfiledLdLocalFld,         PROFILEDOP(OP_ProfiledGetLocalProperty, OP_GetLocalProperty), ElementP)
EXDEF3_WMS(CUSTOM_L_Value,          ProfiledLdSuperFld,         PROFILEDOP(OP_ProfiledGetSuperProperty, OP_GetSuperProperty), ElementC2)
  DEF3_WMS(CUSTOM_L_Value,          ProfiledLdFldForTypeOf,     PROFILEDOP(OP_ProfiledGetPropertyForTypeOf, OP_GetPropertyForTypeOf), ElementCP)
EXDEF3_WMS(CUSTOM_L_Value,          ProfiledLdRootFldForTypeOf, PROFILEDOP(OP_ProfiledGetRootPropertyForTypeOf, OP_GetRootPropertyForTypeOf), ElementRootCP)
  DEF3_WMS(CUSTOM_L_Value,          ProfiledLdFldForCallApplyTarget,PROFILEDOP(OP_ProfiledGetPropertyCallApplyTarget, OP_GetProperty), ElementCP)
  DEF3_WMS(CUSTOM_L_Value,          LdRootFld,                  OP_GetRootProperty, ElementRootCP)
  DEF3_WMS(CUSTOM_L_Value,          ProfiledLdRootFld,          PROFILEDOP(OP_ProfiledGetRootProperty, OP_GetRootProperty), ElementRootCP)
  DEF3_WMS(CUSTOM_L_Value,          LdMethodFld,                OP_GetMethodProperty, ElementCP)
  DEF3_WMS(CUSTOM_L_Value,          ProfiledLdMethodFld,        PROFILEDOP(OP_ProfiledGetMethodProperty, OP_GetMethodProperty), ElementCP)
EXDEF3_WMS(CUSTOM_L_Value,          LdLocalMethodFld,           OP_GetLocalMethodProperty, ElementP)
EXDEF3_WMS(CUSTOM_L_Value,          ProfiledLdLocalMethodFld,   PROFILEDOP(OP_ProfiledGetLocalMethodProperty, OP_GetLocalMethodProperty), ElementP)
  DEF3_WMS(CUSTOM_L_Value,          LdRootMethodFld,            OP_GetRootMethodProperty, ElementRootCP)
  DEF3_WMS(CUSTOM_L_Value,          ProfiledLdRootMethodFld,    PROFILEDOP(OP_ProfiledGetRootMethodProperty, OP_GetRootMethodProperty), ElementRootCP)
  DEF3_WMS(CUSTOM_L_Value,          DeleteFld,                  OP_DeleteFld, ElementC)
EXDEF3_WMS(CUSTOM_L_Value,          DeleteLocalFld,             OP_DeleteLocalFld, ElementU)
  DEF3_WMS(CUSTOM_L_Value,          DeleteRootFld,              OP_DeleteRootFld, ElementC)
  DEF3_WMS(CUSTOM_L_Value,          DeleteFldStrict,            OP_DeleteFldStrict, ElementC)
  DEF3_WMS(CUSTOM_L_Value,          DeleteRootFldStrict,        OP_DeleteRootFldStrict, ElementC)
  DEF3_WMS(CUSTOM,                  StFld,                      OP_SetProperty, ElementCP)
  DEF3_WMS(CUSTOM,                  StLocalFld,                 OP_SetLocalProperty, ElementP)
EXDEF3_WMS(CUSTOM_L_Value,          StSuperFld,                 OP_SetSuperProperty, ElementC2)
  DEF3_WMS(CUSTOM,                  ProfiledStFld,              PROFILEDOP(OP_ProfiledSetProperty, OP_SetProperty), ElementCP)
  DEF3_WMS(CUSTOM,                  ProfiledStLocalFld,         PROFILEDOP(OP_ProfiledSetLocalProperty, OP_SetLocalProperty), ElementP)
EXDEF3_WMS(CUSTOM_L_Value,          ProfiledStSuperFld,         PROFILEDOP(OP_ProfiledSetSuperProperty, OP_SetSuperProperty), ElementC2)
  DEF3_WMS(CUSTOM,                  StRootFld,                  OP_SetRootProperty, ElementRootCP)
  DEF3_WMS(CUSTOM,                  ProfiledStRootFld,          PROFILEDOP(OP_ProfiledSetRootProperty, OP_SetRootProperty), ElementRootCP)
  DEF3_WMS(CUSTOM,                  StFldStrict,                OP_SetPropertyStrict, ElementCP)
  DEF3_WMS(CUSTOM,                  ProfiledStFldStrict,        PROFILEDOP(OP_ProfiledSetPropertyStrict, OP_SetPropertyStrict), ElementCP)
  DEF3_WMS(CUSTOM,                  StRootFldStrict,            OP_SetRootPropertyStrict, ElementRootCP)
  DEF3_WMS(CUSTOM,                  ProfiledStRootFldStrict,    PROFILEDOP(OP_ProfiledSetRootPropertyStrict, OP_SetRootPropertyStrict), ElementRootCP)
  DEF3_WMS(CUSTOM,                  InitFld,                    OP_InitProperty, ElementCP)
  DEF3_WMS(CUSTOM,                  ProfiledInitFld,            PROFILEDOP(OP_ProfiledInitProperty, OP_InitProperty), ElementCP)
  DEF3_WMS(CUSTOM,                  InitLocalFld,               OP_InitLocalProperty, ElementP)
  DEF3_WMS(CUSTOM,                  ProfiledInitLocalFld,       PROFILEDOP(OP_ProfiledInitLocalProperty, OP_InitLocalProperty), ElementP)
  DEF3_WMS(CUSTOM,                  InitRootFld,                OP_InitRootProperty, ElementRootCP)
  DEF3_WMS(CUSTOM,                  ProfiledInitRootFld,        PROFILEDOP(OP_ProfiledInitRootProperty, OP_InitRootProperty), ElementRootCP)
  DEF3_WMS(CUSTOM,                  InitUndeclLetFld,           OP_InitUndeclLetProperty, ElementPIndexed)
EXDEF3_WMS(CUSTOM,                  InitUndeclLocalLetFld,      OP_InitUndeclLocalLetProperty, ElementP)
  DEF3_WMS(CUSTOM,                  InitUndeclConstFld,         OP_InitUndeclConstProperty, ElementPIndexed)
EXDEF3_WMS(CUSTOM,                  InitUndeclLocalConstFld,    OP_InitUndeclLocalConstProperty, ElementP)
  DEF3_WMS(CUSTOM,                  InitLetFld,                 OP_InitLetFld, ElementCP)
EXDEF3_WMS(CUSTOM,                  InitLocalLetFld,            OP_InitLocalLetFld, ElementP)
EXDEF3_WMS(CUSTOM,                  InitInnerFld,               OP_InitInnerFld, ElementPIndexed)
EXDEF3_WMS(CUSTOM,                  InitInnerLetFld,            OP_InitInnerLetFld, ElementPIndexed)
  DEF3_WMS(CUSTOM,                  InitRootLetFld,             OP_InitRootLetFld, ElementRootCP)
  DEF3_WMS(CUSTOM,                  InitConstFld,               OP_InitConstFld, ElementCP)
  DEF3_WMS(CUSTOM,                  InitRootConstFld,           OP_InitRootConstFld, ElementRootCP)
  DEF2_WMS(ELEM_RtU_to_XX,          InitUndeclRootLetFld,       OP_InitUndeclRootLetProperty)
  DEF2_WMS(ELEM_RtU_to_XX,          InitUndeclRootConstFld,     OP_InitUndeclRootConstProperty)
EXDEF3_WMS(CUSTOM,                  InitUndeclConsoleLetFld,    OP_InitUndeclConsoleLetProperty, ElementScopedU)
EXDEF3_WMS(CUSTOM,                  InitUndeclConsoleConstFld,  OP_InitUndeclConsoleConstProperty, ElementScopedU)
  DEF3_WMS(CUSTOM,                  InitClassMember,            OP_InitClassMember, ElementCP)
EXDEF3_WMS(CUSTOM,                  InitClassMemberComputedName,OP_InitClassMemberComputedName, ElementI)
EXDEF3_WMS(CUSTOM,                  InitClassMemberSet,         OP_InitClassMemberSet, ElementC)
EXDEF3_WMS(CUSTOM,                  InitClassMemberGetComputedName, OP_InitClassMemberGetComputedName, ElementI)
EXDEF3_WMS(CUSTOM,                  InitClassMemberGet,         OP_InitClassMemberGet, ElementC)
EXDEF3_WMS(CUSTOM,                  InitClassMemberSetComputedName, OP_InitClassMemberSetComputedName, ElementI)
EXDEF2_WMS(BRB,                     BrOnClassConstructor,       OP_BrOnClassConstructor)
  DEF3_WMS(GET_ELEM_LOCALSLOTNonVar,LdLocalSlot,                OP_LdSlot, ElementSlotI1)
EXDEF3_WMS(GET_ELEM_PARAMSLOTNonVar,LdParamSlot,                OP_LdSlot, ElementSlotI1)
  DEF3_WMS(GET_ELEM_INNERSLOTNonVar,LdInnerSlot,                OP_LdInnerSlot, ElementSlotI2)
EXDEF3_WMS(GET_ELEM_INNERSLOTNonVar,LdInnerObjSlot,             OP_LdInnerObjSlot, ElementSlotI2)
  DEF3_WMS(GET_ELEM_ENVSLOTNonVar,  LdEnvSlot,                  OP_LdEnvSlot, ElementSlotI2)
  DEF3_WMS(GET_ELEM_ENVSLOTNonVar,  LdEnvObj,                   OP_LdEnvObj, ElementSlotI1)
EXDEF3_WMS(GET_ELEM_ENVSLOTNonVar,  LdEnvObjSlot,               OP_LdEnvObjSlot, ElementSlotI2)
EXDEF3_WMS(GET_ELEM_ENVSLOTNonVar,  LdModuleSlot,               OP_LdModuleSlot, ElementSlotI2)
EXDEF2_WMS(SET_ELEM_ENVSLOTNonVar,  StModuleSlot,               OP_StModuleSlot)
  DEF3_WMS(GET_ELEM_SLOTNonVar,     ProfiledLdSlot,             PROFILEDOP(OP_ProfiledLdSlot, OP_LdSlot), ProfiledElementSlot)
  DEF3_WMS(GET_ELEM_INNERSLOTNonVar,ProfiledLdInnerSlot,        PROFILEDOP(OP_ProfiledLdInnerSlot, OP_LdInnerSlot), ProfiledElementSlotI2)
EXDEF3_WMS(GET_ELEM_INNERSLOTNonVar,ProfiledLdInnerObjSlot,     PROFILEDOP(OP_ProfiledLdInnerObjSlot, OP_LdInnerObjSlot), ProfiledElementSlotI2)
  DEF3_WMS(GET_ELEM_LOCALSLOTNonVar,ProfiledLdLocalSlot,        PROFILEDOP(OP_ProfiledLdSlot, OP_LdSlot), ProfiledElementSlotI1)
EXDEF3_WMS(GET_ELEM_PARAMSLOTNonVar,ProfiledLdParamSlot,        PROFILEDOP(OP_ProfiledLdSlot, OP_LdSlot), ProfiledElementSlotI1)
  DEF3_WMS(GET_ELEM_ENVSLOTNonVar,  ProfiledLdEnvSlot,          PROFILEDOP(OP_ProfiledLdEnvSlot, OP_LdEnvSlot), ProfiledElementSlotI2)
EXDEF3_WMS(GET_ELEM_ENVSLOTNonVar,  ProfiledLdEnvObjSlot,       PROFILEDOP(OP_ProfiledLdEnvObjSlot, OP_LdEnvObjSlot), ProfiledElementSlotI2)
EXDEF3_WMS(GET_ELEM_SLOTNonVar,     LdObjSlot,                  OP_LdObjSlot, ElementSlot)
EXDEF3_WMS(GET_ELEM_SLOTNonVar,     ProfiledLdObjSlot,          PROFILEDOP(OP_ProfiledLdObjSlot, OP_LdObjSlot), ProfiledElementSlot)
EXDEF3_WMS(GET_ELEM_LOCALSLOTNonVar,LdLocalObjSlot,             OP_LdObjSlot, ElementSlotI1)
EXDEF3_WMS(GET_ELEM_LOCALSLOTNonVar,ProfiledLdLocalObjSlot,     PROFILEDOP(OP_ProfiledLdObjSlot, OP_LdObjSlot), ProfiledElementSlotI1)
  DEF2_WMS(SET_ELEM_LOCALSLOTNonVar,StLocalSlot,                OP_StSlot)
EXDEF2_WMS(SET_ELEM_LOCALSLOTNonVar,StLocalSlotChkUndecl,       OP_StSlotChkUndecl)
  DEF2_WMS(SET_ELEM_INNERSLOTNonVar,StInnerSlot,                OP_StSlot)
EXDEF2_WMS(SET_ELEM_INNERSLOTNonVar,StInnerSlotChkUndecl,       OP_StSlotChkUndecl)
EXDEF2_WMS(SET_ELEM_INNERSLOTNonVar,StInnerObjSlot,             OP_StObjSlot)
EXDEF2_WMS(SET_ELEM_INNERSLOTNonVar,StInnerObjSlotChkUndecl,    OP_StObjSlotChkUndecl)
  DEF2_WMS(SET_ELEM_ENVSLOTNonVar,  StEnvSlot,                  OP_StEnvSlot)
EXDEF2_WMS(SET_ELEM_ENVSLOTNonVar,  StEnvSlotChkUndecl,         OP_StEnvSlotChkUndecl)
EXDEF2_WMS(SET_ELEM_SLOTNonVar,     StObjSlot,                  OP_StObjSlot)
EXDEF2_WMS(SET_ELEM_LOCALSLOTNonVar,StLocalObjSlot,             OP_StObjSlot)
EXDEF2_WMS(SET_ELEM_LOCALSLOTNonVar,StLocalObjSlotChkUndecl,    OP_StObjSlotChkUndecl)
EXDEF2_WMS(SET_ELEM_ENVSLOTNonVar,  StEnvObjSlot,               OP_StEnvObjSlot)
EXDEF2_WMS(SET_ELEM_SLOTNonVar,     StObjSlotChkUndecl,         OP_StObjSlotChkUndecl)
EXDEF2_WMS(SET_ELEM_ENVSLOTNonVar,  StEnvObjSlotChkUndecl,      OP_StEnvObjSlotChkUndecl)
  DEF3_WMS(CUSTOM_L_Value,          LdElemI_A,                  OP_GetElementI, ElementI)
  DEF3_WMS(CUSTOM_L_Value,          ProfiledLdElemI_A,          PROFILEDOP(OP_ProfiledGetElementI, OP_GetElementI), ProfiledElementI)
  DEF2_WMS(GET_ELEM_IMem,           LdMethodElem,               JavascriptOperators::OP_GetMethodElement)
  DEF3_WMS(CUSTOM,                  StElemI_A,                  OP_SetElementI, ElementI)
  DEF3_WMS(CUSTOM,                  StElemI_A_Strict,           OP_SetElementIStrict, ElementI)
  DEF3_WMS(CUSTOM_L_Value,          ProfiledStElemI_A,          PROFILEDOP(OP_ProfiledSetElementI, OP_SetElementI), ProfiledElementI)
  DEF3_WMS(CUSTOM_L_Value,          ProfiledStElemI_A_Strict,   PROFILEDOP(OP_ProfiledSetElementIStrict, OP_SetElementIStrict), ProfiledElementI)
  DEF3_WMS(CUSTOM,                  StArrItemI_CI4,             OP_SetArrayItemI_CI4, ElementUnsigned1)
  DEF2_WMS(FALLTHROUGH,             StArrInlineItem_CI4,        /*Common case with StArrItemC_CI4 */)
  DEF3_WMS(CUSTOM,                  StArrItemC_CI4,             OP_SetArrayItemC_CI4, ElementUnsigned1)
  DEF3_WMS(CUSTOM_L_R0,             LdArrHead,                  OP_LdArrayHeadSegment, Reg2)
  DEF3_WMS(CUSTOM,                  StArrSegItem_CI4,           OP_SetArraySegmentItem_CI4, ElementUnsigned1)
  DEF3    (CUSTOM,                  StArrSegItem_A,             OP_SetArraySegmentVars, Auxiliary)
  DEF3_WMS(CALL,                    NewScObject,                OP_NewScObject, CallI)
  DEF3_WMS(CUSTOM_L_R0,             NewScObjectNoCtorFull,      OP_NewScObjectNoCtorFull, Reg2)
EXDEF2_WMS(A1toA1Mem,               LdCustomSpreadIteratorList, JavascriptOperators::OP_LdCustomSpreadIteratorList)
EXDEF3_WMS(CALL,                    NewScObjectSpread,          OP_NewScObjectSpread, CallIExtended)
  DEF3_WMS(CALL,                    NewScObjArray,              OP_NewScObjArray, CallI)
  DEF3_WMS(CALL,                    NewScObjArraySpread,        OP_NewScObjArraySpread, CallIExtended)
  DEF3_WMS(CALL,                    ProfiledNewScObject,        PROFILEDOP(OP_ProfiledNewScObject, OP_NewScObject), ProfiledCallI)
EXDEF3_WMS(CALL,                    ProfiledNewScObjectSpread,  PROFILEDOP(OP_ProfiledNewScObjectSpread, OP_NewScObjectSpread), ProfiledCallIExtended)
  DEF3_WMS(CALL,                    ProfiledNewScObjectWithICIndex,       PROFILEDOP(OP_ProfiledNewScObjectWithICIndex, OP_NewScObject), ProfiledCallIWithICIndex)
  DEF3_WMS(CALL,                    ProfiledNewScObjArray,      PROFILEDOP(OP_ProfiledNewScObjArray, OP_ProfiledNewScObjArray_NoProfile), Profiled2CallI)
  DEF3_WMS(CALL,                    ProfiledNewScObjArraySpread,PROFILEDOP(OP_ProfiledNewScObjArraySpread, OP_ProfiledNewScObjArraySpread_NoProfile), Profiled2CallIExtended)
  DEF2_WMS(XXtoA1NonVar,            LdArgCnt,                   OP_LdArgCnt)
  DEF3_WMS(CUSTOM_L_R0,             LdLen_A,                    OP_LdLen, Reg2)
  DEF3_WMS(CUSTOM_L_R0,             ProfiledLdLen_A,            PROFILEDOP(OP_ProfiledLdLen, OP_LdLen), ProfiledReg2)
  DEF2_WMS(XXtoA1Mem,               LdUndef,                    JavascriptOperators::OP_LdUndef)
  DEF2_WMS(XXtoA1Mem,               LdNaN,                      JavascriptOperators::OP_LdNaN)
  DEF2_WMS(XXtoA1Mem,               LdInfinity,                 JavascriptOperators::OP_LdInfinity)
  DEF2_WMS(XXtoA1Mem,               LdTrue,                     JavascriptBoolean::OP_LdTrue)
  DEF2_WMS(XXtoA1Mem,               LdFalse,                    JavascriptBoolean::OP_LdFalse)
  DEF2_WMS(A1I1toA1Mem,             LdThis,                     JavascriptOperators::OP_GetThisNoFastPath)
EXDEF2_WMS(XXtoA1Mem,               LdSuper,                    OP_LdSuper)
EXDEF2_WMS(XXtoA1Mem,               LdSuperCtor,                OP_LdSuperCtor)
EXDEF2_WMS(XXtoA1Mem,               ScopedLdSuper,              OP_ScopedLdSuper)
EXDEF2_WMS(XXtoA1Mem,               ScopedLdSuperCtor,          OP_ScopedLdSuperCtor)
EXDEF2_WMS(A2toXX,                  SetHomeObj,                 JavascriptOperators::OP_SetHomeObj)
  DEF2_WMS(A1toA1Mem,               StrictLdThis,               JavascriptOperators::OP_StrictGetThis)
  DEF2_WMS(A1I1toA1Mem,             ProfiledLdThis,             PROFILEDOP(OP_ProfiledLdThis, JavascriptOperators::OP_GetThisNoFastPath))
  DEF2_WMS(A1toA1Mem,               ProfiledStrictLdThis,       PROFILEDOP(OP_ProfiledStrictLdThis, JavascriptOperators::OP_StrictGetThis))
  DEF2_WMS(XXtoA1Mem,               LdHeapArgsCached,           OP_LdHeapArgsCached)
EXDEF2_WMS(XXtoA1Mem,               LdLetHeapArgsCached,        OP_LdLetHeapArgsCached)
EXDEF2_WMS(XXtoA1NonVar,            LdStackArgPtr,              OP_LdStackArgPtr)
EXDEF3_WMS(CUSTOM,                  InitSetFld,                 OP_InitSetFld, ElementC)
EXDEF3_WMS(CUSTOM,                  InitGetFld,                 OP_InitGetFld, ElementC)
EXDEF3_WMS(CUSTOM,                  InitSetElemI,               OP_InitSetElemI, ElementI)
EXDEF3_WMS(CUSTOM,                  InitGetElemI,               OP_InitGetElemI, ElementI)
EXDEF3_WMS(CUSTOM,                  InitComputedProperty,       OP_InitComputedProperty, ElementI)
EXDEF3_WMS(CUSTOM,                  InitProto,                  OP_InitProto, ElementC)
  DEF3_WMS(CUSTOM,                  LdElemUndefScoped,          OP_LdElementUndefinedScoped, ElementScopedU)
  DEF3_WMS(CUSTOM_L_R0,             LdFuncExpr,                 OP_LdFunctionExpression, Reg1)
  DEF3_WMS(CUSTOM,                  StFuncExpr,                 OP_StFunctionExpression, ElementC)
  DEF3_WMS(CUSTOM,                  StLocalFuncExpr,            OP_StLocalFunctionExpression, ElementU)
EXDEF3_WMS(CUSTOM_L_R0,             LdNewTarget,                OP_LdNewTarget, Reg1)
EXDEF2    (EMPTY,                   ChkNewCallFlag,             OP_ChkNewCallFlag)
  DEF2_WMS(U1toINNERMemNonVar,      NewBlockScope,              JavascriptOperators::OP_NewBlockScope)
  DEF3_WMS(CUSTOM,                  CloneBlockScope,            OP_CloneBlockScope, Unsigned1)
  DEF2_WMS(U1toINNERMemNonVar,      NewPseudoScope,             JavascriptOperators::OP_NewPseudoScope)
  DEF3_WMS(CUSTOM_L_Value,          NewStackScFunc,             OP_NewStackScFunc, ElementSlotI1)
  DEF2_WMS(GET_SLOT_FB,             NewScFunc,                  ScriptFunction::OP_NewScFunc)
  DEF2_WMS(GET_SLOT_FB,             NewScGenFunc,               JavascriptGeneratorFunction::OP_NewScGenFunc)
EXDEF3_WMS(CUSTOM_L_Value,          NewInnerStackScFunc,        OP_NewInnerStackScFunc, ElementSlot)
EXDEF2_WMS(GET_ELEM_SLOT_FB,        NewInnerScFunc,             ScriptFunction::OP_NewScFunc)
EXDEF2_WMS(GET_ELEM_SLOT_FB,        NewInnerScGenFunc,          JavascriptGeneratorFunction::OP_NewScGenFunc)
  DEF2_WMS(A1toA1MemNonVar,         GetForInEnumerator,         JavascriptOperators::OP_GetForInEnumerator)
  DEF3_WMS(A1toXXMemNonVar,         ReleaseForInEnumerator,     JavascriptOperators::OP_ReleaseForInEnumerator, ForInObjectEnumerator *)
  DEF2_WMS(A1toXXMem,               Throw,                      JavascriptExceptionOperators::OP_Throw)
  DEF2_WMS(XXtoA1NonVar,            LdArgumentsFromFrame,       OP_LdArgumentsFromFrame)
  DEF2_WMS(A1toA1MemNonVar,         LdHeapArguments,            OP_LdHeapArguments)
  DEF2_WMS(A1toA1MemNonVar,         LdLetHeapArguments,         OP_LdLetHeapArguments)
  DEF2_WMS(A2toA1MemNonVar,         LdInnerFrameDisplay,        OP_LdInnerFrameDisplay)
  DEF2_WMS(A1toA1MemNonVar,         LdInnerFrameDisplayNoParent,OP_LdInnerFrameDisplayNoParent)
  DEF2_WMS(A1INNERtoA1MemNonVar,    LdIndexedFrameDisplay,      OP_LdFrameDisplay)
  DEF2_WMS(XXINNERtoA1MemNonVar,    LdIndexedFrameDisplayNoParent,OP_LdFrameDisplayNoParent<true>)
  DEF2_WMS(A2toXXMemNonVar,         LdFuncExprFrameDisplay,     OP_LdFuncExprFrameDisplaySetLocal)
  DEF3_WMS(CUSTOM_L_R0,             IsInst,                     OP_IsInst, Reg3C)
  DEF2_WMS(A2toA1Mem,               IsIn,                       JavascriptOperators::IsIn)
  DEF3_WMS(CUSTOM_L_Value,          ScopedLdFld,                OP_GetPropertyScoped, ElementP)
EXDEF3_WMS(CUSTOM_L_Value,          ScopedLdFldForTypeOf,       OP_GetPropertyForTypeOfScoped, ElementP)
  DEF3_WMS(CUSTOM_L_Value,          ScopedLdMethodFld,          OP_GetMethodPropertyScoped, ElementCP)
  DEF3_WMS(CUSTOM,                  ScopedStFld,                OP_SetPropertyScoped, ElementP)
EXDEF3_WMS(CUSTOM,                  ConsoleScopedStFld,         OP_ConsoleSetPropertyScoped, ElementP)
  DEF3_WMS(CUSTOM,                  ScopedStFldStrict,          OP_SetPropertyScopedStrict, ElementP)
  DEF2_WMS(GET_ELEM_IMem,           DeleteElemI_A,              JavascriptOperators::OP_DeleteElementI)
  DEF2_WMS(GET_ELEM_IMem_Strict,    DeleteElemIStrict_A,        JavascriptOperators::OP_DeleteElementI)
  DEF3_WMS(CUSTOM_L_Value,          ScopedLdInst,               OP_ScopedLdInst, ElementScopedC2)
  DEF3_WMS(CUSTOM,                  ScopedInitFunc,             OP_ScopedInitFunc, ElementScopedC)
  DEF3_WMS(CUSTOM_L_Value,          ScopedDeleteFld,            OP_ScopedDeleteFld, ElementScopedC)
  DEF3_WMS(CUSTOM_L_Value,          ScopedDeleteFldStrict,      OP_ScopedDeleteFldStrict, ElementScopedC)
  DEF3_WMS(CUSTOM,                  LdElemUndef,                OP_LdElementUndefined, ElementU)
EXDEF3_WMS(CUSTOM,                  LdLocalElemUndef,           OP_LdLocalElementUndefined, ElementRootU)
  DEF2_WMS(XXtoA1,                  NewScObjectSimple,          OP_NewScObjectSimple)
  DEF3    (CUSTOM,                  NewScObject_A,              OP_NewScObject_A, Auxiliary)
  DEF3    (CUSTOM,                  NewScObjectLiteral,         OP_NewScObjectLiteral, Auxiliary)
  DEF3    (CUSTOM_L_R0,             LdPropIds,                  OP_LdPropIds, Auxiliary)
  DEF3    (CUSTOM,                  InitCachedFuncs,            OP_InitCachedFuncs, AuxNoReg)
  DEF2_WMS(LOCALI1toA1,             GetCachedFunc,              OP_GetCachedFunc)
  DEF2_WMS(EnvU1toXX,               InvalCachedScope,           JavascriptOperators::OP_InvalidateCachedScope)
  DEF3    (CUSTOM,                  CommitScope,                OP_CommitScope, AuxNoReg)
  DEF2_WMS(A1I2toXXNonVar_FuncBody, NewInnerScopeSlots,         OP_NewInnerScopeSlots)
  DEF3_WMS(CUSTOM,                  CloneInnerScopeSlots,       OP_CloneInnerScopeSlots, Unsigned1)
  DEF3_WMS(CUSTOM_L_R0,             NewScArray,                 OP_NewScArray, Reg1Unsigned1)
  DEF2_WMS(U1toA1,                  NewScArrayWithMissingValues,JavascriptArray::OP_NewScArrayWithMissingValues)
  DEF3    (CUSTOM_L_R0,             NewScIntArray,              OP_NewScIntArray, Auxiliary)
  DEF3    (CUSTOM_L_R0,             NewScFltArray,              OP_NewScFltArray, Auxiliary)
  DEF3_WMS(CUSTOM_L_R0,             ProfiledNewScArray,         PROFILEDOP(OP_ProfiledNewScArray, OP_ProfiledNewScArray_NoProfile), ProfiledReg1Unsigned1)
  DEF3    (CUSTOM_L_R0,             ProfiledNewScIntArray,      PROFILEDOP(OP_ProfiledNewScIntArray, OP_NewScIntArray), ProfiledAuxiliary)
  DEF3    (CUSTOM_L_R0,             ProfiledNewScFltArray,      PROFILEDOP(OP_ProfiledNewScFltArray, OP_NewScFltArray), ProfiledAuxiliary)
  DEF2_WMS(RegextoA1,               NewRegEx,                   JavascriptRegExp::OP_NewRegEx)
EXDEF3_WMS(CUSTOM,                  InitClass,                  OP_InitClass, Class)
  DEF3_WMS(BRBReturnP1toA1,         BrOnEmpty,                  JavascriptOperators::OP_BrOnEmpty, ForInObjectEnumerator *)
  DEF2    (TRY,                     TryCatch,                   OP_TryCatch)
  DEF2    (TRY,                     TryFinally,                 OP_TryFinally)
EXDEF2_WMS(TRYBR2,                  TryFinallyWithYield,        OP_TryFinallyWithYield)
EXDEF2    (EMPTY,                   ResumeCatch,                OP_ResumeCatch)
EXDEF2_WMS(TRYBR2,                  ResumeFinally,              OP_ResumeFinally)
  DEF2_WMS(A1NonVarToA1,            ResumeYield,                OP_ResumeYield)
  DEF2_WMS(A2NonVarToA1Reg,         ResumeYieldStar,            OP_ResumeYield)
EXDEF2_WMS(A2toA1Mem,               AsyncSpawn,                 JavascriptOperators::OP_AsyncSpawn)
EXDEF2    (W1,                      RuntimeTypeError,           JavascriptExceptionOperators::OP_RuntimeTypeError)
EXDEF2    (W1,                      RuntimeReferenceError,      JavascriptExceptionOperators::OP_RuntimeReferenceError)
EXDEF3    (CUSTOM_L_R0,             SpreadArrayLiteral,         OP_SpreadArrayLiteral, Reg2Aux)
EXDEF2_WMS(A1toXX,                  ObjectFreeze,               JavascriptOperators::OP_Freeze)
EXDEF3_WMS(CUSTOM,                  ClearAttributes,            OP_ClearAttributes, ElementU)
  DEF3_WMS(CUSTOM,                  ApplyArgs,                  OP_ApplyArgs, Reg5)
EXDEF3_WMS(CUSTOM,                  EmitTmpRegCount,            OP_EmitTmpRegCount, Unsigned1)
EXDEF2    (EMPTY,                   BeginBodyScope,             OP_BeginBodyScope)

#endif

// help the caller to undefine all the macros
#undef DEF2
#undef DEF3
#undef DEF2_WMS
#undef DEF3_WMS
#undef DEF4_WMS
#undef EXDEF2
#undef EXDEF3
#undef EXDEF2_WMS
#undef EXDEF3_WMS
#undef EXDEF4_WMS
