#pragma once

#include <Dolphin/types.h>
#include <JSystem/JDrama/JDRActor.hxx>
#include <JSystem/JGeometry/JGMVec.hxx>
#include <SMS/Enemy/WalkerEnemy.hxx>
#include <SMS/MapObj/MapObjBase.hxx>
#include <SMS/System/Params.hxx>

struct THamuKuriSaveLoadParams : TWalkerEnemyParams {

    THamuKuriSaveLoadParams(const char *prm)
        : TWalkerEnemyParams(prm), SMS_TPARAM_INIT(mSLWaterCoeff, 25.0f),
          SMS_TPARAM_INIT(mSLWaterAttackCoeff, 2.0f), SMS_TPARAM_INIT(mSLFirstVelocityY, 8.0f),
          SMS_TPARAM_INIT(mSLVelocityRate, 0.8f), SMS_TPARAM_INIT(mSLBoundNum, 2),
          SMS_TPARAM_INIT(mSLSearchActorTimer, 500), SMS_TPARAM_INIT(mSLCanSearchDist, 800.0f),
          SMS_TPARAM_INIT(mSLJitabataTimer, 200), SMS_TPARAM_INIT(mSLFirstKickVelocityY, 2.0f),
          SMS_TPARAM_INIT(mSLFlyTimer, 500), SMS_TPARAM_INIT(mSLTrampleBonusNum, 3),
          SMS_TPARAM_INIT(mSLCrashBonusNum, 3), SMS_TPARAM_INIT(mSLSerialCrashFrame, 15),
          SMS_TPARAM_INIT(mSLKyoroTimer, 500) {
        load(prm);
    }

    TParamRT<f32> mSLWaterCoeff;
    TParamRT<f32> mSLWaterAttackCoeff;
    TParamRT<f32> mSLFirstVelocityY;
    TParamRT<f32> mSLVelocityRate;
    TParamRT<u32> mSLBoundNum;
    TParamRT<u32> mSLSearchActorTimer;
    TParamRT<f32> mSLCanSearchDist;
    TParamRT<u32> mSLJitabataTimer;
    TParamRT<f32> mSLFirstKickVelocityY;
    TParamRT<u32> mSLFlyTimer;
    TParamRT<u32> mSLTrampleBonusNum;
    TParamRT<u32> mSLCrashBonusNum;
    TParamRT<u32> mSLSerialCrashFrame;
    TParamRT<u32> mSLKyoroTimer;
};

class THamuKuri : public TWalkerEnemy {

public:
    THamuKuri(const char *);
    virtual ~THamuKuri();

    virtual void attackToMario() override;
    virtual void behaveToFindMario() override;
    virtual void behaveToWater(THitActor *) override;
    virtual void bind() override;
    virtual void endHitWaterJump() override;
    virtual void genRandomItem() override;
    virtual const char **getBasNameTable() const override;
    virtual f32 getGravityY() const override;
    virtual Mtx44 *getTakingMtx() override;
    virtual void init(TLiveManager *) override;
    virtual void initAttacker(THitActor *) override;
    virtual bool isCollideMove(THitActor *) override;
    virtual u32 isFindMario(float) override;
    virtual u32 isHitValid(u32) override;  //(ulong)
    void bool isResignationAttack() override;
    virtual void moveObject() override;
    virtual void reset() override;
    virtual void setAfterDeadEffect() override;
    virtual void setBckAnm(int) override;
    virtual void setDeadAnm() override;
    virtual void setGenerateAnm() override;
    virtual void setMActorAndKeeper() override;
    virtual void setRunAnm() override;
    virtual void setWaitAnm() override;
    virtual void setWalkAnm() override;
    virtual void walkBehavior(int, float) override;

    u8 canDoJitabata();  // uint
    void forceRoll(JGeometry::TVec3<float><float> &, bool);
    void jumpToSearchActor();
    void makeCapFly(TMapObjBase *);
    f32 mCapGravityY;
    f32 mCapSpeed;
    f32 mLandAnimFrameNum;
    f32 mVGenerateGravityY;
    void onHaveCap();
    void selectCapHolder();
    void setBehaviour();
    void setCrashAnm();
    void setRollAnm();

    f32 _194;
    f32 _198;
    f32 _19C;
    u8 _1A0;
    u8 _1A1;
    u8 _1A2;
    u8 _1A3;
    u8 _1A4;
    u8 _1A5;
    u8 _1A6;  // padding?
    u8 _1A7;  // padding?
    f32 _1E0;
    f32 _1F0;
    f32 _1F8;
};

class THamuKuriManager : public TSmallEnemyManager {
public:
    THamuKuriManager(const char *, int isDemoMode);
    virtual ~THamuKuriManager();

    virtual void createModelData() override;
    virtual void load(JSUMemoryInputStream &) override;
    virtual void loadAfter() override;
    virtual void perform(u32, JDrama::TGraphics *);

    void checkSerialKill();
    void createAnmData();
    THamuKuri createEnemyInstance();
    void requestSerialKill(THamuKuri *);
    void setSearchHamuKuri();

    const f32 mSearchActSw;

    u32 _60;  // Something to do with 1up
    u32 _64;  // Something to do with 1up
    u32 _68;  // Something to do with 1up
    u32 _6C;
    u32 _70;
};