#pragma once

#include <Dolphin/types.h>
#include <SMS/Manager/EnemyManager.hxx>
#include <SMS/Enemy/SpineEnemy.hxx>
#include <SMS/System/Params.hxx>

struct TSmallEnemyParams : TSpineEnemyParams {

    TSmallEnemyParams(const char *prm)
        : TSpineEnemyParams(prm), SMS_TPARAM_INIT(mSLJumpForce, 5.0f),
          SMS_TPARAM_INIT(mSLSearchLength, 600.0f), SMS_TPARAM_INIT(mSLSearchHeight, 600.0f),
          SMS_TPARAM_INIT(mSLSearchAware, 150.0f), SMS_TPARAM_INIT(mSLSearchAngle, 140.0f),
          SMS_TPARAM_INIT(mSLGiveUpLength, 1000.0f), SMS_TPARAM_INIT(mSLGiveUpHeight, 650.0f),
          SMS_TPARAM_INIT(mSLAttackWait, 0), SMS_TPARAM_INIT(mSLFreezeWait, 50),
          SMS_TPARAM_INIT(mSLDamageRadius, 115), SMS_TPARAM_INIT(mSLDamageHeight, 100),
          SMS_TPARAM_INIT(mSLAttackRadius, 90), SMS_TPARAM_INIT(mSLAttackHeight, 60),
          SMS_TPARAM_INIT(mSLTurnSpeedLow, 0.9f), SMS_TPARAM_INIT(mSLTurnSpeedHigh, 1.0f),
          SMS_TPARAM_INIT(mSLBodyScaleLow, 1.0f), SMS_TPARAM_INIT(mSLBodyScaleHigh, 1.6f),
          SMS_TPARAM_INIT(mSLGenItemRate, 10.0f), SMS_TPARAM_INIT(mSLGenEggRate, 50.0f),
          SMS_TPARAM_INIT(mSLPolluteRange, 5), SMS_TPARAM_INIT(mSLWaitTime, 100),
          SMS_TPARAM_INIT(mSLPolluteRMin, 1), SMS_TPARAM_INIT(mSLPolluteRMax, 3),
          SMS_TPARAM_INIT(mSLPolluteCycle, 300), SMS_TPARAM_INIT(mSLStampRange, 5),
          SMS_TPARAM_INIT(mSLPolluteInterval, 60), SMS_TPARAM_INIT(mSLGenerateOnlyDead, 0) {
        load(prm);
    }

    TParamRT<f32> mSLJumpForce;
    TParamRT<f32> mSLSearchLength;
    TParamRT<f32> mSLSearchHeight;
    TParamRT<f32> mSLSearchAware;
    TParamRT<f32> mSLSearchAngle;
    TParamRT<f32> mSLGiveUpLength;
    TParamRT<f32> mSLGiveUpHeight;
    TParamRT<u32> mSLAttackWait;
    TParamRT<u32> mSLFreezeWait;
    TParamRT<u32> mSLDamageRadius;
    TParamRT<u32> mSLDamageHeight;
    TParamRT<u32> mSLAttackRadius;
    TParamRT<u32> mSLAttackHeight;
    TParamRT<f32> mSLTurnSpeedLow;
    TParamRT<f32> mSLTurnSpeedHigh;
    TParamRT<f32> mSLBodyScaleLow;
    TParamRT<f32> mSLBodyScaleHigh;
    TParamRT<f32> mSLGenItemRate;
    TParamRT<f32> mSLGenEggRate;
    TParamRT<u8> mSLPolluteRange;
    TParamRT<u32> mSLWaitTime;
    TParamRT<u32> mSLPolluteRMin;
    TParamRT<u32> mSLPolluteRMax;
    TParamRT<u32> mSLPolluteCycle;
    TParamRT<u8> mSLStampRange;
    TParamRT<u32> mSLPolluteInterval;
    TParamRT<u8> mSLGenerateOnlyDead;
};

class TSmallEnemy : public TSpineEnemy {

public:
    TSmallEnemy(const char *name);
    ~TSmallEnemy();

    virtual void init(TLiveManager *) override;
    virtual void kill() override;
    virtual void load(JSUMemoryInputStream &) override;
    virtual void perform(u32, JDrama::TGraphics *) override;
    virtual bool receiveMessage(THitActor *, u32) override;
    virtual void reset() override;
    virtual void moveObject() override;
    virtual void updateAnmSound() override;
    virtual void loadAfter() override;

    virtual void attackToMario();
    virtual void behaveToWater(THitActor *);
    virtual void endHitWaterJump();
    virtual void genRandomItem();
    virtual void initAttacker(THitActor *);
    virtual bool isCollideMove(THitActor *);
    virtual u32 isFindMario(float);
    virtual u32 isHitValid(u32);  //(ulong)
    virtual void scalingChangeActor();
    virtual void sendAttackMsgToMario();
    virtual void setAfterDeadEffect();
    virtual void setBckAnm(int);
    virtual void setBehavior();
    virtual void setDeadAnm();
    virtual void setDeadEffect();
    virtual void setFreezeAnm();
    virtual void setGenerateAnm();
    virtual void setMActorAndKeeper();
    virtual void setMeltAnm();
    virtual void setRunAnm();
    virtual void setWaitAnm();
    virtual void setWalkAnm();

    void behaveToHitOthers(THitActor *);
    void behaveToRelease();
    void behaveToTaken(THitActor *);
    u32 changeByJuice();  // unknown4
    u8 changeMove();      // uint
    void changeOut();
    void decHpByWater(THitActor *);
    u32 doKeepDistance();
    void expandCollision();
    void forceKill();
    void generateEffectColumWater();
    void generateItem();
    void genEventCoin();
    u32 getChangeBlockTime();
    u32 isEaten();  // 1 or 0
    u32 isEatenByYoshi();
    u32 isFindMarioFromParam(float) const;
    u32 isHitWallInBound();
    u32 isInhibitedForceMove();
    u32 isMarioInWater() const;
    void jumpBehavior();
   /* const bool mIsAmpPolluter;
    const bool mIsPolluter;*/

    u32 _150;
    f32 _154;
    f32 _158;
    u32 _15C;
    u32 _160;
    u8 _164;
    u8 _165;
    u8 _166;  // padding?
    u8 _167;  // padding?
    u32 _174;
    u32 _178;
    u32 _17C;
    u32 _180;
    u8 _184;
    u8 _185;
    u8 _186;  // padding?
    u8 _187;  // padding?
    f32 _188;
    u32 _18C;
};

class TSmallEnemyManager : public TEnemyManager {
public:
    TSmallEnemyManager(const char *);
    virtual ~TSmallEnemyManager();

    virtual void createEnemies(int) override;
    virtual void load(JSUMemoryInputStream &) override;
    virtual void createModelData() override;
    virtual void loadAfter() override;

    virtual int getHolder(int);
    virtual void initSetEnemies();

    /*const f32 mBlockMoveSpeed;
    const f32 mBlockWaitMoveY;
    const u32 mBlockWaitTime;
    const f32 mBlockXZScale;
    const f32 mBlockYScale;
    const u32 mChangeBlockTime;
    const u8 mTestJuiceType;*/

    u32 _54;  // code executed after adding enemies
    u32 _58;  // something texStamp Replated
    u32 _5C;  // 60
};